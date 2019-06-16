#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

void help()
{
    cout << endl << "                       TESTES AUTOMATICOS" << endl << endl;
    cout << "   Executa comparacoes entre as entradas e saidas especificadas." << endl << endl;
    cout << "   Comando: " << endl << endl;
    cout << "           ./tester exec pasta N D" << endl << endl;
    cout << "               exec -> Arquivo executavel." << endl;
    cout << "               pasta -> Diretorio de arquivos de entrada e saida (.res, .sol)." << endl;
    cout << "               N -> Numero de testes de 0 a N." << endl;
    cout << "               D -> Remove arquivos de resposta se True." << endl;
    cout << endl << "   Os arquivos de entrada e saida devem esta nomedados da seguinte maneira:" << endl;
    cout << "           0.in   -   0.sol" << endl;
    cout << "           1.in   -   1.sol" << endl;
    cout <<  endl << "  Todos os arquivos devem esta no mesmo diretorio (pasta) e numerados em sequencia de execucao" << endl << endl;

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
            cout << "           Testes Automaticos" << endl;
            cout << "Exec: " << argv[1] << "  -> Pasta: /" << argv[2] << "   -> Quantidade: " << argv[3] << endl << endl;

            string exec = string(argv[1]);
            string pasta = string(argv[2]);

            for(int i = 0; i <= atoi(argv[3]); i++)
            {
                string ind = to_string(i);
                string cexec = "./" + exec +  " < " + pasta + "/" + ind + ".in" + " > " + pasta + "/" + ind + ".res" ;
                string ccomp = "diff -q " +  pasta + "/" + ind + ".res " + pasta + "/" + ind + ".sol";

                if(system(cexec.c_str()) == 0)
                {
                    if(system(ccomp.c_str()) == 0)
                        cout << "TEST " << i << "->    PASSED" << endl;
                    else
                        cout << "TEST " << i << "->    NOT IDENTICAL" << endl;
                } 
                else cout << "TEST " << i  << "->    EXECUTION ERROR" << endl;
               
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