#include <iostream>

int main() {
    // Array normal na CPU (Host)
    int h_array[] = {10, 20, 30};
    
    // Ponteiro para array na GPU (Device)
    int *d_array;
    // Aloca memória na placa de vídeo para 3 inteiros
    cudaMalloc((void**)&d_array, 3 * sizeof(int));
    
    std::cout << "Array na CPU: " << h_array[0] << std::endl;
    // (Nota: Para usar o d_array, seria necessário copiar dados com cudaMemcpy)
    return 0;
}