#include <iostream>
#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    clear();
}

void AVLTree::clear() {
    clear(root);
    root = NULL;
}

void AVLTree::clear(TreePointer &t) {
    if (t != NULL) {
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
    }
}

bool AVLTree::search(int codigo) {
    return search(codigo, root);
}

bool AVLTree::search(int codigo, TreePointer &t) {
    if (t == NULL) {
        return false;
    } 
    if (codigo < t->entry.codigo) {
        return search(codigo, t->leftNode);
    } else {
        if (codigo > t->entry.codigo) {
            return search(codigo, t->rightNode);
        }
        else {
            return true;
        }
    }
}

void AVLTree::searchInsert(TreeEntry f) { 
    bool h=false;
    searchInsert(f,root,h);
}

void AVLTree::searchInsert(TreeEntry f, TreePointer &pA, bool &h) { 
    TreePointer pB, pC;
    if(pA == NULL) { 
        pA = new TreeNode;
        h = true;
        pA->entry = f;
        pA->count = 1;
        pA->leftNode = pA->rightNode = NULL;
        pA->bal = 0;
    }
    else {
        if(f.codigo < pA->entry.codigo) { 
            searchInsert(f, pA->leftNode, h);            
            if(h) { 
                switch (pA->bal) { 
                    case -1: pA->bal = 0; h = false; break;
                    case 0: pA->bal = +1; break;
                    case +1: 
                        pB = pA->leftNode;
                        if (pB->bal == +1) {
                            pA->leftNode = pB->rightNode; 
                            pB->rightNode = pA;
                            pA->bal = 0; 
                            pA = pB;
                        } else { 
                            pC = pB->rightNode; 
                            pB->rightNode = pC->leftNode;
                            pC->leftNode = pB; 
                            pA->leftNode = pC->rightNode;
                            pC->rightNode = pA;

                            if(pC->bal == +1) {
                                pA->bal = -1; 
                            } else {
                                pA->bal = 0;
                            }

                            if(pC->bal == -1) {
                                pB->bal = +1; 
                            } else {
                                pB->bal = 0;
                            }
                        pA = pC;
                        pA->bal = 0; 
                        
                        }
                    h = false;                            
                    break;
                }
            }
        } else {
            if(f.codigo > pA->entry.codigo) { 
                searchInsert(f, pA->rightNode, h);
                if(h) { 
                    switch (pA->bal) { 
                        case +1: pA->bal = 0; h = false; break;
                        case 0: pA->bal = -1; break;
                        case -1: pB = pA->rightNode;

                        if(pB->bal == -1) { 
                            pA->rightNode = pB->leftNode; pB->leftNode = pA;
                            pA->bal = 0; pA = pB;
                        } else { 
                            pC = pB->leftNode; pB->leftNode = pC->rightNode;
                            pC->rightNode = pB; pA->rightNode = pC->leftNode;
                            pC->leftNode = pA;
                            if(pC->bal == -1) {
                                pA->bal = +1;
                            } else {
                                pA->bal = 0;
                            }
                            if(pC->bal == +1) {
                                pB->bal = -1;
                            } else {
                                pB->bal = 0;
                            }
                            pA = pC;
                        }
                        pA->bal = 0; h = false;
                    }
                }
            } else {
                pA->count++;
            }
        }
    }
}

bool AVLTree::remove(int codigo) { 
    bool h=false;
    return remove(codigo,root,h);
}

bool AVLTree::remove(int codigo, TreePointer &p, bool &h) { 
    TreePointer q;
    bool removeu;
    if(p == NULL) {
        return false;
    }

    if(codigo < p->entry.codigo) { 
        removeu = remove(codigo,p->leftNode,h);
        if(h) {
            balanceL(p,h);
        }
    return removeu;
    }
    else {
        if(codigo > p->entry.codigo) { 
            removeu = remove(codigo,p->rightNode,h);
            if(h) {
                balanceR(p,h);
            }
        return removeu;
        } else { 
            q = p;
            if(q->rightNode == NULL) { 
                p = q->leftNode;
                h = true;
            }
            else {
                if(q->leftNode == NULL) { 
                    p = q->rightNode;
                    h = true;
                } else { 
                    removeMin(q,q->rightNode,h);
                    if(h)
                    balanceR(p,h);
                }
            }
            delete q;
            return true;
        }
    }
}

void AVLTree::removeMin(TreePointer &q, TreePointer &r, bool &h) {
    if(r->leftNode != NULL) { 
        removeMin(q, r->leftNode, h);
        if(h) {
            balanceL(r,h);
        }
    } else { 
        q->entry = r->entry;
        q->count = r->count;
        q = r;
        r = r->rightNode;
        h = true;
    }
}

void AVLTree::balanceL(TreePointer &pA, bool &h) { 
    TreePointer pB, pC;
    int balB, balC;

    switch(pA->bal) { 
        case +1: pA->bal = 0; break;
        case 0: pA->bal = -1; h = false; break;
        case -1:
        pB = pA->rightNode; 
        balB = pB->bal;
        if(balB <= 0) { 
            pA->rightNode = pB->leftNode;
            pB->leftNode = pA;
            if(balB == 0) { 
                pA->bal = -1;
                pB->bal = +1; 
                h = false; 
            } else { 
                pA->bal = 0; pB->bal = 0; 
            }
        pA = pB;
        } else {
            pC = pB->leftNode; 
            balC = pC->bal;
            pB->leftNode = pC->rightNode;
            pC->rightNode = pB;
            pA->rightNode = pC->leftNode;
            pC->leftNode = pA;

            if(balC==-1) {
                pA->bal=+1; 
            } else { 
                pA->bal=0;
            } 

            if(balC==+1) {
                pB->bal=-1; 
            } else {
                pB->bal=0;
            }   
            pA = pC; 
            pC->bal = 0;
        }
    }
}

void AVLTree::balanceR(TreePointer &pA, bool &h) { 
    TreePointer pB, pC;
    int balB, balC;
    switch(pA->bal) { 
        case -1: 
            pA->bal = 0; 
            break;
        case 0: 
            pA->bal = +1; 
            h = false; 
                break;
        case +1:
            pB = pA->leftNode; 
            balB = pB->bal;
            if(balB >= 0) { 
                pA->leftNode = pB->rightNode;
                pB->rightNode = pA;
                if(balB == 0) { 
                    pA->bal = +1; 
                    pB->bal = -1; 
                    h = false; 
                } else { 
                    pA->bal = 0; 
                    pB->bal = 0; 
                }
                pA = pB;
            } else { 
                pC = pB->rightNode; balC = pC->bal;
                pB->rightNode = pC->leftNode;
                pC->leftNode = pB;
                pA->leftNode = pC->rightNode;
                pC->rightNode = pA;
            if(balC==+1) {
                pA->bal=-1;
            } else {
                pA->bal=0;
            }            
            if(balC==-1) {
                pB->bal=+1; 
            } else {
                pB->bal=0;
            }
            pA = pC; pC->bal = 0;
        }
    }
}