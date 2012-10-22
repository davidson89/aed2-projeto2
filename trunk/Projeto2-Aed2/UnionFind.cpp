#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include "UnionFind.h"
#include "Les.h"

using namespace std;

/*
 * @param
 * @return
 */
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

/*
 * @param
 * @return
 */
void UnionFind::union_set_simples(int a, int b) {
    Les *auxA = this->les[a]->lesMain;
    Les *auxB = this->les[b]->lesMain;
    Les *auxMainA = this->les[a]->lesMain;
    Les *auxMainB = this->les[b]->lesMain;
    auxMainB->height = auxMainA->height + auxMainB->height;
    bool alterado = false;

    while (auxA != NULL) {
        auxA->lesMain = auxMainB;
        auxA = auxA->lesNext;
        if (auxB->lesNext == NULL) {
            auxB->lesNext = auxMainA;
            alterado = true;
        }
        if (!alterado) {
            auxB = auxB->lesNext;
        }
    }
}

/*
 * @param
 * @return
 */
void UnionFind::union_set_ponderado(int a, int b) {
    if (this->les[a]->lesMain->height > this->les[b]->lesMain->height) {
        union_set_simples(b, a);
    } else {
        union_set_simples(a, b);
    }
}

/*
 * @param
 * @return
 */
void UnionFind::union_set_floresta(int a, int b) {
    Les *x = find_set_arvore(a);
    Les *y = find_set_arvore(b);

    if (x == y) return;

    x->lesMain = y;
    y->height += x->height;
}

/*
 * @param
 * @return
 */
Les* UnionFind::find_set_arvore(int no) {
    Les *representante = this->les[no]->lesMain;
    while (representante != representante->lesMain) {
        representante = representante->lesMain;
    }
    return representante;
};

/*
 * @param
 * @return
 */
Les* UnionFind::find_set_arvore_ponderado(int no) {
    Les *representante = this->les[no]->lesMain;
    while (representante != representante->lesMain) {
        representante = representante->lesMain;
    }
    this->les[no]->lesMain = representante;
    return representante;
};

/*
 * @param
 * @return
 */
void UnionFind::union_set_floresta_ponderada(int a, int b) {
    Les *x = find_set_arvore_ponderado(a);
    Les *y = find_set_arvore_ponderado(b);

    if (x == y) return;
    if (x->height > y->height) {
        y->lesMain = x;
        x->height += y->height;
    } else {
        x->lesMain = y;
        y->height += x->height;
    }
    return;
}

/*
 * @param
 * @return
 */
void UnionFind::find_set(int no) {
}

/*
 * @param
 * @return
 */
void UnionFind::printUnions() {
    for (int i = 0; i < this->size; i++) {
        cout << this->les[i]->lesMain->valor << " ";
    }
    /*
    acredito que o fin_set_arvore serve para os dois casos
    coloquei 10 so para teste , para conseguir ver o arquivo final
    for (int i = 0; i < 10; i++) {
        Les* representante = find_set_arvore(i);
        cout << representante->valor << " ";
    }
     */
}

/*
 * @param
 * @return
 */
string UnionFind::getUnionsState() {
    stringstream ss;
    for (int i = 0; i < this->size; i++) {
        ss << this->les[i]->lesMain->valor << " ";
    }
    return ss.str();
}

/*
 * @param
 * @return
 */
UnionFind::UnionFind(const UnionFind &orig) {
}

/*
 * @param
 * @return
 */
UnionFind::~UnionFind() {
    delete les;
}