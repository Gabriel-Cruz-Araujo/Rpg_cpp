#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>

// Classe Item, representando um item no jogo
class Item {
public:

    std::string nome; // Nome do item
    std::string descricao; // Descrição do item
    int quantidade; // Quantidade do item
    int tipo;  // Tipo do item: 1 para itens que afetam o jogador, 2 para itens que afetam inimigos
    int efeito; // Efeito do item: pode ser dano ou cura, dependendo do tipo de item
    bool quest; // Se o item é necessário para alguma missão
    int preco; // Se o item é necessário para alguma missão

    // Construtor da classe Item
    Item(std::string nome, std::string descricao, int quantidade, int tipo, int efeito, bool quest, int preco);
};

#endif // ITEM_H
