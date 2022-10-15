
#include "tree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initree(tree *t)
{
    t->root = NULL;
}

void insert(tree *t, int elem)
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->data = elem;

    if(t->root  == NULL)
    {
        t->root = newnode;
        return;
    }

    else
    {
        node* ptr = t->root;
        node* temp = ptr;
        
        while(ptr)
        {
            temp = ptr;
            if(elem < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(temp->data > elem)
            temp->left = newnode;
        else
            temp->right = newnode;        
    }
    return;
}


void inorder(tree *t)
{
    stack s;
    initstack(&s);

    node* ptr = t->root;

    while(ptr || !isEmpty(&s))
    {
        while(ptr)
        {
            push(&s, ptr);
            ptr = ptr->left;
        }
            
        ptr = top(&s);
        pop(&s);

        printf("%d ", ptr->data);

        ptr = ptr->right;
    }
}

void preorder(tree *t)
{
    stack s;
    initstack(&s);

    node* ptr = t->root;
    push(&s, ptr);

    while(!isEmpty(&s))
    {
        ptr = top(&s);
        pop(&s);
        printf("%d ", ptr->data);
        if(ptr->right)
            push(&s, ptr->right);
        if(ptr->left)
            push(&s, ptr->left);
    }

}

void postorder(tree *t)
{
    
}
