#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
  static char myblock[SIZE];
  myblock[0]= '0';
  myblock[1]= '1';
  myblock[2]= '0';
  myblock[3]= '0';
  myblock[4]= '1';
  myblock[5]= '0';
  myblock[6]= '0';
  myblock[7]= '0';
  myblock[8]= '1';
  myblock[9]= '1';
  int i = 0;
  while(i< SIZE)
  {
    //printf("%c\n",myblock[i]);
    i++;
  }
  i = 0;
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
//  arr[0]=1;

}
