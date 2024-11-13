#include "Combate.h"  // Inclui o arquivo de cabeçalho para a classe Combate
#include "Sistema.h"  // Inclui o sistema relacionado ao jogo
#include <iostream>   // Biblioteca padrão para entrada e saída

using namespace std;

// Construtor da classe Combate, inicializa com o jogador e o inimigo dados e define o turno do jogador como verdadeiro
Combate::Combate(Personagem* jogador, Inimigo* inimigo)
    : jogador(jogador), inimigo(inimigo), turnoDoJogador(true) {}

// Função principal para iniciar o combate
void Combate::iniciarCombate() {
    cout << "Iniciando combate contra " << inimigo->tipo << "!\n";

    // Loop principal do combate, que ocorre enquanto ambos têm saúde > 0
    while (jogador->saude > 0 && inimigo->saude > 0) {
        if (turnoDoJogador) {  // Caso seja o turno do jogador
            exibirStatus();  // Exibe o status do jogador e do inimigo

            // Mostra as opções de combate para o jogador
            cout << "\nEscolha sua acao (1: Atacar, 2: Habilidade, 3: Item, 4: Fugir): \n";
            int escolha;
            cin >> escolha;

            switch (escolha) {
            case 1:  // Ação de ataque
                cout << "Voce atacou o " << inimigo->tipo << "!\n";
                inimigo->saude -= jogador->forca;  // Diminui a saúde do inimigo
                cout << "Dano causado: " << jogador->forca << "\n";
                break;

            case 2:  // Ação de usar habilidade
                if (!jogador->habilidades.empty()) {  // Verifica se o jogador tem habilidades
                    cout << "Escolha uma habilidade:\n";
                    for (size_t i = 0; i < jogador->habilidades.size(); ++i) {
                        cout << i + 1 << ": " << jogador->habilidades[i].nome << "\n";
                    }
                    int indice;
                    cin >> indice;
                    usarHabilidade(indice - 1);  // Usa a habilidade escolhida
                }
                else {
                    cout << "Você não tem habilidades!\n";
                }
                break;

            case 3:  // Ação de usar item
                if (!jogador->inventario.itens.empty()) {  // Verifica se há itens no inventário
                    cout << "Escolha um item:\n";
                    for (size_t i = 0; i < jogador->inventario.itens.size(); ++i) {
                        cout << i + 1 << " - " << jogador->inventario.itens[i].nome << "\n";
                    }

                    int opcaoItem;
                    cin >> opcaoItem;

                    // Verifica se a opção de item é válida
                    if (opcaoItem >= 1 && opcaoItem <= jogador->inventario.itens.size()) {
                        usarItem(jogador->inventario.itens[opcaoItem - 1].nome);  // Usa o item escolhido
                    }
                    else {
                        cout << "Opcao invalida. Tente novamente.\n";
                    }
                }
                else {
                    cout << "Seu inventario esta vazio!\n";
                }
                break;

            case 4:  // Ação de fugir
                cout << "Voce fugiu da luta!\n";
                jogador->saude = 0;  // Define a saúde do jogador como zero para sair do loop de combate
                return;

            default:  // Caso a escolha seja inválida
                cout << "Escolha invalida!\n";
            }
        }
        else {  // Caso seja o turno do inimigo
            cout << "O " << inimigo->tipo << " ataca!\n";
            jogador->saude -= inimigo->ataque;  // O inimigo causa dano ao jogador
            cout << "Dano causado pelo inimigo: " << inimigo->ataque << "\n \n";
        }

        turnoDoJogador = !turnoDoJogador;  // Alterna o turno
    }

    // Exibe o resultado do combate
    if (jogador->saude <= 0) {
        cout << "Voce foi derrotado!\n";
    }
    else {
        cout << "Voce venceu o combate!\n";
        ganharXP();  // O jogador ganha XP se vencer o combate
    }
}

// Função para calcular o ganho de XP ao vencer um combate
void Combate::ganharXP() {
    int xpGanho = inimigo->nivel * 100;  // XP ganho é proporcional ao nível do inimigo
    cout << "Voce ganhou " << xpGanho << " de XP!\n";
    jogador->xp += xpGanho;  // Adiciona o XP ao jogador

    // Verifica se o jogador deve subir de nível
    while (jogador->xp >= jogador->xpParaProximoNivel()) {
        jogador->subirNivel();  // Jogador sobe de nível
    }
}

// Função para usar uma habilidade
void Combate::usarHabilidade(int indice) {
    if (indice >= 0 && indice < jogador->habilidades.size()) {
        cout << "Voce usou " << jogador->habilidades[indice].nome << "!\n";
        inimigo->saude -= jogador->habilidades[indice].dano + jogador->magia / 2;  // Aplica dano ao inimigo
        cout << "Dano causado pela habilidade: " << jogador->habilidades[indice].dano << "\n";
    }
    else {
        cout << "Habilidade invalida!\n";
    }
}

// Função para usar um item
void Combate::usarItem(const std::string& nome) {
    for (auto it = jogador->inventario.itens.begin(); it != jogador->inventario.itens.end(); ++it) {
        if (it->nome == nome) {
            // Aplica o efeito dependendo do tipo de item
            if (it->tipo == 1) {  // Item de cura
                jogador->saude += it->efeito;
                cout << "Voce usou " << it->nome << " e restaurou " << it->efeito << " de saude!\n";
            }
            else if (it->tipo == 2) {  // Item de ataque
                inimigo->saude -= it->efeito;
                cout << "Voce usou " << it->nome << " e causou " << it->efeito << " de dano ao inimigo!\n";
            }
            jogador->inventario.itens.erase(it);  // Remove o item do inventário após o uso
            return;
        }
    }
    cout << "Item nao encontrado no inventario!\n";  // Mensagem caso o item não seja encontrado
}

// Função para exibir o status do jogador e do inimigo durante o combate
void Combate::exibirStatus() const {
    cout << "Seu status: " << jogador->saude << "/" << jogador->maxSaude << " (Nivel " << jogador->nivel << ")\n";
    cout << inimigo->tipo << " status: " << inimigo->saude << "/" << inimigo->saudeMax << " (Nivel " << inimigo->nivel << ")\n";
}
