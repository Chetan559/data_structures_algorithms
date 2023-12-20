#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

int priority(char operator) {
    if(operator == '^')
        return 3;
    else if(operator == '*' || operator == '/')
        return 2;
    else if(operator == '+' || operator == '-')
        return 1;
    return 0;
}

int main() {
    char infix[SIZE], prefix[SIZE];
    int i, j, p;
    char stack[SIZE], operator;
    j =-1;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    strcpy(prefix, "");
    strcpy(stack, "");
    for(i = 0; infix[i] != '\0'; i++) {
        if(isalpha(infix[i]))
            strncat(prefix, &infix[i], 1);
        else if(infix[i] == '(')
            stack[++j] = infix[i];
        else if(isalnum(stack[j])) {
            stack[++j] = infix[i];
            while(j >= 0 && priority(stack[j]) <= priority(infix[i])) {
                prefix[strlen(prefix)] = stack[j--];
            }
        }
        else if(infix[i] == ')') {
            while(stack[j] != '(')
                prefix[strlen(prefix)] = stack[j--];
            j--;
        }
        else {
            while(j >= 0 && priority(stack[j]) >= priority(infix[i]))
                prefix[strlen(prefix)] = stack[j--];
            stack[++j] = infix[i];
        }
    }
    while(j >= 0)
        prefix[strlen(prefix)] = stack[j--];
    printf("Prefix expression: %s\n", prefix);
    return 0;
}