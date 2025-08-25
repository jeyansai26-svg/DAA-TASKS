#include <stdio.h>

void printStars(int n) {
    if (n == 1)
        return;
        int i,j=0;
    
    for ( i = 1; i <= n; i++) { 
        for ( j = 1; j <= n; j++) { 
            printf("*");
            break;  // breaks inner loop after one star
        }
        printf("\n");  // print newline after each row
    }
}

int main() {
    printStars(5);
    return 0;
}
