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
    
    char* fileName = "entrada.txt";
    FILE *arq = fopen(fileName,"r");
    int a;
    int b;
    int size;
    fscanf(arq,"%d", &size);
    cout << "** " << size << " **" << endl;
    UnionFind *unionFind = new UnionFind(size);
    cout << "\n*TESTE \n" << endl;
    while(!feof(arq)){
        fscanf(arq,"%d", &a);
        fscanf(arq,"%d", &b);
        unionFind->union_set_simples(a , b);
    }
    
    return 0;
}

