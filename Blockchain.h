#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Bloco.h"

using namespace std;


template <typename Tipo>
class Blockchain{
    private:
        Bloco <Tipo> criarPrimeiroBloco(Tipo);
        
    public:
        // Cadeia publica de blocos
        vector< Bloco <Tipo> > chain;
        
        // Construtor
        Blockchain(Tipo);

        // Outra funcoes
        void addBloco(DadosTransacionais <Tipo> dados);
        bool isChainValid();

        // Funcao para hackear a blockchain
        Bloco <Tipo> *getUltimoBloco();
};

#endif