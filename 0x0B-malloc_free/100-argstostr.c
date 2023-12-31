#include "main.h"

/**
 * argstostr - concatenates all the arguments of program
 * @ac: no. of args.
 * @av: pointer to pointer to int char (2nd).
 *
 * Return: pointer to new string.
 */

char *argstostr(int ac, char **av)
{
	int i, j, k = 0, l = 0;
	char *str;

	/* check to see if no. of args <= 0 or av is null */
	if (ac <= 0 || av == NULL)
		return (NULL);

	/* loop through elements row-wise */
	for (i = 0; i < ac; i++)
	{
		/* loop through elements column-wise */
		for (j = 0; av[i][j]; j++)
			l++; /* increment for each element on a given row */
	}

	l += ac + 1; /* add space for \0 */

	str = malloc(sizeof(char) * l); /* allocate mem for string */

	if (str == NULL)
		return (NULL);
	/* write to new string, row and column-wise */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++) /* write each row */
		{
			str[k++] = av[i][j];
		}
		str[k++] = '\n'; /* add new line after each row */
	}
	str[k] = '\0';  /*append \0 char to last row */
	return (str);
}
