#include "Item.h"
//construtor
Item::Item(std::string nome, std::string descricao, int quantidade, int tipo, int efeito, bool quest, int preco)
    : nome(nome), descricao(descricao), quantidade(quantidade), tipo(tipo), efeito(efeito), quest(quest), preco(preco) {}
