#include "Equipamento.h"
// construtor
Equipamento::Equipamento(std::string nome, std::string descricao, int tipo, int stats, int lvreq, int preco)
    : nome(nome), descricao(descricao), tipo(tipo), stats(stats), lvreq(lvreq), preco(preco) {}

