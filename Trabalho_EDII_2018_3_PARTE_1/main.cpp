#include "headers/libraries.h"

///********************************
/// PARTE 1: ANÁLISE DOS ALGORITMOS


int main() {

    int CENARIO;
    fstream entrada, saida, deputados, saidaCenario1, saidaCenario2, saidaCenario3, saidaCenario4;

    entrada.open("entrada.txt", ios::in | ios::binary);

    if(!entrada.is_open()) {
        cout << "Sem entrada." << endl;
        return 0;
    }

    int N, nLines, i, j, k, v, lineCount, randLine;//, comp, copias;
    //int *conjuntoIds, *conjuntoIdsAux,
    unsigned int *comp, *copias;
    string line, tableCell, filename;
    //char aspas;
    GastoDeputado *allDeputados;//, *conjuntoDeputados;
    clock_t startTime, endTime;
    double cpuTime, minTime, auxTime[5] = {0};

    unsigned int auxComp[5] = {0}, auxCopias[5] = {0}, auxMemoria[5] = {0};

    entrada >> N;

    int *NValues, *seedVec;
    NValues = new int[N];
    seedVec = new int[5];

    comp = new unsigned int();
    copias = new unsigned int();

    for(j = 0; j < N; j++) {
        entrada >> NValues[j];
    }

    entrada.close();

    //Ler deputados:

    deputados.open("deputies_dataset_tratado.csv", ios::in);

    if(!deputados.is_open()) {
        cout << "Sem dataset." << endl;
        delete [] NValues;
        delete [] seedVec;
        delete [] comp;
        delete [] copias;
        return 0;
    }

    cout << "QUAL CENARIO? ";
    cin >> CENARIO;
    if(CENARIO != 1 && CENARIO != 2 && CENARIO != 3 && CENARIO != 4) {
        cout << "CENARIO INVALIDO." << endl;
        return 0;
    }

    nLines = 0;

    while(getline(deputados, line)) { //conta o numero de linhas do arquivo
        nLines++;
    }; nLines--; // desconta o cabeçalho

    allDeputados = new GastoDeputado[nLines];

    deputados.clear();              // clearing e
    deputados.seekg(0, ios::beg);   // voltando ao inicio do arquivo

    getline(deputados, line);       // pulando o cabeçalho
    cout << line << endl;
    lineCount = 0;
    while(getline(deputados, tableCell, ';')) {
        allDeputados[lineCount].setBuggedDate(tableCell);
//        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setReceiptDate(tableCell);
//        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setDeputyId(stoi(tableCell));
        //cout << "stoi 1" << endl;
//        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setPoliticalParty(tableCell);
//        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setStateCode(tableCell);
//        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setDeputyName(tableCell);
//        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setReceiptSocialSecurityNumber(tableCell);
//        cout << tableCell << ";";


        /*
        deputados.get(aspas);
        if(aspas == '"') {
            getline(deputados, tableCell, '"');
            allDeputados[lineCount].setReceiptDescription(string(1, aspas) + tableCell);
            cout << tableCell << ",";

            deputados.get(aspas);
            if(aspas != ';') {
                cout << "Erro de Leitura. Field: Receipt Description" << endl;
                return 0;
            }
        } else {
            getline(deputados, tableCell, ';');
            allDeputados[lineCount].setReceiptDescription(string(1, aspas) + tableCell);
            cout << tableCell << ",";
        }
        */

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setReceiptDescription(tableCell);
//        cout << tableCell << ";";


        /*
        deputados.get(aspas);
        if(aspas == '"') {
            getline(deputados, tableCell, '"');
            allDeputados[lineCount].setEstablishmentName(string(1, aspas) + tableCell);

            deputados.get(aspas);
            while(aspas == '"') {
                getline(deputados, tableCell, '"');
                allDeputados[lineCount].setEstablishmentName(allDeputados[lineCount].getEstablishmentName() + tableCell);
                deputados.get(aspas);
            }

            cout << tableCell << ",";
            if(aspas != ';') {
                cout << "Erro de Leitura. Field: Establishment Name" << endl;
                return 0;
            }
        } else {
            getline(deputados, tableCell, ';');
            allDeputados[lineCount].setEstablishmentName(string(1, aspas) + tableCell);
            cout << tableCell << ",";
        }
        */

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setEstablishmentName(tableCell);
//        cout << tableCell << ";";

        getline(deputados, tableCell, '\n');
        allDeputados[lineCount].setReceiptValue(stoi(tableCell));
        //cout << "stoi 2" << endl;
        /*cout << tableCell << endl;


        cout << "\n\n" << "lido: " << endl;
        cout << allDeputados[lineCount].getBuggedDate() << ";";
        cout << allDeputados[lineCount].getReceiptDate() << ";";
        cout << allDeputados[lineCount].getDeputyId() << ";";
        cout << allDeputados[lineCount].getPoliticalParty() << ";";
        cout << allDeputados[lineCount].getStateCode() << ";";
        cout << allDeputados[lineCount].getDeputyName() << ";";
        cout << allDeputados[lineCount].getReceiptSocialSecurityNumber() << ";";
        cout << allDeputados[lineCount].getReceiptDescription() << ";";
        cout << allDeputados[lineCount].getEstablishmentName() << ";";
        cout << allDeputados[lineCount].getReceiptValue() << endl;
        */

        lineCount++;
//        cout << "\n" << lineCount << "\n---------------" << "\n\n" << endl;*/
        cout << lineCount << endl;
    }

    deputados.close();


    /*
    Pseudocode:

    aloca(seedVec[5]); ~

    srand(time(NULL));  **
    for(i = 0; i < 5; i++) {
        seedVec[i] <- randNum(-inf,+inf);
    }

    TIME tempoOrd;
    int comparacoes, copias;

    // 1. Gerar 5 sementes (**)       --done
    // 2. Para cada semente, criar um arquivo de saida. srand(seedVec[k])    --done
    // 3. Nesse arquivo de saida, para cada valor de N (NValues[i], i = 1,...,N), gerar um conjunto com NValues[i] elementos
    //      a partir da tabela dos deputados. Isso será feito da seguinte maneira:
    //  3.1. Para j = 1:NValues[i], conjunto[j] = deputados[linha randNum(1, numero de linhas da tabela)]. conjunto é um conjunto da classe GastoDeputado, de tamanho NValues[i]
    //  3.2. fim para
    // 4. Ordena o conjunto, com cada algoritmo pedido, retornando o conjunto ordenado, o tempo gasto, o numero de comparacoes, e o numero de copias.
    // 5. Contabiliza as estatisicas de desempenho
    // 6. Escreve no arquivo de saida: N = NValues[i], algoritmo 1: tempo, comparacoes, copias; algoritmo 2: tempo, comparacoes, copias; ...
    // 7. fim para cada valor de N
    // 8. fim para cada seed


    for(i = 0; i < N; i++) { //para cada valor de N lido da entrada, gerar 5 conjuntos aleatorios, cada um com uma semente diferente
        1.Gera cada um dos conjuntos de elementos
            - para um valor fixo de N (NValues[i]), gera 5 conjuntos com NValues[i] elementos cada


        2. ordena
        3. contabiliza estatísticas de desempenho
        4. Armazena estatísticas de desempenho em arquivo de saída (saida.txt)

    }
    */


    //srand(time(NULL));
    srand(1);
    for(i = 0; i < 5; i++) {
        seedVec[i] = randomInt(0, pow(2, 31));
    }

    double time1[5][N], time2[5][N], time3[5][N], time4[5][N], time5[5][N]; // tamanho No de seeds vs numero de valores N
    unsigned int comp1[5][N], comp2[5][N], comp3[5][N], comp4[5][N], comp5[5][N];
    unsigned int copias1[5][N], copias2[5][N], copias3[5][N], copias4[5][N], copias5[5][N];
    unsigned int memoria1[5][N], memoria2[5][N], memoria3[5][N], memoria4[5][N], memoria5[5][N];

    for(i = 0; i < 5; i++) {

        filename = "./Parte 1/Cenario " + std::to_string(CENARIO) + "/saida_seed_" + std::to_string(seedVec[i]) + ".txt";

        saida.open(filename, ios::out | ios::binary); //arquivo de saída da seed

        //saida << "/* N\n" << " * Ordenado Deputados(0/1)\n" << " * Tempo Deputados\n" << " * Comparações Deputados\n" << " * copias Deputados\n";
        //saida << " * Ordenado Inteiros(0/1)\n" << " * Tempo Inteiros\n" << " * Comparações Inteiros\n" << " * copias Inteiros\n" << "*/\n" << endl;

        srand(seedVec[i]); //i-ésima seed, para o i-ésimo conjunto, i = 1,...,5
        for(j = 0; j < N; j++) { // para cada valor de N

            saida << "*************\n" << NValues[j] << endl;

            GastoDeputado *conjuntoDeputados = new GastoDeputado[NValues[j]];
            int *conjuntoIds = new int[NValues[j]];
            int *conjuntoIdsAux = new int[NValues[j]];


            for(k = 0; k < NValues[j]; k++) { // para 1:Valor atual de N, adicionar um deputado aleatorio ao conjunto
                randLine = randomInt(0, nLines); // gera numero aleatorio randLin
                conjuntoDeputados[k] = allDeputados[randLine]; // armazena a randLine linha no vetor de deputados
                conjuntoIds[k] = allDeputados[randLine].getDeputyId(); // armazena o deputyId linha no vetor de inteiros
            }

            // ordena o conjunto

            switch(CENARIO) {

                case 1:

                    for(k = 0; k < NValues[j]; k++) {
                        conjuntoIdsAux[k] = conjuntoIds[k];
                    }

                    *comp = 0; *copias = 0; //numero de comparacoes entre chaves, e de copias de chaves

                    startTime = clock();

                    cout << "\n quickSort deputados\n" << endl;
                    quickSortDeputyId(&(conjuntoDeputados[0]), &(conjuntoDeputados[NValues[j]-1]), comp, copias);

                    endTime = clock();
                    cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                    //cout << "\n\n cpuTimeDeputados = " << cpuTime << "\n\n" << endl;
                    saida << ordenado(&(conjuntoDeputados[0]), NValues[j]) << endl;
                    saida << cpuTime << endl;
                    saida << *comp << endl;
                    saida << *copias << endl;

                    time1[i][j] = cpuTime;
                    comp1[i][j] = *comp;
                    copias1[i][j] = *copias;

                    for(k = 0; k < NValues[j]; k++) {
                        cout << conjuntoIds[k] << "   conjuntoIds pre" << endl;
                    }

                    *comp = 0; *copias = 0;

                    startTime = clock();

                    cout << "\n quickSort inteiros\n" << endl;
                    quickSort(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), comp, copias);

                    endTime = clock();
                    cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                    //cout << "\n\n cpuTimeInteiros = " << cpuTime << "\n\n" << endl;
                    saida << ordenado(&(conjuntoIdsAux[0]), NValues[j]) << endl;
                    saida << cpuTime << endl;
                    saida << *comp << endl;
                    saida << *copias << endl;
                    saida << "\n" << endl;

                    time2[i][j] = cpuTime;
                    comp2[i][j] = *comp;
                    copias2[i][j] = *copias;

                    for(k = 0; k < NValues[j]; k++) {
                        cout << conjuntoIdsAux[k] << "   conjuntoIds ord" << endl;
                    }

                    break;


                case 2:

                    for(int l = 0; l < 5; l++) {
                        for(k = 0; k < NValues[j]; k++) {
                            conjuntoIdsAux[k] = conjuntoIds[k];
                        }

                        /*for(k = 0; k < NValues[j]; k++) {
                            cout << conjuntoIdsAux[k] << "   conjuntoIdsAux pre" << endl;
                        }*/


                        switch(l) {
                            case 0:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n quickSort\n" << endl;
                                quickSort(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time1[i][j] = cpuTime;
                                comp1[i][j] = *comp;
                                copias1[i][j] = *copias;
                                break;

                            case 1:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n quickSortMediana3\n" << endl;
                                quickSortMedian(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), 3, comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time2[i][j] = cpuTime;
                                comp2[i][j] = *comp;
                                copias2[i][j] = *copias;
                                break;

                            case 2:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n quickSortMediana5\n" << endl;
                                quickSortMedian(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), 5, comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time3[i][j] = cpuTime;
                                comp3[i][j] = *comp;
                                copias3[i][j] = *copias;
                                break;

                            case 3:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n quickSortInsertion m = 10\n" << endl;
                                quickSortInsertion(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), 10, comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time4[i][j] = cpuTime;
                                comp4[i][j] = *comp;
                                copias4[i][j] = *copias;
                                break;

                            case 4:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n quickSortInsertion m = 100\n" << endl;
                                quickSortInsertion(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), 100, comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time5[i][j] = cpuTime;
                                comp5[i][j] = *comp;
                                copias5[i][j] = *copias;
                                break;
                        }

                        saida << ordenado(&(conjuntoIdsAux[0]), NValues[j]) << endl;
                        saida << cpuTime << endl;
                        saida << *comp << endl;
                        saida << *copias << endl;
                        saida << "\n" << endl;

                        cout << "l = " << l << endl << endl;

                        /*for(k = 0; k < NValues[j]; k++) {
                            cout << conjuntoIdsAux[k] << "   conjuntoIdsAux ord" << endl;
                        }*/

                    }

                    break;


                case 3:

                    for(int l = 0; l < 5; l++) {
                        for(k = 0; k < NValues[j]; k++) {
                            conjuntoIdsAux[k] = conjuntoIds[k];
                        }
                        switch(l) {
                            case 0:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n quickSortInsertion m = 100\n" << endl;
                                quickSortInsertion(&(conjuntoIdsAux[0]), &(conjuntoIdsAux[NValues[j]-1]), 100, comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time1[i][j] = cpuTime;
                                comp1[i][j] = *comp;
                                copias1[i][j] = *copias;
                                break;

                            case 1:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n insertionSort\n" << endl;
                                insertionSort(&(conjuntoIdsAux[0]), NValues[j], comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time2[i][j] = cpuTime;
                                comp2[i][j] = *comp;
                                copias2[i][j] = *copias;
                                break;

                            case 2:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n mergeSort\n" << endl;
                                mergeSort(&(conjuntoIdsAux[0]), 0, NValues[j]-1, comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time3[i][j] = cpuTime;
                                comp3[i][j] = *comp;
                                copias3[i][j] = *copias;
                                break;

                            case 3:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n heapSort\n" << endl;
                                heapSort(conjuntoIdsAux, NValues[j], comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time4[i][j] = cpuTime;
                                comp4[i][j] = *comp;
                                copias4[i][j] = *copias;
                                break;

                            case 4:
                                *comp = 0; *copias = 0;
                                startTime = clock();

                                cout << "\n countingSort\n" << endl;
                                countingSort(&(conjuntoIdsAux[0]), NValues[j], comp, copias);

                                endTime = clock();
                                cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

                                time5[i][j] = cpuTime;
                                comp5[i][j] = *comp;
                                copias5[i][j] = *copias;
                                break;
                        }

                        saida << ordenado(&(conjuntoIdsAux[0]), NValues[j]) << endl;
                        saida << cpuTime << endl;
                        saida << *comp << endl;
                        saida << *copias << endl;
                        saida << "\n" << endl;
                    }

                    break;


                case 4:
                    /// ALGORITMOS DE PESQUISA AQUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    for(int l = 0; l < 5; l++) {
                        for(k = 0; k < NValues[j]; k++) {
                            conjuntoIdsAux[k] = conjuntoIds[k];
                        }
                        switch(l) {
                            case 0:
                            {
                                cout << "\n SondagemLinear\n" << endl;
                                Sondagem_Linear obj1(NValues[j]);
                                for(v=0;v<NValues[j];v++)
                                {
                                    obj1.insere_sond_linear(conjuntoIdsAux[v]);
                                }
                                comp1[i][j] = obj1.comparacoes;
                                memoria1[i][j] = obj1.calculaMemoria();
                                break;
                            }
                            case 1:
                            {
//                                cout << "\n\duploHashing\n" << endl;
//                                Re_hashing obj2(NValues[j]);
//                                for(v=0;v<NValues[j];v++)
//                                {
//                                    obj2.inserir_rehashing(conjuntoIdsAux[v]);
//                                }
//
//                                comp2[i][j] = obj2.comparacoes;
//                                memoria2[i][j] = obj2.calculaMemoria();
//                                break;
                            }
                            case 2:
//                            {
//                                cout << "\n\sondagemQuadratica\n" << endl;
//                                Sond_quad obj3(NValues[j]);
//                                for(v=0;v<NValues[j];v++)
//                                {
//                                    obj3.inserir_func_quadratica(conjuntoIdsAux[v]);
//                                }
//
//                                comp3[i][j] = obj3.comparacoes;
//                                memoria3[i][j] = obj3.calculaMemoria();
//                                break;
//                            }
                            case 3:
                            {
//                                cout << "\n\hashSeparado\n" << endl;
//                                Hash_separa obj4(NValues[j]);
//                                for(v=0;v<NValues[j];v++)
//                                {
//                                    obj4.insere_hash_separado(conjuntoIdsAux[v]);
//                                }
//
//                                comp4[i][j] = obj4.comparacoes;
//                                memoria4[i][j] = obj4.calculaMemoria();
//                                break;
                            }
                            case 4:
                            {
                                *comp = 0;
                                cout << "\n hashCoalescido\n" << endl;
                                Hash_coalesc obj5(NValues[j]);
                                for(v=0;v<NValues[j];v++)
                                {
                                    obj5.insere_hashCoalescido(conjuntoIdsAux[v]);
                                }

                                comp5[i][j] = obj5.comparacoes;
                                memoria5[i][j] = obj5.calculaMemoria();
                                break;
                            }
                        }

                        saida << *comp << endl;
                        saida << "\n" << endl;
                    }

                    break;
            }

            /*for(k = 0; k < NValues[j]; k++) {
                cout << conjuntoIdsAux[k] << "   conjuntoIdsAux ord" << endl;
            }*/

            // Valor de N atual (NValues[j]), numero de comparacoes, numero de copias e tempo de execucao
            // coloca em saida.txt
            delete [] conjuntoDeputados;
            delete [] conjuntoIds;
            delete [] conjuntoIdsAux;
        }


        saida.close();
    }

    switch(CENARIO) { //colocando as medias de cada estatistica nos arquivos saidaCenario

        case 1:
            saidaCenario1.open("saidaFinalCenario1.txt", ios::out);
            saidaCenario1 << "********Resultados Cenário 1********\n\n" << endl;
            for(j = 0; j < N; j++) {
                saidaCenario1 << "N = " << NValues[j] << "\n"<< endl;

                saidaCenario1 << "Algoritmo: QuickSort para Registros de Gastos de Deputados" << endl;

                auxTime[0] = 0;
                auxComp[0] = 0;
                auxCopias[0] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[0] += time1[i][j];
                    auxComp[0] += comp1[i][j];
                    auxCopias[0] += copias1[i][j];
                }
                auxTime[0] = auxTime[0]/5;
                auxComp[0] = auxComp[0]/5;
                auxCopias[0] = auxCopias[0]/5;

                saidaCenario1 << "Tempo médio de ordenação = " << auxTime[0] << "s" << endl;
                saidaCenario1 << "Número médio de comparações de chaves = " << auxComp[0] << endl;
                saidaCenario1 << "Número médio de cópias de registros = " << auxCopias[0] << "\n" << endl;

                ///*******************************

                saidaCenario1 << "Algoritmo: QuickSort para Inteiros" << endl;

                auxTime[1] = 0;
                auxComp[1] = 0;
                auxCopias[1] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[1] += time2[i][j];
                    auxComp[1] += comp2[i][j];
                    auxCopias[1] += copias2[i][j];
                }
                auxTime[1] = auxTime[1]/5;
                auxComp[1] = auxComp[1]/5;
                auxCopias[1] = auxCopias[1]/5;

                saidaCenario1 << "Tempo médio de ordenação = " << auxTime[1] << "s" << endl;
                saidaCenario1 << "Número médio de comparações de chaves = " << auxComp[1] << endl;
                saidaCenario1 << "Número médio de cópias de registros = " << auxCopias[1] << "\n" << endl;

                if(auxTime[1] < auxTime[0])
                    saidaCenario1 << "Algoritmo mais rápido: QuickSort para Inteiros\n" << endl;
                else saidaCenario1 << "Algoritmo mais rápido: QuickSort para Registros de Gastos de Deputados\n" << endl;

                saidaCenario1 << "***********************************" << endl;

            }
            saidaCenario1.close();
            break;

        case 2:
            saidaCenario2.open("saidaFinalCenario2.txt", ios::out);
            saidaCenario2 << "********Resultados Cenário 2********\n\n" << endl;
            for(j = 0; j < N; j++) {
                saidaCenario2 << "N = " << NValues[j] << "\n" << endl;

                saidaCenario2 << "Algoritmo: QuickSort Recursivo" << endl;

                auxTime[0] = 0;
                auxComp[0] = 0;
                auxCopias[0] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[0] += time1[i][j];
                    auxComp[0] += comp1[i][j];
                    auxCopias[0] += copias1[i][j];
                }
                auxTime[0] = auxTime[0]/5;
                auxComp[0] = auxComp[0]/5;
                auxCopias[0] = auxCopias[0]/5;

                saidaCenario2 << "Tempo médio de ordenação = " << auxTime[0] << "s" << endl;
                saidaCenario2 << "Número médio de comparações de chaves = " << auxComp[0] << endl;
                saidaCenario2 << "Número médio de cópias de registros = " << auxCopias[0] << "\n" << endl;

                ///*******************************
                saidaCenario2 << "Algoritmo: QuickSort Mediana k = 3" << endl;

                auxTime[1] = 0;
                auxComp[1] = 0;
                auxCopias[1] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[1] += time2[i][j];
                    auxComp[1] += comp2[i][j];
                    auxCopias[1] += copias2[i][j];
                }
                auxTime[1] = auxTime[1]/5;
                auxComp[1] = auxComp[1]/5;
                auxCopias[1] = auxCopias[1]/5;

                saidaCenario2 << "Tempo médio de ordenação = " << auxTime[1] << "s" << endl;
                saidaCenario2 << "Número médio de comparações de chaves = " << auxComp[1] << endl;
                saidaCenario2 << "Número médio de cópias de registros = " << auxCopias[1] << "\n" << endl;

                ///*******************************
                saidaCenario2 << "Algoritmo: QuickSort Mediana k = 5" << endl;

                auxTime[2] = 0;
                auxComp[2] = 0;
                auxCopias[2] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[2] += time3[i][j];
                    auxComp[2] += comp3[i][j];
                    auxCopias[2] += copias3[i][j];
                }
                auxTime[2] = auxTime[2]/5;
                auxComp[2] = auxComp[2]/5;
                auxCopias[2] = auxCopias[2]/5;

                saidaCenario2 << "Tempo médio de ordenação = " << auxTime[2] << "s" << endl;
                saidaCenario2 << "Número médio de comparações de chaves = " << auxComp[2] << endl;
                saidaCenario2 << "Número médio de cópias de registros = " << auxCopias[2] << "\n" << endl;

                ///*******************************
                saidaCenario2 << "Algoritmo: QuickSortInsertion m = 10" << endl;

                auxTime[3] = 0;
                auxComp[3] = 0;
                auxCopias[3] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[3] += time4[i][j];
                    auxComp[3] += comp4[i][j];
                    auxCopias[3] += copias4[i][j];
                }
                auxTime[3] = auxTime[3]/5;
                auxComp[3] = auxComp[3]/5;
                auxCopias[3] = auxCopias[3]/5;

                saidaCenario2 << "Tempo médio de ordenação = " << auxTime[3] << "s" << endl;
                saidaCenario2 << "Número médio de comparações de chaves = " << auxComp[3] << endl;
                saidaCenario2 << "Número médio de cópias de registros = " << auxCopias[3] << "\n" << endl;

                ///*******************************
                saidaCenario2 << "Algoritmo: QuickSortInsertion m = 100" << endl;

                auxTime[4] = 0;
                auxComp[4] = 0;
                auxCopias[4] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[4] += time5[i][j];
                    auxComp[4] += comp5[i][j];
                    auxCopias[4] += copias5[i][j];
                }
                auxTime[4] = auxTime[4]/5;
                auxComp[4] = auxComp[4]/5;
                auxCopias[4] = auxCopias[4]/5;

                saidaCenario2 << "Tempo médio de ordenação = " << auxTime[4] << "s" << endl;
                saidaCenario2 << "Número médio de comparações de chaves = " << auxComp[4] << endl;
                saidaCenario2 << "Número médio de cópias de registros = " << auxCopias[4] << "\n" << endl;

                minTime = minVec(auxTime, 5);
                int d;
                for(d = 0; d < 5; d++) {
                    if(auxTime[d] == minTime)
                        break;
                }
                switch(d) {
                    case 0: saidaCenario2 << "Algoritmo mais rápido: QuickSort Recursivo\n" << endl; break;
                    case 1: saidaCenario2 << "Algoritmo mais rápido: QuickSort Mediana k = 3\n" << endl; break;
                    case 2: saidaCenario2 << "Algoritmo mais rápido: QuickSort Mediana k = 5\n" << endl; break;
                    case 3: saidaCenario2 << "Algoritmo mais rápido: QuickSortInsertion m = 10\n" << endl; break;
                    case 4: saidaCenario2 << "Algoritmo mais rápido: QuickSortInsertion m = 100\n" << endl; break;
                }

                saidaCenario2 << "***********************************" << endl;

            }
            saidaCenario2.close();
            break;

        case 3:
            saidaCenario3.open("saidaFinalCenario3.txt", ios::out);
            saidaCenario3 << "********Resultados Cenário 2********\n\n" << endl;
            for(j = 0; j < N; j++) {
                saidaCenario3 << "N = " << NValues[j] << "\n" << endl;

                saidaCenario3 << "Algoritmo: QuickSort Insertion m = 100" << endl;

                auxTime[0] = 0;
                auxComp[0] = 0;
                auxCopias[0] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[0] += time1[i][j];
                    auxComp[0] += comp1[i][j];
                    auxCopias[0] += copias1[i][j];
                }
                auxTime[0] = auxTime[0]/5;
                auxComp[0] = auxComp[0]/5;
                auxCopias[0] = auxCopias[0]/5;

                saidaCenario3 << "Tempo médio de ordenação = " << auxTime[0] << "s" << endl;
                saidaCenario3 << "Número médio de comparações de chaves = " << auxComp[0] << endl;
                saidaCenario3 << "Número médio de cópias de registros = " << auxCopias[0] << "\n" << endl;

                ///*******************************
                saidaCenario3 << "Algoritmo: Insertion Sort" << endl;

                auxTime[1] = 0;
                auxComp[1] = 0;
                auxCopias[1] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[1] += time2[i][j];
                    auxComp[1] += comp2[i][j];
                    auxCopias[1] += copias2[i][j];
                }
                auxTime[1] = auxTime[1]/5;
                auxComp[1] = auxComp[1]/5;
                auxCopias[1] = auxCopias[1]/5;

                saidaCenario3 << "Tempo médio de ordenação = " << auxTime[1] << "s" << endl;
                saidaCenario3 << "Número médio de comparações de chaves = " << auxComp[1] << endl;
                saidaCenario3 << "Número médio de cópias de registros = " << auxCopias[1] << "\n" << endl;

                ///*******************************
                saidaCenario3 << "Algoritmo: Merge Sort" << endl;

                auxTime[2] = 0;
                auxComp[2] = 0;
                auxCopias[2] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[2] += time3[i][j];
                    auxComp[2] += comp3[i][j];
                    auxCopias[2] += copias3[i][j];
                }
                auxTime[2] = auxTime[2]/5;
                auxComp[2] = auxComp[2]/5;
                auxCopias[2] = auxCopias[2]/5;

                saidaCenario3 << "Tempo médio de ordenação = " << auxTime[2] << "s" << endl;
                saidaCenario3 << "Número médio de comparações de chaves = " << auxComp[2] << endl;
                saidaCenario3 << "Número médio de cópias de registros = " << auxCopias[2] << "\n" << endl;

                ///*******************************
                saidaCenario3 << "Algoritmo: Heap Sort" << endl;

                auxTime[3] = 0;
                auxComp[3] = 0;
                auxCopias[3] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[3] += time4[i][j];
                    auxComp[3] += comp4[i][j];
                    auxCopias[3] += copias4[i][j];
                }
                auxTime[3] = auxTime[3]/5;
                auxComp[3] = auxComp[3]/5;
                auxCopias[3] = auxCopias[3]/5;

                saidaCenario3 << "Tempo médio de ordenação = " << auxTime[3] << "s" << endl;
                saidaCenario3 << "Número médio de comparações de chaves = " << auxComp[3] << endl;
                saidaCenario3 << "Número médio de cópias de registros = " << auxCopias[3] << "\n" << endl;

                ///*******************************
                saidaCenario3 << "Algoritmo: Counting Sort" << endl;

                auxTime[4] = 0;
                auxComp[4] = 0;
                auxCopias[4] = 0;
                for(i = 0; i < 5; i++) {
                    auxTime[4] += time5[i][j];
                    auxComp[4] += comp5[i][j];
                    auxCopias[4] += copias5[i][j];
                }
                auxTime[4] = auxTime[4]/5;
                auxComp[4] = auxComp[4]/5;
                auxCopias[4] = auxCopias[4]/5;

                saidaCenario3 << "Tempo médio de ordenação = " << auxTime[4] << "s" << endl;
                saidaCenario3 << "Número médio de comparações de chaves = " << auxComp[4] << endl;
                saidaCenario3 << "Número médio de cópias de registros = " << auxCopias[4] << "\n" << endl;

                minTime = minVec(auxTime, 5);
                int d;
                for(d = 0; d < 5; d++) {
                    if(auxTime[d] == minTime)
                        break;
                }
                switch(d) {
                    case 0: saidaCenario3 << "Algoritmo mais rápido: QuickSortInsertion m = 100\n" << endl; break;
                    case 1: saidaCenario3 << "Algoritmo mais rápido: InsertionSort\n" << endl; break;
                    case 2: saidaCenario3 << "Algoritmo mais rápido: MergeSort\n" << endl; break;
                    case 3: saidaCenario3 << "Algoritmo mais rápido: HeapSort\n" << endl; break;
                    case 4: saidaCenario3 << "Algoritmo mais rápido: CountingSort\n" << endl; break;
                }

                saidaCenario3 << "***********************************" << endl;

            }
            saidaCenario3.close();
            break;

        case 4:
            ///SAIDA FINAL (medias) DOS ALGORITMOS DE PESQUISA
            saidaCenario4.open("saidaFinalCenario4.txt", ios::out);
            saidaCenario4 << "********Resultados Cenário 4********\n\n" << endl;

            for(j = 0; j < N; j++) {

                saidaCenario4 << "N = " << NValues[j] << "\n" << endl;

                saidaCenario4 << "Algoritmo: Sondagem linear" << endl;

                auxComp[0] = 0;
                auxMemoria[0] = 0;
                for(i = 0; i < 5; i++) {
                    auxComp[0] += comp1[i][j];
                    auxMemoria[0] += memoria1[i][j];
                }
                auxComp[0] = auxComp[0]/5;
                auxMemoria[0] = auxMemoria[0]/5;

                saidaCenario4 << "Número médio de comparações de chaves = " << auxComp[0] << endl;
                saidaCenario4 << "Número médio de gasto de memoria = " << auxMemoria[0] << "\n" << endl;

                ///*******************************
//                saidaCenario4 << "Algoritmo: Duplo hashing" << endl;
//
//                auxComp[1] = 0;
//                auxMemoria[1] = 0;
//                for(i = 0; i < 5; i++) {
//                    auxComp[1] += comp2[i][j];
//                    auxMemoria[1] += memoria2[i][j];
//                }
//                auxComp[1] = auxComp[1]/5;
//                auxMemoria[1] = auxMemoria[1]/5;
//
//                saidaCenario4 << "Número médio de comparações de chaves = " << auxComp[1] << endl;
//                saidaCenario4 << "Número médio de gasto de memoria = " << auxMemoria[1] << "\n" << endl;

                ///*******************************
//                saidaCenario4 << "Algoritmo: Sondagem quadratica" << endl;
//
//                auxComp[2] = 0;
//                auxMemoria[2] = 0;
//                for(i = 0; i < 5; i++) {
//                    auxComp[2] += comp3[i][j];
//                    auxMemoria[2] += memoria3[i][j];
//                }
//                auxComp[2] = auxComp[2]/5;
//                auxMemoria[2] = auxMemoria[2]/5;
//
//                saidaCenario4 << "Número médio de comparações de chaves = " << auxComp[2] << endl;
//                saidaCenario4 << "Número médio de gasto de memoria = " << "Calcular" << "\n" << endl;

                ///*******************************
//                saidaCenario4 << "Algoritmo: Encadeamento separado" << endl;
//
//                auxComp[3] = 0;
//                auxMemoria[3] = 0;
//                for(i = 0; i < 5; i++) {
//                    auxComp[3] += comp4[i][j];
//                    auxMemoria[3] += memoria4[i][j];
//                }
//                auxComp[3] = auxComp[3]/5;
//                auxMemoria[3] = auxMemoria[3]/5;
//
//                saidaCenario4 << "Número médio de comparações de chaves = " << auxComp[3] << endl;
//                saidaCenario4 << "Número médio de gasto de memoria = " << auxMemoria[3] << "\n" << endl;

                ///*******************************

                saidaCenario4 << "Encadeamento coalescido" << endl;

                auxComp[4] = 0;
                auxMemoria[4] = 0;
                for(i = 0; i < 5; i++) {
                    auxComp[4] += comp5[i][j];
                    auxMemoria[4] += memoria5[i][j];
                }
                auxComp[4] = auxComp[4]/5;
                auxMemoria[4] = auxMemoria[4]/5;

                saidaCenario4 << "Número médio de comparações de chaves = " << auxComp[4] << endl;
                saidaCenario4 << "Número médio de gasto de memoria = " << auxMemoria[4] << "\n" << endl;

                ///*******************************
                int d, menor=auxComp[0];
                for(d = 0; d < 5; d++) {
                    if(d != 1 && d != 2){
                        if(auxComp[d] < menor) {
                            menor = auxComp[d];
                            break;
                        }
                    }
                }
                switch(d) {
                    case 0: saidaCenario4 << "Algoritmo com menos comparacoes: Sondagem linear\n" << endl; break;
//                    case 1: saidaCenario4 << "Algoritmo com menos comparacoes: Duplo hashing\n" << endl; break;
//                    case 2: saidaCenario4 << "Algoritmo com menos comparacoes: Hashing quadratico\n" << endl; break;
//                    case 3: saidaCenario4 << "Algoritmo com menos comparacoes: Encademanto separado\n" << endl; break;
                    case 4: saidaCenario4 << "Algoritmo com menos comparacoes: Encademanto coalescido\n" << endl; break;
                }
                menor=auxMemoria[0];
                for(d = 0; d < 5; d++) {
                    if(d != 1 && d != 2 && d != 3){
                        if(auxMemoria[d] < menor) {
                            menor = auxMemoria[d];
                            break;
                        }
                    }
                }
                switch(d) {
                    case 0: saidaCenario4 << "Algoritmo com menor uso de memoria: Sondagem linear\n" << endl; break;
//                    case 1: saidaCenario4 << "Algoritmo com menor uso de memoria: Duplo hashing\n" << endl; break;
//                    case 2: saidaCenario4 << "Algoritmo com menor uso de memoria: Hashing quadratico\n" << endl; break;
//                    case 3: saidaCenario4 << "Algoritmo com menor uso de memoria: Encademanto separado\n" << endl; break;
                    case 4: saidaCenario4 << "Algoritmo com menor uso de memoria: Encademanto coalescido\n" << endl; break;
                }

                saidaCenario4 << "***********************************" << endl;

            }

            saidaCenario4.close();
            break;
    }


    delete [] NValues;
    delete [] seedVec;
    delete [] comp;
    delete [] copias;

    return 0;
}





