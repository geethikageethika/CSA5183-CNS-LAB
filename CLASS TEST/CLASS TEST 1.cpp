#include <stdio.h>
#include <ctype.h>


char encrypt(char plaintext, int a, int b) {
    if (isalpha(plaintext)) {
        if (islower(plaintext)) {
            return ((a * (plaintext - 'a') + b) % 26) + 'a';
        } else if (isupper(plaintext)) {
            return ((a * (plaintext - 'A') + b) % 26) + 'A';
        }
    }
    return plaintext;
}

int main() {
    int a, b;
    char plaintext[100];
    
    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    
    printf("Enter the value of 'b': ");
    scanf("%d", &b);
    
    if (a % 2 == 0 || a % 13 == 0) {
        printf("Invalid value of 'a'. It should be coprime with 26.\n");
        return 1;
    }
    
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);


    for (int i = 0; plaintext[i]; ++i) {
        plaintext[i] = encrypt(plaintext[i], a, b);
    }
    
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

