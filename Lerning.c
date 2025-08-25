#include <stdio.h>

void main() {

	int array[10] ;
	
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &array[i]);
	}
	int max = array[0];

	for (int i = 0; i < 10; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	printf(" Your max number in the array = %d \n", max);

	return 0;
}   