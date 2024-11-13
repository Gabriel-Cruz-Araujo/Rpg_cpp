#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <vector>             
#include "Habilidade.h"      
#include "Inventario.h"       
#include "Quest.h"            

// Definição da classe Personagem
class Personagem {
public:
    // Atributos do personagem
    std::string nome;         // Nome do personagem
    std::string classe;       // Classe do personagem (guerreiro, mago, etc.)
    int maxSaude;             // Saúde máxima do personagem
    int saude;                // Saúde atual do personagem
    int nivel;                // Nível do personagem
    int forca;                // Força do personagem, usada para ataques
    int xp;                   // XP (experiência) acumulado pelo personagem
    int magia;                // Magia do personagem, usada para habilidades
    Inventario inventario;    // Inventário do personagem para armazenar itens
    Quest* missaoAtiva = nullptr; // Ponteiro para a missão ativa do personagem (inicialmente sem missão)

    // Novo atributo para armazenar as habilidades do personagem
    std::vector<Habilidade> habilidades; // Vetor que armazena as habilidades do personagem

    // Construtor da classe Personagem, inicializa os atributos com valores padrão
    Personagem(std::string nome, std::string classe);

    // Método para exibir o status do personagem (atributos, nível, XP, etc.)
    void exibirStatus();

    // Método para subir de nível (aumentar atributos)
    void subirNivel();

    // Método para calcular e retornar o XP necessário para o próximo nível
    int xpParaProximoNivel() const;

    // Método para listar as habilidades do personagem
    void listarHabilidades() const;

    // Método para adicionar uma nova habilidade ao personagem
    void adicionarHabilidade(const Habilidade& habilidade);
};

#endif // PERSONAGEM_H
#pragma once
