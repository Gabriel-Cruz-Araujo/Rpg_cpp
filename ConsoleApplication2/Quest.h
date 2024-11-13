#pragma once
#ifndef QUEST_H    
#define QUEST_H

#include <string>  

// Declara��o da classe Quest
class Quest {
private:
    // Atributos privados da classe Quest
    std::string nome;             // Nome da quest
    std::string descricao;        // Descri��o da quest
    int recompensaGold;           // Recompensa em ouro pela conclus�o da quest
    int recompensaXP;             // Recompensa em XP (experi�ncia) pela conclus�o da quest
    int andar;                    // Andar da masmorra ou local onde a quest ocorre
    int nivelRequerido;           // N�vel m�nimo do personagem para poder realizar a quest

public:
    // Construtor da classe Quest
    // Inicializa os atributos com os valores passados como par�metros
    Quest(const std::string& nome, const std::string& descricao, int recompensaGold, int recompensaXP, int andar, int nivelRequerido);

    // M�todos getters (m�todos de acesso)
    std::string getNome() const;             // Retorna o nome da quest
    std::string getDescricao() const;        // Retorna a descri��o da quest
    int getRecompensaGold() const;           // Retorna a recompensa em ouro
    int getRecompensaXP() const;             // Retorna a recompensa em XP
    int getAndar() const;                    // Retorna o andar onde a quest ocorre
    int getNivelRequerido() const;           // Retorna o n�vel m�nimo necess�rio para a quest

    // M�todo para exibir informa��es detalhadas sobre a quest
    void exibirQuest() const;
};

#endif // QUEST_H   
