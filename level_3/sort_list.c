/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/
#include "list.h"

//BUBBLE SORT
t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *current = lst;
    int temp;
    int swapped;
 
    // Repeat until no more swaps are needed
    do {
        swapped = 0;
        current = lst;
 
        // Traverse the list and swap adjacent elements if they are in the wrong order
        while (current != NULL && current->next != NULL)
        {
            if (cmp(current->data, current->next->data))
            {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
 
    return lst;
}

/*
 * SELECTION SORT
t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *current = lst;
    t_list *min;
    int temp;

    // Traverse the list
    while (current != NULL)
    {
        min = current;
        // Find the minimum element in the remaining unsorted part of the list
        t_list *search = current->next;
        while (search != NULL)
        {
            if (cmp(search->data, min->data))
                min = search;
            search = search->next;
        }

        // Swap the found minimum element with the current element
        temp = current->data;
        current->data = min->data;
        min->data = temp;

        // Move to the next element in the list
        current = current->next;
    }

    return lst;
}
*/
