#ifndef DVD_H
#define DVD_H

/**
* @file
* @brief Implementação de um DVD (derivado da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class DVD : public Produto
{
	private:
		string title; 	/**< titulo do DVD */
		string genre;	/**< genero do DVD */
		int duration;	/**< duracao do DVD, em minutos */

	public:

		/**
		* @brief Constrói um objeto DVD sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		DVD() 
			: Produto("DVD","", 0, "00000000"), title(""), genre(""), duration(0)
		{}

		/**
		* @brief Constrói um objeto DVD sem especificar seus dados
		*/
		DVD(string titulo, string genero, string duracao) 
			: Produto("DVD","", 0, "00000000"), title(titulo), genre(genero), duration(duracao)
		{}

		// Métodos

		// Gets
		string get_title() { return title; }
		string get_genre() { return genre; }
		int get_duration() { return duration; }

		// Sets
		void set_title(const string &x) { title = x; }
		void set_genre(const string &x) { genre = x; }
		void set_duration(const int &x) { duration = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif