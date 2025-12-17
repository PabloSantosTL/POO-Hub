#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente
{
    string nome;

public:
    Cliente(string n)
    {
        nome = n;
    }

    string getNome()
    {
        return nome;
    }
};

class ItemPedido
{
    string produto;
    int quantidade;
    double precoUnitario;

public:
    ItemPedido(string p, int q, double pre)
    {
        produto = p;
        quantidade = q;
        precoUnitario = pre;
    }

    double subtotal()
    {
        return quantidade * precoUnitario;
    }

    string getProduto()
    {
        return produto;
    }
};

class Pedido
{
    Cliente cliente;
    vector<ItemPedido> itens;

public:
    Pedido(Cliente c) : cliente(c) { }

    void adicionarItem(ItemPedido it)
    {
        itens.push_back(it);
    }

    double valorTotal()
    {
        double total = 0.0;
        for (int i = 0; i < (int)itens.size(); i++)
            total += itens[i].subtotal();
        return total;
    }

    void mostrar()
    {
        cout << "Pedido de: " << cliente.getNome() << "\n";
        for (int i = 0; i < (int)itens.size(); i++)
            cout << "- " << itens[i].getProduto() << " R$ " << itens[i].subtotal() << "\n";
        cout << "Total: R$ " << valorTotal() << "\n";
    }
};

int main()
{
    Cliente c("Ana");
    Pedido p(c);

    p.adicionarItem(ItemPedido("Camiseta", 2, 39.90));
    p.adicionarItem(ItemPedido("Calça", 1, 89.50));

    p.mostrar();

    return 0;
}
