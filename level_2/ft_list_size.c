/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :
*/
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; 

int	ft_list_size(t_list *begin_list)
{
/*	t_list *current;
	t_list *next;
	if (!begin_list)
		return (0);
	current = begin_list;
	int count = 1;
	while (next)
	{
		current = next;
		count++;
		next = current -> next;
	}
*/
	if (!begin_list)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));

}

/*
int	main(void)
{
	t_list mylist;

	return (0);
}
*/
