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
    int indice = valor;
    bool resultado;
    if (indice <= -1) {
        resultado = false;
    }

    if (indice > -1) {
        if (lista->ordenada) {
            //remove ordenada
            while (indice < lista->tamanho-1) {
                lista->elementos[indice] = lista->elementos[indice + 1];
                indice++;
            }
        } else {
            lista->elementos[indice] = lista->elementos[lista->tamanho];
        }
        lista->tamanho--;
        resultado = true;
    }
    return resultado;
}

void lista_destruir(lista_linear_t* lista) {
    free (lista->elementos);
    free(lista);
}

int lista_tamanho(lista_linear_t* lista) {
    return lista->tamanho;
}
