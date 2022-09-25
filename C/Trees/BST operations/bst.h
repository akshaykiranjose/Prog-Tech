#ifndef BST_H
#define BST_H

struct TreeNode
{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
};
typedef struct TreeNode node;

struct BinarySearchTree
{
    int size;
    node* root;
    int max;
    int min;
};
typedef struct BinarySearchTree tree;

int numOfNodes(tree*);
int countNumDescendents(node*);

void init(tree*);

void insert(tree*, int);
void search(tree*, int);

void preOrder(tree*);
void preorder(node*);

void inOrder(tree*);
void inorder(node*);

void postOrder(tree*);
void postorder(node*);

node* findReturn(tree*, int); //returns the node pointer for data passed in

void successor(tree*, int);
void findNextLargest(node*, int, int*);

void predecessor(tree*, int);
void findNextSmallest(node*, int, int*);

int maximum(tree*);
int minimum(tree*);


#endif