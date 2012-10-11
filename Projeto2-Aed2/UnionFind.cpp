/* 
 * File:   UnionFind.cpp
 * Author: davidson
 * 
 * Created on 10 de Outubro de 2012, 21:41
 */
#include <stdio.h>
#include <stdlib.h>
#include "UnionFind.h"

using namespace std;

UnionFind::UnionFind(int size) {
    this->size=size;
    make_set(int size);
}

void UnionFind::make_set(int size){
     for(int i=0;i<size;i++){
        this->les[i] = NULL;
     }
}

UnionFind::UnionFind(const UnionFind& orig) {
}

UnionFind::~UnionFind() {
}

