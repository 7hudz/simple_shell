#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myhistory(info_t *infoo)
{
	print_list(infoo->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * info: parameter struct
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *infooo, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(infooo->alias),
		get_node_index(info->alias, node_starts_with(infooo->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info:- parameter struct
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *infooo, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(infooo, str));

	unset_alias(infooo, str);
	return (add_node_end(&(infooo->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *ooo
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *nodee)
{
	char *p = NULL, *a = NULL;

	if (nodee)
	{
		p = _strchr(nodee->str, '=');
		for (a = nodee->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myalias(info_t *infooo)
{
	int i = 0;
	char *p = NULL;
	list_t *nodee = NULL;

	if (infooo->argc == 1)
	{
		nodee = infooo->alias;
		while (nodee)
		{
			print_alias(nodee);
			nodee = nodee->next;
		}
		return (0);
	}
	for (i = 1; infooo->argv[i]; i++)
	{
		p = _strchr(infooo->argv[i], '=');
		if (p)
			set_alias(infooo, infooo->argv[i]);
		else
			print_alias(nodee_starts_with(infooo->alias, infooo->argv[i], '='));
	}

	return (0);
}

