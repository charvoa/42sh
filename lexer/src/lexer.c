/*
** main.c for  in /home/charvo_a/Work/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Apr  4 13:56:53 2014 Nicolas Charvoz
** Last update Mon Apr 21 15:51:43 2014 Nicolas Charvoz
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

static int	word_check(char *str, int i)
{
  while ((check_letter(str[i]) != -1) && str[i])
    {
      printf("TOKEN_WORD => %c[%d]\n", str[i], i);
      i++;
    }
  return (i);
}

void	lex(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = word_check(str, i);
      i = comma_check(str, i);
      i = pipe_check(str, i);
      i = red_r(str, i);
      i = red_l(str, i);
      i = check_and(str, i);
    }
  printf("str => %s\n", str);
}

int		main(int ac, char **av)
{
  char		*buffer;
  int		ret;
  (void)	av;
  (void)	ac;

  buffer = malloc(4096 * sizeof(char));
  ret = read(0, buffer, 4096);
  buffer[ret - 1] = '\0';
  lex(buffer);
  free(buffer);
  return (0);
}
