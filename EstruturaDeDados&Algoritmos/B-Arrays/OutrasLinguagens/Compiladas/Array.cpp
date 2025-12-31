#include <iostream>
#include <vector>

int main() {
    // Array estilo C (tamanho fixo)
    int numeros[] = {10, 20, 30};
    
    // Moderno (Vector - dinâmico)
    std::vector<int> vetor = {10, 20, 30};

    std::cout << numeros[0] << std::endl; // Imprime 10
    return 0;
}