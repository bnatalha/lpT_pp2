#ifndef SALGADO_H
#define SALGADO_H

/**
* @file
* @brief Implementação de um Salgado (derivados da classe Produto)
* @author Michel Jean Katsilis (https://github.com/MJK2)
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"

/**
* @class Salgado
* @brief Herdeira da classe Produto, usada para produtos do tipo salgado
*/
class Salgado : public Produto
{
	private:
		string expiration; /**< Vencimento do Salgado */
		float sodium;	/**< Taxa de sodio (em mg) */
		bool gluten;    /**< Bala contem glúten ou nao */
		bool lactose;   /**< Bala contem lactose ou nao */

	public:

		/**
		* @brief Constrói um objeto Salgado sem especificar seus dados
		*/
		Salgado() 
			: Produto("Salgado","", 0, "00000000"), expiration(""), sodium(0), gluten(false), lactose(false)
		{}

		/**
		* @brief Constrói um objeto Salgado especificano seus dados através da passagem de seus atributos como parâmetro
		*/
		Salgado(string vencimento, float sodio, bool glut, bool lacto) 
			: Produto("Salgado","", 0, "00000000"), expiration(vencimento), sodium(0), gluten(glut), lactose(lacto)
		{}

		/**
		* @brief Destrutor virtual de CD
		*/
		virtual ~Salgado(){}

		// Métodos

		// Gets
		string get_expiration() { return expiration; }
		float get_sodium() { return sodium; }	/**< Retorna a taxa de sódio (em mg) do produto */
		bool get_gluten() { return gluten; }	/**< Retorna se o produto contém glúten ou não */
		bool get_lactose() { return lactose; }	/**< Retorna se o produto contém lactose ou não */

		// Sets
		void set_expiration(const string &x) { expiration = x; }
		void set_sodium(const float &x) { sodium = x; }	/**< Altera a taxa de açucar (em mg) do produto */
		void set_gluten(const bool &x) { gluten = x; }	/**< Altera o atributo que diz se o produto contém glúten ou não */
		void set_lactose(const bool &x) { lactose = x; }	/**< Altera o atributo que diz se o produto contém lactose ou não */

		// auxiliar da sobrecarga de extração
		void print_it (std::ostream& out) const;	/**< Função que define como vai ser a impressão do produto */
};

// Implementações

/**
* @param out Referência para um stream de saída
* @sa sobrecarga de operadores em subclasses (https://stackoverflow.com/questions/19376943/)
*/
void Salgado::print_it(std::ostream& out) const
{
	out << "[Produto: " <<  product_type
		<< ", Fornecedor: " << provider
		<< ", Preço: R$" << price	// Trocar '.' por ',' na impressão
		<< ", Código de Barras: " << barcode
		<< ", Quantidade: " << quantity
		<< "\n/\\\tVencimento: " << expiration
		<< " , Taxa de sódio: " << sodium << "mg"
		<< " , Contem glúten: " << (gluten? "Sim":"Não")
		<< " , Contem lactose: " << (lactose? "Sim":"Não")
		<< "]" << endl;
}

#endif