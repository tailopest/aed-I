#include "filme.h"
using namespace std;

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef Filme ListEntry;

class List{ 
public:
    List();
    ~List();
    void insert(int p, ListEntry f);
    int search(int codigo, Filme &f);
    int remove(int codigo, Filme &f);
    bool empty();
    bool full();
    void clear();
    int size();
    void print();
    void recomendar(string genero);

private:
    struct ListNode; 
    typedef ListNode * ListPointer;
    struct ListNode{ 
        ListEntry entry; 
        ListPointer nextNode;
    };

    ListPointer head;
    int n;
    void setPosition(int p, ListPointer &current);
};

#endif