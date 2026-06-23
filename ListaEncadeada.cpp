#include <iostream>
#include "ListaEncadeada.h"
using namespace std;

List::List(){
    head = NULL;
    n = 0;
}

List::~List(){
    clear();
}

bool List::empty(){
    return (head == NULL);
}

bool List::full(){
    return false;
}

void List::setPosition(int p, ListPointer &current){
    int i;
    current = head;
    for(i = 2; i <= p; i++)
        current = current->nextNode;
}

void List::insert(int p, ListEntry x){ 
    ListPointer newNode, current;

    if (p < 1 || p > n+1){ 
        cout << "Posicao Invalida.";
        abort();
    }

    newNode = new ListNode;
    newNode->entry = x;

    if(p == 1){ 
        newNode->nextNode = head;
        head = newNode;
    }
    else{ 
        setPosition(p-1,current);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    n++;
}

int List::search(int codigo, Filme &x) {
    ListPointer current = head;
    int pos = 1;
    while (current != NULL) {
        if (current->entry.codigo == codigo) {
            x = current->entry;
            return pos;
        }

        current = current->nextNode;
        pos++;
    }
    return 0;
}

int List::remove(int codigo, Filme &x) {
    ListPointer current = head;
    ListPointer previous = NULL;
    int pos = 1;
    while (current != NULL) {
        if (current->entry.codigo == codigo) {
            x = current->entry;

            if (previous == NULL) {
                head = current->nextNode;
            } else {
                previous->nextNode = current->nextNode;
            }

            delete current;
            n--;

            return pos;
        }
        previous = current;
        current = current->nextNode;
        pos++;
    }
    return 0;
}

void List::clear(){
    ListPointer q;
    while (head != NULL){ 
        q = head;
        head = head->nextNode;
        delete q;
    }
}

int List::size(){
    return n;
}

void List::print() {
    ListPointer current = head;
    while (current != NULL) {
        cout << "Codigo: " << current->entry.codigo << endl;
        cout << "Titulo: " << current->entry.titulo << endl;
        cout << "Genero: " << current->entry.genero << endl;
        cout << "Ano: " << current->entry.ano << endl;
        cout << "Nota: " << current->entry.nota << endl;

        current = current->nextNode;
    }
}

void List::recomendar(string genero) {
    ListPointer current = head;
    while (current != NULL) {
        if (current->entry.genero == genero) {
            cout << "Codigo: " << current->entry.codigo << endl;
            cout << "Titulo: " << current->entry.titulo << endl;
            cout << "Genero: " << current->entry.genero << endl;
            cout << "Ano: " << current->entry.ano << endl;
            cout << "Nota: " << current->entry.nota << endl;
            cout << "----------------------\n";
        }
        current = current->nextNode;
    }
}