#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct Filme
{
    int codigo;
    string titulo;
    string genero;
    int ano;
    float nota;
} Filme;

class ListaFilmes
{
public:
    ListaFilmes();
    bool empty();
    bool full();
    void insert(Filme x);
    void remove(int codigo);
    int search(int codigo);
    int searchComContador(int codigo, int &comp); 
    bool consultar(int codigo, Filme &resultado);
    void ListarFilmes();
    void FilmesRecomendados(string genero);
    void clear();
    int size();

private:
    static const int MaxList = 2000;
    int count;
    Filme entry[MaxList + 1];
};

ListaFilmes::ListaFilmes() {
    count = 0;
}

bool ListaFilmes::empty() {
    return (count == 0);
}

bool ListaFilmes::full() {
    return (count == MaxList);
}

void ListaFilmes::insert(Filme x) {
    int i, j;
    if (full()) {
        cout << "Lista Cheia";
        abort();
    }
    i = 1;
    while (i <= count && x.codigo > entry[i].codigo)
        i++;
    for (j = count; j >= i; j--)
        entry[j + 1] = entry[j];
    entry[i] = x;
    count++;
}

void ListaFilmes::remove(int codigo) {
    int i, p;
    if (empty()) {
        cout << "Lista Vazia";
        abort();
    }
    p = search(codigo);
    if (p == 0)
        return;
    for (i = p; i < count; i++)
        entry[i] = entry[i + 1];
    count = count - 1;
}

int ListaFilmes::search(int codigo) {
    int t, e = 1, d = count;
    while (e < d) {
        t = (e + d) / 2;
        if (entry[t].codigo < codigo)
            e = t + 1;
        else
            d = t;
    }
    return (entry[d].codigo != codigo ? 0 : d);
}


int ListaFilmes::searchComContador(int codigo, int &comp) {
    int t, e = 1, d = count;
    comp = 0;
    while (e < d) {
        t = (e + d) / 2;
        comp++;
        if (entry[t].codigo < codigo)
            e = t + 1;
        else
            d = t;
    }
    if (count > 0) comp++;
    return (count == 0 || entry[d].codigo != codigo ? 0 : d);
}

bool ListaFilmes::consultar(int codigo, Filme &resultado) {
    int con = search(codigo);
    if (con == 0)
        return false;
    resultado = entry[con];
    return true;
}

void ListaFilmes::ListarFilmes() {
    if (empty()) {
        cout << "Nenhum filme cadastrado." << endl;
        return;
    }
    for (int i = 1; i <= count; i++) {
        cout << entry[i].codigo << " - " << entry[i].titulo
             << " (" << entry[i].ano << ") - " << entry[i].genero
             << " - Nota: " << entry[i].nota << endl;
    }
}

void ListaFilmes::FilmesRecomendados(string genero) {
    Filme filme[MaxList + 1];
    int qtd = 0;

    for (int i = 1; i <= count; i++) {
        if (entry[i].genero == genero) {
            qtd++;
            filme[qtd] = entry[i];
        }
    }

    if (qtd == 0) {
        cout << "Nenhum filme encontrado :(" << endl;
        return;
    }

    for (int i = 1; i <= qtd - 1; i++) {
        int maior = i;
        for (int j = i + 1; j <= qtd; j++) {
            if (filme[j].nota > filme[maior].nota)
                maior = j;
        }
        Filme aux = filme[i];
        filme[i] = filme[maior];
        filme[maior] = aux;
    }

    cout << "Filmes recomendados:" << endl;
    for (int i = 1; i <= qtd; i++) {
        cout << filme[i].codigo << " - " << filme[i].titulo
             << " (" << filme[i].ano << ") - Nota: " << filme[i].nota << endl;
    }
}

void ListaFilmes::clear() {
    count = 0;
}

int ListaFilmes::size() {
    return count;
}

void TestarDesempenho() {
    int tamanhos[] = {100, 200, 400, 800, 1000};
    int qtdTestes = 5;

    cout << "\n--- Teste de Desempenho ---" << endl;
    cout << "n\t\tComparacoes" << endl;

    for (int t = 0; t < qtdTestes; t++) {
        ListaFilmes lista;
        int n = tamanhos[t];

        for (int i = 1; i <= n; i++) {
            Filme f;
            f.codigo = i;
            f.titulo = "Barbie";
            f.genero = "Comedia - Animacao";
            f.ano = 2000;
            f.nota = 8.5;
            lista.insert(f);
        }
         for (int k = 1; k <= n; k++) {
            Filme f;
            f.codigo = k;
            f.titulo = "O Auto Da Compadecida";
            f.genero = "Comedia";
            f.ano = 2000;
            f.nota = 10;
            lista.insert(f);
        }

        int comp = 0;
        lista.searchComContador(n + 1, comp);

        cout << n << "\t\t" << comp << endl;
    }
}

int main() {
    ListaFilmes lista;
    int opcao = 0;

    while (opcao != 6) {
        cout << "\n----- MENU -----" << endl;
        cout << "1 - Inserir filme" << endl;
        cout << "2 - Remover filme" << endl;
        cout << "3 - Consultar filme por codigo" << endl;
        cout << "4 - Recomendar filmes por genero" << endl;
        cout << "5 - Listar filmes" << endl;
        cout << "6 - Sair" << endl;
        cout << "7 - Testar desempenho" << endl;  
        cout << "Escolha uma das opcoes: ";
        cin >> opcao;

        if (opcao == 1) {
            Filme f;
            cout << "Codigo: ";
            cin >> f.codigo;

            if (lista.search(f.codigo) != 0) {
                cout << "Ja existe um filme com esse codigo." << endl;
            } else if (lista.full()) {
                cout << "Lista cheia, nao e possivel inserir." << endl;
            } else {
                cout << "Titulo: ";
                cin.ignore();
                getline(cin, f.titulo);
                cout << "Genero: ";
                getline(cin, f.genero);
                cout << "Ano: ";
                cin >> f.ano;
                cout << "Nota: ";
                cin >> f.nota;

                lista.insert(f);
                cout << "Filme inserido com sucesso!" << endl;
            }
        }
        else if (opcao == 2) {
            int codigo;
            cout << "Codigo do filme a remover: ";
            cin >> codigo;

            if (lista.search(codigo) == 0) {
                cout << "Filme nao encontrado." << endl;
            } else {
                lista.remove(codigo);
                cout << "Filme removido com sucesso!" << endl;
            }
        }
        else if (opcao == 3) {
            int codigo;
            cout << "Codigo do filme: ";
            cin >> codigo;

            Filme f;
            if (lista.consultar(codigo, f)) {
                cout << f.codigo << " - " << f.titulo << " (" << f.ano
                     << ") - " << f.genero << " - Nota: " << f.nota << endl;
            } else {
                cout << "Filme nao encontrado." << endl;
            }
        }
        else if (opcao == 4) {
            string genero;
            cout << "Genero preferido: ";
            cin.ignore();
            getline(cin, genero);
            lista.FilmesRecomendados(genero);
        }
        else if (opcao == 5) {
            lista.ListarFilmes();
        }
        else if (opcao == 6) {
            cout << "Saindo..." << endl;
        }
        else if (opcao == 7) {
            TestarDesempenho();  
        }
        else {
            cout << "Opcao invalida." << endl;
        }
    }

    return 0;
}
