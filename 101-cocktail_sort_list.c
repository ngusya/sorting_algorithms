#include "sort.h"

/**
 * list_len - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_nodes - function swaps nodes at pointer p with the following node
 * @list: head of list
 * @ptn: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **ptn)
{
	listint_t *one, *two, *three, *four;

	one = (*ptn)->prev;
	two = *ptn;
	three = (*ptn)->next;
	four = (*ptn)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*ptn = three;
}

/**
 *  cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptn;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	ptn = *list;
	while (!sorted)
	{
		sorted = 1;
		while (ptn->next)
		{
			if (ptn->n > ptn->next->n)
			{
				sorted = 0;
				switch_nodes(list, &ptn);
				print_list(*list);
			}
			else
				ptn = ptn->next;
		}
		if (sorted)
			break;
		ptn = ptn->prev;
		while (ptn->prev)
		{
			if (ptn->n < ptn->prev->n)
			{
				sorted = 0;
				ptn = ptn->prev;
				switch_nodes(list, &ptn);
				print_list(*list);
			}
			else
				ptn = ptn->prev;
		}
	}
}
