#ifndef TEST_H
#define TEST_H

/**
* @file
* @brief Onde fica a função que testa o programa.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 02/06/2017
* @date --
* @sa --
*/

#include "header.h"
#include "myLista.h"
#include "Produto.h"
#include "Produto_tipos.h"

#include <list>
using std::list;

/**
* @brief Testa as funções e métodos de Produto (antes dela ser abstrata)
*/
void test0()
{
	/*
	Produto A("Bebida","Pará Produtos", 13.8, "07968534");
	Produto B;
	Produto C(A);
	Produto D("Doce","Pará Produtos", 13, "43436172");

	// Tenstando impressão
	cout << A << endl << B << endl << C << endl;

	// Testando comparação de produtos
	cout << "Os produtos" << (A == A ? " ":" não ") << "são iguais." << endl;
	cout << "Os produtos" << (A == B ? " ":" não ") << "são iguais." << endl;
	cout << "Os produtos" << (A == C ? " ":" não ") << "são iguais." << endl;
	cout << "Os produtos" << (A == D ? " ":" não ") << "são iguais." << endl;

	// Testando sobrecarga de + e -
	cout << "Total: " << A+D+C+B << endl	// 13.8 + 13 + 13.8 + 0 = 40.6
		<< "A-D+C-B: " << A-D+C-B << endl;	// 13.8 - 13 + 13.8 - 0 = 14.6

	// Testando criação de tipos de produtos
	//Bebida A;	// Não pode ser pq ja existe um "produto A"
	Bebida AA;
	AA.set_barcode("0000000000001");
	Bebida BB("12/06/18",30,4.6);
	BB.set_barcode("1234123412347");
	DVD CC("Tom e Jerry","Infantil",40);
	CC.set_barcode("9999000000111");

	cout << AA << endl << BB << endl;
	*/
}

void test1()
{
	// Testando Lista de produtosz
	list<Produto*> ABC;
	//myLista<Produto*> ABC;
	
	//Bebida a("15/06/17",35,600);
	CD b("Melhor do que parece","O Terno","Rock nacional");
	//DVD c("Zapzap: o filme", "Ficção científica", 240);
	//Doce d("14/06/2017",5,true,true);
	//Fruta e("14/07/2017",104,"14/06/2017");
	//Livro f("Destruindo sua teoria de conjunto","Russel","Ed. De Jesus", 1902);
	Salgado g("14/06/2017",40,false,true);
	/*
	ABC.push_sorted(a);
	ABC.push_sorted(b);
	ABC.push_sorted(c);
	ABC.push_sorted(d);
	ABC.push_sorted(e);
	ABC.push_sorted(f);
	ABC.push_sorted(g);
	*/
	CD* p = new CD("The Black Album","Metallica","Infantil");
	ABC.push_back(p);
	//ABC.push_sorted(new Fruta("14/07/2017",104,"14/06/2017"));


	cout << endl << "Testando lista de Produtos...{" << endl;
	for (auto &e: ABC)
	{
		e->print_it(cout);
		cout << endl;
	}
	cout << "}" << endl;
	
	//cout << "get de lista de produto: " << (ABC.front())->get_duration() << endl;
	
	delete p;

	// Não funciona pq é Lista de Produto e não de DVD
	// Uma lista de Estoque pra cada tipo de produto.
}

void test2_Grupo()
{

	/*
	Grupo_Produto<CD> m_cds;
	//Grupo_Produto<Salgado> m_salga;

	CD cd1("Superunknow","Soundgarden","Rock");
	CD cd2("Melhor do que parece","O Terno","Rock");
	CD cd3("Black album","Metallica","Infantil");

	cd1.set_barcode("001");
	cd1.set_provider("Sony Music");
	cd1.set_price(14.3);

	cd2.set_barcode("002");
	cd2.set_provider("Brasilzil");
	cd2.set_price(10);

	cd3.set_barcode("003");
	cd3.set_provider("Bombom Produções");
	cd3.set_price(1.99);

	m_cds.register(cd1);
	*/

}

/**
* @brief Testa operador== de myLista
*/
void test_lista_1()
{

	myLista<int> aaa;
	myLista<int> bbb;
	myLista<int> ccc;
	myLista<int> ddd;
	
	// preenchendo listas
	for (int i = 0; i <= 10; ++i)
	{
		aaa.push_back(i);
		if(i != 0 )ddd.push_back(i);
		else ddd.push_back(34);
		if(i%2 == 0) bbb.push_back(i);
	}
	
	ccc = aaa;

	// imprimindo listas
	cout << "aaa: [ ";
	for (auto &e : aaa)
		cout << e << " ";
	cout << "]" << endl;
	cout << "bbb: [ ";
	for (auto &e : bbb)
		cout << e << " ";
	cout << "]" << endl;
	cout << "ccc: [ ";
	for (auto &e : ccc)
		cout << e << " ";
	cout << "]" << endl;
		cout << "ddd: [ ";
	for (auto &e : ddd)
		cout << e << " ";
	cout << "]" << endl;

	// comparando listas
	cout << "aaa e bbb" << (aaa == bbb?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ccc" << (aaa == ccc?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ddd" << (aaa == ddd?" ":" não ") << "são iguais" << endl;	
}

/**
* @brief Testa função unique() de myLista
*/
void test_lista_2()
{
	myLista<int> A;

	// preenchendo listas
	A.push_back(22);
	for (int i = 0; i < 3; ++i)
	{
		if(i%2)
		{
			A.push_back(2);
			A.push_back(2);
		}
		A.push_back(3);

	}
	A.push_back(23);
	A.push_back(23);

	// testando unique
	cout << endl << "A: [ ";
	for (auto &e : A)
		cout << e << " ";
	cout << "]" << endl;

	A.unique();

	cout << endl << "unique: [ ";
	for (auto &e : A)
		cout << e << " ";
	cout << "]" << endl;
}

#endif