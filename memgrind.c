#include <stdio.h>
#include <stdlib.h>
#include "my_malloc.c"

int main(int argc, char** argv)
{
	printf("\nTest A: freeing addresses that are not pointers\n");
	int a = 1;
	free( (int*) a );
	
	printf("\nTest B: freeing pointers that were not allocated by malloc\n");
	int *b;
	free(b);
	char *p = (char *)malloc( 200 );
	free( p + 10 );
	
	printf("\nTest C: redundant freeing of the same pointer\n");	
	int *c = (int*) malloc(100);
	free(c);
	free(c);
	//or
	int *ca = (int*) malloc(100);
	free(ca);
	ca = (int*) malloc(100);
	free(ca);
	
	printf("\nTest D: Saturation of Dynamic Memory\n");
	char* d = (char*) malloc(5001);
	//or
	char* da = (char*) malloc(5000);
	char* dab = (char*) malloc(1);	
	
	prinf("\nTesting And Instrumentation\n");
	printf("\nTest A: Malloc 1 byte and immediatelly free it, do this 150 times\n");
	int i=0;
	for(i=0;i <= 150;i++)
	{
		char* a = malloc(1);
		free(a);
	}
	
	/*Complete testcases B, C, D*/
	/*create two new cases of you own E, F*/
	
	
	//TEST B IS NOT DONE CORRECTLY SO COMMENTED OUT
	/*int array[150];
	printf("\nTest B: freeing addresses that are not pointers\n");
	for(i=0;i <= 150;i++)
	{
		int* one = (int*) malloc(1);
		array[i] = (int*) one;
		//free(a);
	}*/

	//TEST C NOT DONE CORRECTLY SO COMMENTED OUT
	/*printf("\nTest C: randomly mallocing 1 byte and freeing 1 byte 150 times such that 150 bytes will be allocated in total and all ptrs will be freed\n");
	int *arr[150];
	int num_of_mallocs = 0;
	int num_of_frees = 0;
	int j = 0;
	while(num_of_mallocs != 150)
	{
		int random = rand()%2;
		if (random == 0)//malloc
		{
			int* a = malloc(1);
			arr[i] = a;
			num_of_mallocs++;
		}
		else //free
		{
			int* freeMe = arr[i];
			free(freeMe);
			for()
			num_of_frees++;
		}
		i++;
	}
	*/
	return 0;
	
}
