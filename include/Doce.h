#ifndef DOCE_H
#define DOCE_H

/**
* @file
* @brief Implementação de um doce (derivados da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class Doce : public Produto
{
	private:
		string expiration; /**< Vencimento do doce */
		float sugar;	/**< Taca de açucar (em mg) */
		bool gluten;    /**< Bala contem gluten ou nao */
		bool lactose;   /**< Bala contem lactose ou nao */

	public:

		/**
		* @brief Constrói um objeto Doce sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		Doce() 
			: Produto("Doce","", 0, "00000000"), expiration(""), gluten(false), lactose(false), sugar(0)
		{}

		/**
		* @brief Constrói um objeto Doce sem especificar seus dados
		*/
		Doce(string vencimento, float acucar, bool glut, bool lacto) 
			: Produto("Doce","", 0, "00000000"), expiration(vencimento), gluten(glut), lactose(lacto), sugar(acucar)
		{}

		// Métodos

		// Gets
		string get_expiration() { return expiration; }
		bool get_gluten() { return gluten; }
		bool get_lactose() { return lactose; }
		float get_sugar() { return sugar; }

		// Sets
		void set_expiration(const string &x) { expiration = x; }
		void set_gluten(const bool &x) { gluten = x; }
		void set_lactose(const bool &x) { lactose = x; }
		void set_sugar(const float &x) { sugar = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif