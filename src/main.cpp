/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 02/06/2017
* @date --
* @sa --
*/
#include "header.h"
#include "myLista.h"
#include "Produto.h"
#include "Produto_tipos.h"
#include "Seccao.h"
#include "Bau.h"
#include "test.h"

/**
* @enum op_principal
* @brief Simula as opções do menu principal que interage com o usuário do sistema
*/
enum op_principal {consulta = 0, cadastro = 1, venda};

/**
* @enum op_consulta
* @brief Simula as opções do menu de consulta/pesquisar por produto
*/
enum op_consulta {codigo=0, tipo=1};

// Variáveis Globais

Bau loja;	/**< Produtos da loja */
Bau cliente;	/**< Produtos que o cliente deseja comprar da loja */

// Funções que auxiliam na interação do usuário com o sistema.

void menu_principal(Bau& m_loja, Bau& m_venda)
void menu_consulta(Bau& alvo);
int menu_cadastro(Bau& alvo);
int menu_venda(Bau &loja, Bau& venda);

// Funções que auxiliam o menu

int get_operation(int beginning, int end);



/**
* @brief Função principal
*/
int main(int argc, char const *argv[])
{
	//test1();
	//test_lista_2();
	//test2_Grupo_1();
	//test2_Grupo_modify();	?
	//test3_bau();

	cout << "Bem vindo ao sistema de admnistração de produtos da QLeveTudo." << endl
		<< 	"Carregando Bau da loja...";

	loja.load();	// Carregando produtos da loja do arquivo "data/my_store.csv"

	cout << "Pronto. Total de Produto x unidades cadastrados: CD = " << loja.s_cds.size_P() << ", Salgado = " << loja.s_sal.size_P() << endl
		<< "====================================================" << endl;

	menu_principal(loja, cliente);	// Interação com o usuário

	// Finalizando o programa

	cout << "Salvando informações do estoque da loja...";

	loja.save();	// Salva os produtos do Bau da loja em "data/my_store.csv" (sobrescreve)

	cout << "Pronto.";

	cout << "Saindo. . ." << endl;
	return 0;
}

/**
* @brief Permite o usuário prosseguir apenas caso tenha digitado um interio que pertença a ['smallest';'greatest']
* @param smallest menor número permitido
* @param greatest maior número permitido
* @return operação válida (dentro do intervalo [fechado) passado)
*/
int get_operation(int smallest, int greatest);
{
	int operation;

	cin >> operation;
	cin.ignore();

	while (operation < smallest or greatest < operation )
	{
		cout << "Digite um número (operação) válido. >>";
		cin >> operation;
		cin.ignore();
	}

	return operation;
}

/**
* @brief Menu de opções principal
* @param m_loja Referência para Bau da loja
* @param m_loja Referência para Bau de venda
*/
void menu_principal(Bau& m_loja, Bau& m_venda)
{
	op_principal op;

	do{
		cout << "Operações principais:" << endl
			<< "1) Consultar items na loja;" << endl
			<< "2) Cadastrar items na loja;" << endl
			<< "3) Iniciar Compra;" << endl;
			<< "4) Finalizar o programa;" << endl;
			<< "Digite o número da operação a ser realizada. >>" << endl;
		
		op = get_operation(1,4);	// Solicita do usuário a operação

		if( op == op_principal::consulta )
		{
			sub_consulta(loja, venda, op_principal::consulta );
		}
		else if( op == op_principal::cadastro )
		{

		}
		else if( op == op_principal::venda )
		{

		}

	}while( op != 4 );
}

/**
* @brief Menu de opções de Modificação de item de item
* @param target Bau que será consultado
* @param aux Bau que será consultado para movimentação de Produtos se necessário
* @param my_case 'consulta' para consulta do Bau da loja e 'venda' consulta do Bau do cliente
*/
template <typename T>
void sub_encontrou_produto( typename myLista<T>::iterator& it, Bau& target, Bau& aux, op_principal my_case )
{
	// variaveis

	bool _venda = (my_case == op_principal::venda);
	int op;
	string a_barcode;

	// prompt

	cout << "O que você deseja fazer com este "<< (*it).get_type() <<":" << endl
		<< "1) modificar;" << endl
		<< "2) remover;" << endl;
	if(_venda) cout << "3) cadastrar;" << endl;
	cout << "0) nada;" << endl;
		<< "Digite o número da operação a ser realizada. >>" << endl;

	if(_venda)	op = get_operation(0,3);
	else op = get_operation(0,2);

	// operações

	if(op == 1)	// Modificar
	{
		(*it).change();
	}

	else if(op == 2 and _venda)	// Remover da venda
	{
		if ( (*it).get_type() == "CD" ) typename myLista<CD> aux_it = aux.search_CD((*it).get_barcode());
		if ( (*it).get_type() == "Salgado" ) typename myLista<Salgado> aux_it = aux.search_Salgado((*it).get_barcode());

		(*aux_it).set_quantity( (*aux_it).get_quantity() + (*it).get_quantity() ) // Repõe o Produto no estoque da loja

		if ( (*it).get_type() == "CD" ) target.unregister_CD(it);		
		if ( (*it).get_type() == "Salgado" ) target.unregister_Salgado(it);
	}

	else if(op == 2 and not(_venda))	// Remover da loga
	{
		if ( (*it).get_type() == "CD" ) target.unregister_CD(it);		
		if ( (*it).get_type() == "Salgado" ) target.unregister_Salgado(it);
	}

	return op;
}

/**
* @brief Menu de opções de Consulta de item
* @param target Bau que será consultado
* @param aux Bau que será consultado para movimentação de Produtos se necessário
* @param my_case Caso da consulta ('consulta' para consulta do Bau da loja e 'venda' consulta do Bau do cliente)
*/
void sub_consulta(Bau& target, Bau& aux, op_principal my_case )
{
	// variaveis

	int op;
	string a_barcode;

	// prompt

	cout << "Opções de consulta:"
		<< "1) por código de barras;" << endl
		<< "2) por tipo de item;" << endl;
		<< "3) voltar ao menu principal" << endl;
		<< "Digite o número da operação a ser realizada. >>" << endl;
	op = get_operation(1,3);

	// operações

	if(op == op_consulta::codigo)
	{
		cout << "Insira o código de barras. >>"
		cin >> a_barcode;
		cin.ignore();

		cout << "Procurando por" << a_barcode << "...";

		// Criando iterators para pesquisar em cada seção pelo código de barra...
		myLista<CD>::iterator      itc = origem.s_cds.search_P(a_barcode);	// 
		myLista<Salgado>::iterator its = origem.s_sal.search_P(a_barcode);

		if(itc != origem.s_cds.l_produtos.end())	// Se encontrou em CD
		{
			cout << "Em CD:" << endl << (*it) << endl;
		}
		else
			cout << "Produto não existe em CD" << endl;

		if(its != origem.s_sal.l_produtos.end())
			cout << "Encontrou em Salgado." << endl << (*it) << endl;
		else
			cout << "Produto não existe em Salgado" << endl;
	}

	if(op == 2)
	{

		cout << "Insira o Tipo (disponíveis \"CD\" e \"Salgado\"). >>"
		cin >> a_barcode;
		cin.ignore();

		if(a_barcode == "CD")
		{
			cout << "Imprimindo CDs:" << endl
			Bau.s_cds.print_P(cout);
			cout << endl << "--Fim--" << endl;
		}
		if else(a_barcode == "Salgado")
		{
			cout << "Imprimindo Salgado:" << endl
			Bau.s_sal.print_P(cout);
			cout << endl << "--Fim--" << endl;
		}
	}

	return op;
}

/**
* @brief Menu de opções de Cadastro de Item
* @param alvo Bau onde o iterm será cadastrado
* @return opção selecionada
*/
int sub_cadastro(Bau& target, Bau& aux, op_principal my_case)
{
	if()
	string new_item;

	//if( )
	cout << "Insira o tipo de produto a ser cadastrado(Salgado ou CD). >>";
	
	cin >> new_item;
	cin.ignore();	

	if(new_item == "CD")
	{
		CD cd;
		cd.change();
		origem.register_CD(cd);
	}
	if else(new_item == "Salgado")
	{
		Salgado sal;
		sal.change();
		origem.register_Salgado(sal);
	}

	return op;
}

/**
* @brief Menu de Realização de venda
* @return opção selecionada
*/
int sub_venda(Bau &loja, Bau& venda)
{
	int op;
	cout << "Compra:"
		<< "1) Consultar items para adicionar a venda;" << endl
		<< "2) Adicionar um item a venda (por código de barra);" << endl
		//<< "3) Remover item da venda;" << endl;
		<< "4) Finalizar venda" << endl;
		<< "5) cancelar" << endl;
		<< "Digite o número da operação a ser realizada. >>" << endl;
	cin >> op;
	cin.ignore();

	if(op == 1)
		sub_consulta(loja);
	else if(op == 2)
	{
		string a_barcode;

		cout << "Insira o código de barras. >>"
		cin >> a_barcode;
		cin.ignore();

		CD cd;
		cd.set_barcode(a_barcode);
		Salgado sg;
		sg.set_barcode(a_barcode);
		
		cout << "Procurando por" << a_barcode << "...";
		myLista<CD>::iterator itc = loja.s_cds.search_P(cd);
		myLista<Salgado>::iterator its = loja.s_sal.search_P(sg);

		if(itc == origem.s_cds.l_produtos.end())
			cout << "Produto não existe em CD" << endl;
		else
		{
			cout << "Encontrou em CD." << endl << (*itc) << endl;
			cout << "registrando na venda... "<< endl;
			venda.register_CD((*itc));
			loja.s_cds.unregister_P((*itc));
		}

		if(its == origem.s_sal.l_produtos.end())
			cout << "Produto não existe em Salgado" << endl;
		else
		{
			cout << "Encontrou em Salgado." << endl << (*its) << endl;
			cout << "registrando na venda... "<< endl;
			venda.register_Salgado((*its));
			loja.s_sal.unregister_P((*its));
		}
	}
	else if(op == 5)
	{
		loja.absorb_B(venda);
		op == 4;
	}

	if(op == 4)
	{
		if(venda.is_empty() == false)
			venda.print(cout);
	}

	return op;
}