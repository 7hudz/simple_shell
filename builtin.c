#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit command
 * (0) if info.argv[0] != "exit".
 */
int _myexit(info_t *infoo)
{
	int exitcheck;

	if (infoo->argv[1]) /* If there is an exit arguement u want */
	{
		exitcheck = _erratoi(infoo->argv[1]);
		if (exitcheck == -1)
		{
			infoo->status = 2;
			print_error(infoo, "Illegal number: ");
			_eputs(infoo->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infoo->err_num = _erratoi(infoo->argv[1]);
		return (-2);
	}
	infoo->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * info: Structure containing potential arguments.
 * Return: Always '0'
 */
int _mycd(info_t *infoo)
{
	char *p, *dir, buffer[1024];
	int chdir_ret;

	p = getcwd(buffer, 1024);
	if (!p)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!infoo->argv[1])
	{
		dir = _getenv(infoo, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(infoo, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(infoo->argv[1], "-") == 0)
	{
		if (!_getenv(infoo, "OLDPWD="))
		{
			_puts(p);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(infoo, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dir = _getenv(infoo, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(infoo->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(infoo, "can't cd to ");
		_eputs(infoo->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(infoo, "OLDPWD", _getenv(infoo, "PWD="));
		_setenv(infoo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments.
 */
int _myhelp(info_t *infoo)
{
	char **arg_array;

	arg_array = infoo->argv;
	_puts("help call works. Function not  implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused work */
	return (0);
}

