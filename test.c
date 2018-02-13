#include <stdio.h>
#include <stdlib.h>
int main()
{
  static char myblock[5000];
  myblock[0] = 'a';
  printf(" %c\n",myblock[0] );
  int *arr;
//  arr[0]=1;
  arr[8]=2;
}
