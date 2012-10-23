#ifndef UNIONFIND_H
#define	UNIONFIND_H
#include "Les.h"
#include "Elemento_Floresta.h"
class UnionFind {
    public:
        UnionFind(int size, bool floresta);
        virtual ~UnionFind();
        Les **les;
		Elemento_Floresta **Floresta;
        int size;
		bool isfloresta;
        Elemento_Floresta* find_set_arvore(int no);
        Elemento_Floresta* find_set_arvore_ponderado(int no);
        void union_set_simples(int a, int b);
        void union_set_ponderado(int a, int b);
        void union_set_floresta(int a, int b);
        void union_set_floresta_ponderada(int a, int b);
        void find_set(int no);
        string getUnionsState();
		string getUnionsState_Floresta();
    private:
        void make_set(int size);
		void make_setFloresta(int size);
};

#endif	/* UNIONFIND_H */