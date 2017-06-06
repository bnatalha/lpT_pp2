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
#include "Grupo_Produto.h"

/**
* @class Bau
* @brief Contém um Grupo_Produto para cada tipo de produto e os modifica.
*/
class Bau
{
	private:
		Grupo_Produto<CD> l_cds; /**< Grupo de Produtos do tipo CD  */
		Grupo_Produto<Salgado> l_salga;	/**< Grupo de Produtos do tipo CD */

		// doce etc

	public:

		/**
		* @brief Constrói um objeto Bau sem especificar seus dados
		*/
		Bau(){}

		/**
		* @brief Constrói um objeto Bau como uma cópia de outro Bau já existente
		*/
		Bau( const Bau& origem) 
			: l_cds(origem.l_cds), l_salga(origem.l_salga)
		{}

		/**
		* @brief Destrutor virtual de Bau
		*/
		virtual ~Bau(){}

		// Métodos
		
		void absorb_B( Bau& origem);	/**<  Move todos os itens de 'origem' () para o Bau que chamou está função */

};

// Implementações
void Bau::absorb_B( Bau& origem)
{
	
}


#endif