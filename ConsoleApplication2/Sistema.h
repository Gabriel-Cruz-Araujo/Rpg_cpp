#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

// Inclusão de cabeçalhos necessários para a classe Sistema
#include "Personagem.h"  // Define a classe Personagem
#include "Expedicao.h"    // Define a classe Expedicao
#include "Loja.h"         // Define a classe Loja
#include "Quest.h"        // Define a classe Quest

// Classe que gerencia o sistema do jogo
class Sistema {
public:
    // Ponteiro para o personagem atual do jogador
    Personagem* jogador = nullptr;
    // Variável que controla se o jogo está ativo
    bool jogoAtivo = true;

    // Lista de missões disponíveis no jogo
    std::vector<Quest> missoesDisponiveis;
    // Lista de habilidades disponíveis para o jogador
    std::vector<Habilidade> habilidadesDisponiveis;
    // Objeto que representa a loja do jogo
    Loja loja;

    // Função principal que inicia o jogo
    void iniciarJogo();

    // Função que exibe o menu principal do jogo
    void exibirMenu();

    // Função que cria o personagem do jogador
    void criarPersonagem();

    // Função que inicia a expedição no jogo (exploração)
    void iniciarExpedicao();

    // Função que exibe o quadro de missões disponíveis para o jogador
    void quadroDeMissoes();

    // Função que exibe o inventário do jogador
    void verInventario();

    // Função que exibe o status atual do personagem
    void exibirStatus();

    // Função que exibe as missões ativas ou completadas do jogador
    void verMissoes();

    // Função que exibe o menu do santuário
    void menuSantuario();

    // Função que exibe o menu de opções da loja
    void menuLoja();

    // Função que inicia a arena de combate, onde o jogador pode lutar
    void arenaDeCombate();

    // Função que permite o jogador ver e gerenciar seus equipamentos
    void verEquipamentos();

    // Construtor da classe Sistema
    Sistema();
};

#endif // SISTEMA_H
