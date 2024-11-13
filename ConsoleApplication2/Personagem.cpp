#include "Personagem.h"    
#include "Inventario.h"   
#include <iostream>        

// Construtor da classe Personagem que inicializa os atributos básicos
Personagem::Personagem(std::string nome, std::string classe)
    : nome(nome), classe(classe), maxSaude(100), saude(100), nivel(1),
    forca(10), magia(5), inventario() {
    // Adiciona a habilidade inicial "Fagulha" ao personagem
    Habilidade fagulha("Fagulha", "lança um ataque de chamas fraco", 30, 0, 0);
    habilidades.push_back(fagulha); // Coloca a habilidade na lista de habilidades
}

// Método para listar as habilidades do personagem
void Personagem::listarHabilidades() const {
    if (habilidades.empty()) {
        std::cout << "Nenhuma habilidade desbloqueada.\n";  // Caso não haja habilidades
    }
    else {
        std::cout << "Habilidades do personagem " << nome << ":\n";
        // Percorre e exibe as habilidades do personagem
        for (const auto& habilidade : habilidades) {
            std::cout << "- " << habilidade.nome << ": " << habilidade.descricao
                << "\n"; // Exibe nome e descrição da habilidade
        }
    }
}

// Método para subir de nível, aumentando atributos do personagem
void Personagem::subirNivel() {
    nivel++;                // Aumenta o nível
    maxSaude += 20;         // Aumenta a saúde máxima em 20
    saude = maxSaude;       // Restaura a saúde para o valor máximo
    forca += 5;             // Aumenta a força em 5
    magia += 5;             // Aumenta a magia em 5
    std::cout << "Voce subiu para o nivel " << nivel << "!\n";  // Mensagem de subida de nível
    std::cout << "Atributos aumentados: +5 de Forca e +5 de Magia.\n";
    std::cout << "Vida maxima aumentada em 20.\n";
}

// Método que retorna o XP necessário para o próximo nível
int Personagem::xpParaProximoNivel() const {
    return (nivel) * 1000;  // Exemplo de cálculo de XP necessário para o próximo nível
}

// Método para exibir o status atual do personagem
void Personagem::exibirStatus() {
    // Exibe o nome, classe, e atributos básicos do personagem
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "Saúde: " << saude << "/" << maxSaude << "\n";
    std::cout << "Força: " << forca << "\n";
    std::cout << "Magia: " << magia << "\n";
    std::cout << "Nivel: " << nivel << "\n";

    // Calcula o XP necessário para o próximo nível e o XP restante
    int xpParaProximo = xpParaProximoNivel();
    int xpRestante = xpParaProximo - xp; // Diferença entre XP atual e o necessário
    std::cout << "XP Atual: " << xp << "/" << xpParaProximo << "\n";
    std::cout << "Falta " << xpRestante << " XP para o próximo nível.\n";

    // Exibe o item atualmente equipado, se houver
    if (!inventario.equip.nome.empty()) {
        std::cout << "Item Equipado: " << inventario.equip.nome << "\n";
        std::cout << "Descrição: " << inventario.equip.descricao << "\n";
        std::cout << "Atributos: ";
        // Dependendo do tipo do item, exibe os atributos específicos
        switch (inventario.equip.tipo) {
        case 1: // Espada
            std::cout << "+" << inventario.equip.stats << " de Força\n";
            break;
        case 2: // Armadura
            std::cout << "+" << inventario.equip.stats << " de Vida\n";
            break;
        case 3: // Amuleto
            std::cout << "+" << inventario.equip.stats << " de Magia\n";
            break;
        default:
            std::cout << "Desconhecido";
        }
    }
    else {
        std::cout << "Item Equipado: Nenhum\n";  // Caso não tenha item equipado
    }
}

// Método para adicionar uma nova habilidade ao personagem
void Personagem::adicionarHabilidade(const Habilidade& habilidade) {
    habilidades.push_back(habilidade);  // Adiciona a habilidade à lista de habilidades
    std::cout << "Habilidade " << habilidade.nome << " adicionada ao seu personagem!\n";
}
