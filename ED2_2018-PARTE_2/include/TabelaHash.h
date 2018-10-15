#define TABELAHASH_H
#include "Deputado.h"

#include<math.h>


using namespace std;


class TabelaHash
{
public:
    TabelaHash(int tam);
    ~TabelaHash();

    int funcaoHash(int id);// HASH PARA OS GASTOS DOS DEPUTADOS.
    int funcaoHashASCII(string partido);// HASH PARA OS GASTOS DOS PARTIDOS.

    void insereDeputado(Deputado d);// INSERCAO PARA OS GASTOS DOS DEPUTADOS.
    void inserePartido(Deputado d);// INSERCAO PARA OS GASTOS DOS PARTIDOS.

    void imprimirDeputados();// IMPRESSAO DOS GASTOS DOS DEPUTADOS.
    void imprimirPartidos();// IMPRESSAO DOS GASTOS DOS PARTIDOS.

    void N_maioresDeputados(int n); //IMPRESSAO DOS N DEPUTADOS QUE MAIS GASTARAM
    void N_maioresPartidos(int n); //IMPRESSAO DOS N PARTIDOS QUE MAIS GASTARAM

    void N_menoresDeputados(int n); //IMPRESSAO DOS N DEPUTADOS QUE MENOS GASTARAM
    void N_menoresPartidos(int n); //IMPRESSAO DOS N DOS PARTIDOS QUE MENOS GASTARAM


    void ordenacaoPartido();//ORDENA OS GASTOS DOS PARTIDOS
    void ordenacaoDeputado();//ORDENA OS GASTOS DOS DEPUTADOS

    int colisao();

private:
    int tam;

    int* id_deputado; //LISTA DOS ID DOS DEPUTADOS
    bool* ocupado_deputado; //LISTA SE AS POSICOES ESTAO OCUPADAS
    string* nome_deputado; //LISTA COM OS NOMES DOS DEPUTADOS
    string* partido_deputado; // LISTA DOS PARTIDOS QUE OS DEPUTADOS FAZEM PARTE
    int* valor_deputado; // LISTA COM OS VALORES DOS GASTOS
    int* vet_deputado; // LISTA COM AS POSICOES OCUPADAS POR CADA DEPUTADO (POSICAO ENCONTRADA PELO HASH)
    int cont_deputado;

    int* vet_partido;// LISTA COM AS POSICOES OCUPADAS POR CADA PARTIDO (POSICAO ENCONTRADA PELO HASH ASCII)
    bool* ocupado_partido; //LISTA SE AS POSICOES ESTAO OCUPADAS
    int* valor_partido;// LISTA COM OS VALORES DOS GASTO
    string* partido_partido;// LISTA COM OS NOMES DOS PARTIDOS
    int cont_partido;

};

