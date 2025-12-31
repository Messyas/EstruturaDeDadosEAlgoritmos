package main
import "fmt"

func main() {
    // Array de tamanho fixo [3]
    var numeros = [3]int{1, 2, 3}

	// Ou Declaração de Slice (mais comum que array fixo)
	numerosSlice := []int{10, 20, 30}
    
    fmt.Println(numeros) // Imprime [10 20 30]
    fmt.Println(numerosSlice)
}