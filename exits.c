#include "shell.h"

/**
 **_strncpy - copies a string
 *dest: the destination string to be copied to
 *n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, h;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		h = i;
		while (h < n)
		{
			dest[h] = '\0';
			h++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the sring
 *@n: the amount of bd string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, h;
	char *s = dest;

	i = 0;
	h = 0;
	while (dest[i] != '\0')
		i++;
	while (src[h] != '\0' && h < n)
	{
		dest[i] = src[h];
		i++;
		h++;
	}
	if (h < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the stringr to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char o)
{
	do {
		if (*s == o)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

