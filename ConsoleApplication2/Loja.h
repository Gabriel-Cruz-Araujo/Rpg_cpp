#pragma once
#ifndef LOJA_H
#define LOJA_H

#include <string>
#include <vector>
#include "Item.h"       
#include "Equipamento.h" 
#include "Personagem.h"

class Loja {
public:
    std::vector<Item> itensDisponiveis;       // Lista de itens da loja (poções, bombas, etc.)
    std::vector<Equipamento> equipamentosDisponiveis; // Lista de equipamentos da loja (espadas, escudos, amuletos)

    Loja(); // Construtor para inicializar os itens e equipamentos da loja
    void mostrarItens() const; // Mostrar itens da loja
    void mostrarEquipamentos() const; // Mostrar equipamentos da loja
    bool comprarItem(int indice, Personagem* personagem); // Comprar item (item ou equipamento)
    bool comprarEquipamento(int indice, Personagem* personagem); // Comprar equipamento
};

#endif // LOJA_H
