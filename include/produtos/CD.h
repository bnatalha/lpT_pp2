#ifndef CD_H
#define CD_H

/**
* @file
* @brief Implementação de um CD (derivado da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

/**
* @class CD
* @brief Herdeira da classe Produto, usada para produtos do tipo cd
*/
class CD : public Produto
{
	private:
		string name;	/**< Nome do CD */
		string artist;	/**< Artista do CD */
		string style; /**< Estilo do CD */

	public:

		/**
		* @brief Constrói um objeto CD sem especificar seus dados
		*/
		CD() 
			: Produto("CD","", 0, "00000000"), name(""), artist(""), style("")
		{}

		/**
		* @brief Constrói um objeto CD especificando seus atributos a partir de passagem de parâmetros
		*/
		CD(string nome, string artista, string estilo) 
			: Produto("CD","", 0, "00000000"), name(nome), artist(artista), style(estilo)
		{}

		/**
		* @brief Constrói um objeto CD copiando de um outro obejto CD
		*/
		CD(const CD& orig) 
			: Produto( orig.get_type(), orig.get_provider(), orig.get_price(), orig.get_barcode()),
			name(orig.name), artist(orig.artist), style(orig.style)
		{ set_quantity(orig.get_quantity()); }

		/**
		* @brief Destrutor virtual de CD
		*/
		virtual ~CD(){}

		// Métodos

		// Gets
		string get_name() { return name; }	/**< Retorna título do CD (string) */
		string get_artist() { return artist; }	/**< Retorna artista do CD (string) */
		string get_style() { return style; }	/**< Retorna o estilo do CD (string) */

		// Sets
		void set_name(const string &x) { name = x; }	/**< Altera título do CD (string) */
		void set_artist(const string &x) { artist = x; }	/**< Altera artista do CD (string) */
		void set_style(const string &x) { style = x; }	/**< Altera o estilo do CD (string) */

		// auxiliar da sobrecarga de extração
		void print_it (std::ostream& out) const;	/**< Função que define como vai ser a impressão do produto */
};

// Implementações

/**
* @param out Referência para um stream de saída
* @sa sobrecarga de operadores em subclasses (https://stackoverflow.com/questions/19376943/)
*/
void CD::print_it(std::ostream& out) const
{
	out << "[Produto: " <<  product_type
		<< ", Fornecedor: " << provider
		<< ", Preço: R$" << price	// Trocar '.' por ',' na impressão
		<< ", Código de Barras: " << barcode
		<< ", Quantidade: " << quantity
		<< "\n/\\\tTítulo: \"" << name << "\""
		<< " , Artista: " << artist
		<< " , Estilo: " << style
		<< "]";
}

#endif
