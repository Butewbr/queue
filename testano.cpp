#include "Fila.h"
#include <iostream>

//estou removendo (dequeueing) o PRIMEIRO
//estou adicionando (enqueueing) ao ÚLTIMO

using namespace std;

int main(int argc, char const *argv[])
{
	int choice = 0;
	Fila *minhaFila = iniciaFila();

	while(choice != 13)
	{
		cout << "1. destroi a fila" << endl;
		cout << "2. fila e vazia?" << endl;
		cout << "3. tira da fila" << endl;
		cout << "4. colocr na fila" << endl;
		cout << "5. qual o elemento no final da fila?" << endl;
		cout << "6. qual o elemento no inicio da fila?" << endl;
		cout << "7. tamanho da fila" << endl;
		cout << "opacao: ";

		cin >> choice;

		if (choice==1)
		{
			destroiFila(minhaFila);
		}
		else if (choice==2)
		{
			if (filaVazia(minhaFila)==true)
			{
			 	cout << "e vazia" << endl;
			} 
			else
			{
				cout << "n e" << endl;
			}
		}

		else if (choice==3)
		{
			dequeue(minhaFila);
		}
		else if (choice==4)
		{
			void* dado;
			cout << "fala o dado pr adiicnoa: ";
			cin >> dado;

			enqueue(minhaFila, dado);
		}
		else if (choice==5)
		{
			if (filaVazia(minhaFila))
			{
				cout << "fila vazia" << endl;
			}
			else
			{
				Elemento *ultiminho = minhaFila->_ultimo; 
				cout << (int*) ultiminho->_dado << endl;	
			}
		}
		else if (choice==6)
		{
			if (filaVazia(minhaFila))
			{
				cout << "fila vazia" << endl;
			}
			else
			{
				Elemento *peimeirinho = minhaFila->_primeiro; 
				cout << (int*) peimeirinho->_dado << endl;	
			}
		}
		else if (choice==7)
		{
			if (filaVazia(minhaFila))
			{
				cout << "0" << endl;
			}
			else
			{
				cout << minhaFila->_quantidade << endl;
			}
		}
		else
		{
			if (!filaVazia(minhaFila))
			{
				destroiFila(minhaFila);
			}
			choice = 13;
		}
	}

	return 0;
}