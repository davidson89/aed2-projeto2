#ifndef ELEMENTO_FLORESTA_H
#define	ELEMENTO_FLORESTA_H

#include "Base.h"

using namespace std;

class Elemento_Floresta : public Base {
    public:
        Elemento_Floresta *pai;
        Elemento_Floresta(int value);
    };

#endif	/* ELEMENTO_FLORESTA_H */