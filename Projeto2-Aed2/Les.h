/* 
 * File:   Les.h
 * Author: davidson
 *
 * Created on 10 de Outubro de 2012, 21:43
 */

#ifndef LES_H
#define	LES_H
#include <string>

using namespace std;

class Les {
public:
    Les(string valor);
    Les(const Les& orig);
    virtual ~Les();
    string valor;
    Les *lesMain;
    Les *lesNext;
private:

};

#endif	/* LES_H */

