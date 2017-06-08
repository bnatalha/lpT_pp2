#ifndef BAU_H
#define BAU_H

/**
* @file
* @brief Implementação de um Salgado (derivados da classe Produto)
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "Produto.h"
#include "Seccao.h"

/**
* @class Bau
* @brief Contém um Seccao para cada tipo de produto e os modifica.
*/
class Bau
{
	private:
		Seccao<CD> s_cds; /**< Seccao do tipo CD  */
		Seccao<Salgado> s_sal;	/**< Seccao do tipo CD */
		//Seccao<Salgado> s_doc;	

		// doce etc

	public:

		/**
		* @brief Constrói um objeto Bau sem especificar seus dados
		*/
		Bau(){}

		/**
		* @brief Constrói um objeto Bau como uma cópia de outro Bau já existente
		*/
		Bau( const Bau& orig) 
			: s_cds(orig.s_cds), s_sal(orig.s_sal)
		{}

		/**
		* @brief Destrutor de Bau
		*/
		~Bau(){}

		// Métodos

		// Getters
		void search_provider(string& prov);	/**< Busca e imprime todos os produtos de um fornecedor */
		
		// Setters
		void absorb_B( Bau& orig);	/**<  Move todos os itens de 'orig' () para o Bau que chamou está função () */
		void clear_B( );	/**<  Remove todos os items deste Bau */

		// save (?)
		// load (?)
		
		// Sobrecarga de operadores
		Bau& operator=(const Bau& orig);
};

// Implementações

void clear_B( )
{
	s_cds.l_produtos.clear();	// Limpa a lista da Seccao de CD
	s_sal.l_produtos.clear();	// Limpa a lista da Seccao de Salgado
	//s_doc.l_produtos.clear();	// Limpa a lista da Seccao de Salgado
}

Bau& Bau::operator=( Bau& orig)
{
	*this.s_cds = orig.s_cds;
	*this.s_sal = orig.s_sal;

	return *this;
}




#endif