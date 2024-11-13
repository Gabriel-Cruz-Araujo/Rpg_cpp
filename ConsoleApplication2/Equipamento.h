#pragma once
#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <string>

// Declara��o da classe Equipamento, que representa um item de equipamento utiliz�vel pelo jogador
class Equipamento {
public:
    std::string nome;         // Nome do equipamento
    std::string descricao;    // Descri��o do equipamento
    int tipo;                 // Tipo do equipamento (1 - espada, 2 - armadura, 3 - amuleto)
    int stats;                // Valor de atributos fornecidos pelo equipamento
    int lvreq;                // N�vel m�nimo necess�rio para utilizar o equipamento
    int preco;                // Pre�o do equipamento para compra

    // Construtor da classe Equipamento, inicializa o item com os valores especificados
    Equipamento(std::string nome, std::string descricao, int tipo, int stats, int lvreq, int preco);
};

#endif // EQUIPAMENTO_H
