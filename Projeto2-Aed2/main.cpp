#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "UnionFind.h"

using namespace std;
using std::string;

bool print(int count);

int main(int argc, char** argv) {

    if (argc == 0) {
        cout << "Falta de argumentos!" << endl;
    }

    char* fileName = "uf1.txt";
    FILE *arq = fopen(fileName, "r");
    int a, b, size, count = 0;
    fscanf(arq, "%d", &size);
    cout << "** size: " << size << " **" << endl;
    UnionFind *unionFind = new UnionFind(size);
    while (!feof(arq)) {
        fscanf(arq, "%d", &a);
        fscanf(arq, "%d", &b);
        unionFind->union_set_simples(a, b);
        count++;
        if (print(count)) {
            unionFind->printUnions(count);
        }
    }
    count = 0;
    fclose(arq);
    return 0;
}

bool print(int count) {
    if (count <= 20 || count % 1000 == 0) {
        return true;
    }
    return false;
}