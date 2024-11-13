#include "Loja.h"
#include "Personagem.h"
#include <iostream>

// Construtor da classe Loja
Loja::Loja() {
    // Inicializando a lista de itens da loja
    itensDisponiveis.push_back(Item("Pocao de Cura", "Recupera 100 de HP", 1, 1, 100, false, 50)); // Poção de Cura: item que recupera HP
    itensDisponiveis.push_back(Item("Bomba", "Causa 75 de dano", 1, 2, 75, false, 75)); // Bomba: item que causa dano

    // Inicializando a lista de equipamentos da loja
    equipamentosDisponiveis.push_back(Equipamento("Espada de Ferro", "Uma espada de ferro utilizado pela cavalaria", 1, 10, 1, 100)); // Espada de Ferro: equipamento tipo espada
    equipamentosDisponiveis.push_back(Equipamento("Espada de Prata", "Uma espada de prata utilizada para matar grandes bestas", 1, 30, 5, 100)); // Espada de Prata: equipamento tipo espada
    equipamentosDisponiveis.push_back(Equipamento("Amuleto de Ferro", "Um amuleto de ferro utilizado pela guilda de magos", 2, 5, 1, 100)); // Amuleto de Ferro: equipamento tipo amuleto
    equipamentosDisponiveis.push_back(Equipamento("Amuleto de Prata", "Um amuleto de prata utilizado para feitiços avançados", 2, 10, 5, 100)); // Amuleto de Prata: equipamento tipo amuleto
    equipamentosDisponiveis.push_back(Equipamento("Escudo de Ferro", "Um escudo de prata utilizado pela guarda", 3, 15, 1, 100)); // Escudo de Ferro: equipamento tipo escudo
    equipamentosDisponiveis.push_back(Equipamento("Escudo de Prata", "Um escudo capaz de proteger contra criaturas demoníacas", 3, 30, 5, 100)); // Escudo de Prata: equipamento tipo escudo
}

// Método para exibir os itens disponíveis na loja
void Loja::mostrarItens() const {
    std::cout << "\n=== Itens da Loja ===\n";
    for (size_t i = 0; i < itensDisponiveis.size(); ++i) {
        std::cout << i + 1 << " - " << itensDisponiveis[i].nome << ": "
            << itensDisponiveis[i].preco << " Gold (Descricao: "
            << itensDisponiveis[i].descricao << ")\n";
    }
}

// Método para exibir os equipamentos disponíveis na loja
void Loja::mostrarEquipamentos() const {
    std::cout << "\n=== Equipamentos da Loja ===\n";
    for (size_t i = 0; i < equipamentosDisponiveis.size(); ++i) {
        std::cout << i + 1 << " - " << equipamentosDisponiveis[i].nome << ": "
            << equipamentosDisponiveis[i].preco << " Gold (Descricao: "
            << equipamentosDisponiveis[i].descricao << ")\n";
    }
}

// Método para realizar a compra de um item da loja
bool Loja::comprarItem(int indice, Personagem* personagem) {  // Recebe ponteiro para Personagem
    // Verifica se o índice está dentro do intervalo dos itens disponíveis
    if (indice < 1 || indice > itensDisponiveis.size() + equipamentosDisponiveis.size()) {
        std::cout << "Item invalido!\n";
        return false;
    }

    // Se o índice corresponde a um item
    if (indice <= itensDisponiveis.size()) {
        Item& item = itensDisponiveis[indice - 1]; // Acessa o item baseado no índice

        // Verifica se o personagem tem gold suficiente para a compra
        if (personagem->inventario.gold < item.preco) {
            std::cout << "Voce nao tem gold suficiente para comprar " << item.nome << ".\n";
            return false;
        }

        personagem->inventario.gold -= item.preco;  // Deduz o valor da compra do gold do personagem
        personagem->inventario.adicionarItem(item); // Adiciona o item ao inventário do personagem
        std::cout << "Voce comprou o item " << item.nome << " com sucesso!\n";
    }
    else {
        // Se o índice corresponde a um equipamento
        int indiceEquipamento = indice - itensDisponiveis.size();
        Equipamento& equip = equipamentosDisponiveis[indiceEquipamento - 1]; // Acessa o equipamento

        // Verifica se o personagem tem gold suficiente para a compra
        if (personagem->inventario.gold < equip.preco) {
            std::cout << "Voce nao tem gold suficiente para comprar " << equip.nome << ".\n";
            return false;
        }

        personagem->inventario.gold -= equip.preco;  // Deduz o valor da compra do gold do personagem
        personagem->inventario.adicionarEquipamento(equip); // Adiciona o equipamento ao inventário
        std::cout << "Voce comprou o equipamento " << equip.nome << " com sucesso!\n";
    }

    return true;
}

// Método para realizar a compra de um equipamento da loja
bool Loja::comprarEquipamento(int indice, Personagem* personagem) {
    // Verifica se o índice está dentro do intervalo dos equipamentos disponíveis
    if (indice < 1 || indice > equipamentosDisponiveis.size()) {
        std::cout << "Equipamento invalido!\n";
        return false;
    }

    // Acessa o equipamento baseado no índice
    Equipamento& equip = equipamentosDisponiveis[indice - 1];

    // Verifica se o personagem tem gold suficiente para a compra
    if (personagem->inventario.gold < equip.preco) {
        std::cout << "Voce nao tem gold suficiente para comprar " << equip.nome << ".\n";
        return false;
    }

    // Deduz o valor da compra do gold do personagem
    personagem->inventario.gold -= equip.preco;

    // Adiciona o equipamento ao inventário do personagem
    personagem->inventario.adicionarEquipamento(equip);

    std::cout << "Voce comprou o equipamento " << equip.nome << " com sucesso!\n";

    return true;
}
