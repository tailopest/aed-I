#include <iostream>
#include "ListaOrdenada.h"
#include "HashTable.h"
#include "AVLTree.h"

using namespace std;

void menuCatalogo(int tipoEstrutura, ListaOrdenada &L, HashTable &H, ALVTree &T) {
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
                if (tipoEstrutura == 1) L.insert(f);
                else if (tipoEstrutura == 2) H.insert(f);
                else T.insert(f);
                break;
            case 2:
                if (tipoEstrutura == 1) L.remove(codigo);
                else if (tipoEstrutura == 2) H.remove(codigo);
                else T.remove(codigo);
                break;
            case 3:
                if (tipoEstrutura == 1) L.search(codigo);
                else if (tipoEstrutura == 2) H.search(codigo);
                else T.search(codigo);
                break;
            case 4:
                if (tipoEstrutura == 1) L.recomendar(genero);
                else if (tipoEstrutura == 2) H.recomendar(genero);
                else T.recomendar(genero);
                break;
            case 5:
                if (tipoEstrutura == 1) L.print();
                else if (tipoEstrutura == 2) H.print();
                else T.print();
                break;
        }
    } while (op != 6);
}

int main() {
    ListaOrdenada lista;
    HashTable H;
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
            case 1: menuCatalogo(1, L, H, T); break;
            case 2: menuCatalogo(2, L, H, T); break;
            case 3: menuCatalogo(3, L, H, T); break;
        }
    } while (estrutura != 4);
}