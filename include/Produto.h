#ifndef PRODUTOS_H
#define PRODUTOS_H

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
	protected:
		string product_type;	/**< Tipo de produto (bebida, cd,etc) */
		string provider;	/**< Nome do fornecedor deste produto */
		float price;	/**< Preço do produto em R$*/
		string barcode;	/**< Código de barras (13 números símbolo EAN-13)*/

	public:

		/**
		* @brief Constrói um objeto Produto sem especificar seus dados
		*/
		Produto()
			: product_type(""), provider(""), price(0), barcode("0000000000000")
		{}
		
		/**
		* @brief Constrói um Produto especificando seus atributos a partir de passagem de parâmetros
		*/
		Produto(string produto, string fornecedor , float valor, string codigo)
			: product_type(produto), provider(fornecedor), price(valor), barcode(codigo)
		{}

		/**
		* @brief Produto criado a partir de outro produto (cópia)
		* @param original produto a ser copiado
		*/
		Produto( const Produto &origem)
			: product_type(origem.product_type), provider(origem.provider), price(origem.price), barcode(origem.barcode)
		{}

		// Sem destrutor (?)

		// Métodos

		// Getter // Checar documentaçao

		string get_type() { return product_type; }	/**< Retorna o tipo do produto (string) */
		string get_provider() { return provider; }	/**< Retorna o nome do fornecedor do produto (string) */
		float get_price() { return price; }	/**< Retorna preço do produto (float) */
		string get_barcode() { return barcode; }	/**< Retorna o código de barras do produto (string) */

		// Setters	// Checar se funciona pra rvalue
		void set_type( const string& x ) { product_type = x; }	/**< Modifica o tipo do produto (string) */
		void set_provider( const string& x ) { provider = x; }	/**< Modifica o nome do fornecedor do produto (string) */
		void set_price( const float& x ) { price = x; }	/**< Modifica preço do produto (float) */
		void set_barcode( const string& x ) { barcode = x; } 	/**< Modifica o código de barras do produto (string) */

		// Sobrecarga de operadores
		float operator+ (const Produto &x);	/**< Retorna o resultado da adição do preço de dois produtos */
		friend float operator+ (float y, const Produto &x);	/**< Retorna o resultado da adição de um float com o preço do produto */
		float operator- (const Produto &x);	/**< Retorna o resultado da subtração do preço de dois produtos */
		friend float operator- (float y, const Produto &x);	/**< Retorna o resultado da subtração de um float com o preço do produto */
		bool operator== (const Produto &x);	/**< Verifica se dois produtos tem codigós de barra iguais */
		bool operator> (const Produto &x); /**< Verifica se este produto tem o seu valor do código de barras maior do que o outro */
		bool operator< (const Produto &x); /**< Verifica se este produto tem o seu valor do código de barras menor do que o outro */
		
		// auxiliar da sobrecarga de extração
		virtual void print_it (std::ostream& out) const;	/**< Função que define como vai ser a impressão do produto */

		
		//friend &istream operator>> (istream &in, const Produto x);	/**< Sobrecarga do >> */
};

// ============ Implementação ============

//  == Sobrecarga de operadores ==

/**
* @param x Referência para o Produto a ter seu preço usado como segunda parcela de uma soma
* @return Um float com o valor do preço do produto atual + o preço do produto 'x'
*/
float Produto::operator+(const Produto &x)
{
	return( this->price + x.price);
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
* @param x Referência para o Produto a ter seu preço usado como segunda parcela da subtração
* @return Um float com o valor do preço do produto atual - o preço do produto 'x'
*/
float Produto::operator-(const Produto &x)
{
	return( this->price - x.price);
}

/**
* @param y Float usado como primeira parcela de uma subtração
* @param x Referência para o Produto a ter seu preço usado como segunda parcela de uma subtração
* @return Um float com o valor do preço do produto atual - o preço do produto 'x'
*/
float operator-(float y, const Produto &x)
{
	return( y - x.price);
}

// Comparação

/**
* @param x Referência para o Produto a ser comparado
* @returns Se os produtos comparadas tem o mesmo código de barras ou não
*/
bool Produto::operator== (const Produto &x)
{
	return (this->barcode == x.barcode);
}

/**
* @param x Referência para o Produto a ter seu código de barras comparado
*/
bool Produto::operator>( const Produto &x){
	return (barcode > x.barcode);
}

/**
* @param x Referência para o Produto a ter seu código de barras comparado
*/
bool Produto::operator<( const Produto &x){
	return (barcode < x.barcode);
}

/**
* @param out Referência para um stream de saída
* @sa sobrecarga de operadores em subclasses (https://stackoverflow.com/questions/19376943/)
*/
void Produto::print_it(std::ostream& out) const
{
	out << "[Produto: " <<  this->product_type
		<< ", Fornecedor: " << this->provider
		<< ", Preço: R$" << this->price	// Trocar '.' por ',' na impressão
		<< ", Código de Barras: " << this->barcode
		<< "]";
}

// ================= Função Fora de Produto =================

/**
* @brief Sobrecarga do operador de extração usando a classe Produto. Esta função tem uma sobrecarga (versão diferente) para cada subclasse de Produto
* @param out Referência para um stream de saída
* @param x Produto a ser "impresso"
*/
ostream& operator<< (ostream &out, const Produto &product)
{
	product.print_it(out);
	return out;
}

#endif