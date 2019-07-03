/* Molly Pabst
mepabst
ECE 2220
Spring Semester
Assignment #1
Purpose - The purpose of this code is to compare a 
user input of lottery numbers to simulated lottery
numbers to see if the user wins. 
Assumptions - this program accepts 6 numbers
within a specified range and total sum.
*/

// Header File

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number(int lowNum, int highNum, int arrayNum, int* array);
void swap(int *a, int *b);
void shuffle(int *array, int n);
void add(int* array, int n);
void sort(int* array);
void generate(int *array);

/* this program successively adds each element
in an array to the previous sum */
void add(int *array, int n) {
        int i;
        for (i = 0; i < n; i++) {
                array[i+1] = array[i] + array[i+1];
        }

        // print
        printf("\n");
        printf("Your lottery numbers are:");
        for (i = 0; i< n; i++) {
                printf(" %d ", array[i]);
        }
        printf("\n");
}

/* This function randomly generates 6 numbers 
between 1 and 50 and puts them in an array */
int i;
void generate(int *array) {
//      srand(time(NULL));
        for (i = 0; i <= 5; i++) {
                array[i] = rand() % 50 + 1;
        }

}

/* these functions swap and randomize elements
in an array to shuffle the array */
void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

void shuffle(int *array, int n) {
        srand(time(NULL));
        int i, j;
        for(i = n-1; i > 0; i--) {
                j = rand() % (i+1);
                swap(&array[i], &array[j]);
        }
}

/* This function asks the user to input a number within
a range and checks to see if the input is within range. */
void number(int lowNum, int highNum, int arrayNum, int* array) {

        // input
        printf("Please input a number from %d to %d inclusive: ", lowNum, highNum);
        scanf("%d", &array[arrayNum]);

        // check if number is within range
        while (array[arrayNum] < lowNum || array[arrayNum] > highNum) {
                printf("Your number is out of range. Please try again: ");
                scanf("%d", &array[arrayNum]);
        }

}

/* This program sorts the contents of the array 
in ascending order and prints is to the user */
void sort(int* array) {

        int i, j, temp;

        // sort array
        for (i = 0; i <= 5; ++i) {
                for(j = 0; j <= 5; ++j) {
                        if (array[j] > array[i]) {
                                temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
                        }
                }
        }

        // print array
        printf("Your delta numbers are:");
        for (i = 0; i <= 5; ++i) {
                printf(" %d ", array[i]);
        }
        printf("\n");
}


int main (void) {

	int userInput[5], sum, i, again, lotteryNums[5];
	srand(time(NULL));
	again = 0;
	while (again == 0) {
		// number from 1 to 5
		number(1,5,0,userInput);

		// two numbers from 1 to 10
		number(1,10,1,userInput);
		number(1,10,2,userInput);

		// number from 10 to 12
		number(10,12,3,userInput);
	
		// two numbers from 8 to 15
		number(8,15,4,userInput);
		number(8,15,5,userInput);
		
		// put numbers in order (print)
		sort(userInput);

		// check if numbers add up to 50 or less
		sum = 0;
		for (i = 0; i <= 5; i++) {
			sum += userInput[i];
		}
	
		if (sum > 50) {
			printf("Your numbers add up to a sum greater than 50. ");
			printf("Please try again.\n");
			again = 0;
		}
		else {
			again = 1;
		}
	} 
		// randomly reorder numbers (print)
		shuffle(userInput, 6);
		printf("Your final delta sequence is: ");
		for(i=0; i<= 5; i++) {
			printf(" %d ", userInput[i]);
		}
		// successive addition of numbers (print)
		add(userInput, 6);

		// randomly generate 6 numbers (from 1 to 50)
		generate(lotteryNums);

		int cnt;
	        cnt = 0;
		// loop that stops until you hit a million attempts or win
        	while (cnt < 1000000) {
			// compares user input to lottery numbers
                	for(i = 0; i <= 5; i++) {
                        	if (userInput[i] != lotteryNums[i]){
                                	++cnt;
                                	break;
                        	}
                        	else if (cnt == 0) {
                                	printf("Congrats, you have won the lottery!");
                                	exit(1);
                        	}
			}
			// generate new lottery numbers for next loop	
        		generate(lotteryNums);
		}
			if (cnt == 1000000){
                        printf("\nSorry, you did not win the lottery.\n");
                	}
                
        

return 0;
}
