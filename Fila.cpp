#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int tamanho = 0;

Fila* iniciaFila()
{
	Fila* umaFila = new Fila;

	umaFila -> _primeiro = NULL;
	umaFila -> _ultimo = NULL;
	umaFila -> _quantidade = 0;

	return umaFila;
}

void destroiFila(Fila* umaFila)
{
	while(tamanho > 0)
	{
		dequeue(umaFila);
	}

	delete umaFila;
}

bool filaVazia(Fila* umaFila)
{
	if (tamanho == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool contem(Fila* umaFila, void* umDado)
{
	if (filaVazia(umaFila))
	{
		return false;
	}
	Elemento *auxiliar = umaFila -> _primeiro;
	for (int i = 0; i < umaFila -> _quantidade; i++)
	{
		if (umDado == auxiliar -> _dado)
		{
			return true;
		}
		auxiliar = auxiliar -> _proximo;
	}
	return false;
}

int posicao(Fila* umaFila, void* umDado)
{
	if (filaVazia(umaFila))
	{
		throw fila_vazia_exception();
	}
	int i = 1;
	Elemento *auxiliar = umaFila -> _primeiro;
	
	while(i < umaFila -> _quantidade +1)
	{
		if (auxiliar -> _dado == umDado)
		{
			return i;
		}
		else
		{
			auxiliar = auxiliar -> _proximo;
			i++;
		}
	}
	return -1;
}

void enqueue(Fila* umaFila, void* umDado)
{
	Elemento* novo = new Elemento;
	if (novo == NULL) //testa se é possível
	{
		throw("ERROSEMMEMORIA");
	}

	if (filaVazia(umaFila))
	{
		umaFila->_primeiro = novo;
	}
	else
	{
		umaFila->_ultimo->_proximo = novo;
	}
	novo -> _proximo = NULL; //n tem próximo ao último
	novo -> _dado = umDado;
	umaFila -> _ultimo = novo; //fazer a cabeça apontar para o novo
	umaFila -> _quantidade = umaFila -> _quantidade + 1;
	tamanho++;
	

	return;
}

void* dequeue(Fila* umaFila)
{
	if (filaVazia(umaFila))
	{
		throw fila_vazia_exception();
	}

	Elemento *saiu;
	void* volta;

	saiu = umaFila->_primeiro; //o primeiro da fila é o primeiro a sair
	volta = saiu->_dado; //o dado que sai pra retornar
	umaFila->_primeiro = saiu->_proximo; //o primeiro saiu, então o novo primeiro vai ser o próximo do antigo primeiro
	if (tamanho==1)
	{
		umaFila->_ultimo = NULL; //se a fila só tem uma pessoa, acaba as pessoas quando a única sai
	}
	umaFila->_quantidade = umaFila->_quantidade-1; //-1 tamanho da fila
	tamanho--;

	delete saiu;

	return volta;
}