/*
 * lista_circular_duplamente_encadeada.c
 *
 *  Created on: 18 de mai de 2020
 *      Author: lucas.rodrigues
 */

#include "lista_circular_duplamente_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

void create(ListaCircularDupla *listaDuplaCircular) {
	listaDuplaCircular->inicio = NULL;
}
int isEmpty(ListaCircularDupla listaDuplaCircular) {
	return (listaDuplaCircular.inicio == NULL);
}
void inserir(ListaCircularDupla *listaDuplaCircular, int elemento) {
	Caixinha *nova;
	nova = (Caixinha*) malloc(sizeof(Caixinha));
	nova->elemento = elemento;

	if (listaDuplaCircular->inicio == NULL) {
		nova->ant = nova;
		nova->prox = nova;
		listaDuplaCircular->inicio = nova;
	} else {
		Caixinha *aux;
		aux = listaDuplaCircular->inicio; //aponta para o inicio da lista
		while (aux->prox != listaDuplaCircular->inicio) //pecorre ate achar o ultimo elemento
			aux = aux->prox;

		nova->ant = aux; //aux agora sera o anterior
		nova->prox = listaDuplaCircular->inicio; //o proximo do ultimo elemento sera inicio
		aux->prox = nova; //o ultimo elemento agora sera nova
		listaDuplaCircular->inicio->ant = nova; //caso não esteja vazia o anterior do primeiro elemento, aponta para o ultimo
	}
}
void exibirNaOrdem(ListaCircularDupla *listaDuplaCircular) {
	Caixinha *aux;
	aux = listaDuplaCircular->inicio; //aponta para o inicio da lista
	do {
		printf("| %d | ", aux->elemento);
		aux = aux->prox;
	} while (aux != listaDuplaCircular->inicio);
}
void exibriNaOrdemInversa(ListaCircularDupla *listaDuplaCircular) {
	Caixinha *aux;
	aux = listaDuplaCircular->inicio; //aponta para o inicio da lista
	do {
		printf("| %d | ", aux->elemento);
		aux = aux->ant;
	} while (aux != listaDuplaCircular->inicio);
}

void removerElemento(ListaCircularDupla *listaDuplaCircular, int elemento) {
	Caixinha *nova;
	nova = (Caixinha*) malloc(sizeof(Caixinha));

	Caixinha *tmp;
	tmp = listaDuplaCircular->inicio; //aponta para o inicio da lista

	if (listaDuplaCircular->inicio != NULL) {
		if (tmp->elemento == elemento) { //caso o elemento seja o primeiro da lista
			nova = tmp->prox; //nova recebe o proximo de inicio
			nova->ant = tmp->ant; //o anteiro de nova, recebe o ultimo elemento
			nova->ant->prox = nova; //o proximo do ultimo elemento aponta para nova
			listaDuplaCircular->inicio = nova; //inicio recebe nova
		} else {	//esteja no meio
			while (tmp->prox != listaDuplaCircular->inicio) {
				if (tmp->elemento == elemento) {
					nova = tmp->prox; //nova recebe o proximo do elemento retirado
					nova->ant = tmp->ant; //anterior de nova recebe o anterior do elemento retirado
					tmp->ant->prox = nova; //o proximo do aterior do elemento retirado, recebe nova;
					break;
				}
				tmp = tmp->prox;
			}
			if (tmp == listaDuplaCircular->inicio) {
				if (tmp->elemento == elemento) { //caso seja o fim da lista
					nova = tmp->ant; //nova recebe o anterior do ultmio
					nova->prox = listaDuplaCircular->inicio; //o proximo de nova, recebe o anterior do incio
					listaDuplaCircular->inicio->ant = nova; //o anterior de incio aponta pra nova
				} else {
					return;
				}
			}
		}
	}
	tmp = NULL;
	free(tmp);
}
void removerElementoIndex(ListaCircularDupla *listaDuplaCircular, int index) {
	Caixinha *nova;
	nova = (Caixinha*) malloc(sizeof(Caixinha));

	Caixinha *tmp;
	tmp = listaDuplaCircular->inicio; //aponta para o inicio da lista
	if (listaDuplaCircular->inicio != NULL) {
		int i = 0;
		if (index == i) { //se o index for o primeiro elemento
			nova = tmp->prox; //nova recebe o proximo de inicio
			nova->ant = tmp->ant; //o anteiro de nova, recebe o ultimo elemento
			nova->ant->prox = nova; //o proximo do ultimo elemento aponta para nova
			listaDuplaCircular->inicio = nova; //inicio recebe nova
		} else {
			while (tmp->prox != listaDuplaCircular->inicio) { //se o index estiver no meio
				if (i == index) {
					nova = tmp->prox; //nova recebe o proximo do elemento retirado
					nova->ant = tmp->ant; //anterior de nova recebe o anterior do elemento retirado
					tmp->ant->prox = nova; //o proximo do aterior do elemento retirado, recebe nova;
					break;
				}
				tmp = tmp->prox;
				i++;
			}
		}
		if (tmp == listaDuplaCircular->inicio) {
			if (i == index) { //se o index for o ultimo
				nova = tmp->ant; //nova recebe o anterior do ultmio
				nova->prox = listaDuplaCircular->inicio; //o proximo de nova, recebe o anterior do incio
				listaDuplaCircular->inicio->ant = nova; //o anterior de incio aponta pra nova
			} else {
				return;
			}
		}
	}
	tmp = NULL;
	free(tmp);
}

