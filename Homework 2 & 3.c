/*Homework2
//Simple calculator
#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        // Display the menu
        printf("\n=== Simple Calculator ===\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Check if the user wants to quit
        if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        // Get numbers from user
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);

        // Perform the chosen operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
} */


//Guess the number
/*
#include <stdio.h>
#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()

int main() {
    int number, guess, attempts = 0;

    // Initialize random seed based on current time
    srand(time(0));

    // Generate a random number between 1 and 100 (inclusive)
    number = rand() % 100 + 1;

    printf("=== Guess the Number Game ===\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    // Loop until the user guesses correctly
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("🎉 Correct! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != number);

    printf("Thanks for playing!\n");

    return 0;
} */

//Calculate Fibonacci number
/*
#include <stdio.h>

int main(void) {
    int n, i;
    long long f0 = 0, f1 = 1, fn;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Fibonacci number F%d = %lld\n", n, f0);
        return 0;
    } else if (n == 1) {
        printf("Fibonacci number F%d = %lld\n", n, f1);
        return 0;
    }

    for (i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    printf("Fibonacci number F%d = %lld\n", n, fn);
    return 0;
}
*/

//Palindrome Checker
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to clean the input string (remove spaces, punctuation, and make lowercase)
void cleanString(const char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) { // keep only letters and numbers
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0'; // null terminate
}

// Function to check if the string is a palindrome
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right])
            return 0; // not palindrome
        left++;
        right--;
    }
    return 1; // palindrome
}

int main() {
    char input[200];
    char cleaned[200];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // read user input
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    cleanString(input, cleaned);

    if (isPalindrome(cleaned))
        printf(" The string is a palindrome.\n");
    else
        printf(" The string is not a palindrome.\n");

    return 0;
}
*/

//Sum of Prime numbers

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* Check if x is prime (simple sqrt method) */
bool is_prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    int limit = (int) sqrt((double)x);
    for (int i = 3; i <= limit; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

/* Find and print all pairs of primes p and q such that p + q == n.
   We iterate p from 2..n/2 and check (p, n-p). */
void find_prime_sums(int n) {
    if (n < 4) {
        printf("No representation as sum of two primes (n < 4).\n");
        return;
    }

    bool found = false;
    for (int p = 2; p <= n / 2; ++p) {
        int q = n - p;
        if (is_prime(p) && is_prime(q)) {
            printf("%d + %d = %d\n", p, q, n);
            found = true;
        }
    }

    if (!found) {
        printf("No combination of two primes sums to %d.\n", n);
    }
}

int main(void) {
    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    printf("Checking representations of %d as sum of two primes:\n", n);
    find_prime_sums(n);

    return 0;
}

//Infix calculator

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

double valStack[MAX]; int valTop = -1;
char opStack[MAX]; int opTop = -1;

void pushVal(double v) { valStack[++valTop] = v; }
double popVal() { return valStack[valTop--]; }

void pushOp(char op) { opStack[++opTop] = op; }
char popOp() { return opStack[opTop--]; }
char peekOp() { return opTop >= 0 ? opStack[opTop] : 0; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*'  op == '/'  op == '%') return 2;
    return 0;
}

double apply(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) { printf("Error: divide by zero\n"); exit(1); }
        return a / b;
    }
    if (op == '%') return (int)a % (int)b;
    return 0;
}

void evalTop() {
    double b = popVal(), a = popVal();
    char op = popOp();
    pushVal(apply(a, b, op));
}

double eval(const char *expr) {
    valTop = opTop = -1;
    for (int i = 0; expr[i];) {
        if (isspace(expr[i])) { i++; continue; }
        if (isdigit(expr[i])) {
            double v = 0;
            while (isdigit(expr[i])) v = v * 10 + (expr[i++] - '0');
            if (expr[i] == '.') {
                i++;
                double frac = 0.1;
                while (isdigit(expr[i])) {
                    v += (expr[i++] - '0') * frac;
                    frac *= 0.1;
                }
            }
            pushVal(v);
        } else if (expr[i] == '(') {
            pushOp(expr[i++]);
        } else if (expr[i] == ')') {
            while (peekOp() != '(') evalTop();
            popOp(); i++;
        } else if (strchr("+-*/%", expr[i])) {
            while (opTop >= 0 && precedence(peekOp()) >= precedence(expr[i]))
                evalTop();
            pushOp(expr[i++]);
        } else {
            printf("Invalid character: %c\n", expr[i]);
            exit(1);
        }
    }
    while (opTop >= 0) evalTop();
    return popVal();
}

int main() {
    char line[256];
    printf("Enter expressions (Ctrl+D to quit):\n");
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n') continue;
        double res = eval(line);
        printf("= %.8g\n", res);
    }
    printf("Goodbye\n");
    return 0;
}

//Number pyramid

#include <stdio.h>

// Function to print one row of the pyramid
void printRow(int row, int totalRows) {
    int spaces = totalRows - row;
    int stars = 2 * row - 1;

    for (int i = 0; i < spaces; i++) printf(" ");
    for (int i = 0; i < stars; i++) printf("*");
    printf("\n");
}

// Function to generate the full pyramid
void printPyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        printRow(i, rows);
    }
}

int main() {
    int n;
    printf("Input number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printPyramid(n);
    return 0;
}

//3-2

#include <stdio.h>

// Converts newline, tab, etc. into visible escape sequences like \n, \t
void escape(char s[], const char t[]) {
    int i = 0, j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }

    s[j] = '\0';
}

// Converts escape sequences like \n and \t into real characters
void unescape(char s[], const char t[]) {
    int i = 0, j = 0;

    while (t[i] != '\0') {
        if (t[i] == '\\') {
            switch (t[i+1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                case '\\':
                    s[j++] = '\\';
                    i++;
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }

    s[j] = '\0';
}

int main() {
    char original[] = "Hello\nWorld\tTabbed\\Slash";
    char escaped[100], unescaped[100];

    escape(escaped, original);
    printf("Escaped: %s\n", escaped);

    unescape(unescaped, escaped);
    printf("Unescaped:\n%s\n", unescaped);

    return 0;
}

//3-3

#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[]) {
    int i = 0, j = 0;
    char c;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0' &&
            ((isalnum(s1[i-1]) && isalnum(s1[i+1])) &&
             (s1[i-1] < s1[i+1]))) {

            // Valid range, e.g., a-z, 0-9
            char start = s1[i-1] + 1;
            char end = s1[i+1];

            for (c = start; c < end; c++) {
                s2[j++] = c;
            }
            i++; // skip s1[i+1] since it's already processed
             } else {
                 s2[j++] = s1[i];
             }
        i++;
    }

    s2[j] = '\0';
}

int main() {
    char s2[100];

    // Test cases
    expand("a-d", s2);
    printf("a-d     => %s\n", s2);

    expand("a-z0-9", s2);
    printf("a-z0-9  => %s\n", s2);

    expand("-a-c-", s2);
    printf("-a-c-   => %s\n", s2);

    expand("a-b-c", s2);
    printf("a-b-c   => %s\n", s2);

    expand("z-a", s2); // invalid, treated literally
    printf("z-a     => %s\n", s2);

    return 0;
}

//3-5

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Converts integer n into base b string in s
void itob(int n, char s[], int b) {
    int i = 0, sign = n;
    unsigned int num;

    // If base is invalid
    if (b < 2 || b > 16) {
        s[0] = '\0';
        return;
    }

    // Handle negative numbers correctly using unsigned
    num = (sign < 0) ? -n : n;

    do {
        int digit = num % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
        num /= b;
    } while (num > 0);

    if (sign < 0 && b == 10) {
        s[i++] = '-';  // only add negative sign for base 10
    }

    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];

    itob(255, s, 16);
    printf("255 in base 16: %s\n", s);  // should print FF

    itob(-255, s, 10);
    printf("-255 in base 10: %s\n", s);  // should print -255

    itob(255, s, 2);
    printf("255 in base 2: %s\n", s);  // should print 11111111

    itob(255, s, 8);
    printf("255 in base 8: %s\n", s);  // should print 377

    itob(-255, s, 2);
    printf("-255 in base 2: %s\n", s);  // no negative sign (unsigned binary)

    return 0;
}



