// Find the sum of numbers in an array
#include <stdio.h>

int main()
{
    // Create an array of 10 integers,
    // and other variables.
    int array[10];
    int i;
    int sum = 0;
    
    // Fill up the array.
    for (i = 0; i < 10; i++) {
        printf("Type a number: ");
        scanf("%d", (i + array));
    }
    
    // Add up the numbers in the array.
    for (i = 0; i < 10; i++) {
        sum = sum + array[i]; // OR sum += array[i];
    }
    
    printf("The sum of the numbers you typed is %d", sum);
	return 0;
}

