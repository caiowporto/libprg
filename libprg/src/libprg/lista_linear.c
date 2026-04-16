//
// Created by aluno on 02/04/2026.
//
#include <libprg/libprg.h>
#include <stdlib.h>

#define CAPACIDADE_INICIAL 10

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

// lista_linear_t* criar_lista_linear(int ordenada) {
//     lista_linear_t* lista = malloc(sizeof(lista_linear_t));
//     lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
//     lista->tamanho = 0;
//     lista->capacidade = CAPACIDADE_INICIAL;
//     lista->ordenada = ordenada;
//     return lista;
// }

void lista_adicionar(lista_linear_t* lista, int valor) {

    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->elementos = (int*) realloc(lista->elementos, sizeof(int)*lista->capacidade);
    }

    if (lista->ordenada && lista->tamanho > 0) {
        //insere ordenada

        // for (int i = lista->tamanho-1; i >= 0; --i) {
        //     if (valor < lista->elementos[i]) {
        //         lista->elementos[i+1] = lista->elementos[i];
        //     } else {
        //         lista->elementos[i+1] = valor;
        //         break;
        //     }
        // }

        int i = lista->tamanho-1;
        while (valor < lista->elementos[i]) {
            lista->elementos[i+1] = lista->elementos[i];
            i--;
        }

    } else {
        //insere não ordenada
        lista->elementos[lista->tamanho] = valor;
        lista->tamanho++;
    }
}

// int buscar{
//     if (lista.ordenada) {
//         indice = buscar_bin
//     } else {
//         inidice = buscar_linear
//     }
// }

int lista_busca(lista_linear_t* lista, int valor) {

    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1;
}

int lista_busca_bin(lista_linear_t* lista, int valor) {
    int inicio = 0;
    int fim = lista->tamanho-1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista->elementos[meio] == valor) {
            inicio = meio + 1;
        } else if (lista->elementos[meio] > valor) {
            fim = meio - 1;
        }
    }
}

bool removel(lista_linear_t* lista, int valor) {

    int indice = lista_busca(lista, valor);
    if (indice == -1) return false;

    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;
    return true;
}

void lista_destruir(lista_linear_t* lista) {
    free (lista->elementos);
    free(lista);
}

int lista_tamanho(lista_linear_t* lista) {
    return lista->tamanho;
}

int lista_first(lista_linear_t* lista) {
    return lista->elementos[0];
}

int lista_percorrer(lista_linear_t* lista, int i) {
    return lista->elementos[i];
}
