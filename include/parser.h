/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/10 17:53:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>

typedef struct			s_parse
{
	char				**argv;
	char				*right_path;
	char				**env;
	pid_t				pid;
}						t_parse;

typedef struct			s_process
{
	char				*cmd;
	int					stdio[3];
	char				aggr;
	int					completed;
	struct s_process	*next;

}						t_process;

typedef struct			s_job
{
	int					linker;
	struct s_process	*process;
	struct s_job		*next;
}						t_job;

t_job	*init_job(void);
void	free_parse(t_parse *parse);
void	push_process(t_process *node, t_process **head);
void	push_job(t_job *node, t_job **head);

#endif
