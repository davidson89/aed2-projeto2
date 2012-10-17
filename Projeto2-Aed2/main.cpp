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

    if (argc == 0) {
        cout << "Falta de argumentos!" << endl;
    }

    char* fileName = "uf1.txt";
    FILE *arq = fopen(fileName, "r");
    int a;
    int b;
    int size;
    fscanf(arq, "%d", &size);
    cout << "** size: " << size << " **" << endl;
    UnionFind *unionFind = new UnionFind(size);
    int count = 0;
    while (!feof(arq)) {
        fscanf(arq, "%d", &a);
        fscanf(arq, "%d", &b);
        unionFind->union_set_simples(a, b);
        //unionFind->union_set_floresta_ponderada(a, b);
        count++;
        if (count <= 20 || count % 1000 == 0) {
            unionFind->printUnions();
            cout << "Estado número : " << count << endl;
        }
    }
    fclose(arq);
    return 0;
}