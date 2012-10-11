/* 
 * File:   UnionFind.cpp
 * Author: davidson
 * 
 * Created on 10 de Outubro de 2012, 21:41
 */
#include <stdio.h>
#include <stdlib.h>
#include "UnionFind.h"
#include "Les.h"

using namespace std;

UnionFind::UnionFind(int size) {
    this->size=size;
    make_set(int size);
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

void UnionFind::union_set(int a, int b) {
    
}

void UnionFind::find_set(int no) {
    
}

UnionFind::UnionFind(const UnionFind& orig) {
}

UnionFind::~UnionFind() {
}

