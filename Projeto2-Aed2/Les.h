#ifndef LES_H
#define	LES_H

#include "Base.h"

using namespace std;

class Les : public Base {
    public:
        Les(int value);
        Les *lesMain;
        Les *lesNext;
};

#endif	/* LES_H */