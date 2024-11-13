#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <vector>             
#include "Habilidade.h"      
#include "Inventario.h"       
#include "Quest.h"            

// Defini��o da classe Personagem
class Personagem {
public:
    // Atributos do personagem
    std::string nome;         // Nome do personagem
    std::string classe;       // Classe do personagem (guerreiro, mago, etc.)
    int maxSaude;             // Sa�de m�xima do personagem
    int saude;                // Sa�de atual do personagem
    int nivel;                // N�vel do personagem
    int forca;                // For�a do personagem, usada para ataques
    int xp;                   // XP (experi�ncia) acumulado pelo personagem
    int magia;                // Magia do personagem, usada para habilidades
    Inventario inventario;    // Invent�rio do personagem para armazenar itens
    Quest* missaoAtiva = nullptr; // Ponteiro para a miss�o ativa do personagem (inicialmente sem miss�o)

    // Novo atributo para armazenar as habilidades do personagem
    std::vector<Habilidade> habilidades; // Vetor que armazena as habilidades do personagem

    // Construtor da classe Personagem, inicializa os atributos com valores padr�o
    Personagem(std::string nome, std::string classe);

    // M�todo para exibir o status do personagem (atributos, n�vel, XP, etc.)
    void exibirStatus();

    // M�todo para subir de n�vel (aumentar atributos)
    void subirNivel();

    // M�todo para calcular e retornar o XP necess�rio para o pr�ximo n�vel
    int xpParaProximoNivel() const;

    // M�todo para listar as habilidades do personagem
    void listarHabilidades() const;

    // M�todo para adicionar uma nova habilidade ao personagem
    void adicionarHabilidade(const Habilidade& habilidade);
};

#endif // PERSONAGEM_H
#pragma once
