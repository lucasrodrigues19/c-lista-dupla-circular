/*
 * lista_circular_duplamente_encadeada.h
 *
 *  Created on: 18 de mai de 2020
 *      Author: lucas.rodrigues
 */

#ifndef LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H_
#define LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H_



#endif /* LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H_ */

typedef struct Caixinha{
	int elemento;
	struct Caixinha *ant;
	struct Caixinha *prox;
}Caixinha;

typedef struct ListaCircularDupla{
	Caixinha *inicio;
}ListaCircularDupla;

/**
 * Cria a lista, aponta para null
 */
void create(ListaCircularDupla *listaDuplaCircular);
/**
 * Verifica se a lista está vazia: 1- verdadeiro, 0- falso
 */
int isEmpty(ListaCircularDupla listaDuplaCircular);
/**
 * Insere um elemento na lista
 */
void inserir(ListaCircularDupla *listaDuplaCircular, int elemento);
/**
 * Imprime a partir do incio na ordem correta
 */
void exibirNaOrdem(ListaCircularDupla *listaDuplaCircular);
/**
 * Imprime a partir do incio na ordem iversa
 */
void exibriNaOrdemInversa(ListaCircularDupla *listaDuplaCircular);
/**
 * Remove um elemento da lista a partir do elemento
 */
void removerElemento(ListaCircularDupla *listaDuplaCircular, int elemento);
/**
 * Remove um elemento da lista a partir do index
 */
void removerElementoIndex(ListaCircularDupla *listaDuplaCircular, int index);
