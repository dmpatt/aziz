// compute parity of an integer
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

short parity(int num)
{
	short result = 0;
	while (num)
	{
		result ^= num & 1;
		num >>= 1; 
	}
	return result;		
}

int main(int argc, const char* argv[])
{
	bool run = true;
	while (run)
	{
		printf("\nEnter number for parity check: ");
		int n = 0;
		if (1 == scanf("%d", &n))
		{
			int p = parity(n);
			printf("\nParity of %d is: %d\n", n, p);
		}
		else
		{
			printf("\nExiting...\n");
			run = false;
		}
	}
	return 1;
}
