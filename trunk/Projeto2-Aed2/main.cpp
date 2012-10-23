#include <iostream>
#include <fstream>
#include <string>
#include "UnionFind.h"

using namespace std;

void createFile(const char *fileIn, string fileOut, char opt,bool floresta);
void printMenu();

int main() {
    bool loop = 1;
    const char *uf1 = "uf1.txt";
    const char *uf2 = "uf2.txt";
    char opt;
    while (loop) {
        printMenu();
        cin >> opt;
        switch (opt) {
            case '0': loop = 0;
                break;
			case '1': createFile(uf1, "uf1_union_find.txt", opt,false);
                break;
            case '2': createFile(uf1, "uf1_union_find_ponderado.txt", opt,false);
                break;
            case '3': createFile(uf1, "uf1_union_find_floresta.txt", opt,true);
                break;
            case '4': createFile(uf1, "uf1_union_find_floresta_ponderado.txt", opt,true);
                break;
            case '5': createFile(uf2, "uf2_union_find.txt", opt,false);
                break;
            case '6': createFile(uf2, "uf2_union_find_ponderado.txt", opt,false);
                break;
            case '7': createFile(uf2, "uf2_union_find_floresta.txt", opt,true);
                break;
            case '8': createFile(uf2, "uf2_union_find_floresta_ponderado.txt", opt,true);
                break;
            default: cout << "Digite uma opcao valida!" << endl;
        }
    }
    return 0;
}

void createFile(const char *fileIn, string fileOut, char opt ,bool floresta) {
    FILE *arq = fopen(fileIn, "r");
    int a, b, size, count = 0;
    string state;
    fscanf(arq, "%d", &size);
    UnionFind *unionFind = new UnionFind(size,floresta);
    ofstream output(fileOut.data());
    if (!output.is_open()) {
        cout << "Nao foi possivel abrir o arquivo para gravacao dos dados." << endl;
        return;
    }
    cout << "Aguarde: Gerando arquivo de saida..." << endl;
    while (!feof(arq)) {
        fscanf(arq, "%d", &a);
        fscanf(arq, "%d", &b);
        if (opt == '1' || opt == '5') unionFind->union_set_simples(a, b);
        else if (opt == '2' || opt == '6') unionFind->union_set_ponderado(a, b);
        else if (opt == '3' || opt == '7') unionFind->union_set_floresta(a, b);
        else if (opt == '4' || opt == '8') unionFind->union_set_floresta_ponderada(a, b);
        count++;
        if (count <= 20 || count % 1000 == 0) {
			if(floresta)
			{
			state = unionFind->getUnionsState_Floresta();
			} else {
			state = unionFind->getUnionsState();
			}
			output << state << endl;
        }
    }
    output.close();
    fclose(arq);
    cout << "Arquivo " << fileOut << " gerado com sucesso!!!\n" << endl;
    delete unionFind;
}

void printMenu() {
    cout << "************************MENU************************\n"
            "Digite: \n"
            "0 - Para sair\n"
            "1 - Para gerar o arquivo com os estados do union find do arquivo uf1\n"
            "2 - Para gerar o arquivo com os estados do union find ponderado do arquivo uf1\n"
            "3 - Para gerar o arquivo com os estados do union find floresta do arquivo uf1\n"
            "4 - Para gerar o arquivo com os estados do union find floresta ponderado do arquivo uf1\n"
            "5 - Para gerar o arquivo com os estados do union find do arquivo uf2\n"
            "6 - Para gerar o arquivo com os estados do union find ponderado do arquivo uf2\n"
            "7 - Para gerar o arquivo com os estados do union find floresta do arquivo uf2\n"
            "8 - Para gerar o arquivo com os estados do union find floresta ponderado do arquivo uf2\n"
            << endl;
}