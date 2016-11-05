/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:45:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/05 12:06:32 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

char		*input_return(t_shell *sh, t_prompt *prompt)
{
	char	*str;

	str = NULL;
	prompt_print(prompt, 0);
	while (sh->hist->next)
		sh->hist = sh->hist->next;
	if (prompt->cmd[0])
	{
		sh->hist->str = ft_strdup(prompt->cmd);
		str = ft_strdup(sh->hist->str);
		return (str);
	}
	else
		sh->hist->str = ft_strdup("");
	return (str);
}

char		*input_eof(t_prompt *prompt, char buff)
{
	char	*str;

	str = NULL;
	prompt_print(prompt, 0);
	str = ft_strdup(&buff);
	return (str);
}

void		exit_eof(t_shell *sh, t_prompt *prompt)
{
	prompt_print(prompt, 0);
	reset_term(sh);
	exit(0);
}

static char	*input_return_heredoc(t_prompt *prompt)
{
	char	*str;

	str = NULL;
	prompt_print(prompt, 0);
	if (prompt->cmd[0])
		str = ft_strdup(prompt->cmd);
	else
		str = ft_strdup("");
	return (str);
}

char		*termcap_heredoc(t_shell *sh)
{
	t_prompt	*p;
	int			ret;
	char		buff[4];
	char		*str;

	p = init_prompt();
	stock_prompt(p, 0);
	prompt_print(p, 1);
	str = NULL;
	while ((ret = read(0, buff, BUFF_SIZE) != -1))
	{
		prompt_shell(sh, p, buff);
		if (buff[0] == 4 && !p->cmd[0] && (str = input_eof(p, buff[0])))
			break ;
		if (buff[0] == 10)
		{
			str = input_return_heredoc(p);
			break ;
		}
		ft_bzero(buff, 4);
	}
	free_prompt(&p);
	return (str);
}
