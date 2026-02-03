#include <stdio.h>

int main() {
    int age;

    printf("Enter your age for check: ");
    scanf("%d", &age); 

    if (age < 15) {
        printf("Sorry, you are not allowed to enter.\n");
    } else if (age >= 15 && age < 18) {
        printf("Wait 1 until 3 years again to enter.\n");
    } else {
        printf("This way, sir.\n");
    }

    printf("Your age is: %d\n", age);

    return 0;
}
