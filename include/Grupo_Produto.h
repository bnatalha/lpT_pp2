#ifndef GRUPO_PRODUTO_H
#define GRUPO_PRODUTO_H

/**
* @file
* @brief Definição e implementação da classe Produto
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 05/06/2017
* @date 06/06/2017
* @sa --
*/

#include "header.h"
#include "Produto.h"
#include "myLista.h"

/**
* @class Grupo_Produto
* @brief Classe que armazenará uma lista de um tipo de produto, 
* @tparam Um tipo de produto (CD, DVD, Fruta, etc.)
*/
template <typename tipo_P>
class Grupo_Produto
{
	protected:
		myLista<tipo_P> l_produtos;	/**< Lista de 'tipo_P' */

	public:

		/**
		* @brief Constrói um objeto Grupo_Produto vazio
		*/
		Grupo_Produto(){}

		/**
		* @brief Grupo_Produto criado a partir de outro grupo de produtos (cópia)
		* @param original Grupo_Produto a ser copiado
		*/
		Grupo_Produto( const Grupo_Produto &origem)
			: l_produtos(origem.l_produtos)
		{}

		/**
		* @brief Grupo_Produto criado a partir de outro grupo de produtos (cópia)
		* @param original Grupo_Produto a ser copiado
		*/
		~Grupo_Produto(){}

		// Métodos

		// Getter // Checar documentaçao
		//void search_P( const tipo_P& product ); 	/**< Procura o produto por alguma de sua característica(?) */
		//bool get_P( const tipo_P& product );	/**< Retorna se existe o produto buscado */
		

		// Setters	// Checar se funciona pra rvalue
		//void register_P( const tipo_P& product ) { l_produtos.push_sorted(product); }	/**< Adiciona um produto tipo_P a lista do grupo */
		//void modify_P( const tipo_P& product );
		//void remove_P( const tipo_P& product );
		
		//friend &istream operator>> (istream &in, const Produto x);	/**< Sobrecarga do >> */
};

// ============ Implementação ============

// Metodos especificos para todos templates

#endif