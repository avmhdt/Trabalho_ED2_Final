#include "Deputado.h"

Deputado::Deputado()
{

}

Deputado::Deputado(string n, int i, string p, int v)
{
    nome = n;
    id= i;
    partido = p;
    valor = v;
}

Deputado::~Deputado()
{
}

void Deputado::setNome_deputado(string n)
{
    nome = n;
}

void Deputado::setId(int n)
{
    id = n;
}

void Deputado::setPartido(string n)
{
    partido = n;
}

void Deputado::setValor(int n)
{
    valor = n;
}

void Deputado::setBugged_date(string n)
{
    bugged_date = n;
}
void Deputado::setReceipt_date(string n)
{
    receipt_date = n;
}
void Deputado::setEstado(string n)
{
    estado = n;
}
void Deputado::setReceipt_social_security_number(string n)
{
    receipt_social_security_number = n;
}
void Deputado::setReceipt_description(string n)
{
    receipt_description = n;
}
void Deputado::setEstablishment_name(string n)
{
    establishment_name = n;
}


string Deputado::getNome_deputado()
{
    return nome;
}

string Deputado::getPartido()
{
    return partido;
}

int Deputado::getId()
{
    return id;
}

int Deputado::getValor()
{
    return valor;
}

string Deputado::getBugged_date()
{
    return bugged_date;
}
string Deputado::getReceipt_date()
{
    return receipt_date;
}
string Deputado::getEstado()
{
    return estado;
}
string Deputado::getReceipt_social_security_number()
{
    return receipt_social_security_number;
}
string Deputado::getReceipt_description()
{
    return receipt_description;
}
string Deputado::getEstablishment_name()
{
    return establishment_name;
}
