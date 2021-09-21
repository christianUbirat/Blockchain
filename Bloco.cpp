#include "Bloco.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// Construtor
template< typename Tipo >
Bloco < Tipo >::Bloco(int index, DadosTransacionais <Tipo> dados, size_t hashAnterior){

    this->index = index;
    this->dados = dados;
    this->hashAnterior = hashAnterior;
    blockHash = gerarHash();    
}

// Funcoes privadas
template< typename Tipo >
size_t Bloco < Tipo >::gerarHash(){
    // Uso de templates na classe hash
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> hashFinal;

    // String com dados da transação (para passar na hash)
    string toHash = to_string(dados.informacao) + dados.chaveReceptor + dados.chaveEnvio + to_string(dados.momento);

    return hashFinal(hash1(toHash) + hash2(hashAnterior));
    //return hash1(toHash) ^ (hash2(to_string(hashAnterior)) << 1);
}

// Sobrecarregando um metodo
// Devemos avisar ao compilador que o que segue é um template (para ele checar a sintaxe e etc)
template<>
size_t Bloco < string >::gerarHash(){
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> hashFinal;

    // String nao pode passar por to_string
    string toHash = dados.informacao + dados.chaveReceptor + dados.chaveEnvio + to_string(dados.momento);

    return hashFinal(hash1(toHash) + hash2(hashAnterior));
}

// Funcoes publicas
template< typename Tipo >
size_t Bloco < Tipo >::getHash(){
    return blockHash;
}

template< typename Tipo >
size_t Bloco < Tipo >::getHashAnterior(){
    return hashAnterior;
}

template< typename Tipo >
bool Bloco < Tipo >::isHashValid(){
    // Se qualquer dado for violado, o hash sera diferente, retornando falso
    return gerarHash() == blockHash;  
}

// class BlocoStr: public Bloco <string>{};