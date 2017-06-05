#ifndef FRUTA_H
#define FRUTA_H

/**
* @file
* @brief Implementação de um Fruta (derivados da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class Fruta : public Produto
{
	private:
		string expiration; /**< Vencimento da fruta */
		int number 		/**< Numero do lote */
		string date		/**< Data de producao do lote */

	public:

		/**
		* @brief Constrói um objeto Fruta sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		Fruta() 
			: Produto("Fruta","", 0, "00000000"), expiration(""), number(0), date("")
		{}

		/**
		* @brief Constrói um objeto Fruta sem especificar seus dados
		*/
		Fruta(string vencimento, fint numero, string data) 
			: Produto("Fruta","", 0, "00000000"), expiration(vencimento), number(numero), date(data)
		{}

		// Métodos

		// Gets
		string get_expiration() { return expiration; }
		int get_number() { return number; }
		string get_date() { return date; }

		// Sets
		void set_expiration(const string &x) { expiration = x; }
		void set_number(const int &x) { number = x; }
		void set_date(const string &x) { date = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif