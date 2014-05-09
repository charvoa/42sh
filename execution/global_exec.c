/*
** global_exec.c for global_exec in /home/garcia_t/42/execution
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Thu May  8 16:21:37 2014 garcia antoine
** Last update Fri May  9 13:25:32 2014 garcia antoine
*/

#include <unistd.h>
#include "../parser/parser.h"
#include "execution.h"

int	global_exec(t_cmd *cmd, t_42sh *shell, int tok)
{
  int	i;

  i = 0;
  while (tok != 0)
    {
      if (cmd[i].token == NULL || strcmp(cmd[i].token, ";") == 0)
	exec_cmd_simple(&cmd[i], shell);
      else if (strcmp(cmd[i].token, ">") == 0 /*&& cmd[i].token != NULL*/)
	redir_right(&cmd[i], &cmd[i + 1], shell);
      else if (strcmp(cmd[i].token, ">>") == 0)
	double_redir_right(&cmd[i], &cmd[i + 1], shell);
      i++;
      tok--;
  }
  return (0);
}
