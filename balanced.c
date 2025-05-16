#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

int match(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

int isBalanced(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top == -1 || !match(stack[top--], s[i]))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf(isBalanced(str) ? "Balanced\n" : "Unbalanced\n");
    return 0;
}
