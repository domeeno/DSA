#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int strlength (char* str)
{
	int k = 0;
	while (str[k] != '\0')
		k++;

	return k;
}

int main()
{
	int const LEN = 80;
	int const NM  = 10000;

	FILE *fin, *fout;

	fin = fopen("text_in.txt", "r");

	char str[NM][LEN];

	int *spaces = (int*)calloc(100, sizeof(int));

	int c, k = 0, l = 0, last_c = 0;
	int space_flag = 0, newline_flag = 0;
	while ((c = fgetc(fin)) != EOF)
	{
		/*
		** Do something with c, such as check against '\n'
		** and increment a line counter.
		*/

		if ( c != '\n' && c != 32 )
		{
			str[k][l] = (char)c;
			l++;
			space_flag = 0;
			newline_flag = 0;
		}
		else if (c == '\n' && last_c == '\n')
		{
			if (!newline_flag)
			{
				str[k][0] = (char)230;
				k++;
			}
			newline_flag = 1;
		}
		else
		{
			if (!space_flag)
			{
				k++;
				l = 0;
			}
			space_flag = 1;
		}
		last_c = c;
	}

	fclose(fin);

	int char_count = 0, last_n = 0;

	fout = fopen("text_out.txt", "w");

	for (int m = 0; last_n <= k; m++)
	{
		int n, rem = 0, fl = 0;
		for (n = 0; ; n++)
		{
			int lngth;
			if (str[n+last_n][0] == (char)230)
				lngth = -1;
			else
				lngth = strlength(str[n+last_n]);

			if (char_count + lngth > LEN)
			{
				rem = LEN - char_count + 1;
				break;
			}
			if (lngth == -1)
			{
				fl = 1;
				rem = 0;
				break;
			}
			char_count += lngth + 1;
		}

		while (rem > 0 && n != 0)
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (rem == 0)
					break;
				spaces[i]++;
				rem--;
			}
		}

		int s = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i)
			{
				for (int o = 0; o < spaces[s]+1; ++o)
					fprintf(fout, " ");
				s++;
			}


			for (int j = 0; str[i+last_n][j] != '\0'; ++j)
			{
				fprintf(fout, "%c", str[i+last_n][j]);
			}
		}
		fprintf(fout, "\n");
		if (fl)
		{
			last_n++;
			fprintf(fout, "\n");
		}
		char_count = 0;
		last_n += n;
		memset(spaces, 0, sizeof(int) * LEN);
	}

	fclose(fout);
	free(spaces);

	return 0;
}