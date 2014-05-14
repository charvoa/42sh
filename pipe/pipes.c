/*
** pipes.c for 42sh in /home/girard_s/rendu/42/execution/pipes
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue May  6 14:01:38 2014 Nicolas Girardot
** Last update Wed May 14 14:19:23 2014 Nicolas Girardot
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "pipe.h"

int		init_pipes(t_cmd *cmd_1, t_cmd *cmd_2, t_42sh *shell)
{
  pid_t		pid;
  pid_t		pid2;
  int		fd[2];
  int		status;

  pipe(fd);
  pid = fork();
  if (pid == 0)
    {
      printf("fils\n");
      close(fd[0]);
      dup2(fd[1], 1);
      exec_cmd(cmd_1, shell);
    }
  else
    {
      printf("père\n");
      wait(&status);
      pid2 = fork();
      close(fd[1]);
      if (pid2 == 0)
	{
	  printf("fils du père\n");
	  close(fd[1]);
	  dup2(fd[0], 0);
	  exec_cmd(cmd_2, shell);
	}
      else
	{
	  close(fd[0]);
	  printf("père du père\n");
	}
    }
  return (0);
}
