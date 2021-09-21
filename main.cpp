#include "Blockchain.cpp"
#include "Bloco.cpp"

using namespace std;

// Template de variável
template <class T>
T dado1 = T(3.141);

// Template de função com sobrecarga
template <typename Tipo>
Tipo isValid(Tipo argumento){
    return argumento;
}
string isValid(bool argumento){
    if(argumento){
        return "Sim.";
    }
    else{
        return "Não.";
    }
}
string isValid(int argumento){
    if(argumento == 1){
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
        system("clear");
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
        << "... Bem-vindo à rede de blockchains ..." << endl
        << "--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#" << endl
        << "Escolha o tipo de dados que você quer armazar na blockchain: " << endl
        << "1 - números inteiros" << endl
        << "2 - bira coin (float)" << endl
        << "3 - texto" << endl
        << "4 - encerrar" << endl;
        cin >> escolha;
        system("clear");
        if(escolha == 1){
            cout << "Criando blockchain: Bira Int" << endl
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
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 1" << endl
            << "De: " << dados1.chaveEnvio << endl
            << "Para: " << dados1.chaveReceptor << endl
            << "Dado armazenado: " << dados1.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados1);
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 2" << endl
            << "De: " << dados2.chaveEnvio << endl
            << "Para: " << dados2.chaveReceptor << endl
            << "Dado armazenado: " << dados2.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados2);
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 3" << endl
            << "De: " << dados3.chaveEnvio << endl
            << "Para: " << dados3.chaveReceptor << endl
            << "Dado armazenado: " << dados3.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados3);
            size_t hashOriginal3 = Bira.chain[3].getHash();
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
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
            cout << "A chave do receptor e a informação "
            << "do último bloco foram alteradas" << endl;
            cout << "Informações do último bloco (corrompido):" << endl
            << "------------------------------------------------" << endl
            << "De: " << Bira.chain[3].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[3].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[3].dados.informacao << endl;
        
            cout << "A blockchain é válida?  ";
            cin.get();
            cout << isValid(Bira.isChainValid());

            // Pausa dramática
            cin.get();
            system("clear");
            cout << "Apesar da quantidade enviada e do receptor"
            <<" terem sido alterados, a função hash continua a mesma: " << endl << endl     
            << "Hash original:" << endl 
            << hashOriginal3 << endl
            << "Hash do bloco corrompido: " << endl
            << Bira.chain[3].getHash() << endl << endl
            << "Assim, quando a rede for verificar se o bloco "
            <<"é válido, vai perceber que o hash do bloco não é "
            << "o mesmo do hash que deveria aparecer caso os dados "
            << "tivessem passado pela função hash" << endl
            << "Afinal, quando os dados mudaram,"
            << " o hash deveria mudar também" << endl;

            cin.get();
            system("clear");

        }
        if(escolha == 2){
            cout << "Criando blockchain: Bira Coin" << endl
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
            << "Dado armazenado: " << Bira.chain[0].dados.informacao << " biras" << endl;
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 1" << endl
            << "De: " << dados1.chaveEnvio << endl
            << "Para: " << dados1.chaveReceptor << endl
            << "Dado armazenado: " << dados1.informacao << " biras"  << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados1);
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 2" << endl
            << "De: " << dados2.chaveEnvio << endl
            << "Para: " << dados2.chaveReceptor << endl
            << "Dado armazenado: " << dados2.informacao << " biras" << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados2);
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 3" << endl
            << "De: " << dados3.chaveEnvio << endl
            << "Para: " << dados3.chaveReceptor << endl
            << "Dado armazenado: " << dados3.informacao  << " biras" << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados3);
            size_t hashOriginal3 = Bira.chain[3].getHash();
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
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
            cout << "A chave do receptor e a informação do último bloco foram alteradas" << endl;
            cout << "Informações do último bloco (corrompido):" << endl
            << "------------------------------------------------" << endl
            << "De: " << Bira.chain[3].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[3].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[3].dados.informacao << " biras" << endl;
        
            cout << "A blockchain é válida?  ";
            cin.get();
            cout << isValid(Bira.isChainValid());

            cin.get();
            system("clear");

            cout << "Apesar da quantidade enviada e do receptor"
            <<" terem sido alterados, a função hash continua a mesma: " << endl << endl     
            << "Hash original:" << endl 
            << hashOriginal3 << endl
            << "Hash do bloco corrompido: " << endl
            << Bira.chain[3].getHash() << endl << endl
            << "Assim, quando a rede for verificar se o bloco "
            <<"é válido, vai perceber que o hash do bloco não é "
            << "o mesmo do hash que deveria aparecer caso os dados "
            << "tivessem passado pela função hash " << endl
            << "Afinal, quando os dados mudaram, "
            << " o hash deveria mudar também" << endl;

            cin.get();
            system("clear");
        }
        if(escolha == 3){
            cout << "Criando blockchain: Bira Text" << endl
            << "Tipo dos dados: string" << endl;
            Blockchain <string> Bira("Genesis");
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
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 1" << endl
            << "De: " << dados1.chaveEnvio << endl
            << "Para: " << dados1.chaveReceptor << endl
            << "Dado armazenado: " << dados1.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados1);
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 2" << endl
            << "De: " << dados2.chaveEnvio << endl
            << "Para: " << dados2.chaveReceptor << endl
            << "Dado armazenado: " << dados2.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados2);
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
            cout << "----------------------------------------------" << endl;

            cout << "Bloco 3" << endl
            << "De: " << dados3.chaveEnvio << endl
            << "Para: " << dados3.chaveReceptor << endl
            << "Dado armazenado: " << dados3.informacao << endl;
            // Adicionando bloco na blockchain
            Bira.addBloco(dados3);
            size_t hashOriginal3 = Bira.chain[3].getHash();
            cout << "A blockchain é válida? " << isValid(Bira.isChainValid()) << endl;
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
            cout << "A chave do receptor e a informação do último bloco foram alteradas" << endl;
            cout << "Informações do último bloco (corrompido):" << endl
            << "------------------------------------------------" << endl
            << "De: " << Bira.chain[3].dados.chaveEnvio << endl
            << "Para: " << Bira.chain[3].dados.chaveReceptor << endl
            << "Dado armazenado: " << Bira.chain[3].dados.informacao << endl;
        
            cout << "A blockchain é válida?  ";
            cin.get();
            cout << isValid(Bira.isChainValid());

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
