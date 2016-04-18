#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* errmsg = "Usage: montyhall [positive number of iterations]\n";
void montyhall(int elements);
int stayiter();
int changeiter();
int main(int argc, char **argv)
{
	srand(time(NULL));
	int iterations;
	if (argc != 2) {
		printf(errmsg);
		goto args_error;
	}
	if ((iterations = strtoul(argv[1], NULL, 10)) == '\0') {
		printf(errmsg);
		goto value_error;
	}
	if (iterations < 1) {
		printf(errmsg);
		goto value_error;
	}
	montyhall(iterations);
	return 0;
args_error:
	return 1;
value_error:
	return 2;
}

/* void montyhall(int elements)
 * return value: N/A
 * Runs elements number of simulations, and averages the number of successes
 * and failures for both into a percentage
 */
void montyhall(int elements)
{
	double change = 0;
	double stay = 0;
	int i;
	for (i = 1; i <= elements; ++i)
		change += changeiter();
	for (i = 1; i <= elements; ++i)
		stay += stayiter();
	change = change / elements * 100;
	stay = stay / elements * 100;
	printf("Change Accuracy: %.5f%%\n", change);
	printf("Stay Accuracy: %.5f%%\n", stay);
	// Ideal values: Change - ~66%; Stay - ~33%
}

int stayiter()
{
	int door = rand() % 3 + 1;
	int choice = rand() % 3 + 1;
	/* Logic: The only way to win if staying is if the door chosen first was
	 * the goal door */
	return door == choice;
}

int changeiter()
{
	int door = rand() % 3 + 1;
	int choice = rand() % 3 + 1;
	/* Logic: If the chosen door is the goal door, then switching will result
	 * in losing */
	return door != choice;
}
