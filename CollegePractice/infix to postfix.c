#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  char data[50];
  int top;
};

int isEmpty(struct Stack *s) {
  return (s->top == -1);
}

char peek(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty\n");
    return '\0';
  }
  return s->data[s->top];
}

int precedence(char ch) {
  switch (ch) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return -1;
  }
}

int checkIfOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

void push(struct Stack *s, char ch) {
  if (s->top == 49) {
    printf("Stack overflow\n");
    return;
  }
  s->data[++s->top] = ch;
}

char pop(struct Stack *s) {
  if (s->top == -1) {
    printf("Stack underflow\n");
    return '\0';
  }
  return s->data[s->top--];
}

void covertInfixToPostfix(char* expression) {
  struct Stack s;
  s.top = -1;
  int i, j;

  for (i = 0, j = -1; expression[i]; ++i) {
    if (checkIfOperand(expression[i])) {
      expression[++j] = expression[i];
    } else if (expression[i] == '(') {
      push(&s, expression[i]);
    } else if (expression[i] == ')') {
      while (!isEmpty(&s) && peek(&s) != '(') {
        expression[++j] = pop(&s);
      }
      if (!isEmpty(&s) && peek(&s) != '(') {
        printf("Invalid expression\n");
        return;
      } else {
        pop(&s);
      }
    } else {
      while (!isEmpty(&s) && precedence(expression[i]) <= precedence(peek(&s))) {
        expression[++j] = pop(&s);
      }
      push(&s, expression[i]);
    }
  }

  while (!isEmpty(&s)) {
    expression[++j] = pop(&s);
  }
  expression[++j] = '\0';
  printf("Postfix expression: %s\n", expression);
}

int main() {
  char expression[50];
  printf("Enter infix expression: ");
  gets(expression);
  covertInfixToPostfix(expression);
  return 0;
}
