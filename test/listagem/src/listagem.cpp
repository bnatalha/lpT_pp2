#include <iostream>
#include "listagem.h"
#include <list>

#define TOTAL 10

int main(int argc, char const *argv[])
{
	TipoA a1(1,"a"); // Instancia UM objeto da classe TipoA
	TipoB b1(2,"b"); // Instancia UM objeto da classe TipoB
	a1.imprime(); 
	b1.imprime();

	list<Base*> lista; // Cria UMA lista (usando STL) genérica usando a classe Base
	
	// Preenche a lista com elementos do TipoA (quando i for par) ou TipoB (quando i for impar)
	for(int i=0; i<TOTAL; i++)
	{
		// O metodo push_back() insere um elemento no final da lista (STL)
		(i%2)?lista.push_back(new TipoA(i,"aa")):lista.push_back(new TipoB(i,"bb"));
	}

	// Imprime os elementos da lista usando um iterador (STL)
	for (list<Base*>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		// Como cada elemento da lista é um objeto TipoA ou TipoB e ambos respondem ao 
		// metodo imprime()...
		(*it)->imprime();
	}

	cout << "NEXT" << endl;

	a1.foo();

	return 0;
}