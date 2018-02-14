#include "mymalloc.h"

#define SIZE 5000

struct Node
{
	struct Node *prev, *next;
	int free;		// 1 - yes, 0 - no
	int size;
};


static char memblock[SIZE]; //big block of memory space
static const int entriesSize = SIZE/sizeof(struct Node)+1; //size of array
static void *array[SIZE/sizeof(struct Node)+1] = {0}; //pointers to array


// free a memory buffer pointed to by p
void myfree(void *p, char *file, int line)
{
	struct Node *ptr;
	struct Node *prev;
	struct Node *next;

	if (p == NULL) {
		fprintf(stderr, "Pointer is NULL in file, free failed in FILE: '%s' on LINE: '%d'\n", file, line);
		return;
	}

	ptr = (struct Node*)((char*)p - sizeof(struct Node));
	
	//check if valid Node ptr
	int i;
	int valid = 0;
	for (i = 0; i < entriesSize; i++) {//iterate through all spots in array 
        //if ptr matches spot and free value is 0 (has been allocated)
		if (ptr == array[i] && !ptr->free) {
			valid = 1; //Node is valid
			break;
		}
	}
	if (!valid) {//no spot was ever found since it was not malloced
		fprintf(stderr, "Attempting to free memory that was not malloced in FILE: '%s' on LINE: '%d'\n", file, line);
		return;
	}

	if((prev = ptr->prev) != 0 && prev->free)
	{
		// the previous chunk is free
		// merge current chunk with the previous chunk
		prev->size += sizeof(struct Node) + ptr->size;
		array[i] = 0; //merged with previous, so removing free Node
	}
	else
	{ //not setting Node to null b/c not necessarily removing it, just free=1
		ptr->free = 1;
		prev = ptr;	// used for the step below
	}
	if((next = ptr->next) != 0 && next->free)
	{
		// the next chunk is free, merge with it
		prev->size += sizeof(struct Node) + next->size;
		prev->next = next->next;
		//prev->free = 1;
		for (i = 0; i < entriesSize; i++) {
			if (next == array[i]) {
				array[i] = 0; //merged with next, so removing free Node
				break;
			}
		}
	}
}