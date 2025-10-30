#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int evalPostfix(char* postfix) {
    int stack[SIZE], top = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        // Skip whitespace
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        // If digit, parse full number
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack[++top] = num;
        } else {
            // Operator
            int b = stack[top--];
            int a = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < b; j++) result *= a;
                    stack[++top] = result;
                    break;
                }
                default:
                    printf("Unsupported operator: %c\n", postfix[i]);
                    return -1;
            }
            i++;
        }
    }

    return stack[top];
}

int main() {
    char postfix[SIZE];

    printf("Enter postfix expression (space-separated): ");
    fgets(postfix, SIZE, stdin);

    // Remove trailing newline if present
    size_t len = strlen(postfix);
    if (len > 0 && postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }

    int result = evalPostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}


