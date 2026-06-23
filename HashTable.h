#include "filme.h"
#include "ListaEncadeada.h"
#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef int HashKey;

class HashTable {
    public:
        HashTable();
        ~HashTable();
        bool empty();
        bool full();
        float loadFactor();
        int insert(Filme f);
        int search(HashKey k, Filme &f);
        void remove(HashKey k, Filme &f);
        void recomendar(string genero);
        void print();
        void clear();

    private:
        static const int MaxList = 100;
        int n;
        List tabela[MaxList+1];
        int hash(HashKey k);
};

#endif