#include "asm.h"

void	label_append(t_list **curr_labs, t_list **all_labs, t_label *label)
{
	ft_lstaddend(curr_labs, ft_lstnew(label, sizeof(t_label)));
	ft_lstaddend(all_labs, ft_lstnew(label, sizeof(t_label)));
}

bool	is_label(char *line)
{
	while (*line)
	{
		if (!(ft_strchr(LABEL_CHARS, *line)))
			return (false);
		line++;
	}
	return (true);
}

bool	label_exists(t_list	*all_labels, t_label *label)
{
	t_list *tmp;

	tmp = all_labels;
	while (tmp)
	{
		if (ft_strequ(((t_label *)tmp->content)->name, label->name))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

t_label	*label_get(char *line, t_counter *counter)
{
	size_t	label_char;
	ssize_t	invalid_symbol;
	t_label	*label;

	label_char = ft_strcspn(line, ":");
	if (line[label_char] == LABEL_CHAR)
	{
		if ((invalid_symbol = get_invalid_symbols(line, label_char - 1, LABEL_CHARS)) == -1)
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
	ssize_t	invalid_symbol;
	t_label	*label;

	label_char = ft_strcspn(line, ":");
	if (line[label_char] == LABEL_CHAR
	&& line[label_char + 1] == '\0')
	{
		label = ft_memalloc(sizeof(t_label));
		if ((invalid_symbol = get_invalid_symbols(line, label_char - 1, LABEL_CHARS)) != -1)
		{
			counter->column += (size_t)invalid_symbol;
			lexical_errors(E_INVALID_SYMBOLS, line, counter);
		}
		label->name = ft_strsub(line, 0, label_char);
		label->len = ft_strlen(label->name);
		return (label);
	}
	return (NULL);
}