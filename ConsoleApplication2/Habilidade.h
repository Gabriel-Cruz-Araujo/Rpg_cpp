#pragma once
#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <string>

// Declaração da classe Habilidade, que representa as habilidades disponíveis para o personagem
class Habilidade {
public:
    std::string nome;            // Nome da habilidade (ex: "Ataque Fogo", "Cura")
    std::string descricao;       // Descrição da habilidade (ex: "Causa dano de fogo ao inimigo")
    int dano;                    // Dano que a habilidade causa (valor numérico)
    int custoGold;               // Quanto custa a habilidade em gold para o personagem adquirir ou usar
    int nivelRequerido;          // Nível necessário do personagem para poder usar ou adquirir a habilidade

    // Construtor da classe Habilidade, inicializa as propriedades com os valores fornecidos
    Habilidade(std::string nome, std::string descricao, int dano, int custoGold, int nivelRequerido);
};

#endif // HABILIDADE_H
