#include "Sistema.h"
#include <iostream>
#include "Inimigo.h"
#include "Combate.h"
#include "Loja.h"
using namespace std;

void Sistema::iniciarJogo() {
    while (jogoAtivo) {
        exibirMenu();
    }
}

Sistema::Sistema() {
    // Inicializa a loja
    loja = Loja();
    // Inicializa as missões disponíveis
    missoesDisponiveis.emplace_back("Explorador do Andar 1", "Explore o primeiro andar e elimine o inimigos!", 100, 1500, 1, 1);
    missoesDisponiveis.emplace_back("Caçador de esqueleto", "Derrote o esquleto no andar 5", 100, 3000, 5, 2);
    missoesDisponiveis.emplace_back("Coleta de item", "Encontre o item perdido no andar 12", 200, 4000, 12, 6);
    missoesDisponiveis.emplace_back("Chefe do 10 Andar", "Derrote o chefe do decimo andar!", 200, 5000, 10, 5);
    habilidadesDisponiveis.emplace_back("Golpe Pesado", "Um ataque que causa dano significativo ao inimigo.", 40, 100, 2);
    habilidadesDisponiveis.emplace_back("Cura Rápida", "Restaura uma grande quantidade de saúde.", 60, 50, 3);
    habilidadesDisponiveis.emplace_back("Relampago", "Um ataque eletrico que da muito dano.", 80, 200, 6);
}


void Sistema::exibirMenu() {
    cout << "\n=== Menu Principal ===\n";
    cout << "1 - Criar Personagem\n2 - Iniciar Expedicao\n3 - Ver Inventario\n";
    cout << "4 - Quadro de Missoes\n5 - Status do Personagem\n6 - Habilidades\n";
    cout << "7 - Loja\n8 - Arena de Combate\n9 - Santuario\n10 - Sair\nEscolha uma opcao: "; 
    int opcao;
    cin >> opcao;
    switch (opcao) {
    case 1:
        // Verifica se o jogador já foi criado
        if (jogador == nullptr) {
            criarPersonagem();
        }
        else {
            cout << "Você já tem um personagem criado!\n";
        }
        break;
    case 2:
        if (jogador) {
            Expedicao expedicao(jogador);
            expedicao.iniciarExpedicao();
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 3:
        if (jogador) {
            verInventario(); // Chama a função de listar itens  do personagem
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 4:
        if (jogador) {
            quadroDeMissoes(); // Chama a função do quadro de missoes
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 5:
        if (jogador) {
            exibirStatus(); // Chama a função de listar status  do personagem
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 6:
        if (jogador) {
            jogador->listarHabilidades(); // Chama a função de listar habilidades do personagem
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 7:
        if (jogador) {
            menuLoja(); // Chama a função da loja
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 8:
        if (jogador) {
            arenaDeCombate();  // Chama a função da arena de combate
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 9:
        if (jogador) {
            menuSantuario(); // Chama a função do santuario
        }
        else {
            cout << "Crie um personagem primeiro!\n";
        }
        break;
    case 10:
        jogoAtivo = false;
        cout << "Saindo do jogo...\n";
        break;
    default:
        cout << "Opcao invalida. Tente novamente.\n";
    }
}


void Sistema::menuLoja() {
    if (!jogador) {
        cout << "Crie um personagem primeiro!\n";
        return;
    }

    cout << "Voce tem " << jogador->inventario.gold << " Gold.\n";

    // Oferece ao jogador escolher entre a loja de itens ou a loja de equipamentos
    cout << "Escolha a loja:\n";
    cout << "1 - Loja de Itens\n";
    cout << "2 - Loja de Equipamentos\n";
    cout << "0 - Voltar ao menu principal\n";
    int opcaoLoja;
    cin >> opcaoLoja;

    // Se a escolha for inválida, voltar ao menu principal
    if (opcaoLoja == 0) {
        cout << "Voltando ao menu principal.\n";
        return;
    }

    // Se o jogador escolher a loja de itens
    if (opcaoLoja == 1) {
        loja.mostrarItens();  // Exibe os itens da loja
        cout << "Escolha um item para comprar (1-" << loja.itensDisponiveis.size() << ") ou 0 para voltar: ";
        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            cout << "Voltando ao menu da loja.\n";
        }
        else {
            loja.comprarItem(opcao, jogador);  // Compra o item
        }
    }

    // Se o jogador escolher a loja de equipamentos
    else if (opcaoLoja == 2) {
        loja.mostrarEquipamentos();  // Exibe os equipamentos da loja
        cout << "Escolha um equipamento para comprar (1-" << loja.equipamentosDisponiveis.size() << ") ou 0 para voltar: ";
        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            cout << "Voltando ao menu da loja.\n";
        }
        else {
            loja.comprarEquipamento(opcao, jogador);  // Compra o equipamento
        }
    }
    else {
        cout << "Opcao invalida. Voltando ao menu principal.\n";
    }
}
void Sistema::criarPersonagem() {
    cout << "Digite o nome do personagem: ";
    string nome;
    cin >> nome;

    string classe;
    while (true) {
        cout << "Escolha a classe (guerreiro/mago): ";
        cin >> classe;
        // Verifica se a classe inserida é válida
        if (classe == "guerreiro" || classe == "mago") {
            break; // Sai do loop se a classe for válida
        }
        else {
            cout << "Classe invalida! Por favor, escolha entre 'guerreiro' ou 'mago'.\n";
        }
    }

    jogador = new Personagem(nome, classe);
    cout << "Personagem criado com sucesso!\n";
}

void Sistema::verInventario() {
    if (!jogador) {
        cout << "Nenhum personagem criado.\n";
        return;
    }

    int opcao;
    do {
        // Menu principal de visualização de inventário
        cout << "\n=== Inventario ===\n";
        cout << "1 - Ver Itens\n";
        cout << "2 - Ver Equipamentos\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            jogador->inventario.listarItens();  // Lista os itens
            break;
        case 2:
            verEquipamentos();  // Função que lida com o submenu de equipamentos
            break;
        case 0:
            cout << "Voltando ao menu anterior.\n";
            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 0);  // Volta ao menu principal
}

void Sistema::verEquipamentos() {
    int opcao;
    do {
        cout << "\n=== Equipamentos do Inventário ===\n";
        jogador->inventario.listarEquipamentos();  // Exibe os equipamentos

        cout << "Escolha um equipamento para equipar (1-" << jogador->inventario.equipamentos.size() << ") ou 0 para voltar: ";
        cin >> opcao;

        if (opcao == 0) {
            cout << "Voltando ao menu de inventário.\n";
            break;
        }
        else if (opcao >= 1 && opcao <= jogador->inventario.equipamentos.size()) {
            jogador->inventario.equiparEquipamento(opcao);  // Equipar o equipamento selecionado
        }
        else {
            cout << "Opção invalida. Tente novamente.\n";
        }
    } while (opcao != 0);
}




void Sistema::verMissoes() {
    // Implementar lógica para exibir missões
    cout << "Missoes disponiveis:\n";
    cout << "1 - Va para o andar 10 e elimine o chefe.\n";
}

void Sistema::exibirStatus() {
    if (jogador) jogador->exibirStatus();
    else cout << "Nenhum personagem criado.\n";
}

void Sistema::quadroDeMissoes() {
    if (jogador->missaoAtiva) {
        cout << "Voce ja possui uma missao ativa: " << jogador->missaoAtiva->getNome() << ". Complete-a antes de aceitar outra.\n";
        return;
    }

    if (!jogador) {
        cout << "Crie um personagem primeiro!\n";
        return;
    }

    cout << "\n=== Quadro de Missoes ===\n";
    for (size_t i = 0; i < missoesDisponiveis.size(); ++i) {
        cout << i + 1 << " - " << missoesDisponiveis[i].getNome() << ": "
            << missoesDisponiveis[i].getDescricao() << " (Recompensa: "
            << missoesDisponiveis[i].getRecompensaGold() << " Gold, "
            << missoesDisponiveis[i].getRecompensaXP() << " XP, "
            << "Nivel Requerido: " << missoesDisponiveis[i].getNivelRequerido() << ")\n\n";
    }

    cout << "Escolha uma missao para aceitar (1-4) ou 0 para voltar ao menu principal: ";
    int opcao;
    cin >> opcao;

    if (opcao >= 1 && opcao <= 4) {
        Quest& missaoEscolhida = missoesDisponiveis[opcao - 1];

        // Verifica o nível do jogador
        if (jogador->nivel >= missaoEscolhida.getNivelRequerido()) {
            jogador->missaoAtiva = &missaoEscolhida;
            cout << "Voce aceitou a missao: " << jogador->missaoAtiva->getNome() << "!\n";
        }
        else {
            cout << "Seu nivel e muito baixo para esta missao. Nivel necessario: "
                << missaoEscolhida.getNivelRequerido() << ". Seu nivel: "
                << jogador->nivel << ".\n";
        }
    }
    else if (opcao == 0) {
        cout << "Voltando ao menu principal.\n";
    }
    else {
        cout << "Opcao invalida. Voltando ao menu principal.\n";
    }
}

void Sistema::menuSantuario() {
    if (!jogador) {
        cout << "Crie um personagem primeiro!\n";
        return;
    }

    cout << "Voce tem " << jogador->inventario.gold << " Gold.\n";
    cout << "Nivel do jogador: " << jogador->nivel << "\n";

    // Exibe as habilidades disponíveis para compra
    cout << "\n=== Menu do Santuário ===\n";
    for (size_t i = 0; i < habilidadesDisponiveis.size(); ++i) {
        const Habilidade& habilidade = habilidadesDisponiveis[i];
        cout << i + 1 << " - " << habilidade.nome << ": "
            << habilidade.descricao << " (Custo: "
            << habilidade.custoGold << " Gold, "
            << "Nivel Requerido: " << habilidade.nivelRequerido << ")\n\n";
    }

    cout << "Escolha uma habilidade para comprar (1-" << habilidadesDisponiveis.size() << ") ou 0 para voltar: ";
    int opcao;
    cin >> opcao;

    if (opcao == 0) {
        cout << "Voltando ao menu principal.\n";
        return;
    }

    // Verifica se a opção está dentro do intervalo correto
    if (opcao >= 1 && opcao <= habilidadesDisponiveis.size()) {
        Habilidade& habilidadeEscolhida = habilidadesDisponiveis[opcao - 1];

        // Verifica o nível do jogador
        if (jogador->nivel >= habilidadeEscolhida.nivelRequerido) {
            // Verifica se o jogador tem gold suficiente
            if (jogador->inventario.gold >= habilidadeEscolhida.custoGold) {
                // Deduz o custo do gold do jogador
                jogador->inventario.gold -= habilidadeEscolhida.custoGold;
                // Adiciona a habilidade ao personagem (supondo que exista um método de adicionar habilidade)
                jogador->adicionarHabilidade(habilidadeEscolhida);
                cout << "Voce comprou a habilidade: " << habilidadeEscolhida.nome << "!\n";
            }
            else {
                cout << "Voce nao tem gold suficiente para comprar esta habilidade.\n";
            }
        }
        else {
            cout << "Seu nivel e muito baixo para esta habilidade. Nivel necessario: "
                << habilidadeEscolhida.nivelRequerido << ". Seu nivel: "
                << jogador->nivel << ".\n";
        }
    }
    else {
        cout << "Opcao invalida. Voltando ao menu principal.\n";
    }
}

void Sistema::arenaDeCombate() {
    if (!jogador) {
        cout << "Crie um personagem primeiro!\n";
        return;
    }

    cout << "Voce esta entrando na arena de combate contra inimigos poderosos!\n";

    // Criação de inimigos de alto nível (por exemplo, nível 20 a 50)
    int nivelInimigo = rand() % 31 + 20;  // Gera um nível entre 20 e 50
    Inimigo inimigo("Inimigo Lendario", nivelInimigo);

    // Inicia o combate
    Combate combate(jogador, &inimigo);
    combate.iniciarCombate();

    // Se o jogador vencer, ele tem uma chance de ganhar a espada ou gold
    if (jogador->saude > 0) {
        cout << "Voce venceu o combate!\n";

        // Geração de recompensa
        int chance = rand() % 100;
        if (chance < 15) {
            cout << "Voce ganhou uma espada lendaria!\n";
            Equipamento espadaLendaria("Espada Lendaria", "uma espada das lendas capaz de cortar o mal", 1, 50, 10, 100);
            jogador->inventario.adicionarEquipamento(espadaLendaria);
        }
        else {
            cout << "Voce ganhou 1000 Gold!\n";
            jogador->inventario.gold += 1000;
        }
    }
    else {
        cout << "Você foi derrotado! Volte quando estiver mais forte.\n";
    }
}