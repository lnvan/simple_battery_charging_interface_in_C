//This program creates a simple battery-charging interface. This program will be sent to Blue Marble Communications. I(Lam Van) compiled it using GCC on a Linux Ubuntu computer with an Intel CPU.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _speed 0x8ffffff	//sweet-spot constant number. if it is smaller or bigger, the bar will move way faster or way slower.
//rewrite the whole thing to make a batter charging graphic interface with 3 modes: slow, medium, and fast charging. DONE
//output the increasing level of battery. For example: 65%...65%...66%...67%. KEEP WORKING HERE!!!!!!!!!!!!!!! DONE

//n is how fast you want to charge your phone, n must be from 1 to 3. *battery_level (in percentage) must be in range [0...100] 
void charging(int n, int *battery_level);

int main()
{
	int n, rnd;
	time_t t;
		
        srand((unsigned) time(&t));
	rnd = rand() % 101;			
	printf("\nYour battery is at %d%%\n\n", rnd);
	printf("How fast do you want to charge your phone?\n1. Slow\t\t2. Medium\t3. Fast\n\n");
	scanf("%d", &n);			//get the speed from stdin and save it into n. n should be from 1 to 3. 
	while(1)
		charging(n, &rnd);		//rnd value will be changed by the function charging. caller makes sure rnd is in range [0...100] 
}

void charging(int n, int *battery_level) {

	int speed; 				//speed of moving bars depend on n 

	if (n < 1 || n > 3) {			//callee makes sure n valid	
		fprintf(stderr, "Error!!!! Number must be 1,2, or 3. Terminate the program.\n");
		exit(1);
	}

	//the bigger the value of n, the faster the bars move. But n = 3 is the fastest speed that human eyes can recognize	
	speed = _speed >> (n*2-1);

	if ((*battery_level) == 100) {
		printf("Full Battery\n\n");
		exit(1);
	}
	else {
		printf("%d%%", *battery_level);
		(*battery_level)++;
	}
	for(int j = 0; j < 20; j++) {
		printf("|");
		fflush(stdout);
		for(int i = 0; i < speed; i++)  
			;			//do nothing. could add some useful work here. but the work might affect the timing logic
	}
	for(int j = 0; j < 23; j++) {		//add 3 more loops to clear the battery-percentage output
		printf("\b \b");		//destructive backspace because the usual backspace \b doesn't delete the character.
		fflush(stdout);
	}
}

//Thanks for reading my code, Blue Marble :))))

