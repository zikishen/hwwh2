#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_malloc.h"

#define MAXSIZE 5000

// return a pointer to the memory buffer requested
void *mymalloc(size_t n, char *file, int line)
{
	
	if (n > MAXSIZE) 
	{
		printf("Error: Unable to allocate more than 5000 bytes in FILE: '%s' on LINE: '%d'\n", file, line);
		return NULL;
	}
	
	int newBytes = n + sizeof(*root);//n bytes wanted plus metadata of new node
	int* remainingSpace = (int*) mySpace;
	//*remainingSpace = 5000;

	printf("Initially, our remaining space is = %d\n", (int) *remainingSpace);
	printf("Initially, the requested space is = %d\n", (int) newBytes);
	struct Node* newGuy;
	
	if (!root) //LL is empty-------------------------------------------------------------------------------------------------
	{
		printf("LL is empty!\n");
		//lastIndex is set to a spot in mySpace and it's at the last index
		if(lastIndex != NULL && (lastIndex != (void*) &mySpace[4999]))//memory must be full due to malloc(5000) not requiring a LL at all
		{
			printf("Mem must be full due to malloc(5000)\n");
			printf("As you can see the remainingSpace is: %d", (int) *remainingSpace);
		   printf("Memory is full. Malloc failed at line %d of file \"%s\".\n",(int)line,file);
		   return NULL;			
		}
		else if( MAXSIZE - abs(*remainingSpace) >= newBytes)//memory not full and enough space for newBytes
		{
			printf("Memory not full, we have enough space available for newBytes ;)\n");
			root = (struct Node*) (mySpace + sizeof(*remainingSpace)); //root is at first index of array
			root->size = newBytes; //set size
			root->isFree = false; //set to not free
			root->next = NULL;
			root->prev = NULL;
			*remainingSpace = (int) (MAXSIZE - sizeof(*newGuy) - sizeof(*remainingSpace) - n);
			printf("new remaining space is: 5000 - %d - %d - n(%d) = %d\n", sizeof(*newGuy), sizeof(*remainingSpace), n, *remainingSpace);
			currNode = root; //currNode is always the last node in LL
			printf("root/head node successfuly allocated at: %p ", (void*) root);
			//printf(": the address of mySpace[] is: %p\n", (void*) mySpace);
		}
		else //memory not full but not enough space for newBytes
		{
			printf("mem not full, remaining space not enough for bytes requested :/ so we return a ptr to mySpace[n-1]\n");
			void* traverse = (void*) mySpace;
			int i=0;
			for(i=0; i<n; i++)
			{
				traverse++;
			}
			lastIndex = traverse;
			*remainingSpace -= (int) (n);
			printf("new remaining space is: %d\n", *remainingSpace);
			printf("The address return is: %p while", (void*) lastIndex-1);
			printf("The address of mySpace[4998] is: %p\n", (void*) &mySpace[4998]);
			printf("The address of mySpace[4999] is: %p\n", (void*) &mySpace[4999]);
			return (void*) lastIndex-1;
		}
	}
	else //LL is occupied----------------------------------------------------------------------------------------------------
	{
		printf("LL has atleast 1 node!\n");
		//check if enough space for n bytes and plus metadata
		if (*remainingSpace >= newBytes)
		{
			printf("We have enough space = %d bytes, for %d bytes and %d metadata\n", *remainingSpace, newBytes);
			*remainingSpace -= newBytes; //update remainingSpace via subtracting newBytes
			printf("New remaining space is now = %d bytes\n", *remainingSpace);
			void *curr = (void*) currNode;
			newGuy = curr + currNode->size; //set newGuy to address in mySpace[] after currNode + currNode's size
			newGuy->size = newBytes; //set newGuy's size
			newGuy->isFree = false; //set newGuy to NOT free
			currNode->next = newGuy; //modify the LL for new data
			newGuy->prev = currNode;
			currNode = currNode->next;
			printf("New node for new data successfully allocated\n");
		}
		//only enough space for n bytes
		else if (*remainingSpace >= n)
		{
			printf("Only enough space for n bytes and no free nodes with great enough size\n");
			void* curr = (void*) currNode;
			lastIndex = curr + currNode->size;
			*remainingSpace = 0; //no space left			
		}
		else
		{
			//traverse LL to find a free node with enough space
			printf("Not enough space for n bytes, traversing through list now for free node\n");
			struct Node* ptr = root;
			while (ptr != NULL)
			{
				if(ptr->isFree && ptr->size >= newBytes) //node is free with enough space
				{
					ptr->isFree = false;
					//this free node might have more space than needed for newBytes, let's make a new node to hold the unused space
					//we will insert this new node into the existing LL
					if ( (ptr->size - sizeof(*ptr)) > n ) //node has more space than n bytes needed
					{
						newGuy = ptr + newBytes; //set newGuy's address to after ptr and newBytes
						newGuy->size = ptr->size - newBytes; //set newGuy's size to difference between ptr's old size and new size
						newGuy->isFree = true; //this is a free node for future allocations
						newGuy->next = ptr->next;
						newGuy->prev = ptr;
						if (ptr->next != NULL)//if ptr has a child node
						{
							struct Node* next = ptr->next;
							next->prev = newGuy;
						}
						ptr->next = newGuy;
					}
					ptr->size = newBytes; //set ptr's new size
					void* address = (void*) ptr;
					return (address + sizeof(*ptr));
				}
				ptr = ptr->next;
			}
			//No free nodes exist ;(
			printf("No free nodes with enough space/size exist\n");
		   printf("Memory is full. Malloc failed at line %d of file \"%s\".\n",(int)line,file);
			return NULL;
		}
		
		
	}//end of LL occupied else stmt
	
	return (void*) currNode + sizeof(*currNode);
}


