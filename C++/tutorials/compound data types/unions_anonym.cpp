/*
typedef char C;
typedef unsigned int WORD;
typedef char * pChar;
typedef char field [50]; 

using C = char;
using WORD = unsigned int;
using pChar = char *;
using field = char [50];
*/
#include<iostream>

struct book2_t {
  char title[50];
  char author[50];
  union {
    float dollars;
    int yen;
  };
} book2;

int main()
{
  book2.dollars = 10.0;
  
  std::cout<<sizeof(book2)<<std::endl;
  std::cout<<book2.dollars;
}