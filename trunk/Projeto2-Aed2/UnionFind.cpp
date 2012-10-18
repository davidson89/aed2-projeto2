#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "UnionFind.h"
#include "Les.h"

using namespace std;

UnionFind::UnionFind(int size) {
    this->size = size;
    this->les = new Les *[size];
    make_set(size);
}

/**
 * Inicializa todos os Les, fazendo com que cada um receba o seu valor e aponte para si mesmo como Head
 * @param size quantidade de Les que tem que ser inicializados
 */
void UnionFind::make_set(int size) {
    for (int i = 0; i < size; i++) {
        this->les[i] = new Les(i);
        this->les[i]->lesMain = this->les[i];
        this->les[i]->lesNext = NULL;
    }
}

void UnionFind::union_set_simples(int a, int b) {
    Les *auxHead = this->les[a]->lesMain;
    Les *auxA = this->les[a]->lesMain;
    while (auxA != NULL) {
        auxA->lesMain = this->les[b]->lesMain;
        auxA = auxA->lesNext;
    }
    Les *auxB = this->les[b];
    while (auxB != NULL) {
        if (auxB->lesNext == NULL) {
            auxB->lesNext = auxHead;
            printUnions();
            return;
        }
        auxB = auxB->lesNext;
    }
}

void UnionFind::union_set_ponderado(int a, int b) {

}

void UnionFind::union_set_floresta(int a, int b) {
    Les *x = find_set_arvore(a);
    Les *y = find_set_arvore(b);

    if (x == y) return;

    x->lesMain = y;
    y->tamConjunto += x->tamConjunto;
}

Les* UnionFind::find_set_arvore(int no) {
    Les *representante = this->les[no]->lesMain;
    while (representante != representante->lesMain) {
        representante = representante->lesMain;
    }
    return representante;
};

Les* UnionFind::find_set_arvore_ponderado(int no) {
    Les *representante = this->les[no]->lesMain;
    while (representante != representante->lesMain) {
        representante = representante->lesMain;
    }
    this->les[no]->lesMain = representante;
    return representante;
};

void UnionFind::union_set_floresta_ponderada(int a, int b) {
    Les *x = find_set_arvore_ponderado(a);
    Les *y = find_set_arvore_ponderado(b);

    if (x == y) return;
    if (x->tamConjunto > y->tamConjunto) {
        y->lesMain = x;
        x->tamConjunto += y->tamConjunto;
    } else {
        x->lesMain = y;
        y->tamConjunto += x->tamConjunto;
    }
    return;
}

void UnionFind::find_set(int no) {
}

void UnionFind::printUnions() {
    for (int i = 0; i < this->size; i++) {
        cout << this->les[i]->lesMain->valor << " ";
    }
    cout << "\n" << endl;
    /*
        // acredito que o fin_set_arvore serve para os dois casos
        // coloquei 10 so para teste , para conseguir ver o arquivo final
        for (int i = 0; i < 10; i++) {
            Les* representante = find_set_arvore(i);
            cout << representante->valor << " ";
        }
     */
}

UnionFind::UnionFind(const UnionFind& orig) {
}

UnionFind::~UnionFind() {
}

