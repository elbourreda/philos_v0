/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:40:23 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/18 14:38:12 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long	ft_atoi(char *str)
{
	long	rslt;
	int		sign;
	int		cnt;

	rslt = 0;
	sign = 1;
	cnt = 0;
	while (str[cnt] == 32 || (str[cnt] >= 9 && str[cnt] <= 13))
		cnt++;
	if (str[cnt] == '-')
	{
		cnt++;
		sign = -1;
	}
	else if (str[cnt] == '+')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		rslt = rslt * 10 + (str[cnt] - '0');
		cnt++;
	}
	return (rslt * sign);
}
