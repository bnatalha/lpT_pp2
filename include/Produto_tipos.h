#ifndef PRODUTOS_TIPOS_H
#define PRODUTOS_TIPOS_H

/**
* @file
* @brief Implementação dos tipos de produtos (derivados da classe Produto)
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

class Bebida : public Produto
{
	private:
		string expiration; /**< Vencimento do produto */
		float alchool;	/**< Teor alcoólico (em %) */
		float sugar;	/**< Taca de açucar (em mg) */

	public:

		/**
		* @brief Constrói um objeto Bebida sem especificar seus dados
		* @sa Chamando construtor da classe Mãe na classe filha no construtoe(http://www.studytonight.com/cpp/order-of-constructor-call.php)
		*/
		Bebida() 
			: Produto("Bebida","", 0, "00000000"), expiration(""), alchool(0), sugar(0)
		{}

		/**
		* @brief Constrói um objeto Bebida sem especificar seus dados
		*/
		Bebida(string vencimento, float teor_alcool, float acucar_mg) 
			: Produto("Bebida","", 0, "00000000"), expiration(""), alchool(0), sugar(0)
		{}

		// Métodos

		// Gets
		string get_expiration() { return expiration; }
		float get_alchool() { return alchool; }
		float get_sugar() { return sugar; }

		// Sets
		void set_expiration(const string &x) { expiration = x; }
		void set_alchool(const float &x) { alchool = x; }
		void set_sugar(const float &x) { sugar = x; }

		// Sobrecarga de operadores
		
};

// Implementações

// Sobrecarga de operadores


#endif