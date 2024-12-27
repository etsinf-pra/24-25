/*
calculo de la altura de un arbol binario
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int key;
    node *left;
    node *right;
};


void insert(int x, node *&root) {
    if(root == NULL) {
        root = new node;
        root->key = x;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(x < root->key)
        insert(x, root->left);
    else
        insert(x, root->right);
}

void print(node *root, int level) {
    if(root == NULL)
        return;
    print(root->left, level + 1);
    cout << root->key << "(" << level << ") ";
    print(root->right, level + 1);
}


void generate_tree(node *&root, int n) {
    for(int i = 0; i < n; i++)
        insert(rand() % 100, root);    
}

// esta es la función para la pregunta del parcial
int height(node *root) {
    if(root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}


int main() {
    node *root = NULL;

    generate_tree(root, 10);
    print(root, 1);
    cout << endl << "Altura: " << height(root) << endl;
    return 0;
}
