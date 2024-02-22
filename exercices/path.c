#include "main.h"


char	**_path(void)
{
	char	*c;
	char	**s;
	int	i;

	i = 0;
	c = _getenv("PATH");
	s = ft_split(c, ':');
	/*while (s[i])
	{
		printf("%s\n",s[i]);
		i++;
	}*/
	free(c);
	return (s);
}


t_list	*create_node(char *path)
{
	t_list	*node;

	if (!path)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->text = path;
	node->next = NULL;
	return (node);
}

t_list	*find_last_node(t_list **lst)
{
	t_list	*index;

	index = *lst;
	while (index->next != NULL)
		index = index->next;
	return (index);
}

t_list	*path_list(char **path)
{
	int	i;
	t_list	*lst;
	t_list	*last;
	t_list	*node;

	if (!path || !*path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		if (lst == NULL)
			lst = create_node(path[i]);
		else
		{
			node = create_node(path[i]);
			last = find_last_node(&lst);
			last->next = node;
		}
		i++;
	}
	return (lst);
}

int main(void)
{
	char	**p;
	t_list	*lst;

	p = _path();
	lst = create
	lst = path_list(p);
	printf("%s\n", lst->text);
	return (0);
}
