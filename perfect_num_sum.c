#include <stdio.h>

int dvisior(int num) {
    
}

int main(void) {
    int n;

    printf("Enter Array size: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
    printf("Array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]");
}