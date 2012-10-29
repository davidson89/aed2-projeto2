#include <string>
#include "Elemento_Floresta.h"

using namespace std;

Elemento_Floresta::Elemento_Floresta(int value) {
    this->value = value;
    this->height = 1;
    this->pai = this;
}