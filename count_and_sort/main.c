#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		printf("No arguments found");
		return (1);
	}

	//2-D array for all ASCII symbols and set each cell to -1
	int table[256][256] = {-1};
	int count = 0;
	char cur_symbol = 0;
	char *str = argv[1];

	while (*str)
	{
		count = 0;
		cur_symbol = *str;
		while (*str && *str == cur_symbol) //count the # of occurances for current symbol
		{
			count++;
			str++;
		}
		// use ASCII code as a hash key and switch corresponding index to 1 (counting sort)
		table[count][(int)cur_symbol] = 1;
		table[0][(int)cur_symbol] = 1; //mark 0 index to indicate the row has data
		if (!*str)
			break ;
	}
	//print results
	for (int y = 0; y < 256; y++)
	{
		if (table[0][y] == 1)
		{
			for (int x = 1; x < 256; x++) //start from 1 since 0 index is for marking the row
			{
			
				if (table[x][y] == 1)
					printf("%c%d", (char)y, x);
			}
		}
	}
	printf("\n");
	return (0);
}

