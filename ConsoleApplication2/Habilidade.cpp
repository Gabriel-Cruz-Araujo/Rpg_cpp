#include "Habilidade.h"

// construtor
Habilidade::Habilidade(std::string nome, std::string descricao, int dano, int custoGold, int nivelRequerido)
    : nome(nome), descricao(descricao), dano(dano), custoGold(custoGold), nivelRequerido(nivelRequerido) {}