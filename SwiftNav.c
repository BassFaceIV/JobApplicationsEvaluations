#include <stdio.h>
#include <stdlib.h>

/********************************************
* Instructions were unclear as to what to do
* if a Fibonacci number exhibited more than
* one of the parameters.  Therfore, I print
* the statement associated with each rule.
* For example, 3 is both prime and divisible
* by 3 so I print "Buzz BuzzFizz".  You can
* distinguish a Fibonacci number that is
* divisible by 3 and 5 from one that is prime
* because I ensured a space would be printed
* between "Buzz" and "Fizz" in the former
* case.
*
* The value 'n' is going to be limited no
* matter what size the data type is. I chose
* to use long unsigned types for the
* Fibonacci numbers rather than the largest,
* long double, because the program's
* footprint is significantly smaller and over
* 100 Fibonacci numbers can still be printed
* without overflowing.
*
* This code can also be found at
* https://github.com/BassFaceIV/JobApplicationsEvaluations
********************************************/

void getNextFibonacciNumber(long unsigned *, long unsigned *);
int isDivisibleBy3(long unsigned *);
int isDivisibleBy5(long unsigned *);
int isPrime(long unsigned *);

int main(int argc, char * argv[]){
	int nums;		//remaining number of fibonacci numbers
	long unsigned fibNum;		//most recent fibonacci number
	long unsigned fibNumPrev;	//2nd most recent fibonacci number
	int div3Flag;	//indicates if value is divisible by 3
	int div5Flag;	//indicates if value is divisible by 5

	nums = atoi(argv[1]);
	fibNum = 1;
	fibNumPrev = 0;

	if(nums > 0){
		printf("0\n");
	}
	if(nums > 1){
		printf("BuzzFizz\n");
	}

	if(nums > 2){
		nums -= 2;
		while(nums--){
			getNextFibonacciNumber(&fibNum, &fibNumPrev);
			div3Flag = isDivisibleBy3(&fibNum);
			div5Flag = isDivisibleBy5(&fibNum);

			if(div3Flag){
				printf("Buzz ");
			}
			if(div5Flag){
				printf("Fizz ");
			}
			if(!div3Flag && !div5Flag){
				if(isPrime(&fibNum)){
					printf("BuzzFizz");
				}
				else{
					printf("%lu", fibNum);
				}
			}
			if((fibNum == 3) || (fibNum == 5)){
				printf("BuzzFizz");
			}
			printf("\n");
		}
	}

	return 0;
}

// Retrieve next Fibonacci Number given previous 2 numbers
void getNextFibonacciNumber(long unsigned *num, long unsigned *previousNum){
	long unsigned sum;

	sum = *num + *previousNum;
	*previousNum = *num;
	*num = sum;
}

// Check 3 divisibility
int isDivisibleBy3(long unsigned *num){
	return (*num % 3) ? 0 : 1;
}

// Check 5 divisibility
int isDivisibleBy5(long unsigned *num){
	return (*num % 5) ? 0 : 1;
}

// Check prime
int isPrime(long unsigned *num){
	int primeFlag = 1;
	long unsigned divisor = 2;

	while(((*num / divisor) >= divisor) && primeFlag){
		primeFlag = (*num % divisor) ? 1 : 0;
		divisor++;
	}

	return primeFlag;
}