#include "Quest.h"     
#include <iostream>     
// Construtor da classe Quest
Quest::Quest(const std::string& nome, const std::string& descricao, int recompensaGold, int recompensaXP, int andar, int nivelRequerido)
    : nome(nome), descricao(descricao), recompensaGold(recompensaGold), recompensaXP(recompensaXP), andar(andar), nivelRequerido(nivelRequerido) {
    // O construtor inicializa os atributos da quest com os valores passados como par�metros
}

// M�todos de acesso para obter informa��es sobre a quest

std::string Quest::getNome() const {
    return nome; // Retorna o nome da quest
}

std::string Quest::getDescricao() const {
    return descricao; // Retorna a descri��o da quest
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
    return nivelRequerido; // Retorna o n�vel m�nimo exigido para a quest
}

// M�todo para exibir as informa��es detalhadas da quest
void Quest::exibirQuest() const {
    std::cout << "Nome: " << nome << "\n";                      // Exibe o nome da quest
    std::cout << "Descricao: " << descricao << "\n";              // Exibe a descri��o da quest
    std::cout << "Recompensa em Ouro: " << recompensaGold << "\n"; // Exibe a recompensa em ouro
    std::cout << "Recompensa em XP: " << recompensaXP << "\n";    // Exibe a recompensa em XP
    std::cout << "Andar: " << andar << "\n";                      // Exibe o andar onde a quest ocorre
    std::cout << "Nivel Requerido: " << nivelRequerido << "\n";    // Exibe o n�vel necess�rio para realizar a quest
}
