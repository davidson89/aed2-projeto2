/* 
 * File:   UnionFind.cpp
 * Author: davidson
 * 
 * Created on 10 de Outubro de 2012, 21:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "UnionFind.h"
#include "Les.h"

using namespace std;

UnionFind::UnionFind(int size) {
    this->size=size;
    make_set(size);
}

/**
 * Inicializa todos os Les, fazendo com que cada um receba o seu valor e aponte para si mesmo como Head
 * 
 * @param size quantidade de Les que tem que ser inicializados
 */
void UnionFind::make_set(int size) {
     for(int i=0;i<size;i++){
        this->les[i] = new Les(i);
        this->les[i]->lesMain = this->les[1];
        this->les[i]->lesNext = NULL;
     }
}

void UnionFind::union_set_simples(int a, int b) {
    while(this->les[a] != NULL){
        this->les[a]->lesMain = this->les[b];
        this->les[a] = this->les[a]->lesNext;
    }
    printUnions();
}

void UnionFind::union_set_ponderado(int a, int b) {
    
}

void UnionFind::union_set_floresta(int a, int b) {
    
}

void UnionFind::union_set_floresta_ponderada(int a, int b) {
    
}

void UnionFind::find_set(int no) {
    
}

void UnionFind::printUnions() {
    for(int i = 0 ; i < 4 ; i++){
        cout << this->les[i]->valor << " " << endl;
    }
}

UnionFind::UnionFind(const UnionFind& orig) {
}

UnionFind::~UnionFind() {
}
