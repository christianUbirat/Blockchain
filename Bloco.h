#ifndef BLOCO_H
#define BLOCO_H

#include <ctime>
#include <vector>
#include <string>

using namespace std;

template< typename TipoTranc >
struct DadosTransacionais{
    TipoTranc informacao;
    string chaveEnvio;
    string chaveReceptor;
    time_t momento;
};

template <typename Tipo >
class Bloco{
    private:
        int index;
        size_t blockHash;
        size_t hashAnterior;
        size_t gerarHash();

    public:
        // Construtor
        Bloco(int index, DadosTransacionais <Tipo> dados, size_t hashAnterior);

        // Retornar o hash
        size_t getHash();

        // Retornar o hash anterior
        size_t getHashAnterior();

        // Dados publicos de um bloco
        DadosTransacionais <Tipo> dados;

        // Verificar se o hash é valido
        bool isHashValid();
};

#endif