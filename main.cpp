#include "Blockchain.cpp"
#include "Bloco.cpp"

using namespace std;

template <class T>
T dado1 = T(3.141);

string isValidStr(bool argumento){
    if(argumento){
        return "Sim.";
    }
    else{
        return "Não.";
    }
}

int main(){
    int escolha;
    bool stop = false;
    while(!stop){
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
        << "... Bem-vindo à rede de blockchains Bira0..." << endl
        << "--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#" << endl
        << "Escolha o tipo de blockchain que você quer gerar: " << endl
        << "1 - int" << endl
        << "2 - float" << endl
        << "3 - string" << endl
        << "4 - encerrar" << endl;
        cin >> escolha;
        if(escolha == 1){
            cout << "Criando primeira blockchain: Bira" << endl
            << "Tipo dos dados: inteiros" << endl;
            Blockchain <int> Bira(dado1 <int>);
            DadosTransacionais <int> dados1, dados2, dados3;

            // Criando dados dos blocos
            time_t dados1Momento;
            dados1.informacao = 10;
            dados1.chaveReceptor = "Christian";
            dados1.chaveEnvio = "Lucas";
            dados1.momento = time(&dados1Momento);

            time_t dados2Momento;
            dados2.informacao = 5;
            dados2.chaveReceptor = "Chiva";
            dados2.chaveEnvio = "Christian";
            dados2.momento = time(&dados2Momento);

            time_t dados3Momento;
            dados3.informacao = 1;
            dados3.chaveReceptor = "João";
            dados3.chaveEnvio = "Pedro";
            dados3.momento = time(&dados3Momento);

            cout << "... Criando blocos ..." << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 0" << endl
            << "De: " << Bira.chain[0].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[0].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[0].dados.informacao << endl;
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 1" << endl
            << "De: " << dados1.chaveEnvio << endl
            << "Para: " << dados1.chaveReceptor << endl
            << "Dado armazenado: " << dados1.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados1);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 2" << endl
            << "De: " << dados2.chaveEnvio << endl
            << "Para: " << dados2.chaveReceptor << endl
            << "Dado armazenado: " << dados2.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados2);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 3" << endl
            << "De: " << dados3.chaveEnvio << endl
            << "Para: " << dados3.chaveReceptor << endl
            << "Dado armazenado: " << dados3.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados3);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Blocos adicionado à blockchain com sucesso!" << endl;
            
            // Pausa e limpeza
            cin.get();
            cin.get();
            system("clear");
            
            cout << "Blockchain: " << endl
            << Bira.chain[0].dados.informacao << "<->" << Bira.chain[1].dados.informacao << "<->" 
            << Bira.chain[2].dados.informacao << "<->" << Bira.chain[3].dados.informacao<< endl;

            cin.get();
            system("clear");

            cout << "!*>&#±@<≠!*>&#±@<≠!*>&#±@<≠" << endl
            << "!!! SISTEMA HACKEADO !!!" << endl
            <<  "!*>&#±@<≠!*>&#±@<≠!*>&#±@<≠" << endl << endl;
            // Tentativa de alterar os dados    
            Bloco <int> *blocoHackeado = Bira.getUltimoBloco();
            cout << "Acesso ao último bloco: concedido." << endl; 

            cin.get();
            system("clear");
            
            blocoHackeado->dados.informacao = 100000;
            blocoHackeado->dados.chaveReceptor = "Christian";
            cout << "Informações do último bloco (corrompido):" << endl
            << "------------------------------------------------" << endl
            << "De: " << Bira.chain[3].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[3].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[3].dados.informacao << endl;
        
            cout << "A blockchain é válida?  ";
            cin.get();
            cout << isValidStr(Bira.isChainValid());

            cin.get();
            system("clear");
        }
        if(escolha == 2){
            cout << "Criando primeira blockchain: Bira" << endl
            << "Tipo dos dados: float" << endl;
            Blockchain <float> Bira(dado1 <float>);
            DadosTransacionais <float> dados1, dados2, dados3;

            // Criando dados dos blocos
            time_t dados1Momento;
            dados1.informacao = 10.5;
            dados1.chaveReceptor = "Christian";
            dados1.chaveEnvio = "Lucas";
            dados1.momento = time(&dados1Momento);

            time_t dados2Momento;
            dados2.informacao = 0.1;
            dados2.chaveReceptor = "Chiva";
            dados2.chaveEnvio = "Christian";
            dados2.momento = time(&dados2Momento);

            time_t dados3Momento;
            dados3.informacao = 0.0011;
            dados3.chaveReceptor = "João";
            dados3.chaveEnvio = "Pedro";
            dados3.momento = time(&dados3Momento);

            cout << "... Criando blocos ..." << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 0" << endl
            << "De: " << Bira.chain[0].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[0].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[0].dados.informacao << endl;
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 1" << endl
            << "De: " << dados1.chaveEnvio << endl
            << "Para: " << dados1.chaveReceptor << endl
            << "Dado armazenado: " << dados1.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados1);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 2" << endl
            << "De: " << dados2.chaveEnvio << endl
            << "Para: " << dados2.chaveReceptor << endl
            << "Dado armazenado: " << dados2.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados2);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 3" << endl
            << "De: " << dados3.chaveEnvio << endl
            << "Para: " << dados3.chaveReceptor << endl
            << "Dado armazenado: " << dados3.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados3);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Blocos adicionado à blockchain com sucesso!" << endl;
            
            // Pausa e limpeza
            cin.get();
            cin.get();
            system("clear");
            
            cout << "Blockchain: " << endl
            << Bira.chain[0].dados.informacao << "<->" << Bira.chain[1].dados.informacao << "<->" 
            << Bira.chain[2].dados.informacao << "<->" << Bira.chain[3].dados.informacao<< endl;

            cin.get();
            system("clear");

            cout << "!*>&#±@<≠!*>&#±@<≠!*>&#±@<≠" << endl
            << "!!! SISTEMA HACKEADO !!!" << endl
            <<  "!*>&#±@<≠!*>&#±@<≠!*>&#±@<≠" << endl << endl;
            // Tentativa de alterar os dados    
            Bloco <float> *blocoHackeado = Bira.getUltimoBloco();
            cout << "Acesso ao último bloco: concedido." << endl; 

            cin.get();
            system("clear");
            
            blocoHackeado->dados.informacao = 9876.54;
            blocoHackeado->dados.chaveReceptor = "Christian";
            cout << "Informações do último bloco (corrompido):" << endl
            << "------------------------------------------------" << endl
            << "De: " << Bira.chain[3].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[3].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[3].dados.informacao << endl;
        
            cout << "A blockchain é válida?  ";
            cin.get();
            cout << isValidStr(Bira.isChainValid());

            cin.get();
            system("clear");
        }
        if(escolha == 3){
            cout << "Criando primeira blockchain: Bira" << endl
            << "Tipo dos dados: string" << endl;
            Blockchain <string> Bira("Default");
            DadosTransacionais <string> dados1, dados2, dados3;

            // Criando dados dos blocos
            time_t dados1Momento;
            dados1.informacao = "Poesia cara e muito bem estruturada";
            dados1.chaveReceptor = "Christian";
            dados1.chaveEnvio = "Lucas";
            dados1.momento = time(&dados1Momento);

            time_t dados2Momento;
            dados2.informacao = "Localização da minha fortuna";
            dados2.chaveReceptor = "Chiva";
            dados2.chaveEnvio = "Christian";
            dados2.momento = time(&dados2Momento);

            time_t dados3Momento;
            dados3.informacao = "Testamento: deixo tudo para João";
            dados3.chaveReceptor = "João";
            dados3.chaveEnvio = "Pedro";
            dados3.momento = time(&dados3Momento);

            cout << "... Criando blocos ..." << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 0" << endl
            << "De: " << Bira.chain[0].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[0].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[0].dados.informacao << endl;
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 1" << endl
            << "De: " << dados1.chaveEnvio << endl
            << "Para: " << dados1.chaveReceptor << endl
            << "Dado armazenado: " << dados1.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados1);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 2" << endl
            << "De: " << dados2.chaveEnvio << endl
            << "Para: " << dados2.chaveReceptor << endl
            << "Dado armazenado: " << dados2.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados2);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 3" << endl
            << "De: " << dados3.chaveEnvio << endl
            << "Para: " << dados3.chaveReceptor << endl
            << "Dado armazenado: " << dados3.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados3);
            cout << "A blockchain é válida? " << isValidStr(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Blocos adicionado à blockchain com sucesso!" << endl;
            
            // Pausa e limpeza
            cin.get();
            cin.get();
            system("clear");
            
            cout << "Blockchain: " << endl
            << Bira.chain[0].dados.informacao << "<->" << Bira.chain[1].dados.informacao << "<->" 
            << Bira.chain[2].dados.informacao << "<->" << Bira.chain[3].dados.informacao<< endl;

            cin.get();
            system("clear");

            cout << "!*>&#±@<≠!*>&#±@<≠!*>&#±@<≠" << endl
            << "!!! SISTEMA HACKEADO !!!" << endl
            <<  "!*>&#±@<≠!*>&#±@<≠!*>&#±@<≠" << endl << endl;
            // Tentativa de alterar os dados    
            Bloco <string> *blocoHackeado = Bira.getUltimoBloco();
            cout << "Acesso ao último bloco: concedido." << endl; 

            cin.get();
            system("clear");
            
            blocoHackeado->dados.informacao = "Testamento: deixo tudo para Christian";
            blocoHackeado->dados.chaveReceptor = "Christian";
            cout << "Informações do último bloco (corrompido):" << endl
            << "------------------------------------------------" << endl
            << "De: " << Bira.chain[3].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[3].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[3].dados.informacao << endl;
        
            cout << "A blockchain é válida?  ";
            cin.get();
            cout << isValidStr(Bira.isChainValid());

            cin.get();
            system("clear");
        }
        if(escolha == 4){
            system("clear");
            cout << "Encerrando o sistema..." << endl;
            stop = true;
        }
    }
    return 0;
}