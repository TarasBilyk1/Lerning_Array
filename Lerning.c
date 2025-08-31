#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fifty_fifty(int array_random[], int arry_size);

int main(void) {
	srand(time(NULL));

	int Array_NUM[8];
	int arry_for_guess[3];

	printf(" Guess a number from 1 to 100 : ");
	fifty_fifty( Array_NUM,8);
	scanf_s("%d %d %d", &arry_for_guess[0], &arry_for_guess[1], &arry_for_guess[2]);

	int max = Array_NUM[0];
	for (int i = 0; i < 8; i++) {
		if (Array_NUM[i] > max) {
			max = Array_NUM[i];
		}
	}

	printf(" Your max number in the array = %d \n", max  );

	if (arry_for_guess[0] == max || arry_for_guess[1] == max || arry_for_guess[2] == max) {
		printf(" You Win !) Arr =  ");
	}
	else {
		printf(" You loss !( Arr =  ");
	}
	for (int i = 0; i < 8; i++)
			printf(" %d , ", Array_NUM[i]);

	return 0;
}

void fifty_fifty(int array_random[], int arry_size)
{
	for (int i = 0; i < arry_size; i++)
		array_random[i] = rand() % 100 + 1;
}