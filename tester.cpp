#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

/*
	Programa de Automatização de Testes
*/

void help()
{
    cout << endl << "                           TESTER" << endl << endl;
    cout << "   Executa comparaçoes entre as entradas e saídas especificadas." << endl << endl;
    cout << "   Comando: " << endl << endl;
    cout << "           ./tester exec dir N D" << endl << endl;
    cout << "               exec -> Arquivo executável." << endl;
    cout << "               dir -> Diretório de arquivos de entrada e saída (.in, .sol)." << endl;
    cout << "               N -> Quantidade de testes." << endl;
    cout << "               D -> Remove arquivos de resposta se 1 (.res)." << endl;
    cout << endl << "   Os arquivos de entrada e saída devem ser nomedados da seguinte maneira:" << endl << endl;
    cout << "           0.in   -   0.sol" << endl;
    cout << "           1.in   -   1.sol" << endl;
    cout <<  endl << "  Todos os arquivos devem ficar no mesmo diretorio (dir) e numerados" << endl;
    cout << "  em sequência de execuçao (De 0 a N-1)." << endl;
    cout << "  O executavel deve ficar no mesmo diretório do tester." << endl << endl;
    cout << "  Exemplo:  ./tester myprogram testes 5 1" << endl << endl;
}

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        if(argc == 2)
        {
            if(strcmp(argv[1], "--help") == 0)
            {
                help();
            }
        }
        else
        {
            cout << "                   TESTER" << endl;
            cout << "Exec: " << argv[1] << "  -> Pasta: /" << argv[2] << "   -> Quant: " << argv[3] << endl << endl;

            string exec = string(argv[1]);
            string pasta = string(argv[2]);

            for(int i = 0; i < atoi(argv[3]); i++)
            {
                string ind = to_string(i);
                string cexec = "./" + exec +  " < " + pasta + "/" + ind + ".in" + " > " + pasta + "/" + ind + ".res" ;
                string ccomp = "diff -q " +  pasta + "/" + ind + ".res " + pasta + "/" + ind + ".sol";

                if(system(cexec.c_str()) == 0)
                {
                    if(system(ccomp.c_str()) == 0)
                        cout << "TEST " << i << " ->    PASSED" << endl;
                    else
                        cout << "TEST " << i << " ->    NOT IDENTICAL" << endl;
                } 
                else cout << "TEST " << i  << " ->    EXECUTION ERROR" << endl;
               
            }
            string clean = "rm " +  pasta + "/*.res";
            if(argv[4])
                system(clean.c_str());
        }
    }
    else
    {
        cout << "Parametros Invalidos" << endl << endl;
        help();
    }
    cout << endl << "FINISHED" << endl;
    return 0;
}
