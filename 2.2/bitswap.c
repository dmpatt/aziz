// function that swaps bits i, j in an integer

#include <stdio.h>
#include <stdbool.h>

#define INT_SIZE ((unsigned int)sizeof(unsigned int)) * 8

unsigned int swapbits(unsigned int num, unsigned int bitIndex1, unsigned int bitIndex2)
{
	if (bitIndex1 == bitIndex2) return num; //indexes are equal
	unsigned int mask1 = 1, mask2 = 1;
	mask1 <<= bitIndex1;
	mask2 <<= bitIndex2;
	unsigned int bit1 = (num & mask1) >> bitIndex1;
	unsigned int bit2 = (num & mask2) >> bitIndex2;
	if (bit1 == bit2) return num; //bits are equal
	bit1 <<= bitIndex2;
	bit2 <<= bitIndex1;
	unsigned int combinedBits = bit1 | bit2;
	unsigned int mask = ~(mask1 | mask2) ;
	num &= mask;
	num |= combinedBits;
	return num;
}

unsigned int swapbits_aziz(unsigned int num, unsigned int bitIndex1, unsigned int bitIndex2)
{
	if (((num >> bitIndex1) & 1) != ((num >> bitIndex2) & 1))
	{
		num ^= (1 << bitIndex1) | (1 << bitIndex2);
	}
	return num;
}

int main(int argc, char **argvc)
{
	printf("\nSIZE OF INT:%u", INT_SIZE);
	printf("Indexes count from 0, unsigned ints\n");
	bool run = true;
	while (run)
	{
		printf("\nPlease enter 'number,bit1,bit2' for swap: ");
		unsigned int n = 0, b1 = 0, b2 = 0;
		if (3 == scanf("%u,%u,%u", &n,&b1,&b2))
		{
			if (b1 < 0 || b2 < 0 || b1 >= INT_SIZE || b2 >= INT_SIZE)
			{
				printf("\nInvalid input\n");
			}
			unsigned int s = swapbits(n,b1,b2);
			printf("\nSwapped number: %u\n", s);
		}
		else
		{
			printf("\nExiting...\n");
			run = false;
		}
	}
	return 1;
}
