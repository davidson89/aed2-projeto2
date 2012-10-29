#ifndef UNIONFIND_H
#define	UNIONFIND_H

#include "Les.h"
#include "Elemento_Floresta.h"

class UnionFind {
    public:
        int operPointer;
        UnionFind(int size, bool floresta);
        virtual ~UnionFind();
        void union_set_simples(int a, int b);
        void union_set_ponderado(int a, int b);
        void union_set_floresta(int a, int b);
        void union_set_floresta_ponderada(int a, int b);
        string get_unions_state();
        string get_unions_state_floresta();
    private:
        Les **les;
        Elemento_Floresta **floresta;
        int size;
        bool isFloresta;
        void make_set(int size);
        void make_set_floresta(int size);
        Les* find_set(int no);
        int find_set_arvore_imprecao(int no);
        Elemento_Floresta* find_set_arvore(int no);
        Elemento_Floresta* find_set_arvore_ponderado(int no);
};

#endif	/* UNIONFIND_H */