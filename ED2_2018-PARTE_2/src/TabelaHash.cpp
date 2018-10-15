#include <iostream>

#include <../headers/libraries.h>

#include "TabelaHash.h"
#include "Deputado.h"

using namespace std;


TabelaHash::TabelaHash(int tamanho)
{
    tam = tamanho;

    vet_deputado = new int[tam]();
    ocupado_deputado = new bool[tam];
    id_deputado = new int[tam]();
    nome_deputado = new string[tam];
    partido_deputado = new string[tam];
    valor_deputado = new int[tam]();

    valor_partido = new int[tam]();
    partido_partido = new string[tam];
    ocupado_partido = new bool[tam];
    vet_partido = new int[tam]();

    cont_deputado= -1;
    cont_partido= -1;

    for(int i= 0; i < tam; i++)
    {
        ocupado_deputado[i] = false;

        ocupado_partido[i] = false;
    }
}

TabelaHash::~TabelaHash()
{
    delete[]vet_deputado;
    delete[]ocupado_deputado;
    delete[]id_deputado;
    delete[]nome_deputado;
    delete[]partido_deputado;
    delete[]valor_deputado;

    delete[]valor_partido;
    delete[]partido_partido;
    delete[]ocupado_partido;
    delete[]vet_partido;
}

int TabelaHash::funcaoHash(int id)//FUNCAO HASH PARA OS GASTOS DOS DEPUTADOS. USA O ID DO DEPUTADO COMO CHAVE.
{
    return id%tam;
}

int TabelaHash::funcaoHashASCII(string part)//FUNCAO HASH PARA OS GASTOS DOS PARTIDOS. USA A SIGLA DO PARTIDO COMO CHAVE.
{
    int tamanho = strlen(part.c_str());
    int valor = 0;
    for(int i =0; i < tamanho ; i++)
    {
        valor = valor + part[i];
    }
    return valor % tam;
}

void TabelaHash::insereDeputado(Deputado d)// FUNCAO DE INSERCAO PARA O CALCULO DOS GASTOS DOS DEPUTADOS
{
    if(cont_deputado < tam)//TESTE PARA SABER SE A TABELA ESTA CHEIA;
    {
        int n = funcaoHash(d.getId());
        if(ocupado_deputado[n])
        {
            if(d.getId() == id_deputado[n])
            {
                valor_deputado[n]= valor_deputado[n]+ d.getValor();
            }
            else
            {

                while(ocupado_deputado[n])
                {
                    if(n<tam-1)
                    {
                        n++;
                    }
                    else
                    {
                        n=0;
                    }
                }
//                n = colisao();
//                while(ocupado_deputado[n])
//                {
//                    n = colisao();
//                }
                vet_deputado[n]= n;
                id_deputado[n]= d.getId();
                valor_deputado[n]= d.getValor();
                nome_deputado[n]= d.getNome_deputado();
                partido_deputado[n]= d.getPartido();
                ocupado_deputado[n]= true;
                cont_deputado++;

            }
        }
        else
        {
            vet_deputado[n]= n;
            id_deputado[n]= d.getId();
            valor_deputado[n]= d.getValor();
            nome_deputado[n]= d.getNome_deputado();
            partido_deputado[n]= d.getPartido();
            ocupado_deputado[n]= true;
            cont_deputado++;
        }
    }
    else
    {
        cout << "LISTA CHEIA!!" << endl;
        exit(1);
    }
}



void TabelaHash::inserePartido(Deputado d)// FUNCAO DE INSERCAO PARA O CALCULO DOS GASTOS DOS PARTIDOS
{
    if(cont_partido < tam)//TESTE PARA SABER SE A TABELA ESTA CHEIA;
    {
        int n = funcaoHashASCII(d.getPartido());
        if(ocupado_partido[n])
        {
            if(d.getPartido() == partido_partido[n])
            {
                valor_partido[n] = valor_partido[n] + d.getValor();
            }
            else
            {

                while(ocupado_partido[n])
                {
                    if(n<tam-1)
                    {
                        n++;
                    }
                    else
                    {
                        n=0;
                    }
                }
//                n = colisao();
//                while(ocupado_partido[n])
//                {
//                    n = colisao();
//                }
                vet_partido[n]= n;
                valor_partido[n]= d.getValor();
                partido_partido[n]= d.getPartido();
                ocupado_partido[n]= true;
                cont_partido++;

            }
        }
        else
        {
            vet_partido[n]= n;
            valor_partido[n]= d.getValor();
            partido_partido[n]= d.getPartido();
            ocupado_partido[n]= true;
            cont_partido++;
        }
    }
    else
    {
        cout << "LISTA CHEIA!!" << endl;
    }
}


void TabelaHash::ordenacaoDeputado()//COM BASE NO CENARIO 3 FOI ESCOLHIDO O COUNTING SORT, APLICANDO UMAS PEQUENAS MUDANÇAS
{
    int minRange, maxRange, range, i;
    minRange = minVec(valor_deputado, tam);
    maxRange = maxVec(valor_deputado, tam);
    range = maxRange - minRange + 1;

    int *countVec = new int[range]();
    int *output = new int[tam];

    for(i = 0; i < tam; i ++)
    {
        ++countVec[valor_deputado[i]-minRange];
    }

    for(i = 1; i < range; i++)
    {
        countVec[i] += countVec[i-1];
    }

    for (i = tam-1; i >= 0; i--)
    {
        output[countVec[valor_deputado[i]-minRange]-1] = valor_deputado[i];
        --countVec[valor_deputado[i]-minRange];
    }

//    string aux_nome[tam];
//    string aux_partido[tam];
//    int aux_vet[tam] {0};
//    bool aux_ocupacao[tam] {'false'};
//    int aux_id[tam] {0};

    string *aux_nome = new string[tam];
    string *aux_partido = new string[tam];
    int *aux_vet = new int[tam]();
    bool *aux_ocupacao = new bool[tam]();
    for(i = 0; i < tam; i++) {
        aux_ocupacao[i] = false;
    }
    int *aux_id = new int[tam]();

    for(i =0; i < tam ; i++)
    {
        int n = 0;
        while(output[i]!= valor_deputado[n])
        {
            n++;
        }
        aux_vet[i]= n;
        aux_nome[i]= nome_deputado[n];
        aux_partido[i]= partido_deputado[n];
        aux_ocupacao[i]= ocupado_deputado[n];
        aux_id[i]= id_deputado[n];
    }

    for(i = 0; i < tam; i++)
    {
        valor_deputado[i]= output[i];
        vet_deputado[i]= aux_vet[i];
        nome_deputado[i]= aux_nome[i];
        partido_deputado[i]= aux_partido[i];
        ocupado_deputado[i]= aux_ocupacao[i];
        id_deputado[i]= aux_id[i];
    }

    delete [] aux_nome;
    delete [] aux_partido;
    delete [] aux_vet;
    delete [] aux_ocupacao;
    delete [] aux_id;
    delete [] countVec;
    delete [] output;
}
void TabelaHash::ordenacaoPartido() //COM BASE NO CENARIO 3 FOI ESCOLHIDO O COUNTING SORT, APLICANDO UMAS PEQUENAS MUDANÇAS
{
    int minRange, maxRange, range, i;
    minRange = minVec(valor_partido, tam);
    maxRange = maxVec(valor_partido, tam);
    range = maxRange - minRange + 1;

    int *countVec = new int[range]();
    int *output = new int[tam];

    for(i = 0; i < tam; i ++)
    {
        ++countVec[valor_partido[i]-minRange];
    }

    for(i = 1; i < range; i++)
    {
        countVec[i] += countVec[i-1];
    }

    for (i = tam-1; i >= 0; i--)
    {
        output[countVec[valor_partido[i]-minRange]-1] = valor_partido[i];
        --countVec[valor_partido[i]-minRange];
    }

//    string aux_partido[tam];
//    int aux_vet[tam]= {0};
//    bool aux_ocupacao[tam] {'false'};
    string *aux_partido = new string[tam];
    int *aux_vet = new int[tam]();
    bool *aux_ocupacao = new bool[tam]();
    for(i = 0; i < tam; i++) {
        aux_ocupacao[i] = false;
    }


    for(i =0; i < tam ; i++)
    {
        int n = 0;
        while(output[i]!=valor_partido[n])
        {
            n++;
        }
        aux_vet[i]= n;
        aux_partido[i]= partido_partido[n];
        aux_ocupacao[i]= ocupado_partido[n];
    }

    for(i = 0; i < tam; i++)
    {
        valor_partido[i] = output[i];
        vet_partido[i] = aux_vet[i];
        partido_partido[i] = aux_partido[i];
        ocupado_partido[i]= aux_ocupacao[i];
    }

    delete [] aux_partido;
    delete [] aux_vet;
    delete [] aux_ocupacao;
    delete [] countVec;
    delete [] output;
}


int TabelaHash::colisao()// COM BASE NOS TESTES SO CENARIO 4
{
    //ESPERANDO OS TESTES DO BRIAN!
}


void TabelaHash::imprimirDeputados()//FUNCAO PARA A IMPRESSAO DOS GASTOS DOS DEPUTADOS
{
    cout << "POSICAO    ";
    cout <<" ID   ";
    cout << " NOME        ";
    cout << "      PARTIDO      ";
    cout << " GASTOS ";
    cout << endl;
    for(int i=0; i < tam; i++)
    {
        if(ocupado_deputado[i])
        {
            cout << vet_deputado[i] << "        ";
            cout << id_deputado[i] <<"   ";
            cout << nome_deputado[i] << "       ";
            cout << partido_deputado[i] <<"         ";
            cout << valor_deputado[i] << endl;
        }
    }
    cout << endl;
}

void TabelaHash::imprimirPartidos()//FUNCAO PARA A IMPRESSAO DOS GASTOS DOS PARTIDOS
{
    cout << "POSICAO  ";
    cout << "PARTIDO   ";
    cout << "GASTOS " << endl;
    for(int i = 0; i < tam; i++)
    {
        if(ocupado_partido[i])
        {
            cout << vet_partido[i] << "        ";
            cout << partido_partido[i] << "     ";
            cout << valor_partido[i] << endl ;
        }
    }
    cout << endl;
}


void TabelaHash::N_maioresDeputados(int N)
{
    cout <<"--> OS "<< N <<" CANDIDATOS QUE MAIS GASTARAM: " << endl;
    for(int i= tam-1; i >= tam - N; i--)
    {
        cout << "º " << nome_deputado[i] << " DO " << partido_deputado[i];
        cout  << " QUE GASTOU " << valor_deputado[i] << endl;
    }
    cout << endl;
}

void TabelaHash::N_maioresPartidos(int N)
{
    cout <<"--> OS "<< N <<" PARTIDOS QUE MAIS GASTARAM: " << endl;
    for(int i= tam-1; i >= tam - N; i--)
    {
        cout << "º " << partido_partido[i] << " QUE GASTOU " << valor_partido[i] << endl;
    }
    cout << endl;
}

void TabelaHash::N_menoresDeputados(int N)
{
    int cont = 0;
    while(!ocupado_deputado[cont])
    {
        cont++;
    }
    int a = cont + N;

    cout <<"--> OS "<< N <<" CANDIDATOS QUE MENOS GASTARAM: " << endl;
    for(int i= cont; i < a ; i++)
    {
        cout << "º " << nome_deputado[i] << " DO " << partido_deputado[i];
        cout  << " QUE GASTOU " << valor_deputado[i] << endl;
    }
    cout << endl;
}

void TabelaHash::N_menoresPartidos(int N)
{
    int cont = 0;
    while(!ocupado_partido[cont])
    {
        cont++;
    }
    int a = cont + N;

    cout <<"--> OS "<< N <<" PARTIDOS QUE MENOS GASTARAM: " <<endl;
    for(int i= cont; i < a ; i++)
    {
        cout << "º " << partido_partido[i]  << " QUE GASTOU " << valor_partido[i]<< endl;
    }
    cout << endl;
}





