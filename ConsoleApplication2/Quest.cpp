#include "Quest.h"     
#include <iostream>     
// Construtor da classe Quest
Quest::Quest(const std::string& nome, const std::string& descricao, int recompensaGold, int recompensaXP, int andar, int nivelRequerido)
    : nome(nome), descricao(descricao), recompensaGold(recompensaGold), recompensaXP(recompensaXP), andar(andar), nivelRequerido(nivelRequerido) {
    // O construtor inicializa os atributos da quest com os valores passados como parâmetros
}

// Métodos de acesso para obter informações sobre a quest

std::string Quest::getNome() const {
    return nome; // Retorna o nome da quest
}

std::string Quest::getDescricao() const {
    return descricao; // Retorna a descrição da quest
}

int Quest::getRecompensaGold() const {
    return recompensaGold; // Retorna a quantidade de ouro como recompensa pela quest
}

int Quest::getRecompensaXP() const {
    return recompensaXP; // Retorna a quantidade de XP como recompensa pela quest
}

int Quest::getAndar() const {
    return andar; // Retorna o andar onde a quest ocorre
}

int Quest::getNivelRequerido() const {
    return nivelRequerido; // Retorna o nível mínimo exigido para a quest
}

// Método para exibir as informações detalhadas da quest
void Quest::exibirQuest() const {
    std::cout << "Nome: " << nome << "\n";                      // Exibe o nome da quest
    std::cout << "Descricao: " << descricao << "\n";              // Exibe a descrição da quest
    std::cout << "Recompensa em Ouro: " << recompensaGold << "\n"; // Exibe a recompensa em ouro
    std::cout << "Recompensa em XP: " << recompensaXP << "\n";    // Exibe a recompensa em XP
    std::cout << "Andar: " << andar << "\n";                      // Exibe o andar onde a quest ocorre
    std::cout << "Nivel Requerido: " << nivelRequerido << "\n";    // Exibe o nível necessário para realizar a quest
}
