#include <iostream>
#include <string>
#include "HashTable.h"
#include "ListaEncadeada.h"

HashTable::HashTable() {
    n = 0;
}

HashTable::~HashTable() {
    clear();
}

int HashTable::hash(HashKey k) {
    return k % MaxList;
}

bool HashTable::empty() {
    return (n == 0);
}

bool HashTable::full() {
    return false;
}

float HashTable::loadFactor() {
    return (float) n / MaxList;
}

int HashTable::insert(Filme f) {
    int pos = hash(f.codigo);
    tabela[pos].insert(1, f);
    n++;
    return pos;
}

int HashTable::search(HashKey k, Filme &f) {
    int pos = hash(k);

    if (tabela[pos].search(k, f) != 0) {
        return pos;
    }
    return 0;
}

void HashTable::remove(HashKey k, Filme &f) {
    int pos = hash(k);
    if (tabela[pos].remove(k, f) != 0) {
        n--;
    }
}

void HashTable::recomendar(string genero) {
    for (int i = 0; i < MaxList; i++) {
        tabela[i].recomendar(genero);
    }
}

void HashTable::print() {
    for (int i = 0; i < MaxList; i++) {
        if (!tabela[i].empty()) {
            cout << "Posicao " << i << ":\n";
            tabela[i].print();
        }
    }
}

void HashTable::clear() {
    for (int i = 0; i < MaxList; i++) {
        tabela[i].clear();
    }
    n = 0;
}
