environ.c

#include "shell.h"

/**
 * _myenv -- prints the current environment
 * info: -Structure containing potential arguments. Used to maintain
 * cont func prototype.
 * Return: Always 0
 */
int _myenv(info_t *infooo)
{
	print_list_str(infooo->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments.
 * Return: the value
 */
char *_getenv(info_t *infooo, const char *name)
{
	list_t *node = infooo->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 * || modify an existing one
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _mysetenv(info_t *infooo)
{
	if (infooo->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(infooo, infooo->argv[1], infooo->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remv an Environment variable
 */
int _myunsetenv(info_t *infooo)
{
	int u;

	if (infooo->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (u = 1; u <= infooo->argc; u++)
		_unsetenv(infooo, infooo->argv[u]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * info:- Structure containing arguments. Used to maintain
 *          constant func
 * Return: Always 0
 */
int populate_env_list(info_t *infooo)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	infooo->env = node;
	return (0);
}

