//
// Created by aluno on 17/03/2026.
//

#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct pilha {
  int* elementos;
  int topo;
  int capacidade;
} pilha_t;

pilha_t* criar_pilha(int capacidade) {
  pilha_t* pilha = malloc(sizeof(pilha_t));
  pilha->elementos = malloc(sizeof(int) * capacidade);
  pilha->topo = -1;
  pilha->capacidade = capacidade;
  return pilha;
}

int pilha_cheia(pilha_t *pilha) {
  return pilha->topo == pilha->capacidade - 1;
}

int pilha_vazia(pilha_t *pilha) {
  if (pilha->topo < 0) return 1;
  return 0;
}

void pilha_destruir(pilha_t* pilha) {
  free(pilha->elementos);
  free(pilha);
}

int empilhar(pilha_t* pilha, int valor) {

  if (pilha_cheia(pilha) == 1) {
    pilha->capacidade *= 2;
    pilha->elementos = realloc(pilha->elementos,pilha->capacidade * sizeof(int));

    if (pilha->elementos == NULL)
      return -1;
  }

  pilha->topo++;
  pilha->elementos[pilha->topo] = valor;

  return 0;
}

int desempilhar(pilha_t *pilha) {
  if (pilha_vazia(pilha))
    return -1;

  int valor = pilha->elementos[pilha->topo];
  pilha->topo--;
  return valor;
}

int topo_pilha(pilha_t *pilha) {
  return pilha->elementos[pilha->topo];
}

int tamanho_pilha(pilha_t *pilha) {
  return pilha->topo+1;
}
