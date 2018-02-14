#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

static char myblock[SIZE];
int ini = 0;

void * mymalloc(unsigned int size, char * filename, unsigned int linenum)
{
  if(ini = 0) //initilize the array
  {
    int i = 0;
    while(i<5000)
    {
      myblock[i]='0';i++;
    }
    ini = 1;
  }
  if(size == 0)
  {
    printf("error:can't assign 0 size");
    return NULL;
  }
  int *p = (int *)(&myblock[0]);
  //*p is the pointer of the array, pointing the first index of array
  int i=0,j=0,met=0,counter=0;
  int* arr = (int *)calloc(SIZE,sizeof(int));
  /*
    arr is an array that contains the index of available malloc spot.
    For instance, supposed we have a memory block [0,1,0,0,1,0,0,0,1,1]
    0 stands for freed spaces
    1 stands for malloced spaces
    so after the following method, we can find the index of each avalable
    block and find the amounts of bytes in each gap
    So for [0,1,0,0,1,0,0,0,1,1]
    arr is supposed to become [0,1,2,2,5,3]
    odd number stands for the index of starting index of 0(freed space)
    even number stands for the amount of malloc spaces following the
    starting index.
  */
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
  /*
  for folling codes, we are getting the sum of the empty spots and determine
  if there are enough memory to malloc the request
  */
  i = 1;
  int avai;
  while(arr[i]>0)
  {
    avai+=arr[i];
    //printf("arr[%d] is %d\n",i, arr[i] );i+=2;
  }

  if(avai>size)
  {
    printf("error:request is too huge");
    return NULL;
  }
  //Fill in empty spot with '1' to simulate the malloc method
  int space_arr_size = i-2; //the length of arr
  int k;
   for(i=0;i<space_arr_size;i+=2)
     {
       j = i+1;
       for(k=0;k<arr[j];k++)
       {
         myblock[k+arr[i]]='1';
         size--;
         if(size==0)
         {break;}
       }
       if(size==0)
       {break;}
     }

  return p;
}
int main()
{
  printf("hellow\n" );
  return 0;
}
