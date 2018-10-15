#include <iostream>

#ifndef DEPUTADO_H
#define DEPUTADO_H
using namespace std;


class Deputado
{
public:
    Deputado();
    Deputado(string nome, int id, string partido, int valor);
    ~Deputado();

    void setNome_deputado(string nome);
    void setPartido(string partido);
    void setId(int id);
    void setValor(int valor);
    void setBugged_date(string bugged_date);
    void setReceipt_date(string receipt_date);
    void setEstado(string estado);
    void setReceipt_social_security_number(string receipt_social_security_number);
    void setReceipt_description(string receipt_description);
    void setEstablishment_name(string establishment_name);


    string getNome_deputado();
    string getPartido();
    int getId();
    int getValor();
    string getBugged_date();
    string getReceipt_date();
    string getEstado();
    string getReceipt_social_security_number();
    string getReceipt_description();
    string getEstablishment_name();

private:
    string nome;
    string partido;
    int id;
    int valor;
    string bugged_date;
    string  receipt_date;
    string estado;
    string receipt_social_security_number;
    string receipt_description;
    string establishment_name;

};

#endif // DEPUTADO_H
