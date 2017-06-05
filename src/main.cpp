/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 02/06/2017
* @date --
* @sa --
*/
#include "header.h"
#include "myLista.h"
#include "Produto.h"
#include "Produto_tipos.h"

/**
* @brief Função principal
*/
int main(int argc, char const *argv[])
{

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
	
	// Testando Lista de produtosz
	myLista<Produto> ABC;
	ABC.push_sorted(A);
	ABC.push_sorted(B);
	ABC.push_sorted(C);
	ABC.push_sorted(D);
	ABC.push_sorted(AA);
	ABC.push_sorted(BB);
	ABC.push_sorted(CC);

	cout << endl << "Testando lista de Produtos...{" << endl;
	for (auto &e: ABC)
		cout << e << endl ;
	cout << "}" << endl;

	cout << "get de lista de produto: " << (ABC.front()).get_duration() << endl;	// Não funciona pq é Lista de Produto e não de DVD
	// Uma lista de Estoque pra cada tipo de produto.

	return 0;
}