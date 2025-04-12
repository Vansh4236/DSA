#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to get height of a node
int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Create a new node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Get balance factor of a node
int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert a key into AVL tree
Node* insert(Node* node, int key) {
    // Step 1: Normal BST insertion
    if (node == nullptr) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicates not allowed

    // Step 2: Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Step 3: Get balance factor
    int balance = getBalance(node);

    // Step 4: Balance the tree
    // Case 1 - Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2 - Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3 - Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4 - Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 5);

    cout << "Inorder traversal of AVL Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
