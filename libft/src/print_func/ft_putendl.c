/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtsyvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:36:46 by dtsyvin           #+#    #+#             */
/*   Updated: 2017/10/27 22:36:48 by dtsyvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}
