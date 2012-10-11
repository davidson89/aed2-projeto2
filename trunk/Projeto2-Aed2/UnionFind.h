/* 
 * File:   UnionFind.h
 * Author: davidson
 *
 * Created on 10 de Outubro de 2012, 21:41
 */

#ifndef UNIONFIND_H
#define	UNIONFIND_H

class UnionFind {
public:
    UnionFind(int size);
    UnionFind(const UnionFind& orig);
    virtual ~UnionFind();
    Les** les;
    int size;
    void union_set_simples(int a, int b);
    void union_set_ponderado(int a, int b);
    void union_set_floresta(int a, int b);
    void union_set_floresta_ponderada(int a, int b);
    void find_set(int no);
private:
    void make_set(int size);

};

#endif	/* UNIONFIND_H */

