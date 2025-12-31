const std = @import("std");

pub fn main() !void {
    // Declaração: [Tamanho]Tipo
    // O '_' diz ao compilador: "conte os elementos para mim"
    const numeros = [_]i32{1, 2, 3};

    // Acessando um índice específico ({d} é para decimais/inteiros)
    std.debug.print("Primeiro valor: {d}\n", .{numeros[0]});

    // Imprimindo o array inteiro ({any} imprime qualquer estrutura)
    std.debug.print("Array completo: {any}\n", .{numeros});
}