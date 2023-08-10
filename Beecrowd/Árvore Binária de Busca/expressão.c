#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

// Definição da estrutura de um nó da árvore
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// Função que cria a árvore a partir da expressão aritmética
Node* createTree(string expression) {
    stack<Node*> s;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (isdigit(c) || isalpha(c)) { // Se é um operando
            Node* node = new Node(c);
            s.push(node);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') { // Se é um operador
            Node* node = new Node(c);
            node->right = s.top();
            s.pop();
            node->left = s.top();
            s.pop();
            s.push(node);
        } else if (c == '(') { // Ignoramos os parênteses abrindo
            continue;
        } else if (c == ')') { // Ignoramos os parênteses fechando
            continue;
        }
    }
    return s.top();
}

// Função que imprime a árvore nível a nível
void printTree(Node* root) {
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        cout << "Nivel " << level << ": ";
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->value;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        cout << endl;
        level++;
    }
}

int main() {
    string expression;
    while (getline(cin, expression)) {
        Node* root = createTree(expression);
        printTree(root);
        cout << endl;
    }
    return 0;
}
