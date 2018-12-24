/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:25:19 by vsokolog          #+#    #+#             */
/*   Updated: 2017/11/23 19:00:07 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strtrim(char const *s)
// {
// 	char	*cs;
// 	size_t	end;
// 	size_t	begin;
// 	size_t	len;

// 	if (s == NULL)
// 		return (NULL);
// 	end = ft_strlen(s);
// 	begin = 0;
// 	len = 0;
// 	while ((s[end] == '\n' || s[end] == '\t' || s[end] == ' ') && (end > 0))
// 		end--;
// 	if (end == 0)
// 		return (ft_strdup(""));
// 	while (s[begin] == '\n' || s[begin] == '\t' || s[begin] == ' ')
// 		begin++;
// 	len = end - begin + 1;
// 	if (!(cs = ft_strsub(s, begin, len)))
// 		return (NULL);
// 	return (cs);
// }

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
