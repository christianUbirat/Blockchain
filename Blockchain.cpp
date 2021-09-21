#include "Blockchain.h"
#include <typeinfo>

template <typename Tipo>
Blockchain <Tipo>::Blockchain(Tipo informacao){
    Bloco <Tipo> primeiroBloco = criarPrimeiroBloco(informacao);
    chain.push_back(primeiroBloco);

}

template <typename Tipo>
Bloco <Tipo> Blockchain <Tipo>::criarPrimeiroBloco(Tipo informacao){
    time_t current;
    DadosTransacionais <Tipo> d;
    d.informacao = informacao;
    d.chaveReceptor = "None";
    d.chaveEnvio = "None";
    d.momento = time(&current);

    hash<int> hash1;
    Bloco <Tipo> primeiroBloco(0, d, hash1(0));
    return primeiroBloco;
}

// Apenas para demonstracao
template <typename Tipo>
Bloco <Tipo> *Blockchain <Tipo>::getUltimoBloco(){
    return &chain.back();
}

template< typename Tipo >
void Blockchain <Tipo>::addBloco(DadosTransacionais <Tipo> d){
    int index = (int)chain.size();

    size_t hashAnterior = (int)chain.size() > 0 ? getUltimoBloco()->getHash() : 0;
    // Usando o ponteiro para encontrar o hash do ultimo bloco
    //Bloco <Tipo> newBloco(index, d, getUltimoBloco()->getHash());
    Bloco <Tipo> newBloco(index, d, hashAnterior);
    chain.push_back(newBloco);    
}

template <typename Tipo>
bool Blockchain <Tipo>::isChainValid(){
    // Iterator para iterar no vetor de blocos
    typename vector <Bloco <Tipo> >::iterator it;

    for(it = chain.begin(); it != chain.end(); ++it){
        Bloco <Tipo> blocoAtual = *it;
        if(!blocoAtual.isHashValid()){
            // Os dados foram corrompidos
            return false;
        }
        if(it != chain.begin()){
            Bloco <Tipo> blocoAnterior = *(it - 1);
            if(blocoAtual.getHashAnterior() != blocoAnterior.getHash()){
                // Os dados foram corrompidos
                return false;
            }
        }
    }
    // Dados estao corretos
    return true;
}