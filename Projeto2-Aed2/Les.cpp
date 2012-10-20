#include "Les.h"

/*
 * @param
 * @return
 */
Les::Les(int valor) {
    this->valor = valor;
    this->height = 1;
    this->lesMain = NULL;
    this->lesNext = NULL;
}

/*
 * @param
 * @return
 */
Les::Les(const Les &orig) {
}

/*
 * @param
 * @return
 */
Les::~Les() {
}