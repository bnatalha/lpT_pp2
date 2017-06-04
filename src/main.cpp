/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 02/06/2017
* @date --
* @sa --
*/
#include "header.h"
#include "Produto.h"

/**
* @brief Função principal
* @detail 
* @param argc Tamanho de 'argv'
* @param argv Ponteiro para um array de Char constante com --
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
	cout << "Os produtos" << (A == C ? " ":" não ") << "são iguais." << endl;

	// Testando sobrecarga de + e -
	cout << "Total: " << A+D+C+B << endl	// 13.8 + 13 + 13.8 + 0 = 40.6
		<< "A-D+C-B: " << A-D+C-B << endl;	// 13.8 - 13 + 13.8 - 0 = 14.6
	

	return 0;
}