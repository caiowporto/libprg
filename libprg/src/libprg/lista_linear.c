//
// Created by aluno on 02/04/2026.
//
#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    int ordenada;
} lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, int ordenada) {
    lista_linear_t* lista_linear = malloc(sizeof(lista_linear_t));
    lista_linear->elementos = malloc(sizeof(int) * capacidade);
    lista_linear->tamanho = 0;
    lista_linear->capacidade = capacidade;
    lista_linear->ordenada = ordenada;

    return lista_linear;
}

