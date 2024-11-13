#pragma once
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include "Equipamento.h"
#include <vector>

// Classe Inventario, respons�vel por gerenciar os itens e equipamentos do jogador
class Inventario {
public:
    std::vector<Item> itens; // Vetor de itens no invent�rio
    std::vector<Equipamento> equipamentos; // Vetor de equipamentos no invent�rio
    Equipamento equip; // Equipamento atual do jogador
    int gold; // Quantidade de ouro no invent�rio

    Inventario(); // Construtor do invent�rio, inicializa o invent�rio com valores padr�o

    // M�todo para adicionar um item ao invent�rio
    void adicionarItem(const Item& item);

    // M�todo para listar os itens no invent�rio
    void listarItens() const;

    // M�todo para adicionar um equipamento ao invent�rio
    void adicionarEquipamento(const Equipamento& equip);

    // M�todo para listar os equipamentos no invent�rio
    void listarEquipamentos() const;

    // M�todo para equipar um equipamento, baseado no �ndice fornecido
    void equiparEquipamento(int indice);
};

#endif // INVENTARIO_H
