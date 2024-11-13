#pragma once
#ifndef QUEST_H    
#define QUEST_H

#include <string>  

// Declaração da classe Quest
class Quest {
private:
    // Atributos privados da classe Quest
    std::string nome;             // Nome da quest
    std::string descricao;        // Descrição da quest
    int recompensaGold;           // Recompensa em ouro pela conclusão da quest
    int recompensaXP;             // Recompensa em XP (experiência) pela conclusão da quest
    int andar;                    // Andar da masmorra ou local onde a quest ocorre
    int nivelRequerido;           // Nível mínimo do personagem para poder realizar a quest

public:
    // Construtor da classe Quest
    // Inicializa os atributos com os valores passados como parâmetros
    Quest(const std::string& nome, const std::string& descricao, int recompensaGold, int recompensaXP, int andar, int nivelRequerido);

    // Métodos getters (métodos de acesso)
    std::string getNome() const;             // Retorna o nome da quest
    std::string getDescricao() const;        // Retorna a descrição da quest
    int getRecompensaGold() const;           // Retorna a recompensa em ouro
    int getRecompensaXP() const;             // Retorna a recompensa em XP
    int getAndar() const;                    // Retorna o andar onde a quest ocorre
    int getNivelRequerido() const;           // Retorna o nível mínimo necessário para a quest

    // Método para exibir informações detalhadas sobre a quest
    void exibirQuest() const;
};

#endif // QUEST_H   
