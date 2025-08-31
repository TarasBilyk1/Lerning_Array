#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void fifty_fifty(int array_random[],int arry_size)
{
	 for (int i = 0; i < arry_size; i++)
		 array_random[i] = rand() %100 + 1;
}

int main(void) {
	srand(time(NULL));

	int Array_NUM[8];

	fifty_fifty(Array_NUM,8);

	int max = Array_NUM[0];
	for (int i = 0; i < 8; i++) {
		if (Array_NUM[i] > max) {
			max = Array_NUM[i];
		}
	}
	printf(" Your max number in the array = %d \n", max);
	printf(" \n ");

	for (int i = 0; i < 8; i++) {
		printf("Arr = %d ",Array_NUM[i]); 
	}
	printf(" \n ");

	return 0;
}