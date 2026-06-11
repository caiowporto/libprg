#include "libprg/libprg.h"
#include <stdlib.h>

#define max(a, b) (a > b ? a : b);

typedef struct noavl {
    int dado;
    noavl_t *esquerda;
    noavl_t *direita;
    int altura;
} noavl_t;

noavl_t *criar_noavl(int dado) {
    noavl_t *no = malloc(sizeof(noavl_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;

    return no;
}

int altura_avl(noavl_t *raiz) {
    if (raiz == NULL) return 0;

    return raiz->altura;
}

int fator_balanceamento(noavl_t *raiz) {
    if (raiz == NULL) return 0;

    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita);
}

noavl_t *adicionar_noavl(noavl_t *raiz, int dado) {
    if (raiz == NULL) {
        return criar_noavl(dado);
    }

    if (raiz->dado < dado) {
        raiz->direita = adicionar_noavl(raiz->direita, dado);
    }

    if (raiz->dado > dado) {
        raiz->esquerda = adicionar_noavl(raiz->esquerda, dado);
    }


    return raiz;
}

noavl_t *rotacao_direita(noavl_t *V) {
    noavl_t *U = V->esquerda;
    noavl_t *T2 = U->direita;

    U->direita = V;
    V->esquerda = T2;

    V->altura = max(altura_avl(V->esquerda), altura_avl(V->direita)) +1;
    U->altura = max(altura_avl(U->esquerda), altura_avl(U->direita)) +1;

    return U;
}

noavl_t* rotacao_dupla_direita(noavl_t *v) {
    // rotação simples à esquerda no filho esquerdo de v
    v->esquerda = rotacao_esquerda(v->esquerda);
    // rotação simples à direita em v
    return rotacao_direita(v);
}


//rotacao_dupla_direita
noavl_t *rotacao_esquerda(noavl_t *V) {
    noavl_t *U = V->direita;
    noavl_t *T2 = U->esquerda;

    U->esquerda = V;
    V->direita = T2;

    V->altura = max(altura_avl(V->esquerda), altura_avl(V->direita)) +1;
    U->altura = max(altura_avl(U->esquerda), altura_avl(U->direita)) +1;

    return U;
}

noavl_t* rotacao_dupla_esquerda(noavl_t *v) {
    v->direita = rotacao_direita(v->direita);
    return rotacao_esquerda(v);
}

noavl_t* balancear(noavl_t* v) {
    int fb = fator_balanceamento(v);
    if (fb > 1) {
        if (fator_balanceamento(v->esquerda) > 0) {
            return rotacao_direita(v);
        }
        return rotacao_dupla_direita(v);
    }

    if (fb < -1) {
        if (fator_balanceamento(v->direita) < 0) {
            return rotacao_esquerda(v);
        }
        return rotacao_dupla_esquerda(v);
    }
    return v;
}
noavl_t* remover_noavl(noavl_t* raiz, int dado) {
    if (raiz == NULL) return NULL;

    if(dado < raiz->dado) {
        raiz-> esquerda = remover_noavl(raiz->esquerda, dado);
    }else if (dado > raiz->dado) {
        raiz->direita = remover_noavl(raiz->direita, dado);
    }else {
        if (raiz->direita == NULL || raiz->esquerda == NULL) {// um ou zero filhos
            noavl_t* temp = raiz->esquerda != NULL? raiz->esquerda : raiz->direita;
            if (temp == NULL) { //zero filhos
                free(raiz);
                return NULL;
            }
            free(raiz);//1 filho
            return temp;
        }else { //2 filhos
            //encontra o menor valor da sub arvore da direita
            noavl_t* temp = raiz->direita;
            while (temp && temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            raiz->dado = temp->dado;
            raiz->direita = remover_noavl(raiz->direita, temp->dado);
        }
    }
    if (raiz != NULL) {
        raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
        raiz=balancear(raiz);
    }
    return raiz;
}
