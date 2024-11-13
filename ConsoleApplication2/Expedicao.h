#pragma once
#ifndef EXPEDICAO_H
#define EXPEDICAO_H

#include "Personagem.h"
#include <vector>

// Declara��o da classe Expedicao que gerencia o processo de expedi��o no jogo
class Expedicao {
public:
    Personagem* jogador; // Ponteiro para o personagem jogador que participar� da expedi��o
    int andarAtual; // Vari�vel para armazenar o andar atual em que o jogador est� na expedi��o
    bool emExpedicao; // Vari�vel booleana que indica se o jogador est� em uma expedi��o ativa

    // Construtor da classe Expedicao, inicializa com o jogador
    Expedicao(Personagem* jogador);

    // M�todo para iniciar a expedi��o, onde o jogador avan�a por andares e encontra eventos
    void iniciarExpedicao();

    // M�todo que define um evento aleat�rio para o jogador (inimigo ou item)
    void encontrarEvento();

    // M�todo para avan�ar para o pr�ximo andar da expedi��o
    void avancarParaProximoAndar();

    // M�todo que permite ao jogador encontrar um item aleat�rio durante a expedi��o
    void encontrarItem();
};

#endif // EXPEDICAO_H
