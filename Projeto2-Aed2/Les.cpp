#include "Les.h"

/*
 * Les - Constructor. Cria uma instancia da classe Les (Lista Encadeada Simples).
 * @param value, o valor inteiro correspondente ao indice do vetor les.
 */
Les::Les(int value) {
    this->value = value;
    this->height = 1;
    this->lesMain = NULL;
    this->lesNext = NULL;
}