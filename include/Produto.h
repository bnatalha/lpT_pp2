/**
* @file
* @brief Definição e implementação da classe Produto
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "header.h"

/**
* @class Produto
* @brief Tem as principais caracteríscitacas comuns a todos os produtos da loja.
*/
class Produto
{
	private:
		string product_type;	/**< Tipo de produto (bebida, cd,etc) */
		string provider;	/**< Nome do fornecedor deste produto */
		float price;	/**< Preço do produto em R$*/
		string barcode;	/**< Código de barras */

	public:

		/**
		* @brief Constrói um objeto Produto sem especificar seus dados
		*/
		Produto(string produto, string fornecedor , float valor, string codigo)
			: product_type(produto), provider(fornecedor), price(valor), barcode(codigo)
		{}
		
		/**
		* @brief Constrói um lista a partir de uma lista já existente
		* @param copy Lista a ser copiada
		*/
		Produto()
			: product_type(""), provider(""), price(0), barcode("00000000")
		{}

		/**
		* @brief Produto criado a partir de outro produto (cópia)
		* @param original produto a ser copiada
		*/
		Produto( const Produto &origem)
			: product_type(origem.product_type), provider(origem.provider), price(origem.price), barcode(origem.barcode)
		{}

		// Sem destrutor

		// Métodos
		string get_type();
		string get_barcode();

		// Sobrecarga de operadores
		friend ostream& operator<< (ostream &out, const Produto &x);	/**< Sobrecarga do << */
		//friend &istream operator>> (istream &in, const Produto x);	/**< Sobrecarga do >> */
		float operator+ (const Produto &x);	/**< Retorna o resultado da adição do preço de dois produtos */
		friend float operator+ (float y, const Produto &x);	/**< Retorna o resultado da adição de um float com o preço do produto */
		float operator- (const Produto &x);	/**< Retorna o resultado da subtração do preço de dois produtos */
		friend float operator- (float y, const Produto &x);	/**< Retorna o resultado da subtração de um float com o preço do produto */
		bool operator== (const Produto &x);	/**< Verifica se dois produtos tem codigós de barra iguais */
};

// ============ Implementação ============

/**
* @returns O tipo do produto (string)
*/
string Produto::get_type()
{
	return(product_type);
}

/**
* @returns O código de barras do produto (string)
*/
string Produto::get_barcode()
{
	return(barcode);
}

//  == Sobrecarga de operadores ==

/**
* @param out Referência para um stream de saída
* @param x Produto a ser "impresso"
*/
ostream& operator<< (ostream &out, const Produto &x)
{
	out << "[Produto: " <<  x.product_type
		<< ", Fornecedor: " << x.provider
		<< ", Preço: R$" << x.price	// Trocar '.' por ',' na impressão
		<< ", Código de Barras: " << x.barcode << "]";

	return out;
}

/**
* @param x Referência para o Produto a ser comparado
* @returns Se os produtos comparadas tem o mesmo código de barras ou não
*/
bool Produto::operator== (const Produto &x)
{
	return (this->barcode == x.barcode);
}

/**
* @param y Float usado como primeira parcela de uma soma
* @param x Referência para o Produto a ter seu preço usado como segunda parcela de uma soma
* @return Um float com o valor do preço do produto atual + o preço do produto 'x'
*/
float operator+ (float y, const Produto &x)
{
	return( y + x.price);
}

/**
* @param x Referência para o Produto a ter seu preço usado como segunda parcela de uma soma
* @return Um float com o valor do preço do produto atual + o preço do produto 'x'
*/
float Produto::operator+ (const Produto &x)
{
	return( this->price + x.price);
}

/**
* @param x Referência para o Produto a ter seu preço usado como segunda parcela da subtração
* @return Um float com o valor do preço do produto atual - o preço do produto 'x'
*/
float Produto::operator- (const Produto &x)
{
	return( this->price - x.price);
}

/**
* @param y Float usado como primeira parcela de uma subtração
* @param x Referência para o Produto a ter seu preço usado como segunda parcela de uma subtração
* @return Um float com o valor do preço do produto atual - o preço do produto 'x'
*/
float operator- (float y, const Produto &x)
{
	return( y - x.price);
}