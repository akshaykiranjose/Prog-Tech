#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE* outPtr;

void init(tree* t)
{
    t->size = 0;
    t->root = NULL;
    t->max = 0;
    t->min = 100000;
}

int numOfNodes(tree* t)
{
    return countNumDescendents(t->root);
}

int countNumDescendents(node* ptr)
{
    if (ptr == NULL)
        return 0;
    else 
        return 1 + countNumDescendents(ptr->left) + countNumDescendents(ptr->right);
}


void insert(tree *t, int elem)
{
    fprintf(outPtr, "%d inserted\n", elem);
    node* newnode = (node*) malloc(sizeof(node));
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->data = elem;
    t->size++;

    if(t->root  == NULL)
    {
        t->root = newnode;
        t->max = newnode->data;
        t->min = newnode->data;
        return;
    }

    else
    {
        node* thru = t->root;
        int stopFlag = 0;

        t->max = (t->max > elem)? t->max: elem;
        t->min = (t->min < elem)? t->min: elem;

        while(!stopFlag)
        {
            if(elem < thru->data)
            {   
                if(thru->left != NULL)
                    thru = thru->left;
                else
                {
                    thru->left = newnode; stopFlag = 1;
                }
                    
            }
            else //elem > thru->data
            {
                if(thru->right != NULL)
                    thru = thru->right;
                else
                {
                    thru->right = newnode; stopFlag = 1;
                }
            }
        }
    }
    return;
}

void search(tree* t, int elem)
{
    node* found = findReturn(t, elem);
    if (found == NULL) 
        fprintf(outPtr, "%d not found\n", elem); 
    else
        fprintf(outPtr, "%d found\n", elem);
}

void preOrder(tree* t)
{

    if(t->root == NULL)
        fprintf(outPtr, " ");
    else
        preorder(t->root);

    fprintf(outPtr, "\n");
}

void preorder(node* ptr)
{
    if(ptr == NULL)
        return;


    fprintf(outPtr, "%d ", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}

void inOrder(tree* t)
{
    if(t->root == NULL)
        fprintf(outPtr, " ");
    else
        inorder(t->root);
    fprintf(outPtr, "\n");
}

void inorder(node* ptr)
{
    if(ptr == NULL)
        return;

    inorder(ptr->left);
    fprintf(outPtr, "%d ", ptr->data);
    inorder(ptr->right);
}

void postOrder(tree* t)
{

    if(t->root == NULL)
        fprintf(outPtr, " ");
    else
        postorder(t->root);
    fprintf(outPtr, "\n");
}

void postorder(node* ptr)
{
    if(ptr == NULL)
        return;
    
    postorder(ptr->left);
    postorder(ptr->right);
    fprintf(outPtr, "%d ", ptr->data);
}


node* findReturn(tree* t, int elem)
{
    node* thru = t->root;

    if(thru == NULL)
        return NULL;
    else
    {
        int stopFlag = 0;

        while(!stopFlag)
        {
            if(elem == thru->data)
            {  
                stopFlag = 1; 
            }
            else if(elem < thru->data)
            {   
                if(thru->left != NULL)
                {
                    thru = thru->left; 
                }
                else
                {    
                    thru = NULL; 
                    stopFlag = 1; 
                }
            }
            else //elem > thru->data
            {
                if(thru->right != NULL)
                {
                    thru = thru->right; 
                }
                else
                {    
                    thru = NULL; 
                    stopFlag = 1;
                }
            }
        }
    }

    return thru;
}

int maximum(tree* t) {return t->max;}
    
int minimum(tree* t) {return t->min;}
    
void successor(tree* t, int elem)
{

    if (elem == maximum(t))
    {
        fprintf(outPtr, "successor %d does not exist\n", elem);
        return;
    }
    
    node* ptr = findReturn(t, elem);
    
    if(ptr == NULL)
    {    
        fprintf(outPtr, "%d does not exist\n", elem);
        return;
    }

    else
    {
        int _succ = maximum(t);
        findNextLargest(t->root, elem, &_succ);
        fprintf(outPtr, "%d\n", _succ);
        return;
    }    
}

void findNextLargest(node* ptr, int elem, int* currLargest)
{
    if(ptr == NULL)
        return;
    
    if(ptr->data > elem && ptr->data < *currLargest)
        *currLargest = ptr->data;
    
    findNextLargest(ptr->left, elem, currLargest);
    findNextLargest(ptr->right, elem, currLargest);
}

void predecessor(tree* t, int elem)
{

    if (elem == minimum(t))
    {
        fprintf(outPtr, "predecessor of %d does not exist\n", elem);
        return;
    }
        
    
    node* ptr = findReturn(t, elem);
    
    if(ptr == NULL)
    {
        fprintf(outPtr, "%d does not exist\n", elem);
        return;
    }
    
    else
    {
        int _pred = minimum(t);
        findNextSmallest(t->root, elem, &_pred);
        fprintf(outPtr, "%d\n", _pred);
        return;
    }    
}

void findNextSmallest(node* ptr, int elem, int* currLargest)
{
    if(ptr == NULL)
        return;
    
    if(ptr->data < elem && ptr->data > *currLargest)
        *currLargest = ptr->data;
    
    findNextSmallest(ptr->left, elem, currLargest);
    findNextSmallest(ptr->right, elem, currLargest);
}