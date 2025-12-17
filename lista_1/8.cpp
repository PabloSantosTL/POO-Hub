#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produto
{
    string nome;
    double preco;

public:
    Produto(string n, double p)
    {
        nome = n;
        preco = p;
    }

    string getNome()
    {
        return nome;
    }

    double getPreco()
    {
        return preco;
    }
};

class CarrinhoItem
{
    Produto produto;
    int quantidade;

public:
    CarrinhoItem(Produto p, int q) : produto(p), quantidade(q) { }

    double subtotal()
    {
        return produto.getPreco() * quantidade;
    }

    string getNome()
    {
        return produto.getNome();
    }
};

class Carrinho
{
    vector<CarrinhoItem> itens;

public:
    void adicionar(Produto p, int q)
    {
        itens.push_back(CarrinhoItem(p, q));
    }

    double total()
    {
        double t = 0.0;
        for (int i = 0; i < (int)itens.size(); i++)
            t += itens[i].subtotal();
        return t;
    }

    vector<CarrinhoItem> getItens()
    {
        return itens;
    }
};

class Pagamento
{
    string tipo; // ex: "Cartao", "Boleto"
    string dados; // info simples

public:
    Pagamento(string t, string d)
    {
        tipo = t;
        dados = d;
    }

    string getTipo()
    {
        return tipo;
    }
};

class Pedido
{
    vector<CarrinhoItem> itens;
    Pagamento pagamento;

public:
    Pedido(vector<CarrinhoItem> its, Pagamento p) : itens(its), pagamento(p) { }

    double valorTotal()
    {
        double tot = 0.0;
        for (int i = 0; i < (int)itens.size(); i++)
            tot += itens[i].subtotal();
        return tot;
    }

    void mostrar()
    {
        cout << "Pedido:\n";
        for (int i = 0; i < (int)itens.size(); i++)
            cout << "- " << itens[i].getNome() << " R$ " << itens[i].subtotal() << "\n";
        cout << "Pagamento: " << pagamento.getTipo() << "\n";
        cout << "Total: R$ " << valorTotal() << "\n";
    }
};

int main()
{
    Carrinho carr;
    carr.adicionar(Produto("Mouse", 79.90), 1);
    carr.adicionar(Produto("Teclado", 149.90), 1);

    Pagamento pag("Cartao", "**** **** **** 1234");

    Pedido pedido(carr.getItens(), pag);
    pedido.mostrar();

    return 0;
}
