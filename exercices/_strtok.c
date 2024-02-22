#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int _strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nb_words(char *str, char del)
{
	int	i;
	int	count;
	int	s;
	int	check;

	check = 0;
	s = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == del && s == 0)
		{
			count++;
			s = 1;
		}
		if (str[i] != del)
		{
			s = 0;
			check = 1;
		}
		i++;
	}
	if (check == 0)
		return (1);
	if (str[i - 1] == del)
		return (count + 1);
	else
		return (count + 2);
}

char	**create_array(int nb_words)
{
	int	i;
	char	**array;

	i = 0;
	array = malloc(sizeof(char *) * nb_words);
	if (!array)
		return (NULL);
	while (i < nb_words)
	{
		array[i] = malloc(sizeof(char *));
		if (array[i] == NULL)
		{
			while (i > 0)
			{
				free(array[i - 1]);
				i--;
			}
			return (NULL);
		}
		printf("space malloced \n");
		i++;
	}
	return (array);
}

/*int main(void)
{
	int	count;
	char	a[5] = "abcd";
	char	**array;

	array = create_array(2);
	//array[0] = a;
	printf("%s\n",array[0]);
	return (0);
}*/
