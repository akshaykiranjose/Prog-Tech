#ifndef UTILS_H
#define UTILS_H


struct node_sll
{
	int data;
	struct node_sll* next;
};
typedef struct node_sll node_sll_t;

struct node_dll
{
	struct node_dll* prev;
	int data;
	struct node_dll* next;
};
typedef struct node_dll node_dll_t;

struct dll
{
	int len;
	node_dll_t* head;
	node_dll_t* tail;
};
typedef struct dll dll_t;

struct cirq
{
	int len;
	node_sll_t* head;
	node_sll_t* tail;
};
typedef struct cirq cirq_t;

struct stack
{
	int len;
	node_sll_t* top;
};
typedef struct stack stack_t;

void init();
void def_files();

void initS(stack_t*);
void initC(cirq_t*);
void initL(dll_t*);

void display();
void insert(int);
void Delete(int);
void find(int);

void display_dll(dll_t*);
void display_cirq(cirq_t*);
void display_stack(stack_t *);

void delete_dll(dll_t*, int);
void delete_cirq(cirq_t*, int);
void delete_stack(stack_t *);

void insert_dll(dll_t*, int);
void insert_cirq(cirq_t*, int);
void insert_stack(stack_t *, int );

void find_stack(stack_t *, int);
void find_dll(dll_t*, int);
void find_cirq(cirq_t*, int);

#endif