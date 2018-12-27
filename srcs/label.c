/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:35:27 by vsokolog          #+#    #+#             */
/*   Updated: 2018/12/25 14:35:28 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_append(t_list **curr_labs, t_list **all_labs, t_label *l)
{
	if (!label_exists(*all_labs, l->name))
	{
		ft_lstaddend(curr_labs, ft_lstnew(l, sizeof(t_label)));
		ft_lstaddend(all_labs, ft_lstnew(l, sizeof(t_label)));
	}
}

bool	is_label(char *line, size_t len)
{
	size_t counter;

	counter = -1;
	while (++counter < len)
	{
		if (!(ft_strchr(LABEL_CHARS, line[counter])))
			return (false);
	}
	return (true);
}

bool	label_exists(t_list *labels, char *label)
{
	t_list *tmp;

	tmp = labels;
	while (tmp)
	{
		if (ft_strequ(((t_label *)tmp->content)->name, label))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

t_label	*label_get(char *line, t_counter *counter)
{
	size_t	label_char;
	ssize_t	invld_smbl;
	t_label	*label;

	label_char = ft_strcspn(line, ":");
	if (is_label(line, label_char))
	{
		if ((invld_smbl = get_invalid_symbols(line, label_char,\
			LABEL_CHARS)) == -1)
		{
			label = ft_memalloc(sizeof(t_label));
			counter->column += label_char;
			label->name = ft_strsub(line, 0, label_char);
			label->len = ft_strlen(label->name);
			return (label);
		}
	}
	return (NULL);
}

t_label	*label_get_solo(char *line, t_counter *counter)
{
	size_t	label_char;
	ssize_t	invld_smbl;
	t_label	*label;

	label_char = ft_strcspn(line, ":");
	if (line[label_char] == LABEL_CHAR
	&& line[label_char + 1] == '\0')
	{
		label = ft_memalloc(sizeof(t_label));
		if ((invld_smbl = get_invalid_symbols(line, label_char - 1,\
			LABEL_CHARS)) != -1)
		{
			counter->column += (size_t)invld_smbl;
			lexical_errors(E_INVALID_SYMBOLS, counter);
		}
		label->name = ft_strsub(line, 0, label_char);
		label->len = ft_strlen(label->name);
		return (label);
	}
	return (NULL);
}
