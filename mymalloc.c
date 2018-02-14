#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

static char myblock[SIZE];
char * a='0';
char * b='1';
int ini = 0;

int avai(char arr[]) // check available spaces
{
  int i=0;
  while(i<SIZE)
  {
    if(arr[i]== a)
    {
      i++;
    }
  }
  return i;
}

void * mymalloc(unsigned int size, char * filename, unsigned int linenum)
{
  if(ini = 0) //initilize the array
  {
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
  int* arr = (int *)calloc(SIZE,sizeof(int));
  int j=0;
  int met =0;
  i=0;
  int counter = 0;
  for(i=0;i<SIZE;i++)
  {
    if(myblock[i]=='1')
    {
      if(met==1)
      {
        arr[j]=counter;
        met = 0;
        j++;
        counter =0;
        continue;
      }
      counter =0;
    }
    else if(myblock[i]=='0')
    {

      if(met==0)
      {
        arr[j]=i;met=1;printf("arr[%d] is %d\n",j,arr[j]);j++;}
      counter++;
    }
  }
  i = 0;
  if(arr[0]==0){printf("arr[%d] is %d\n",i, arr[i] );i++;}
  while(arr[i]>0)
  {
    printf("arr[%d] is %d\n",i, arr[i] );i++;
  }






}
