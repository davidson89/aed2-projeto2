#include "Elemento_Floresta.h"

using namespace std;

/**
 * Elemento_Floresta - Constructor. Cria uma instancia da classe Elemento_Floresta.
 * @param value, o valor inteiro correspondente ao indice do vetor floresta.
**/
Elemento_Floresta::Elemento_Floresta(int value) {
    this->value = value;
    this->height = 1;
    this->pai = this;
}