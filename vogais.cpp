#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char value;
    Node* next;

    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

struct Stack {
    Node* topNode;

    Stack() {
        topNode = NULL;
    }

    bool empty() {
        return topNode == NULL;
    }

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (empty()) {
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    char top() {
        if (empty()) {
            return '\0'; 
        }
        return topNode->value;
    }
};

int main() {
    char palavra[100];

    scanf("%s", palavra);

    Stack pilha;

    
    for (int i = 0; i < strlen(palavra); i++) {
        if (islower(palavra[i])) {
            palavra[i] = toupper(palavra[i]);
        }

        if (palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            pilha.push(palavra[i]);
        }
    }

    
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            printf("%c", pilha.top());
            pilha.pop();
        } else {
            printf("%c", palavra[i]);
        }
    }

    printf("\n");

    return 0;
}
