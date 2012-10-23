#ifndef LES_H
#define	LES_H
#include <string>
#include "Base.h"
using namespace std;

class Les: public Base {
    public:
        Les(int value);
       
        Les *lesMain ;
        Les *lesNext;
    private:
};

#endif	/* LES_H */