#include <iostream>
#include <string>
#include <sstream>
#include "UnionFind.h"
#include "Base.h"
#include "Les.h"
#include "Elemento_Floresta.h"

using namespace std;

/**
 * UnionFind - Constructor. Cria o vetor para objetos da classe Les ou Elemento Floresta.
 * @param size, o tamanho do vetor a ser criado.
 * @param floresta, bool que faz distinção entre objetos a serem criados, podendo ser Les ou Elemento Floresta.
 **/
UnionFind::UnionFind(int size, bool floresta) {
    this->size = size;
    this->operPointer = 0;
    this->isFloresta = floresta;
    if (floresta) {
        this->floresta = new Elemento_Floresta *[size];
        make_set_floresta(size);
    } else {
        this->les = new Les *[size];
        make_set(size);
    }
}

/**
 * make_set_floresta - Inicializa todos as instâncias da classe Elemento_Floresta.
 * @param size, a quantidade de instâncias da classe Elemento_Floresta que serão criadas.
 **/
void UnionFind::make_set_floresta(int size) {
    for (int i = 0; i < size; i++) {
        this->floresta[i] = new Elemento_Floresta(i);
        this->floresta[i]->pai = this->floresta[i];
    }
}

/**
 * make_set - Inicializa todos as instâncias da classe Les, fazendo com que cada uma receba o seu valor e aponte para si mesmo como Head.
 * @param size, a quantidade de instâncias da classe Les que serão criadas.
 **/
void UnionFind::make_set(int size) {
    for (int i = 0; i < size; i++) {
        this->les[i] = new Les(i);
        this->les[i]->lesMain = this->les[i];
        this->les[i]->lesNext = NULL;
    }
}

/**
 * find_set - Retorna o ponteiro para o Head do conjunto.
 * @param no, inteiro que representa o valor de um conjunto.
 **/
Les* UnionFind::find_set(int no) {
    return this->les[no]->lesMain;
}

/**
 * union_set_simples - Une o conjunto que contém o elemento a no conjunto que contém o elemento b.
 * @param a, elemento do conjunto a ser unido.
 * @param b, elemento do conjunto a ser unido.
 **/
void UnionFind::union_set_simples(int a, int b) {
    Les *auxA = find_set(a);
    Les *auxB = find_set(b);
    if (auxA == auxB) return;
    Les *auxMainA = auxA;
    Les *auxMainB = auxB;
    auxMainB->height += auxMainA->height;
    bool alterado = false;
    while (auxA != NULL) {
        auxA->lesMain = auxMainB;
        auxA = auxA->lesNext;
        this->operPointer++;
    }
    while (!alterado) {
        if (auxB->lesNext == NULL) {
            auxB->lesNext = auxMainA;
            this->operPointer++;
            alterado = true;
        }
        auxB = auxB->lesNext;
    }
}

/**
 * union_set_ponderado - Une o menor conjunto no maior conjunto.
 * @param a, elemento do conjunto a ser unido.
 * @param b, elemento do conjunto a ser unido.
 **/
void UnionFind::union_set_ponderado(int a, int b) {
    if (this->les[a]->lesMain->height > this->les[b]->lesMain->height) union_set_simples(b, a);
    else union_set_simples(a, b);
}

/**
 * union_set_floresta - 
 * @param
 **/
void UnionFind::union_set_floresta(int a, int b) {
    Elemento_Floresta *x = find_set_arvore(a);
    Elemento_Floresta *y = find_set_arvore(b);
    if (x == y) return;
    x->pai = y;
    this->operPointer++;
    y->height += x->height;
}

/**
 * find_set_arvore - 
 * @param
 * @return
 **/
Elemento_Floresta* UnionFind::find_set_arvore(int no) {
    Elemento_Floresta *representante = this->floresta[no]->pai;
    while (representante != representante->pai) {
        representante = representante->pai;
        this->operPointer++;
    }
    return representante;
}

/**
 * find_set_arvore_ponderado - 
 * @param
 * @return
 **/
Elemento_Floresta* UnionFind::find_set_arvore_ponderado(int no) {
    Elemento_Floresta *representante = this->floresta[no]->pai;
    while (representante != representante->pai) {
        representante = representante->pai;
        this->operPointer++;
    }
    this->floresta[no]->pai = representante;
    this->operPointer++;
    return representante;
}

/**
 * union_set_floresta_ponderada - 
 * @param
 **/
void UnionFind::union_set_floresta_ponderada(int a, int b) {
    Elemento_Floresta *x = find_set_arvore_ponderado(a);
    Elemento_Floresta *y = find_set_arvore_ponderado(b);
    if (x == y) return;
    if (x->height > y->height) {
        y->pai = x;
        this->operPointer++;
        x->height += y->height;
    } else {
        x->pai = y;
        y->height += x->height;
        this->operPointer++;
    }
    return;
}

/**
 * find_set_arvore_imprecao - 
 * @param
 * @return
 **/
int UnionFind::find_set_arvore_imprecao(int no) {
    Elemento_Floresta *representante = this->floresta[no];
    while (representante != representante->pai) {
        representante = representante->pai;
    }
    return representante->value;
}

/**
 * getUnionsState - Concatena numa string o valor do head de todos os elementos em um determinado estado.
 * @return retorna a string.
 **/
string UnionFind::get_unions_state_floresta() {
    stringstream ss;
    for (int i = 0; i < this->size; i++) {
        ss << this->find_set_arvore_imprecao(i) << " ";
    }
    return ss.str();
}

/**
 * getUnionsState - Concatena numa string o valor do head de todos os elementos em um determinado estado.
 * @return retorna a string.
 **/
string UnionFind::get_unions_state() {
    stringstream ss;
    for (int i = 0; i < this->size; i++) {
        ss << this->les[i]->lesMain->value << " ";
    }
    return ss.str();
}

/**
 * ~UnionFind - Destructor. Desaloca o ponteiro para o vetor les ou floresta criado no construtor e todos os ponteiros contidos nestes vetores.
 **/
UnionFind::~UnionFind() {
    if (isFloresta) {
        for (int i = 0; i < this->size; i++) {
            delete this->floresta[i];
        }
        delete floresta;
    } else {
        for (int i = 0; i < this->size; i++) {
            delete this->les[i];
        }
        delete les;
    }
}