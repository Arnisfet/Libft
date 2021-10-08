#include "libft.h"

int ft_lstsize(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	i++;
	return (i);
}
