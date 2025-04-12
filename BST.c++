//Write Program for Binary Search Tree
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node in BST

struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) 
    return newNode(key);
    // Otherwise, recur down the tree
    if (key < node->data)
    node->left = insert(node->left, key);

    else if (key > node->data)
    node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;    
}

// Function to inorder traversal of BST

void inorder(struct Node *root) {
    if (root!=NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

//delete the node

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left!= NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    // Base case
    if (root == NULL) 
    return root;
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
    root->left = deleteNode(root->left, key);
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
    root->right = deleteNode(root->right, key);
    // If the key is same as root's key, then this is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL)
        return root->right;
        else if (root->right == NULL)
        return root->left;
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
    int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    cout << "Inorder traversal of the constructed BST is: \n";
    inorder(root);
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "\nInorder traversal of the modified BST is: \n";
    inorder(root);
    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    inorder(root);
    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);    
    inorder(root);
    return 0;  
    }
