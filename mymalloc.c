#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

static char myblock[SIZE];

int ini = 0;

int avai(char arr[]) // check available spaces
{
  int i=0;
  while(i<SIZE)
  {
    if(arr[i]=='0')
    {
      i++;
    }
  }
  return i;
}

char ** split(char myblock)
void * mymalloc(unsigned int size, char * filename, unsigned int linenum)
{
  if(ini = 0) //initilize the array
  {
    char * a="0";
    int i = 0;
    while(i<5000)
    {
      myblock[i]=a;i++;
    }
    ini = 1;
  }

  int a = avai(myblock); // get the available spaces

  if(size == 0 || size>a)
  {
    printf("error:can't assign spaces to request")；
    return NULL;
  }

  int *p = (int *)(&block[0]);
  printf("p is %d\n",p);
  int i;
  int counter = 0;
  int *arr;
  for(i=0;i<SIZE;i++)
  {

  }
  while(size>0)
  {

  }






}
