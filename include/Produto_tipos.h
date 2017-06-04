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
		Bebida() 
			: Produto("Bebida","", 0, "00000000"), expiration(""), alchool(0), sugar(0)
		{}

		Bebida(string vencimento, float teor_alcool, float acucar_mg) 
			: Produto("Bebida","", 0, "00000000"), expiration(""), alchool(0), sugar(0)
		{}

		// Métodos

		// Gets
		string get_expiration();
		float get_alchool();
		float get_sugar();

		// Sets
		string set_expiration(const string &x) : expiration(x) {}
		float set_alchool(const float &x) : alchool(x) {}
		float set_sugar(const float &x) : sugar(x) {}

};