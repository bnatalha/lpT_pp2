#include <iostream>
#include <string>


using namespace std;

class Base
{
protected:
	int m_codigo;
public:
	Base(int vCodigo);
	virtual void imprime()=0;
	virtual void foo(){}
	virtual void bar(){}
};

Base::Base(int vCodigo):
	m_codigo(vCodigo){}

class TipoA: public Base
{
	//friend class Base;
private:
	string m_prefixo;
public:
	TipoA(int vCodigo, string vPrefixo);
	void imprime();
	void foo(){ cout << "foo" << m_prefixo << endl;}
};

TipoA::TipoA(int vCodigo, string vPrefixo):
	Base(vCodigo),m_prefixo(vPrefixo){}

void
TipoA::imprime()
{
	cout << m_prefixo << m_codigo << endl;
}

class TipoB: public Base
{
	//friend class Base;
private:
	string m_sufixo;

public:
	TipoB(int vCodigo, string vSufixo);
	void imprime();
	void bar(){ cout << "bar" << m_sufixo << endl;}
};

TipoB::TipoB(int vCodigo, string vSufixo):
	Base(vCodigo),m_sufixo(vSufixo){}

void
TipoB::imprime()
{
	cout << m_codigo << m_sufixo << endl;
}