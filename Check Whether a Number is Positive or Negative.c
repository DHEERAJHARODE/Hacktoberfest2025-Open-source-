#include <stdio.h>
int main() {
    double num;
    printf("To Check whether the number is Positive or Negative");
    printf("Enter a number: ");
    scanf("%lf", &num);
    if (num <= 0.0) {
        if (num == 0)
            printf("You entered 0.");
        else
            printf("You entered a negative number.");
    } else
        printf("You entered a positive number.");
    return 0;
}
