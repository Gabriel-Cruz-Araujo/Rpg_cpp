#include "Inventario.h"
#include "Equipamento.h"
#include <iostream>

using namespace std;

class Quest;

// Construtor da classe Inventario
Inventario::Inventario()
    : equip("espada basica", "espada basica para aventureiros iniciantes", 1, 3, 0, 100), gold(150) {}
// Inicializa o invent�rio com um equipamento b�sico e 150 de ouro.
// O equipamento "espada basica" tem atributos como nome, descri��o, tipo (1 para espada), ataque, defesa e durabilidade.

void Inventario::adicionarItem(const Item& item) {
    itens.push_back(item); // Adiciona um novo item ao vetor 'itens' do invent�rio.
}

void Inventario::adicionarEquipamento(const Equipamento& equip) {
    equipamentos.push_back(equip); // Adiciona um novo equipamento ao vetor 'equipamentos' do invent�rio.
}

void Inventario::listarItens() const {
    if (itens.empty()) {
        cout << "Inventario vazio.\n"; // Exibe mensagem se o invent�rio de itens estiver vazio.
    }
    else {
        cout << "Itens no inventario:\n";
        for (const auto& item : itens) {
            cout << "- " << item.nome << "\n"; // Lista os itens do invent�rio com seus nomes.
        }
    }
    cout << "Ouro: " << gold << "\n"; // Exibe a quantidade de ouro no invent�rio.
}

void Inventario::listarEquipamentos() const {
    if (equipamentos.empty()) {
        cout << "Voce nao tem equipamentos no inventario.\n"; // Exibe mensagem se o invent�rio de equipamentos estiver vazio.
    }
    else {
        for (size_t i = 0; i < equipamentos.size(); ++i) {
            // Lista os equipamentos do invent�rio com seus nomes, descri��es e tipos (Espada, Armadura, Amuleto).
            cout << i + 1 << " - " << equipamentos[i].nome << ": "
                << equipamentos[i].descricao << " (Tipo: "
                << (equipamentos[i].tipo == 1 ? "Espada" : (equipamentos[i].tipo == 2 ? "Armadura" : "Amuleto"))
                << ")\n";
        }
    }

    // Exibe o equipamento atualmente equipado, se houver
    if (!equip.nome.empty()) {
        cout << "\nEquipamento atual: " << equip.nome << " ("
            << equip.descricao << ")\n"; // Exibe o nome e descri��o do equipamento equipado.
    }
}

void Inventario::equiparEquipamento(int indice) {
    // Verifica se o �ndice fornecido � v�lido
    if (indice < 1 || indice > equipamentos.size()) {
        cout << "Equipamento invalido.\n"; // Mensagem de erro caso o �ndice n�o seja v�lido.
        return;
    }

    // Seleciona o equipamento com base no �ndice fornecido (subtrai 1 porque o �ndice come�a em 0).
    Equipamento equipamentoSelecionado = equipamentos[indice - 1];

    // Se j� h� um equipamento equipado, ele � movido de volta para o invent�rio.
    if (equip.nome != "") {  // Verifica se j� h� um equipamento atual.
        equipamentos.push_back(equip);  // Adiciona o equipamento atual de volta ao invent�rio.
    }

    // Equipamos o novo equipamento selecionado.
    equip = equipamentoSelecionado;  // Atualiza o equipamento atualmente equipado.
    equipamentos.erase(equipamentos.begin() + (indice - 1));  // Remove o equipamento do invent�rio.

    cout << "Voce equipou " << equip.nome << " com sucesso!\n"; // Mensagem de sucesso ao equipar o novo equipamento.
}
