#include <iostream>
#include "./headers/libraries.h"

#include "TabelaHash.h"
#include "Deputado.h"


using namespace std;

int main()
{/*
    TabelaHash t(5);
    Deputado d1("MATHEUS", 32, "PT", 500);
    Deputado d2("MATHEUS", 32, "PT", 200);
    Deputado d3("MATHEUS", 32, "PT", 500);
    Deputado d4("JOSE", 20, "PSD",200);
    Deputado d5("JOSE", 20, "PSD",3000);
    Deputado d6("BRIAN", 14, "PT", 1000);
    Deputado d7("BRIAN", 14, "PT", 100);
    Deputado d8("BRIAN", 14, "PT", 1000);
    Deputado d9("DAVID", 23, "PSOL", 6000);

    t.insereDeputado(d1);
    t.insereDeputado(d2);
    t.insereDeputado(d3);
    t.insereDeputado(d4);
    t.insereDeputado(d5);
    t.insereDeputado(d6);
    t.insereDeputado(d7);
    t.insereDeputado(d8);
    t.insereDeputado(d9);

    t.inserePartido(d1);
    t.inserePartido(d2);
    t.inserePartido(d3);
    t.inserePartido(d4);
    t.inserePartido(d5);
    t.inserePartido(d6);
    t.inserePartido(d7);
    t.inserePartido(d8);
    t.inserePartido(d9);


    t.imprimirDeputados();
    t.imprimirPartidos();

    t.ordenacaoDeputado();
    t.ordenacaoPartido();

    t.imprimirDeputados();
    t.imprimirPartidos();

    t.N_maioresDeputados(2);
    t.N_menoresDeputados(2);

    t.N_maioresPartidos(2);
    t.N_menoresPartidos(2);

*/


     fstream deputados;
//     TabelaHash tabela(10000);
     int nLines, lineCount, randLine;
     string line, tableCell;

     deputados.open("deputies_dataset_tratado.csv", ios::in);

     if(!deputados.is_open())
     {
         cout << "Sem dataset." << endl;
         return 0;
     }

     nLines = 0;
     while(getline(deputados, line))
     {
         nLines++;
     };
     nLines--;

     TabelaHash tabela(nLines+100); //Tabela Hash!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

     Deputado* allDeputados = new Deputado[nLines];
     deputados.clear();
     deputados.seekg(0, ios::beg);
     getline(deputados, line);
     lineCount = 0;

     while(getline(deputados, tableCell, ';'))
     {

         allDeputados[lineCount].setBugged_date(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setReceipt_date(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setId(atoi(tableCell.c_str()));

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setPartido(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setEstado(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setNome_deputado(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setReceipt_social_security_number(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setReceipt_description(tableCell);

         getline(deputados, tableCell, ';');
         allDeputados[lineCount].setEstablishment_name(tableCell);

         getline(deputados, tableCell, '\n');
         allDeputados[lineCount].setValor(atoi(tableCell.c_str()));

         tabela.insereDeputado(allDeputados[lineCount]);
         tabela.inserePartido(allDeputados[lineCount]);

         lineCount++;
         cout << lineCount << endl;//"\n---------------" << "\n" << endl;

     }
     tabela.imprimirDeputados();
     tabela.imprimirPartidos();

     tabela.ordenacaoDeputado();
     tabela.ordenacaoPartido();

     tabela.imprimirDeputados();
     tabela.imprimirPartidos();

     int N;
     cout << "DIGITE UM VALOR PARA N :";
     cin >> N;
     cout << endl;

     tabela.N_maioresDeputados(N);
     tabela.N_menoresDeputados(N);

     tabela.N_maioresPartidos(N);
     tabela.N_menoresPartidos(N);

     deputados.close();
     //*/

    return 0;

}
