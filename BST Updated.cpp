#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

// Inorder traversal
void traverseInOrder(struct node* root) {
    if ( root == NULL) {
        return;
    }
    traverseInOrder(root-> left);
    cout << root->key<<" ";
    traverseInOrder(root-> right);
}

//creating new node
struct node* newNode(int item) {
    struct node* val
        = (struct node*)malloc(sizeof(struct node));
    val->key = item;
    val->left = val->right = NULL;
    return val;
}

//finding node with minumum key
struct node* minNode(struct node* node) {
    struct node* currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->left != NULL)
        currentNode = currentNode->left;

    return currentNode;
}


// Insert a node
struct node* insertNode(struct node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }
    else if (node->key < key) {
        node->right = insertNode(node->right, key);
    }
    else if (node->key > key) {
        node->left = insertNode(node->left, key);
    }
    return node;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    else if (root->key < key) {
        root->right = deleteNode(root->right, key);
    }
    else if (root->key > key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        if (root->left == NULL and root->right == NULL)
            return NULL;
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}



// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}