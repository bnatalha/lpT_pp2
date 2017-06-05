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
		string style; /**< Estilo do CD */
		string artist;	/**< Artista do CD */

	public:

		/**
		* @brief Constrói um objeto CD sem especificar seus dados
		*/
		CD() 
			: Produto("CD","", 0, "00000000"), artist(""), style(""), name("")
		{}

		/**
		* @brief Constrói um objeto CD especificando seus atributos a partir de passagem de parâmetros
		*/
		CD(string estilo, string artista, string nome) 
			: Produto("CD","", 0, "00000000"), artist(""), style(estilo), artist(artista), name(nome)
		{}

		// Métodos

		// Gets
		string get_name() { return name; }	/**< Retorna título do CD (string) */
		string get_style() { return style; }	/**< Retorna o estilo do CD (string) */
		string get_artist() { return artist; }	/**< Retorna artista do CD (string) */

		// Sets
		void set_name(const string &x) { name = x; }	/**< Altera título do CD (string) */
		void set_style(const string &x) { style = x; }	/**< Altera o estilo do CD (string) */
		void set_artist(const string &x) { artist = x; }	/**< Altera artista do CD (string) */

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
		<< "\n/\\\tTítulo: \"" << name << "\""
		<< " , Artista: " << artist
		<< " , Estilo: " << style
		<< "]";
}

#endif
