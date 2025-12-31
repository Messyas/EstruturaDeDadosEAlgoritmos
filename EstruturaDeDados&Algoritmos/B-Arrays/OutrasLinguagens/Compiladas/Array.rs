fn main() {
    // Array de tamanho fixo [Tipo; Tamanho]
    let numeros: [i32; 3] = [10, 20, 30];
    
    // Para imprimir array inteiro, usa-se {:?} debug
    println!("{:?}", numeros); 

    //ou

     // Declaração implícita de tipo e tamanho
    let numerosInp = [1, 2, 3];

    // {:?} é usado para debug printing de arrays
    println!("{:?}", numerosInp);
}