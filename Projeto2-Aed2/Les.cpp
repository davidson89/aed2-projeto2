#include "Les.h"

Les::Les(int valor) {
    this->valor = valor;
    this->lesMain = NULL;
    this->lesNext = NULL;
}

Les::Les(const Les &orig) {
}

Les::~Les() {
}

