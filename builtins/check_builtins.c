/*
** check_builtins.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Mon May 12 12:59:09 2014 louis audibert
** Last update Sat May 24 07:02:57 2014 heitzl_s
*/

#include "builtins.h"
#include "../execution/execution.h"
#include "../xlib/xlib.h"

int	find_cmd(char *cmd)
{
  char	**find;
  int	i;

  i = 0;
  find = xmalloc(7 * sizeof(char*));
  find[0] = "cd";
  find[1] = "env";
  find[2] = "echo";
  find[3] = "history";
  find[4] = "exit";
  find[5] = "set";
  find[6] = NULL;
  while (find[i] != NULL)
    {
      if (strcmp(cmd, find[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	fill_builtins(int (**builtins)(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i))
{
  builtins[0] = &my_cd;
  builtins[1] = &my_env;
  builtins[2] = &my_echo;
  builtins[3] = &my_history;
  builtins[4] = &my_exit;
  builtins[5] = &set_env;
}

int     check_builtins(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  int   (*builtins[6])(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i);
  int	x;

  fill_builtins(builtins);
  x = 0;
  if (cmd[i].args && (check_or_and(cmd, i, shell) == 0))
    {
      while (x < 6)
	{
	  if (find_cmd(cmd[i].args[0]) == x)
	    {
	      if (builtins[x](shell, cmd, env, i) == -42)
		return (-42);
	      return (1);
	    }
	  x++;
	}
    }
  return (0);
}
