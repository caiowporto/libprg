//
// Created by aluno on 06/03/24.

#include <stdio.h>
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 10


typedef struct lista{
    int *vetor;
    int capacidade;
    int tamanho;
    bool ordenada;
} lista_t;
//elementos que compoe uma lista


lista_t* criar(){
    lista_t *lista = (lista_t*)malloc(sizeof (lista_t));//malloc retorna void, por isso o (lista_t*)
    lista->vetor = (int*) malloc(sizeof (int)*TAMANHO);
    lista->tamanho = 0;
    lista->ordenada = false;
};


void inserir(lista_t *lista, int elemento){
    if (lista->tamanho >= lista->capacidade) {
        //  Esta parte verifica se o tamanho atual da lista excede a capacidade atual. Se sim, significa que não há espaço suficiente para inserir um novo elemento. Nesse caso, dobramos a capacidade da lista realocando o vetor interno para acomodar mais elementos.
        lista->capacidade *= 2;//dobra a capacidade conforme acaba espaço
        lista->vetor = (int *) realloc(lista->vetor, lista->capacidade * sizeof(int));
    }

    int posicao = lista->tamanho; //Esta variável será usada para encontrar a posição correta para inserir o novo elemento.
    while (posicao > 0 && lista->vetor[posicao - 1] > elemento) {
        // enquanto a posição é maior que zero e o elemento na posição anterior é maior que o elemento a ser inserido,Isso é feito para encontrar a posição correta para o novo elemento
        lista->vetor[posicao] = lista->vetor[posicao - 1];
        posicao--;
    }

    // Inserir o novo elemento na posição correta e disponivel
    lista->vetor[posicao] = elemento;
    //tamanho++ fala que colocamos um elemento nesta lista
    lista->tamanho++;
}

void busca(lista_t *lista);

void excluir();
