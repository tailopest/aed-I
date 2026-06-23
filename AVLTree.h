#include "filme.h"
using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

typedef Filme TreeEntry;
class AVLTree {
    public:
        AVLTree();
        ~AVLTree(); 
        void clear();
        bool search(int codigo);
        void searchInsert(TreeEntry f);
        bool remove(int codigo);
    private:
        struct TreeNode;

        typedef TreeNode * TreePointer;

        struct TreeNode { 
            TreeEntry entry; 
            int count; 
            int bal;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;

        void clear(TreePointer &t);
        bool search(int codigo, TreePointer &t);
        void searchInsert(TreeEntry f, TreePointer &pA, bool &h);
        bool remove(int codigo, TreePointer &p, bool &h);
        void removeMin(TreePointer &q, TreePointer &r, bool &h);
        void balanceL(TreePointer &pA, bool &h);
        void balanceR(TreePointer &pA, bool &h);
};

#endif