/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:20:56 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:42:37 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	unsigned int	counter;

	if (!(s))
		return ;
	counter = 0;
	while (s[counter])
	{
		s[counter] = 0;
		counter++;
	}
}
