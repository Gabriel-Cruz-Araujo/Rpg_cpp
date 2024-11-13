#include "Personagem.h"    
#include "Inventario.h"   
#include <iostream>        

// Construtor da classe Personagem que inicializa os atributos b�sicos
Personagem::Personagem(std::string nome, std::string classe)
    : nome(nome), classe(classe), maxSaude(100), saude(100), nivel(1),
    forca(10), magia(5), inventario() {
    // Adiciona a habilidade inicial "Fagulha" ao personagem
    Habilidade fagulha("Fagulha", "lan�a um ataque de chamas fraco", 30, 0, 0);
    habilidades.push_back(fagulha); // Coloca a habilidade na lista de habilidades
}

// M�todo para listar as habilidades do personagem
void Personagem::listarHabilidades() const {
    if (habilidades.empty()) {
        std::cout << "Nenhuma habilidade desbloqueada.\n";  // Caso n�o haja habilidades
    }
    else {
        std::cout << "Habilidades do personagem " << nome << ":\n";
        // Percorre e exibe as habilidades do personagem
        for (const auto& habilidade : habilidades) {
            std::cout << "- " << habilidade.nome << ": " << habilidade.descricao
                << "\n"; // Exibe nome e descri��o da habilidade
        }
    }
}

// M�todo para subir de n�vel, aumentando atributos do personagem
void Personagem::subirNivel() {
    nivel++;                // Aumenta o n�vel
    maxSaude += 20;         // Aumenta a sa�de m�xima em 20
    saude = maxSaude;       // Restaura a sa�de para o valor m�ximo
    forca += 5;             // Aumenta a for�a em 5
    magia += 5;             // Aumenta a magia em 5
    std::cout << "Voce subiu para o nivel " << nivel << "!\n";  // Mensagem de subida de n�vel
    std::cout << "Atributos aumentados: +5 de Forca e +5 de Magia.\n";
    std::cout << "Vida maxima aumentada em 20.\n";
}

// M�todo que retorna o XP necess�rio para o pr�ximo n�vel
int Personagem::xpParaProximoNivel() const {
    return (nivel) * 1000;  // Exemplo de c�lculo de XP necess�rio para o pr�ximo n�vel
}

// M�todo para exibir o status atual do personagem
void Personagem::exibirStatus() {
    // Exibe o nome, classe, e atributos b�sicos do personagem
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "Sa�de: " << saude << "/" << maxSaude << "\n";
    std::cout << "For�a: " << forca << "\n";
    std::cout << "Magia: " << magia << "\n";
    std::cout << "Nivel: " << nivel << "\n";

    // Calcula o XP necess�rio para o pr�ximo n�vel e o XP restante
    int xpParaProximo = xpParaProximoNivel();
    int xpRestante = xpParaProximo - xp; // Diferen�a entre XP atual e o necess�rio
    std::cout << "XP Atual: " << xp << "/" << xpParaProximo << "\n";
    std::cout << "Falta " << xpRestante << " XP para o pr�ximo n�vel.\n";

    // Exibe o item atualmente equipado, se houver
    if (!inventario.equip.nome.empty()) {
        std::cout << "Item Equipado: " << inventario.equip.nome << "\n";
        std::cout << "Descri��o: " << inventario.equip.descricao << "\n";
        std::cout << "Atributos: ";
        // Dependendo do tipo do item, exibe os atributos espec�ficos
        switch (inventario.equip.tipo) {
        case 1: // Espada
            std::cout << "+" << inventario.equip.stats << " de For�a\n";
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
        std::cout << "Item Equipado: Nenhum\n";  // Caso n�o tenha item equipado
    }
}

// M�todo para adicionar uma nova habilidade ao personagem
void Personagem::adicionarHabilidade(const Habilidade& habilidade) {
    habilidades.push_back(habilidade);  // Adiciona a habilidade � lista de habilidades
    std::cout << "Habilidade " << habilidade.nome << " adicionada ao seu personagem!\n";
}
