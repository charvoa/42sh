/*
** exec.h for  in /home/charvo_a/42/execution
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May  5 15:33:03 2014 Nicolas Charvoz
** Last update Mon May  5 17:17:25 2014 Nicolas Charvoz
*/

#ifndef EXEC_H_
# define EXEC_H_

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int	size_fo_tab(char**);
void	send(char**, char**, char**);
int	exec_simple(char**, char**, char**);

#endif
