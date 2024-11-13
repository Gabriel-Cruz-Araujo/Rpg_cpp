#include "Expedicao.h"
#include <iostream>
#include "Inimigo.h"
#include "Combate.h"
#include "Sistema.h"
#include "Inventario.h"  
#include <cstdlib>       // Para as fun��es rand() e srand()

using namespace std;

// Construtor da classe Expedicao, inicializa com o jogador e define andar inicial e status da expedi��o
Expedicao::Expedicao(Personagem* jogador)
    : jogador(jogador), andarAtual(0), emExpedicao(false) {}

// Inicia o processo da expedi��o, onde o jogador enfrenta eventos em sequ�ncia at� decidir sair
void Expedicao::iniciarExpedicao() {
    cout << "Iniciando expedicao...\n";
    emExpedicao = true;

    while (emExpedicao) {
        encontrarEvento();  // Encontra um evento a cada itera��o da expedi��o
    }
}

// Determina aleatoriamente um evento para o jogador a cada andar
void Expedicao::encontrarEvento() {
    srand(static_cast<unsigned>(time(0))); // Inicializa o gerador de n�meros aleat�rios
    int evento = rand() % 100; // Gera um n�mero aleat�rio de 0 a 99

    // Checa se o jogador est� em uma miss�o e no andar correto para a miss�o
    if (jogador->missaoAtiva != nullptr) {
        if (andarAtual == jogador->missaoAtiva->getAndar()) {
            cout << "Voce chegou ao andar da missao - " << jogador->missaoAtiva->getNome() << endl;
            Inimigo inimigo("Esqueleto", jogador->missaoAtiva->getNivelRequerido());
            Combate combate(jogador, &inimigo);
            combate.iniciarCombate(); // Inicia o combate

            if (jogador->saude > 0) {
                cout << "\nMissao completa\n";
                cout << "\nGold ganho: " << jogador->missaoAtiva->getRecompensaGold();
                cout << "\nXp ganho: " << jogador->missaoAtiva->getRecompensaXP() << "\n";
                jogador->inventario.gold += jogador->missaoAtiva->getRecompensaGold();
                jogador->xp += jogador->missaoAtiva->getRecompensaXP();
                jogador->missaoAtiva = nullptr;
                while (jogador->xp >= jogador->xpParaProximoNivel()) {
                    jogador->subirNivel();  // Jogador sobe de n�vel
                }
            }
            else {
                cout << "\nMissao falha\n";
            }
        }
    }
    else if (andarAtual % 10 == 0 && andarAtual != 0) {
        // Encontra um inimigo em andares m�ltiplos de 10
        Inimigo inimigo("Minotauro", andarAtual); // Inimigo de exemplo
        Combate combate(jogador, &inimigo);
        combate.iniciarCombate(); // Inicia o combate
    }
    else if (evento < 25) {
        // 25% de chance de encontrar um item
        encontrarItem();
    }
    else if (evento < 50) {
        // 25% de chance de encontrar um inimigo
        Inimigo inimigo("Goblin", andarAtual); // Inimigo de exemplo
        Combate combate(jogador, &inimigo);
        combate.iniciarCombate(); // Inicia o combate
    }
    else {
        cout << "Nada aconteceu.\n";  // Evento neutro
    }

    // Op��o para avan�ar ou sair da expedi��o ap�s cada evento
    if (jogador->saude <= 0) {
        jogador->saude = jogador->maxSaude;  // Recupera a sa�de do jogador
        emExpedicao = false;
    }
    else {
        cout << "Deseja avan�ar para o proximo andar? (s/n): ";
        char escolha;
        cin >> escolha;
        if (escolha == 's') {
            avancarParaProximoAndar();  // Avan�a para o pr�ximo andar
        }
        else {
            jogador->saude = jogador->maxSaude;
            emExpedicao = false;  // Sai da expedi��o e retorna ao menu principal
        }
    }
}

// Fun��o para encontrar um item aleat�rio durante a expedi��o
void Expedicao::encontrarItem() {
    int itemEncontrado = rand() % 4 + 1; // Seleciona um item entre 1 e 4
    switch (itemEncontrado) {
    case 1:
        jogador->inventario.gold += 200;
        cout << "Voce encontrou 200 de ouro!\n";
        break;
    case 2:
        jogador->inventario.gold += 100;
        cout << "Voce encontrou 100 de ouro!\n";
        break;
    case 3: {
        Item bomba("Bomba", "Explosivo poderoso", 1, 2, 75, false, 75); // Item que causa dano ao inimigo
        jogador->inventario.adicionarItem(bomba);
        cout << "Voce encontrou uma bomba!\n";
        break;
    }
    case 4: {
        Item pocao("Pocao de Cura", "Recupera 100 pontos de vida", 1, 1, 100, false, 50); // Item que cura o jogador
        jogador->inventario.adicionarItem(pocao);
        cout << "Voce encontrou uma po��o de cura!\n";
        break;
    }
    }
}

// Avan�a para o pr�ximo andar da expedi��o
void Expedicao::avancarParaProximoAndar() {
    andarAtual++;
    cout << "Voce avan�ou para o andar " << andarAtual << ".\n";
}
