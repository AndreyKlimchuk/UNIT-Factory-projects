/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:24:59 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:43:07 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	if (!(s))
		return ;
	counter = 0;
	while (s[counter])
	{
		(*f)(counter, s + counter);
		counter++;
	}
}
