#ifndef LES_H
#define	LES_H
#include <string>

using namespace std;

class Les {
    public:
        Les(int value);
        int value;
        int height;
        Les *lesMain;
        Les *lesNext;
    private:
};

#endif	/* LES_H */