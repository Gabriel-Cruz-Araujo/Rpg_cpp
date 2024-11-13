#pragma once
#ifndef INIMIGO_H
#define INIMIGO_H

#include <string>

// Classe Inimigo, que representa um inimigo no jogo
class Inimigo {
public:
    std::string tipo;    // Tipo do inimigo (ex: "Esqueleto", "Goblin")
    int nivel;           // Nível do inimigo, usado para calcular atributos
    int xp;              // Experiência que o inimigo pode conceder ao ser derrotado
    int saude;           // Saúde atual do inimigo
    int saudeMax;        // Saúde máxima do inimigo
    int ataque;          // Dano de ataque do inimigo
    int magia;           // Valor de magia do inimigo (poderia ser usado para ataques mágicos)

    // Construtor da classe Inimigo, inicializa os atributos com base no tipo e nível
    Inimigo(std::string tipo, int nivel);

    // Método que retorna o valor de ataque do inimigo (quanto de dano ele pode causar)
    int atacar() const;

    // Método que verifica se o inimigo ainda está vivo (se sua saúde for maior que zero)
    bool estaVivo() const;
};

#endif // INIMIGO_H
