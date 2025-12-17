#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aluno
{
    string nome;

public:
    Aluno(string n)
    {
        nome = n;
    }

    string getNome()
    {
        return nome;
    }
};

class Professor
{
    string nome;

public:
    Professor(string n)
    {
        nome = n;
    }

    string getNome()
    {
        return nome;
    }
};

class Turma
{
    string codigo;
    Professor professor;
    vector<Aluno> alunos;

public:
    Turma(string c, Professor p) : codigo(c), professor(p) { }

    void matricular(Aluno a)
    {
        alunos.push_back(a);
    }

    void listar()
    {
        cout << "Turma " << codigo << " - Prof. " << professor.getNome() << "\n";
        for (int i = 0; i < (int)alunos.size(); i++)
            cout << "- " << alunos[i].getNome() << "\n";
    }
};

class Curso
{
    string nome;
    vector<Turma> turmas;

public:
    Curso(string n)
    {
        nome = n;
    }

    void adicionarTurma(Turma t)
    {
        turmas.push_back(t);
    }

    void listar()
    {
        cout << "Curso: " << nome << "\n";
        for (int i = 0; i < (int)turmas.size(); i++)
        {
            turmas[i].listar();
            cout << "\n";
        }
    }
};

int main()
{
    Professor prof("Luiz");
    Turma t("A1", prof);
    t.matricular(Aluno("Ana"));
    t.matricular(Aluno("Bruno"));

    Curso curso("Programacao");
    curso.adicionarTurma(t);

    curso.listar();

    return 0;
}
