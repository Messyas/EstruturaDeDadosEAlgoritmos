#include <stdio.h>

int main () {
    int nums[] = {10, 20, 30};
    int size = sizeof(nums)/sizeof(nums[0]);
    int *ptr = nums;
    int i = 0;

    printf("%d\n", *ptr); //10
    printf("%d\n", *ptr + 1); //11 kkk
    printf("%d\n", *(ptr + 1)); // é como se fosse 1 + 1 (posicao 0, 1) e ai manda pra ref a memoria do array


    printf("\n");

    while (i < size) {
        printf("%d\n", *(ptr + i)); // é como se fosse 1 + 1 (posicao 0, 1) e ai manda pra ref a memoria do array
        i++;
    }

    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%d\n", *(ptr + i));
    }

    return 0;
}