#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 10;
    int y = 20;
    int *p = &x;
    int *q = &y;

    printf("x = %d, y = %d\n", x, y);
    printf("Endereco de x: %p\n", (void *)p);
    printf("Endereco de y: %p\n", (void *)q);

    *p = 15;
    printf("Valor de x apos *p = 15: %d\n", x);

    troca(&x, &y);
    printf("Depois de troca(): x = %d, y = %d\n", x, y);

    int arr[5] = {1, 2, 3, 4, 5};
    int *r = arr; // nome do array é endereço do primeiro elemento

    printf("Acessando array com ponteiro:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(r + %d) = %d\n", i, arr[i], i, *(r + i));
    }

    return 0;
}
