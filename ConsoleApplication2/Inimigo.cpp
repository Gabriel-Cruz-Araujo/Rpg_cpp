#include "Inimigo.h"

// Construtor da classe Inimigo, que inicializa as propriedades do inimigo com base no tipo e nível fornecidos
Inimigo::Inimigo(std::string tipo, int nivel)
    : tipo(tipo),                        // Inicializa o tipo do inimigo (ex: "Esqueleto", "Goblin")
    nivel(nivel),                      // Inicializa o nível do inimigo
    saude(50 + nivel * 10),             // A saúde inicial é 50 mais 10 vezes o nível do inimigo
    saudeMax(50 + nivel * 10),         // A saúde máxima é igual à saúde inicial (usada para comparar com a saúde atual)
    ataque(10 + nivel * 2),            // O ataque do inimigo é 10 mais 2 vezes o nível
    magia(5 + nivel)                   // A magia do inimigo é 5 mais o nível (valor de magia aumentada com o nível)
{}

// Função que retorna o valor de ataque do inimigo
int Inimigo::atacar() const {
    return ataque; // Retorna o valor do ataque, que representa o dano que o inimigo pode causar
}

// Função que verifica se o inimigo ainda está vivo
bool Inimigo::estaVivo() const {
    return saude > 0; // Retorna verdadeiro se a saúde do inimigo for maior que 0
}
