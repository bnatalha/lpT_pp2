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
* @class Seccao
* @brief Classe que armazenará uma lista de um tipo de produto, 
* @tparam Um tipo de produto (CD, DVD, Fruta, etc.)
*/
template <typename T>
class Seccao
{
	friend class Bau;
	
	protected:
		myLista<T> l_produtos;	/**< Lista de 'T' */

	public:

		/**
		* @brief Constrói um objeto Seccao vazio
		*/
		Seccao(){}

		/**
		* @brief Seccao criado a partir de outro grupo de produtos (cópia)
		* @param original Seccao a ser copiado
		*/
		Seccao( const Seccao<T> &origem)
			: l_produtos(origem.l_produtos)
		{}

		/**
		* @brief Seccao criado a partir de outro grupo de produtos (cópia)
		* @param original Seccao a ser copiado
		*/
		~Seccao(){}

		// Métodos
		// Getters
		int size_P();	/**< Retorna a quantidade total de produtos (contando com as unidade) neste grupo */
		float price_P();	/**< Retorna a soma dos preços de todos os produtos (contando com as unidade) neste grupo */
		void print_P( std::ostream& out );	/**< Imprime uma lista com todos os produtos do grupo */ 
		void print_P( std::ostream& out, typename myLista<T>::iterator& it );	/**< Imprime informações sobre um produto */ 
		typename myLista<T>::iterator search_P( const string& m_barcode ); /**< Procura Por um produto cadastrado que tenha seu código de barras igual a 'm_barcode' */
		// procurar por fornecedor (string)
		
		// Setters
		void register_P( T& prod );	/**< Cadastra um produto na lista (se ele ja estiver cadastrado, aumenta a sua quantidade em um) */
		void unregister_P( typename myLista<T>::iterator& it ); /**< Descadastra um produto */
		void change_qnt_P( typename myLista<T>::iterator& it, const int x ); /**< Remove ou acrescenta uma quantidade de unidades de um certo produto cadastrado*/

		void modify_P( T& prod );
		void save_csv_P(std::ofstream& out);	/**< Salva os produtos desta lista em um arquivo linkado a 'out' */
			

		// Sobrecarga de operadores
		bool operator== (const Seccao<T> &g_direita);	/**< Compara um grupo com outro pra ver se são iguais (possuem a mesma lista de produtos)*/
		Seccao<T>& operator= (const Seccao<T> &g_direita);	/**< Atribui a lista de um grupo para este */
		//friend &istream operator>> (istream &in, const Produto x);	/**< Sobrecarga do >> */


		typedef typename myLista<T>::iterator it_P;
};

// ============ Implementação ============

template <typename T>
int Seccao<T>::size_P()
{
	int sum = 0;	// Vai armazenar a soma total de unidades de todos os produtos do grupo

	for( auto &e: l_produtos )
		sum += e.get_quantity() ;	// Soma as quantidades

	return sum;
}

template <typename T>
float Seccao<T>::price_P()
{
	float sum = 0;	// Vai armazenar a soma total de preços de todos os produtos do grupo

	for( auto &e: l_produtos )
		sum = sum + e ;	// Soma os preços

	return sum;
}

/**
* @param it Iterator para o produto
* @param x quantidade a ser acrescentada ou removida ( se for negativo)
*/
template <typename T>
void Seccao<T>::change_qnt_P( typename myLista<T>::iterator& it, const int x )
{
	(*it).set_quantity( x );

//	cout << "Nova quantidade: " << (*it).get_quantity() << endl;
}

/*
* @param prod Produto utilizado na função
*/
template <typename T>
void Seccao<T>::register_P( T& prod )
{
	typename myLista<T>::iterator it = search_P(prod.get_barcode());	// Iterator para o produto
	int qtd;	// Quantidade a ser registrada.

	if (it != l_produtos.end())	// Se o produto ja foi registrado
		cout << " Produto ja tinha sido registrado." << endl;
	else	// Se o produto ainda não foi registrado
	{
		l_produtos.push_sorted(prod);	// Regista o produto.
		cout << " Produto foi registrado.";
	
		it = search_P(prod.get_barcode());
	
		cout << "Diga quantas unidades deste produto serão registradas (ex.: 9). >>";
		cin >> qtd;

		change_qnt_P(it, qtd);	// Muda a quantidade

		cout << "Visualizando produto:" << endl;
		print_P(cout, it);
		cout << endl;
	}
}

/**
* @param m_barcode código de barras do Produto procurado
* @return Interator pra localização do Produto procurado na lista. Se o iterator for igual ao fim da lista, o produto buscado não foi achado.
*/
template <typename T>
typename myLista<T>::iterator Seccao<T>::search_P( const string& m_barcode )
{
	typename myLista<T>::iterator it = l_produtos.begin();	// Cria um iterator pro inícia da 'l_produtos'
	
	for( ; it != l_produtos.end() ; it++ )
		if( (*it).get_barcode() == m_barcode ) break;	// encontrou*

	return it;	// *se it == l_produtos.end(), não encontrou.
}

/**
* @param it Iterator para o produto
*/
template <typename T>
void Seccao<T>::unregister_P( typename myLista<T>::iterator& it )
{
	l_produtos.remove( (*it) );
}

/**
* @param out ostream onde vai ser impressa a função
*/
template <typename T>
void Seccao<T>::print_P( std::ostream& out )
{
	int i = 0;	// índice

	out << "LISTANDO PRODUTOS: {" << endl;
	for (auto &e: l_produtos)
	{
		cout << "(" << i++ << "):";
		e.print_it(out);
		cout << endl;
	}
	out << "}" << endl;
}

/**
* @param out ostream onde vai ser impressa a função
* @param it Iterator para o produto
*/
template <typename T>
void Seccao<T>::print_P( std::ostream& out, typename myLista<T>::iterator& it )
{
	(*it).print_it(out);
}

/**
* @param g_direita grupo a ser comparado
*/
template <typename T>
bool Seccao<T>::operator== (const Seccao<T> &g_direita)
{
	return (l_produtos == g_direita.l_produtos);
}

/**
* @param g_direita grupo a ser copiado
*/
template <typename T>
Seccao<T>& Seccao<T>::operator= (const Seccao<T> &g_direita)
{
	l_produtos = g_direita.l_produtos;

	return *this;
}

template <typename T>
void Seccao<T>::save_csv_P(std::ofstream& out)
{
	for ( auto &p : l_produtos )	p.save_csv_it(out);
}

// MODIFY ========================

template <>
void Seccao<CD>::modify_P( CD& prod )
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
void Seccao<Salgado>::modify_P( Salgado& prod )
{
	int operation = 1000;
	while( operation != 0)
	{
		string new_s;
		float new_f;
		char u;

		cout << "O que será modificado do Salgado ("<< prod.get_barcode() <<")?" << endl
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

template < typename T>
void Seccao<T>::modify_P( T& prod )
{}

#include "Bau.h"

#endif