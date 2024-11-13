#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

// Inclus�o de cabe�alhos necess�rios para a classe Sistema
#include "Personagem.h"  // Define a classe Personagem
#include "Expedicao.h"    // Define a classe Expedicao
#include "Loja.h"         // Define a classe Loja
#include "Quest.h"        // Define a classe Quest

// Classe que gerencia o sistema do jogo
class Sistema {
public:
    // Ponteiro para o personagem atual do jogador
    Personagem* jogador = nullptr;
    // Vari�vel que controla se o jogo est� ativo
    bool jogoAtivo = true;

    // Lista de miss�es dispon�veis no jogo
    std::vector<Quest> missoesDisponiveis;
    // Lista de habilidades dispon�veis para o jogador
    std::vector<Habilidade> habilidadesDisponiveis;
    // Objeto que representa a loja do jogo
    Loja loja;

    // Fun��o principal que inicia o jogo
    void iniciarJogo();

    // Fun��o que exibe o menu principal do jogo
    void exibirMenu();

    // Fun��o que cria o personagem do jogador
    void criarPersonagem();

    // Fun��o que inicia a expedi��o no jogo (explora��o)
    void iniciarExpedicao();

    // Fun��o que exibe o quadro de miss�es dispon�veis para o jogador
    void quadroDeMissoes();

    // Fun��o que exibe o invent�rio do jogador
    void verInventario();

    // Fun��o que exibe o status atual do personagem
    void exibirStatus();

    // Fun��o que exibe as miss�es ativas ou completadas do jogador
    void verMissoes();

    // Fun��o que exibe o menu do santu�rio
    void menuSantuario();

    // Fun��o que exibe o menu de op��es da loja
    void menuLoja();

    // Fun��o que inicia a arena de combate, onde o jogador pode lutar
    void arenaDeCombate();

    // Fun��o que permite o jogador ver e gerenciar seus equipamentos
    void verEquipamentos();

    // Construtor da classe Sistema
    Sistema();
};

#endif // SISTEMA_H
