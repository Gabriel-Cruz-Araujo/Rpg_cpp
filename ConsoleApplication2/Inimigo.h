#pragma once
#ifndef INIMIGO_H
#define INIMIGO_H

#include <string>

// Classe Inimigo, que representa um inimigo no jogo
class Inimigo {
public:
    std::string tipo;    // Tipo do inimigo (ex: "Esqueleto", "Goblin")
    int nivel;           // N�vel do inimigo, usado para calcular atributos
    int xp;              // Experi�ncia que o inimigo pode conceder ao ser derrotado
    int saude;           // Sa�de atual do inimigo
    int saudeMax;        // Sa�de m�xima do inimigo
    int ataque;          // Dano de ataque do inimigo
    int magia;           // Valor de magia do inimigo (poderia ser usado para ataques m�gicos)

    // Construtor da classe Inimigo, inicializa os atributos com base no tipo e n�vel
    Inimigo(std::string tipo, int nivel);

    // M�todo que retorna o valor de ataque do inimigo (quanto de dano ele pode causar)
    int atacar() const;

    // M�todo que verifica se o inimigo ainda est� vivo (se sua sa�de for maior que zero)
    bool estaVivo() const;
};

#endif // INIMIGO_H
