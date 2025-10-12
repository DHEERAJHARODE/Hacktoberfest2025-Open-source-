#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    

    // Character that store the read
    // character
    char ch;

    // Opening file in reading mode
    FILE *fptr = fopen("file.txt", "r");

    // Reading file character by character
    while ((ch = fgetc(fptr)) != EOF)
        printf("%c", ch);
        
    // Closing the file
    fclose(fptr);
    return 0;
}
