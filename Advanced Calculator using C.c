//######## Mini Project **Calculator Using C** ##########
// Developer - Dernyt-TPE

#include <stdio.h>
// #include <conio.h> // Removed: non-standard, not used
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void optionTray();
void secondOptionTray();

void flushInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void addition() {
    printf("\nEnter nos. to add separated by space_ || press Enter ┘ for solution \n\n");
    int input = 0, ans = 0;
    char c = '\0';

    while (1) {
        if (scanf("%d", &input) != 1) break;
        ans += input;
        c = getchar();
        if (c == '\n') break;
    }

    printf("\n = %d", ans);
    secondOptionTray();
}

void subtraction() {
    int first, second, ans = 0;

    printf("\nEnter the first number  : ");
    scanf("%d", &first);
    printf("Enter the second number : ");
    scanf("%d", &second);

    ans = first - second;
    printf("\n = %d", ans);

    flushInputBuffer();
    secondOptionTray();
}

void multiplication() {
    printf("\nEnter nos. to multiply separated by space_ || press Enter ┘ for solution \n\n");
    int input = 0, ans = 1;
    char c = '\0';

    while (1) {
        if (scanf("%d", &input) != 1) break;
        ans *= input;
        c = getchar();
        if (c == '\n') break;
    }

    printf("\n = %d", ans);
    secondOptionTray();
}

void division() {
    int dend, isor = 0;

    printf("\nEnter the Dividend: ");
    scanf("%d", &dend);

    printf("Enter the Divisor: ");
    scanf("%d", &isor);

    if (isor == 0) {
        printf("\nError: Division by zero is undefined.\n");
    } else {
        int ans = dend / isor;
        printf("\nQuotient is = %d", ans);
        printf("\nRemainder is = %d", (dend % isor));
    }

    flushInputBuffer();
    secondOptionTray();
}

void power() {
    double base, exponent, ans;

    printf("\nEnter the Base: ");
    scanf("%lf", &base);

    printf("Enter the Exponent(Power): ");
    scanf("%lf", &exponent);

    ans = pow(base, exponent);
    printf("\n = %lf", ans);

    flushInputBuffer();
    secondOptionTray();
}

void sqroot() {
    double input;

    printf("\nEnter no. for Square Root: ");
    scanf("%lf", &input);

    if (input < 0) {
        printf("\nError: Square root of negative number is not defined in real numbers.");
    } else {
        printf("\n = %lf", sqrt(input));
    }

    flushInputBuffer();
    secondOptionTray();
}

void cbroot() {
    double input;

    printf("\nEnter no. for Cube Root: ");
    scanf("%lf", &input);
    printf("\n = %lf", cbrt(input));

    flushInputBuffer();
    secondOptionTray();
}

void factorial() {
    int input;
    unsigned long long fact = 1;

    printf("\nEnter a number to find factorial : ");
    scanf("%d", &input);

    if (input < 0) {
        printf("\nPlease enter a positive number..");
    } else if (input > 20) {
        printf("\nWarning: Number too large. May cause overflow.");
    } else if (input == 0) {
        printf("\n = 1");
    } else {
        for (int x = 1; x <= input; x++) {
            fact *= x;
        }
        printf("\n = %llu", fact);
    }

    flushInputBuffer();
    secondOptionTray();
}

//**************************************

int main() {
    char choice = '\0';

    printf("\n\t\t\t\t***** Welcome to C Calculator *****\n\n");
    optionTray();

    while (1) {
        choice = getchar();

        switch (choice) {
            case '1':
            case '+':
                addition();
                break;

            case '2':
            case '-':
                subtraction();
                break;

            case '3':
            case '*':
                multiplication();
                break;

            case '4':
            case '/':
                division();
                break;

            case '5':
            case '^':
                power();
                break;

            case '6':
            case '|':
                sqroot();
                break;

            case '7':
            case '~':
                cbroot();
                break;

            case '8':
            case '!':
                factorial();
                break;

            case 'M':
            case 'm':
                optionTray();
                break;

            case 's':
            case 'S':
                exit(0);
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }
}

void secondOptionTray() {
    printf("\n\n## Press 's' to stop ##");
    printf("\n\n## Press 'm' for Full Option Menu ##  ");
}

void optionTray() {
    secondOptionTray();

    printf("\n\n\nEnter '+' or '1' for Addition");
    printf("\t\t\t\tEnter '-' or '2' for Subtraction");
    printf("\nEnter '*' or '3' for Multiplication");
    printf("\t\t\tEnter '/' or '4' for Division");
    printf("\nEnter '^' or '5' for Power");
    printf("\t\t\t\t\tEnter '|' or '6' for Square Root");
    printf("\nEnter '~' or '7' for Cube Root");
    printf("\t\t\t\tEnter '!' or '8' for Factorial \n\n");

    printf("\n\n\n\nEnter the option you wish to perform — ");
}
