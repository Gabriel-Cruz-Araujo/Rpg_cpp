#pragma once
#ifndef EXPEDICAO_H
#define EXPEDICAO_H

#include "Personagem.h"
#include <vector>

// Declaração da classe Expedicao que gerencia o processo de expedição no jogo
class Expedicao {
public:
    Personagem* jogador; // Ponteiro para o personagem jogador que participará da expedição
    int andarAtual; // Variável para armazenar o andar atual em que o jogador está na expedição
    bool emExpedicao; // Variável booleana que indica se o jogador está em uma expedição ativa

    // Construtor da classe Expedicao, inicializa com o jogador
    Expedicao(Personagem* jogador);

    // Método para iniciar a expedição, onde o jogador avança por andares e encontra eventos
    void iniciarExpedicao();

    // Método que define um evento aleatório para o jogador (inimigo ou item)
    void encontrarEvento();

    // Método para avançar para o próximo andar da expedição
    void avancarParaProximoAndar();

    // Método que permite ao jogador encontrar um item aleatório durante a expedição
    void encontrarItem();
};

#endif // EXPEDICAO_H
