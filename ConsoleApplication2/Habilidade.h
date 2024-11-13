#pragma once
#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <string>

// Declara��o da classe Habilidade, que representa as habilidades dispon�veis para o personagem
class Habilidade {
public:
    std::string nome;            // Nome da habilidade (ex: "Ataque Fogo", "Cura")
    std::string descricao;       // Descri��o da habilidade (ex: "Causa dano de fogo ao inimigo")
    int dano;                    // Dano que a habilidade causa (valor num�rico)
    int custoGold;               // Quanto custa a habilidade em gold para o personagem adquirir ou usar
    int nivelRequerido;          // N�vel necess�rio do personagem para poder usar ou adquirir a habilidade

    // Construtor da classe Habilidade, inicializa as propriedades com os valores fornecidos
    Habilidade(std::string nome, std::string descricao, int dano, int custoGold, int nivelRequerido);
};

#endif // HABILIDADE_H
