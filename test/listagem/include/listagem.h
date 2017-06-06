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
};

Base::Base(int vCodigo):
	m_codigo(vCodigo){}

class TipoA: public Base
{
private:
	string m_prefixo;
public:
	TipoA(int vCodigo, string vPrefixo);
	void imprime();
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
private:
	string m_sufixo;
public:
	TipoB(int vCodigo, string vSufixo);
	void imprime();
};

TipoB::TipoB(int vCodigo, string vSufixo):
	Base(vCodigo),m_sufixo(vSufixo){}

void
TipoB::imprime()
{
	cout << m_codigo << m_sufixo << endl;
}


