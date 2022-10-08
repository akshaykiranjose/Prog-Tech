//190020003 hash table

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define nl putchar('\n')
const int max_wordlength = 50;

struct chain_link
{
	char cptr[50];
	struct chain_link *next;
};
typedef struct chain_link node;

int MAX = 25000;

int hash(char*);
int isAnagram(char*, char*);
void print_HashTable(node**, int);

int main(int argc, char *argv[]) // main.exe words.txt 25000 query.txt
{
	
	if(argc < 4)
	{
		perror("Not Enough Input arguments");
		exit(1);
	}

	int hash_value = 0;
	MAX = atoi(argv[2]);
	node **hash_table = malloc(sizeof(node*)  * MAX);

	FILE *wordPtr = fopen(argv[1], "r");
	FILE *queryPtr = fopen(argv[3], "r");
	FILE *outPtr = fopen("anagrams.txt", "w");
	
	if(hash_table == NULL)
	{
		printf("No Memory Allocated");
		exit(1);
	}
	else if(wordPtr == NULL || queryPtr == NULL)
	{
		printf("File Not Found Error");
		exit(1);
		nl;
	}

	for(int i = 0; i < MAX; ++i)
		hash_table[i] = NULL;
	
	char word[max_wordlength];
	
	while(fscanf(wordPtr, "%s", word) != EOF)
	{
		node* newnode = malloc(sizeof(node));  
		strcpy(newnode->cptr, word);

		hash_value = hash(word); 
		// chaining
		if(hash_table[hash_value] == NULL)
		{
			hash_table[hash_value] = newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = hash_table[hash_value];
			hash_table[hash_value] = newnode;
		}
	}
	
	//print_HashTable(hash_table, MAX);
	
	while(fscanf(queryPtr, "%s", word) != EOF)
	{
		hash_value = hash(word); 
		node* thru = hash_table[hash_value];

		while(thru != NULL)
		{
			if(isAnagram(word, thru->cptr))
				fprintf(outPtr, "%s ", thru->cptr);

			thru = thru->next;
		}
		fprintf(outPtr, "\n");
	}
	
	/**/
	fclose(wordPtr);
	fclose(queryPtr);
	fclose(outPtr);
} 

void print_HashTable(node** hashtable, int size)
{
	for(int i=0; i < size; ++i)
	{
		if(hashtable[i] == NULL)
			printf("%3d:\n", i);
		else
		{
			printf("%3d:", i);
			node *thru = hashtable[i];
			while(thru != NULL)
			{
				printf("%15s", thru->cptr);
				thru = thru->next;
			}
			nl;
		}
		
	}
}

int isAnagram(char* word1, char* word2) // 0 if not; 1 if it is.
{	
	if(strlen(word1) != strlen(word2))
		return 0;
	
	int j;
	int FreqList[256];
	for(j=0; j<256; j++)
		FreqList[j] = 0;

	int length = strlen(word1);
	for (j = 0; j < length; ++j)
		FreqList[word1[j]]++;
	for (j = 0; j < length; ++j)
		FreqList[word2[j]]--;

	for (j = 0; j < 256; ++j)
		if (FreqList[j] != 0)
			return 0;

	return 1;
}

int hash(char* word)
{
	int len = strlen(word);
	int value = 0;
	for(int i=0; i<len; ++i)
		value += (int)word[i];
	return value % MAX;
}
