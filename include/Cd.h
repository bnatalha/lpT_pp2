#ifndef CD_H
#define CD_H

/**
* @file
* @brief Implementação de um CD (derivado da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class Cd : public Produto
{
	private:
		string style; /**< estilo do cd */
		string artist;	/**< artista do cd */
		string name;	/**< nome do cd */

	public:

		/**
		* @brief Constrói um objeto Cd sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		Cd() 
			: Produto("Cd","", 0, "00000000"), style(""), artist(""), name("")
		{}

		/**
		* @brief Constrói um objeto Cd sem especificar seus dados
		*/
		Cd(string estilo, string artista, string nome) 
			: Produto("Cd","", 0, "00000000"), style(estilo), artist(artista), name(nome)
		{}

		// Métodos

		// Gets
		string get_style() { return style; }
		string get_artist() { return artist; }
		sting get_name() { return name; }

		// Sets
		void set_style(const string &x) { style = x; }
		void set_artist(const string &x) { artist = x; }
		void set_name(const string &x) { name = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif