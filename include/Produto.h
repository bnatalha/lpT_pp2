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
* @brief Classe abstrata contendo as principais características comuns aos produtos da loja.
*/
class Produto
{
	protected:
		string product_type;	/**< Tipo de produto (bebida, cd,etc) */
		string provider;	/**< Nome do fornecedor deste produto */
		float price;	/**< Preço do produto por unidade em R$*/
		string barcode;	/**< Código de barras (13 números símbolo EAN-13)*/

		int quantity;	/**< Quantidade deste produto em estoque */
		
	public:

		/**
		* @brief Constrói um objeto Produto sem especificar seus dados
		*/
		Produto()
			: product_type(""), provider(""), price(0), barcode("0000000000000"), quantity(0) 
		{}
		
		/**
		* @brief Constrói um Produto especificando seus atributos a partir de passagem de parâmetros (quantidade sempre inicia em 0)
		*/
		Produto(string produto, string fornecedor , float valor, string codigo)
			: product_type(produto), provider(fornecedor), price(valor), barcode(codigo), quantity(0)
		{}

		/**
		* @brief Produto criado a partir de outro produto (cópia)
		* @param original produto a ser copiado
		*/
		Produto( const Produto &origem)
			: product_type(origem.product_type), provider(origem.provider), price(origem.price), barcode(origem.barcode), quantity(origem.quantity)
		{}

		virtual ~Produto(){}

		// Métodos

		// Getter // Checar documentaçao
		string get_type() const { return product_type; }	/**< Retorna o tipo do produto (string) */
		string get_provider() const { return provider; }	/**< Retorna o nome do fornecedor do produto (string) */
		float get_price() const { return price; }	/**< Retorna preço do produto (float) */
		string get_barcode() const { return barcode; }	/**< Retorna o código de barras do produto (string) */
		float get_quantity() const { return quantity; }	/**< Retorna a quantidade de produtos (unidade) existentes */

		// Setters	// Checar se funciona pra rvalue
		void set_type( const string& x ) { product_type = x; }	/**< Modifica o tipo do produto (string) */
		void set_provider( const string& x ) { provider = x; }	/**< Modifica o nome do fornecedor do produto (string) */
		void set_price( const float& x ) { price = x; }	/**< Modifica preço do produto (float) */
		void set_barcode( const string& x ) { barcode = x; } 	/**< Modifica o código de barras do produto (string) */
		void set_quantity( const int& x ) { quantity = x; }	/**< Modifica a quantidade de produtos (unidade) existentes */

		// Sobrecarga de operadores
		float operator+ (const Produto &x);	/**< Retorna o resultado da adição do preço de dois produtos */
		friend float operator+ (float y, const Produto &x);	/**< Retorna o resultado da adição de um float com o preço do produto */
		float operator- (const Produto &x);	/**< Retorna o resultado da subtração do preço de dois produtos */
		friend float operator- (float y, const Produto &x);	/**< Retorna o resultado da subtração de um float com o preço do produto */
		virtual bool operator== (const Produto &x);	/**< Verifica se dois produtos tem codigós de barra iguais */
		virtual bool operator!= (const Produto &x);	/**< Verifica se dois produtos tem codigós de barra diferentes */
		virtual bool operator> (const Produto &x); /**< Verifica se este produto tem o seu valor do código de barras maior do que o outro */
		virtual bool operator< (const Produto &x); /**< Verifica se este produto tem o seu valor do código de barras menor do que o outro */
		virtual bool operator>= (const Produto &x); /**< Verifica se este produto tem o seu valor do código de barras maior ou igual do que o outro */
		virtual bool operator<= (const Produto &x); /**< Verifica se este produto tem o seu valor do código de barras menor ou igual do que o outro */
		
		// auxiliar da sobrecarga de extração
		virtual void print_it (std::ostream& out) const =0;	/**< Função virtual pura que define como vai ser a impressão das informações do produto */

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
	return( (this->price * this->quantity ) + ( x.price * x.quantity )) ;
}

/**
* @param y Float usado como primeira parcela de uma soma
* @param x Referência para o Produto a ter seu preço usado como segunda parcela de uma soma
* @return Um float com o valor do preço do produto atual + o preço do produto 'x'
*/
float operator+ (float y, const Produto &x)
{
	return( y + ( x.price * x.quantity ) );
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
* @returns Se os produtos comparados tem códigos de barras iguais
*/
bool Produto::operator== (const Produto &x)
{
	return (this->barcode == x.barcode);
}

/**
* @param x Referência para o Produto a ser comparado
* @returns Se os produtos comparados tem códigos de barras diferentes
*/
bool Produto::operator!= (const Produto &x)
{
	return (this->barcode != x.barcode);
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
* @param x Referência para o Produto a ter seu código de barras comparado
*/
bool Produto::operator>= ( const Produto &x){
	return ((barcode > x.barcode) or (barcode == x.barcode));
}

/**
* @param x Referência para o Produto a ter seu código de barras comparado
*/
bool Produto::operator<= ( const Produto &x){
	return ((barcode < x.barcode) or (barcode == x.barcode));
}

#include "Produto_tipos.h"

#endif