#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* pre = NULL;
struct Node* suc = NULL;

void findPreSuc(struct Node* root, int key) {
    if (root == NULL)
        return;
    
    if (root->key == key) {
        if (root->left != NULL) {
            struct Node* tmp = root->left;
            while (tmp->right != NULL)
                tmp = tmp->right;
            pre = tmp;
        }
        
        if (root->right != NULL) {
            struct Node* tmp = root->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }
    
    if (root->key > key) {
        suc = root;
        findPreSuc(root->left, key);
    } else {
        pre = root;
        findPreSuc(root->right, key);
    }
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct Node* buildSampleTree() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    return root;
}

int main() {
    int key;
        
    printf("Please enter the key to find its predecessor and successor: ");
    scanf("%d", &key);

    struct Node* root = buildSampleTree();

    findPreSuc(root, key);
    
    printf("\nResults for the key %d:\n", key);
    
    if (pre != NULL)
        printf("Predecessor: %d\n", pre->key);
    else
        printf("Predecessor: Not found (this is the smallest element in the tree)\n");

    if (suc != NULL)
        printf("Successor: %d\n", suc->key);
    else
        printf("Successor: Not found (this is the largest element in the tree)\n");

    return 0;
}