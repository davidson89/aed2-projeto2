#include <iostream>
#include <string>
#include <sstream>
#include "UnionFind.h"
#include "Base.h"
#include "Les.h"
#include "Elemento_Floresta.h"
using namespace std;

/*
 * UnionFind - Constructor. Cria o vetor para objetos da classe les.
 * @param size, o tamanho do vetor a ser criado.
 */
UnionFind::UnionFind(int size,bool floresta) {
    this->size = size;
	this->isfloresta = floresta;
	if(floresta)
	{
		this->Floresta = new Elemento_Floresta *[size];
	     make_setFloresta(size);
	}
	else{
		this->les = new Les *[size];
		make_set(size);
	}
    
	
}
void UnionFind::make_setFloresta(int size) {
    for (int i = 0; i < size; i++) {
		this->Floresta[i] = new Elemento_Floresta(i);
        this->Floresta[i]->pai = this->Floresta[i];
     
    }
}

/**
 * ::make_set - Inicializa todos as instancias da classe Les, fazendo com que cada um receba o seu valor e aponte para si mesmo como Head.
 * @param size, a quantidade de instancias da classe Les que serao criadas.
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
 */
void UnionFind::union_set_simples(int a, int b) {
    Les *auxA = this->les[a]->lesMain;
    Les *auxB = this->les[b]->lesMain;
    if (auxA == auxB) return;
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
 */
void UnionFind::union_set_floresta(int a, int b) {
    Elemento_Floresta *x = find_set_arvore(a);
    Elemento_Floresta *y = find_set_arvore(b);
    if (x == y) return;
	x->pai = y;
    y->height += x->height;
}

/*
 * @param
 * @return
 */
Elemento_Floresta* UnionFind::find_set_arvore(int no) {
	Elemento_Floresta *representante = this->Floresta[no]->pai;
    while (representante != representante->pai) {
        representante = representante->pai;
    }
    return representante;
};

/*
 * @param
 * @return
 */
Elemento_Floresta* UnionFind::find_set_arvore_ponderado(int no) {
	Elemento_Floresta *representante = this->Floresta[no]->pai;
    while (representante != representante->pai) {
        representante = representante->pai;
    }
    this->Floresta[no]->pai = representante;
    return representante;
};

/*
 * @param
 */
void UnionFind::union_set_floresta_ponderada(int a, int b) {
    Elemento_Floresta *x = find_set_arvore_ponderado(a);
    Elemento_Floresta *y = find_set_arvore_ponderado(b);
    if (x == y) return;
    if (x->height > y->height) {
        y->pai = x;
        x->height += y->height;
    } else {
        x->pai = y;
        y->height += x->height;
    }
    return;
}

/*
 * @param
 */
void UnionFind::find_set(int no) {
}
string UnionFind::getUnionsState_Floresta()
{
	stringstream ss;
    for (int i = 0; i < this->size; i++) {
        ss << this->Floresta[i]->pai->value << " ";
    }
    return ss.str();
}


/*
 * getUnionsState - Concatena numa string o valor do head de todos os elementos em um determinado estado.
 * @return retorna a string.
 */
string UnionFind::getUnionsState() {
    stringstream ss;
    for (int i = 0; i < this->size; i++) {
        ss << this->les[i]->lesMain->value << " ";
    }
    return ss.str();
}

/*
 * ~UnionFind - Destructor. Desaloca o ponteiro para o vetor les criado no construtor.
 */
UnionFind::~UnionFind() {
    ;
	if(isfloresta)
		{
			delete[] Floresta;
	} else 
	{
	 delete les;
	}
	}