#include <iostream>
#include "../headers/libraries.h"
#include "sys/types.h"
#include "sys/sysinfo.h"

Sondagem_Linear::Sondagem_Linear(int tam)
{
    tamanho = tam;
    vetor = new int[tam];
    for(int i=0;i<tam;++i)
    {
        vetor[i]=0;
    }
}

Sondagem_Linear::~Sondagem_Linear()
{
    delete []vetor;
}

int Sondagem_Linear::func_sond_linear(int valor)
{
    return valor%tamanho;
}

void Sondagem_Linear::insere_sond_linear(int valor)
{
    int f = func_sond_linear(valor);
    comparacoes+=1;
    if(vetor==0)
    {
        vetor[f] = valor;
    }
    else
    {
        comparacoes+=1;
        while(vetor[f]!=0)
        {
            if(f<tamanho-1)
            {
                f++;
            }
            else
            {
                f=0;
            }
        }
        vetor[f]=valor;
    }
}

void Sondagem_Linear::imprimir()
{
    for(int i=0;i<tamanho;++i)
    {
        cout << "Indice " << i << ": " << vetor[i] << endl;
    }
}

int Sondagem_Linear::calculaMemoria()
{
    struct sysinfo memInfo;
    sysinfo (&memInfo);
    long long virtualMemUsed = memInfo.totalram - memInfo.freeram;
    virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
    virtualMemUsed *= memInfo.mem_unit;
    long long physMemUsed = memInfo.totalram - memInfo.freeram;
    physMemUsed *= memInfo.mem_unit;
    return (virtualMemUsed + physMemUsed);
}
