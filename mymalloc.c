#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

static char myblock[SIZE];
char * a='0';
char * b='1';
int ini = 0;

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
  if(size == 0)
  {
    printf("error:can't assign 0 size")；
    return NULL;
  }
  int *p = (int *)(&block[0]);
  int* arr = (int *)calloc(SIZE,sizeof(int));
  int i=0,j=0,met=0,counter=0;
  for(i=0;i<SIZE;i++) //FIND THE INDEX OF AVAILABLE SPOT AND THE SIZE OF EACH SPOT
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

  i = 1;
  int avai;
  while(arr[i]>0)
  {
    avai+=arr[i];
    printf("arr[%d] is %d\n",i, arr[i] );i+=2;
  }
  int space_arr_size = i-2;

  if(avai>size)
  {
    printf("error:request is too huge");
    return NULL;
  }

  while(size>0)
    {
      for(i=0;i<space_arr_size;i+=2)
      {
        for(j=arr[i];j<arr[i+1];j++)
        {
          myblock[j]='1';
          size--;
        }
      }
    }












}
