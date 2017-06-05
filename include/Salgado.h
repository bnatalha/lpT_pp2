#ifndef SALGADO_H
#define SALGADO_H

/**
* @file
* @brief Implementação de um Salgado (derivados da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class Salgado : public Produto
{
	private:
		string expiration; /**< Vencimento do Salgado */
		float sodium;	/**< Taca de sodio (em mg) */
		bool gluten;    /**< Bala contem gluten ou nao */
		bool lactose;   /**< Bala contem lactose ou nao */

	public:

		/**
		* @brief Constrói um objeto Salgado sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		Salgado() 
			: Produto("Salgado","", 0, "00000000"), expiration(""), gluten(false), lactose(false), sodium(0)
		{}

		/**
		* @brief Constrói um objeto Salgado sem especificar seus dados
		*/
		Salgado(string vencimento, float sodio, bool glut, bool lacto) 
			: Produto("Salgado","", 0, "00000000"), expiration(vencimento), gluten(glut), lactose(lacto), sodium(sodio)
		{}

		// Métodos

		// Gets
		string get_expiration() { return expiration; }
		bool get_gluten() { return gluten; }
		bool get_lactose() { return lactose; }
		float get_sodium() { return sodium; }

		// Sets
		void set_expiration(const string &x) { expiration = x; }
		void set_gluten(const bool &x) { gluten = x; }
		void set_lactose(const bool &x) { lactose = x; }
		void set_sodium(const float &x) { sodium = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif