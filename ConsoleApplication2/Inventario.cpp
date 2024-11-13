#include "Inventario.h"
#include "Equipamento.h"
#include <iostream>

using namespace std;

class Quest;

// Construtor da classe Inventario
Inventario::Inventario()
    : equip("espada basica", "espada basica para aventureiros iniciantes", 1, 3, 0, 100), gold(150) {}
// Inicializa o inventário com um equipamento básico e 150 de ouro.
// O equipamento "espada basica" tem atributos como nome, descrição, tipo (1 para espada), ataque, defesa e durabilidade.

void Inventario::adicionarItem(const Item& item) {
    itens.push_back(item); // Adiciona um novo item ao vetor 'itens' do inventário.
}

void Inventario::adicionarEquipamento(const Equipamento& equip) {
    equipamentos.push_back(equip); // Adiciona um novo equipamento ao vetor 'equipamentos' do inventário.
}

void Inventario::listarItens() const {
    if (itens.empty()) {
        cout << "Inventario vazio.\n"; // Exibe mensagem se o inventário de itens estiver vazio.
    }
    else {
        cout << "Itens no inventario:\n";
        for (const auto& item : itens) {
            cout << "- " << item.nome << "\n"; // Lista os itens do inventário com seus nomes.
        }
    }
    cout << "Ouro: " << gold << "\n"; // Exibe a quantidade de ouro no inventário.
}

void Inventario::listarEquipamentos() const {
    if (equipamentos.empty()) {
        cout << "Voce nao tem equipamentos no inventario.\n"; // Exibe mensagem se o inventário de equipamentos estiver vazio.
    }
    else {
        for (size_t i = 0; i < equipamentos.size(); ++i) {
            // Lista os equipamentos do inventário com seus nomes, descrições e tipos (Espada, Armadura, Amuleto).
            cout << i + 1 << " - " << equipamentos[i].nome << ": "
                << equipamentos[i].descricao << " (Tipo: "
                << (equipamentos[i].tipo == 1 ? "Espada" : (equipamentos[i].tipo == 2 ? "Armadura" : "Amuleto"))
                << ")\n";
        }
    }

    // Exibe o equipamento atualmente equipado, se houver
    if (!equip.nome.empty()) {
        cout << "\nEquipamento atual: " << equip.nome << " ("
            << equip.descricao << ")\n"; // Exibe o nome e descrição do equipamento equipado.
    }
}

void Inventario::equiparEquipamento(int indice) {
    // Verifica se o índice fornecido é válido
    if (indice < 1 || indice > equipamentos.size()) {
        cout << "Equipamento invalido.\n"; // Mensagem de erro caso o índice não seja válido.
        return;
    }

    // Seleciona o equipamento com base no índice fornecido (subtrai 1 porque o índice começa em 0).
    Equipamento equipamentoSelecionado = equipamentos[indice - 1];

    // Se já há um equipamento equipado, ele é movido de volta para o inventário.
    if (equip.nome != "") {  // Verifica se já há um equipamento atual.
        equipamentos.push_back(equip);  // Adiciona o equipamento atual de volta ao inventário.
    }

    // Equipamos o novo equipamento selecionado.
    equip = equipamentoSelecionado;  // Atualiza o equipamento atualmente equipado.
    equipamentos.erase(equipamentos.begin() + (indice - 1));  // Remove o equipamento do inventário.

    cout << "Voce equipou " << equip.nome << " com sucesso!\n"; // Mensagem de sucesso ao equipar o novo equipamento.
}
