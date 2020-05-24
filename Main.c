/*
 * Main.c
 *
 *  Created on: 18 de mai de 2020
 *      Author: lucas.rodrigues
 */

#include "lista_circular_duplamente_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	ListaCircularDupla listaCircularDupla;
	create(&listaCircularDupla);
	inserir(&listaCircularDupla, 9);
	inserir(&listaCircularDupla, 45);
	inserir(&listaCircularDupla, 98);
	inserir(&listaCircularDupla, 10);

	printf("\n--------------------\n");
	exibirNaOrdem(&listaCircularDupla);
	printf("\n--------------------\n");
	exibriNaOrdemInversa(&listaCircularDupla);

	printf("\nDepois de remover um elemento\n");

	printf("\n--------------------\n");
	removerElementoIndex(&listaCircularDupla, 3);
	exibirNaOrdem(&listaCircularDupla);
	printf("\n--------------------\n");
	exibriNaOrdemInversa(&listaCircularDupla);
	return 0;
}

