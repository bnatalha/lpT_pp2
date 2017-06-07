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

		int list_size(){ return l_produtos.size(); }
		
		bool exist_P( const tipo_P& prod );	/**< Retorna se existe o produto buscado */
		typename myLista<tipo_P>::iterator search_P( const tipo_P& prod ); 	/**< Procura o produto por alguma de sua característica(?) */
		
		// Setters	// Checar se funciona pra rvalue
		void register_P( const tipo_P& prod );	/**< Adiciona um produto tipo_P a lista do grupo */
		void modify_P( tipo_P& prod );
		void remove_all_P( const tipo_P& prod ); /**< Remove todos os produtos com o mesmo código de barras que 'prod' da lista */
		void remove_this_P( const tipo_P& prod ); /**< Remove o primeiro produto com o mesmo código de barras que 'prod' da lista */
		void remove_this_P( typename myLista<tipo_P>::iterator& it ); /**< Remove o primeiro produto com o mesmo código de barras que 'prod' da lista */
		void print_P( std::ostream& out );
		
		//friend &istream operator>> (istream &in, const Produto x);	/**< Sobrecarga do >> */

		typedef typename myLista<tipo_P>::iterator it_P;
};

// ============ Implementação ============

template <typename tipo_P>
bool Grupo_Produto<tipo_P>::exist_P( const tipo_P& prod )	// Procura pelo codigo de barras
{
	for(auto &e: l_produtos)
		if( e == prod ) return true;

	return false;
}

template <typename tipo_P>
void Grupo_Produto<tipo_P>::register_P( const tipo_P& prod )
{
	typename myLista<tipo_P>::iterator it  = search_P(prod);

	if (it != l_produtos.end())	// Se o produto não for registrado
		l_produtos.push_sorted(it);	// Registra
	else
		*(it).set_quantity(*(it).get_quantity() + 1);	// Aumenta a quantidade de unidades deste produto em 1;
}

/**
* @return Interator pra localização do produto procurado na lista. Se o iterator for igual ao fim da lista, o produto buscado não foi achado.
*/
template <typename tipo_P>
typename myLista<tipo_P>::iterator Grupo_Produto<tipo_P>::search_P( const tipo_P& prod )
{
	typename myLista<tipo_P>::iterator it = l_produtos.begin();
	
	for( ; it != l_produtos.end() ; it++ )
	{
		if( *(it) == prod ) break;	// encontrou*
	}

	return it;	// *se it == l_produtos.end(), não encontrou.
}

template <typename tipo_P>
void Grupo_Produto<tipo_P>::remove_all_P( const tipo_P& prod )
{
	l_produtos.remove(prod);
}

template <typename tipo_P>
void Grupo_Produto<tipo_P>::remove_one_P( const tipo_P& prod )
{
	typename myLista<tipo_P>::iterator it  = search_P(prod);

	if (it != l_produtos.end())
		*(it).set_quantity(*(it).get_quantity() - 1);	// Diminui em 1 unidade a quantidade de produtos apontados por 'it'
}

template <typename tipo_P>
void Grupo_Produto<tipo_P>::remove_this_P( typename myLista<tipo_P>::iterator& it )
{
	if (it != l_produtos.end())
		*(it).set_quantity(*(it).get_quantity() - 1);	// Diminui em 1 unidade a quantidade de produtos apontados por 'it'
}

template <typename tipo_P>
void Grupo_Produto<tipo_P>::print_P( std::ostream& out )
{
	out << "{" << endl;
	for (auto &e: l_produtos)
	{
		e.print_it(out);
		cout << endl;
	}
	out << "}" << endl;
}


// MODIFY ========================

template <>
void Grupo_Produto<CD>::modify_P( CD& prod )
{
	int operation = 1000;
	while( operation != 0)
	{
		string new_s;

		cout << "O que será modificado do CD ("<< prod.get_barcode() <<")?" << endl
			 << "(1) nome;"
			 << "(2) artista;"
			 << "(3) estilo;"
			 << "(0) Não modificar agora."
			 << endl << "Insira o numero. >> ";

		cin >> operation;

		// Operações
		if(operation == 1){

			cout << "Modificar nome. Atual: \"" << prod.get_name() << "\""
				<< endl << "Insira novo nome. >>" ;

			getline(cin, new_s);	// Armazena o novo nome em 'new_s'
			cin.ignore();

			prod.set_name(new_s);	// Modifica o nome para o conteudo de 'new_s'

			cout << "nome: \"" << prod.get_name() << "\"" << endl;
		}
		if(operation == 2){
			cout << "Modificar artista. Atual: \"" << prod.get_artist() << "\""
				<< endl << "Insira novo artista. >>" ;
			
			getline(cin, new_s);	// Armazena o novo artista em 'new_s'
			cin.ignore();

			prod.set_artist(new_s);	// Modifica o artista para o conteudo de 'new_s'

			cout << "artista: \"" << prod.get_artist() << "\"" << endl;
		}
		if(operation == 3){
			cout << "Modificar estilo. Atual: \"" << prod.get_style() << "\""
				<< endl << "Insira novo estilo. >>" ;
			
			getline(cin, new_s);	// Armazena o novo estilo em 'new_s'
			cin.ignore();

			prod.set_style(new_s);	// Modifica o estilo para o conteudo de 'new_s'

			cout << "estilo: \"" << prod.get_style() << "\"" << endl;			
		}
	}
}

template <>
void Grupo_Produto<Salgado>::modify_P( Salgado& prod )
{
	int operation = 1000;
	while( operation != 0)
	{
		string new_s;
		float new_f;
		char u;

		cout << "O que será modificado do CD ("<< prod.get_barcode() <<")?" << endl
			 << "(1) sódio;"
			 << "(2) glutem;"
			 << "(3) lactose;"
			 << "(0) Não modificar agora."
			 << endl << "Insira o numero. >> ";

		cin >> operation;

		// Operações
		if(operation == 1){

			cout << "Modificar sódio. Atual: \"" << prod.get_sodium() << "\""
				<< endl << "Insira novo sódio. >>" ;

			cin >> new_f;	// Armazena o novo sódio em 'new_'
			cin.ignore();

			prod.set_sodium(new_f);	// Modifica o sódio para o conteudo de 'new_'

			cout << "sódio: \"" << prod.get_sodium() << "\"" << endl;
		}
		if(operation == 2){
			cout << "Modificar glúten. Atual: \"" << (prod.get_gluten()?"":"NAO") << "contém\"."
				<< endl << "Alterar para \"" << (prod.get_gluten()?"NAO":"") << " contem\" ? (letra 'y' para 'sim' e letra 'n' para não). >>" ;
			
			cin >> u;	// Armazena o novo glúten em 'u'
			//cin.ignore();

			// Modifica o glúten
			if( u == 'y')	prod.set_gluten(!prod.get_gluten());

			cout << "glúten:  \"" << (prod.get_gluten()?"":"NAO") << "contém\"."<< endl;
		}
		if(operation == 3){
			cout << "Modificar lactose. Atual: \"" << (prod.get_lactose()?"":"NAO") << "contém\"."
				<< endl << "Alterar para \"" << (prod.get_lactose()?"NAO":"") << " contem\" ? (letra 'y' para 'sim' e letra 'n' para não). >>" ;
			
			cin >> u;	// Armazena o novo lactose em 'u'
			//cin.ignore();

			// Modifica o lactose
			if( u == 'y')	prod.set_lactose(!prod.get_lactose());

			cout << "lactose:  \"" << (prod.get_lactose()?"":"NAO") << "contém\"."<< endl;			
		}
	}
}

template < typename tipo_P>
void Grupo_Produto<tipo_P>::modify_P( tipo_P& prod )
{}

 
#endif