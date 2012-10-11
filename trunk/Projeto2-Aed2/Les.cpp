/* 
 * File:   Les.cpp
 * Author: davidson
 * 
 * Created on 10 de Outubro de 2012, 21:43
 */

#include "Les.h"

Les::Les(string valor) {
    this->valor = valor;
    this->lesMain= NULL;
    this->lesNext= NULL;
}

Les::Les(const Les& orig) {
}

Les::~Les() {
}

