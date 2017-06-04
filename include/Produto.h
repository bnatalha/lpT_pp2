/**
* @file
* @brief Definição e implementação da classe Produto
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 04/06/2017
* @date --
* @sa --
*/

#include "header.h"

/**
* @class Produto
* @brief Tem as principais caracteríscitacas comuns a todos os produtos da loja.
*/
class Produto
{
	public:
		float preco;	/**< Preço do produto */
		long int codigo_de_barras;	/**< Código de barras */
		string tipo;	/**< Tipo de produto (bebida, cd,etc) */
		string de_fornecedor;	/**< Nome do fornecedor deste produto */

	private:
		Produto(){}

};

// ============ Implementação ============