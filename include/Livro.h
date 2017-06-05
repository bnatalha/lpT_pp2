#ifndef LIVRO_H
#define LIVRO_H

/**
* @file
* @brief Implementação de um Livro (derivado da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class Livro : public Produto
{
	private:
		string title; 	/**< titulo do Livro */
		string author;	/**< autor do Livro */
		string editora; /**< editora do Livro */
		int year;	/**< ano em que o livro foi publicado */

	public:

		/**
		* @brief Constrói um objeto Livro sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		Livro() 
			: Produto("Livro","", 0, "00000000"), title(""), author(""), editora(""), year(0)
		{}

		/**
		* @brief Constrói um objeto Livro sem especificar seus dados
		*/
		Livro(string titulo, string autor, string edit, string ano) 
			: Produto("Livro","", 0, "00000000"), title(titulo), author(autor), editora(edit), year(0)
		{}

		// Métodos

		// Gets
		string get_title() { return title; }
		string get_author() { return author; }
		string get_editora() { return editora; }
		int get_year() { return year; }

		// Sets
		void set_title(const string &x) { title = x; }
		void set_author(const string &x) { author = x; }
		void set_editora(const string &x) { editora = x; }
		void set_year(const int &x) { year = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif