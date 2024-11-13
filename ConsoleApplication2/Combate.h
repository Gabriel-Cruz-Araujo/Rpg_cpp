#pragma once
#ifndef COMBATE_H
#define COMBATE_H

// Inclui os arquivos de cabe�alho das classes Inimigo e Personagem
#include "Inimigo.h"
#include "Personagem.h"

// Declara��o da classe Combate, que gerencia o sistema de combate entre o jogador e o inimigo
class Combate {
public:
	Personagem* jogador;    // Ponteiro para o jogador (classe Personagem)
	Inimigo* inimigo;       // Ponteiro para o inimigo (classe Inimigo)
	bool turnoDoJogador;    // Indica de quem � o turno (true para jogador, false para inimigo)

	// Construtor da classe Combate, inicializa com o jogador e o inimigo
	Combate(Personagem* jogador, Inimigo* inimigo);

	// M�todo que inicia e controla o fluxo do combate
	void iniciarCombate();

	// M�todo para o jogador usar uma habilidade espec�fica
	void usarHabilidade(int indice);

	// M�todo que concede XP ao jogador ao vencer o combate
	void ganharXP();

	// M�todo para usar um item, identificado pelo seu nome
	void usarItem(const std::string& nome);

	// M�todo para exibir o status atual do jogador e do inimigo durante o combate
	void exibirStatus() const;

	// M�todo para curar o jogador, podendo ser chamado em combate
	void curarJogador();
};

#endif // COMBATE_H
