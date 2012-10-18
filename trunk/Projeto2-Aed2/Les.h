#ifndef LES_H
#define	LES_H
#include <string>

using namespace std;

class Les {
public:
    Les(int valor);
    Les(const Les& orig);
    virtual ~Les();
    int valor;
    int height;
    Les *lesMain;
    Les *lesNext;
private:
};

#endif	/* LES_H */

