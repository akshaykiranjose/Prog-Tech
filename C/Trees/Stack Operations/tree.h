#ifndef _TREE_H_
#define _TREE_H_

struct BSTnode
{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};
typedef struct BSTnode node;

struct BST
{
    node* root;
};
typedef struct BST tree;

void initree(tree *);
void insert(tree *, int);
void search(tree*, int);

void preorder(tree*);
void inorder(tree*);
void postorder(tree*);


#endif