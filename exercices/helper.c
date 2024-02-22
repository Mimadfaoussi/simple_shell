#include "main.h"


int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen((char *)src);
	if (!src || !dst)
		return (0);
	if (destsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && (i < destsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_length);
}



static char	*put(char const *str, int *index, char c)
{
	int		i;
	int		length;
	char	*result;

	i = *index;
	length = 0;
	while (str[i] == c && str[i] != '\0')
	{
		i++;
		*index = *index + 1;
	}
	while (str[*index] != c && str[*index] != '\0')
	{
		*index = *index + 1;
		length++;
	}
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str + i, length + 1);
	return (result);
}

static int	countwords(char const *str, char c)
{
	int	i;
	int	count;
	int	trigger;

	trigger = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (trigger == 0)
			{
				trigger = 1;
				count++;
			}
		}
		else if (trigger == 1)
			trigger = 0;
		i++;
	}
	return (count + 1);
}

static void	freelist(int i, char **res)
{
	while (i > 0)
	{
		free(res[i]);
		i = i - 1;
	}
	free(res[i]);
	free(res);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		count;
	char	**res;
	int		index;

	if (str == NULL)
		return (NULL);
	count = countwords(str, c);
	res = (char **)malloc(sizeof(char *) * (count));
	if (res == NULL)
		return (NULL);
	index = 0;
	i = 0;
	while (i < count - 1)
	{
		res[i] = put(str, &index, c);
		if (res[i] == NULL)
		{
			freelist(i, res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		length1;
	int		length2;

	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	newstr = malloc(length1 + length2 + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, length1 + 1);
	ft_strlcpy(newstr + length1, s2, length2 + 1);
	newstr[length1 + length2] = '\0';
	return (newstr);
}


/*
int main(void)
{
	char	**str;
	int	i;

	str = ft_split("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", ':');
	i = 0;
	while (str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}
	return (0);
}
*/
