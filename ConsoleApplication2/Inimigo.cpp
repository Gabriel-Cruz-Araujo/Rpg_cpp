#include "Inimigo.h"

// Construtor da classe Inimigo, que inicializa as propriedades do inimigo com base no tipo e n�vel fornecidos
Inimigo::Inimigo(std::string tipo, int nivel)
    : tipo(tipo),                        // Inicializa o tipo do inimigo (ex: "Esqueleto", "Goblin")
    nivel(nivel),                      // Inicializa o n�vel do inimigo
    saude(50 + nivel * 10),             // A sa�de inicial � 50 mais 10 vezes o n�vel do inimigo
    saudeMax(50 + nivel * 10),         // A sa�de m�xima � igual � sa�de inicial (usada para comparar com a sa�de atual)
    ataque(10 + nivel * 2),            // O ataque do inimigo � 10 mais 2 vezes o n�vel
    magia(5 + nivel)                   // A magia do inimigo � 5 mais o n�vel (valor de magia aumentada com o n�vel)
{}

// Fun��o que retorna o valor de ataque do inimigo
int Inimigo::atacar() const {
    return ataque; // Retorna o valor do ataque, que representa o dano que o inimigo pode causar
}

// Fun��o que verifica se o inimigo ainda est� vivo
bool Inimigo::estaVivo() const {
    return saude > 0; // Retorna verdadeiro se a sa�de do inimigo for maior que 0
}
