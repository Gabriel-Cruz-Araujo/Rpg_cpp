#pragma once
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include "Equipamento.h"
#include <vector>

// Classe Inventario, responsável por gerenciar os itens e equipamentos do jogador
class Inventario {
public:
    std::vector<Item> itens; // Vetor de itens no inventário
    std::vector<Equipamento> equipamentos; // Vetor de equipamentos no inventário
    Equipamento equip; // Equipamento atual do jogador
    int gold; // Quantidade de ouro no inventário

    Inventario(); // Construtor do inventário, inicializa o inventário com valores padrão

    // Método para adicionar um item ao inventário
    void adicionarItem(const Item& item);

    // Método para listar os itens no inventário
    void listarItens() const;

    // Método para adicionar um equipamento ao inventário
    void adicionarEquipamento(const Equipamento& equip);

    // Método para listar os equipamentos no inventário
    void listarEquipamentos() const;

    // Método para equipar um equipamento, baseado no índice fornecido
    void equiparEquipamento(int indice);
};

#endif // INVENTARIO_H
