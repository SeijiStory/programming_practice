#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void montyhall(int elements);
int stayiter();
int changeiter();
int main(int argc, char **argv)
{
	srand(time(NULL));
	int iterations;
	if (argc < 2) return 1;
	if ((iterations = strtoul(argv[1], NULL, 10)) == '\0')
		return 2;
	montyhall(iterations);
	return 0;
}

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
}

int stayiter()
{
	int door = rand() % 3 + 1;
	int choice = rand() % 3 + 1;
	return door == choice;
}

int changeiter()
{
	int door = rand() % 3 + 1;
	int choice = rand() % 3 + 1;
	return door != choice;
}
