/* 
 * File:   main.cpp
 * Author: davidson
 *
 * Created on 10 de Outubro de 2012, 21:28
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "UnionFind.h"

using namespace std;
using std::string;

/*
 * 
 */
int main(int argc, char** argv) {

    if(argc == 0){
        cout << "Falta de argumentos!" << endl;
    }
    
    char* fileName = argv[1];
    FILE *arq = fopen(fileName,"r");
    int* a;
    int* b;
    int* size;
    fscanf(arq,"%d",size);
    UnionFind unionFind = new UnionFind(size);
    while(!feof(arq)){
        fscanf(arq,"%d","%d",a,b); //Le  a linha e grava e em str
        unionFind->union_set(a,b);
    }
    
    return 0;
}
