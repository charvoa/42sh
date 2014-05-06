/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
<<<<<<< Updated upstream
** Last update Tue May  6 13:55:15 2014 Nicolas Charvoz
=======
** Last update Mon May  5 14:45:34 2014 garcia antoine
>>>>>>> Stashed changes
*/

#include "parser.h"

char		*check_token(t_token **token, t_lex *lexi)
{
  t_token       *tok;

  tok = *token;
  if ((tok->type != TOKEN_WORD || tok->type == TOKEN_UNK) && (tok))
    return (tok->value);
  tok = tok->next;
  while (tok && tok->next)
    {
      if (tok->type == TOKEN_UNK)
  	{
  	  lexi->cmd[tok->pos - 1] = '\0';
	  return (tok->value);
  	}
      if (tok->type != TOKEN_WORD && tok->next)
  	{
	  tok = tok->next;
  	  if (tok->type != TOKEN_WORD || tok->type == TOKEN_UNK)
  	    {
  	      lexi->cmd[tok->pos] = '\0';
	      return (tok->value);
  	    }
  	}
      tok = tok->next;
    }
  return (NULL);
}

int		size_of_list(t_token **token)
{
  t_token	*tok;
  int		i;

  i = 0;
  tok = *token;
  while (tok->next)
    {
      i++;
      tok = tok->next;
    }
  return (i);
}

void		parser(t_token **token, t_42sh *shell)
{
  t_token	*tok;
  int		a;
  t_pars	*pars;

  a = 0;
  tok = *token;
  pars = malloc(sizeof(*pars));
  pars->tab = malloc((size_of_list(token) + 1) * sizeof(char*));
  pars->tab = memset(pars->tab, 0, (size_of_list(token) + 1));
  while (tok->next)
    {
      pars->tab[a] = malloc((strlen(tok->value) + 1) * sizeof(char));
      pars->tab[a] = memset(pars->tab[a], 0, (strlen(tok->value) + 1));
      pars->tab[a] = strdup(epur_str(tok->value));
      a++;
      tok = tok->next;
    }
  pars->tab[a] = malloc((strlen(tok->value) + 1) * sizeof(char));
  pars->tab[a] = memset(pars->tab[a], 0, (strlen(tok->value) + 1));
  pars->tab[a] = strdup(epur_str(tok->value));
  a++;
  pars->tab[a] = NULL;
  send(pars->tab, shell->path, shell->envtab);
}
