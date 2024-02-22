#include "main.h"


int main(void)
{
	char	*c;
	char	**s;
	int	i;

	i = 0;
	c = _getenv("PATH");
	s = ft_split(c, ':');
	while (s[i])
	{
		printf("%s\n",s[i]);
		i++;
	}
	return (0);

}
