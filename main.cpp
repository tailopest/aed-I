#include <iostream>
#include "ListaOrdenada.h"
#include "TabelaHash.h"
#include "ArvoreAVL.h"

using namespace std;

void menuCatalogo(int tipoEstrutura, ListaOrdenada& lista, TabelaHash& hash, ArvoreAVL& avl) {
    int op;
    do {
        cout << "============================================\n"; 
        cout << "Sistema de Catalogo e Recomendacao de Filmes\n"; 
        cout << "============================================\n";
        cout << "1. Inserir filme\n";
        cout << "2. Remover filme\n";
        cout << "3. Consultar filme por codigo\n";
        cout << "4. Recomendar filmes por genero\n";
        cout << "5. Listar filmes\n";
        cout << "6. Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> op;
        
        switch (op) {
            case 1:
                Filme f;
                if (tipoEstrutura == 1) lista.inserir(f);
                else if (tipoEstrutura == 2) hash.inserir(f);
                else avl.inserir(f);
                break;
            case 2:
                if (tipoEstrutura == 1) lista.remover(cod);
                else if (tipoEstrutura == 2) hash.remover(cod);
                else avl.remover(cod);
                break;
            case 3:
                if (tipoEstrutura == 1) lista.consultar(cod);
                else if (tipoEstrutura == 2) hash.consultar(cod);
                else avl.consultar(cod);
                break;
            case 4:
                if (tipoEstrutura == 1) lista.recomendar(gen);
                else if (tipoEstrutura == 2) hash.recomendar(gen);
                else avl.recomendar(gen);
                break;
            case 5:
                if (tipoEstrutura == 1) lista.listar();
                else if (tipoEstrutura == 2) hash.listar();
                else avl.listar();
                break;
        }
    } while (op != 6);
}

int main() {
    ListaOrdenada lista;
    TabelaHash hash;
    ArvoreAVL avl;

    int estrutura;
    do {
        cout << "1. Lista Ordenada\n";
        cout << "2. Tabela Hash\n";
        cout << "3. Arvore AVL\n";
        cout << "4. Sair\n";
        cout << "Escolha uma estrutura: ";
        cin >> estrutura;

        switch (estrutura) {
            case 1: menuCatalogo(1, lista, hash, avl); break;
            case 2: menuCatalogo(2, lista, hash, avl); break;
            case 3: menuCatalogo(3, lista, hash, avl); break;
        }
    } while (estrutura != 4);
}