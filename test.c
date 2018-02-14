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
  int size = 2;
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
        arr[j]=i;met=1;//printf("arr[%d] is %d\n",j,arr[j]);
        j++;}
      counter++;
    }
  }
  i = 0;
  if(arr[0]==0){//printf("arr[%d] is %d\n",i, arr[i] );
  i++;}
  int avai;
  while(arr[i]>0)
  {
    avai+=arr[i];
    //printf("arr[%d] is %d\n",i, arr[i] );
    i+=2;
  }

//  arr[0]=1;
  int k;
 int space_arr_size = i-2;

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


  i = 0;
  while(i<10)
  {
    printf("myblock[%d] is %c\n",i,myblock[i] ); i++;
  }


}
