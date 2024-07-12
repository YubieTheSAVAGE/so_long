/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:38 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 03:01:54 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

long long	current_time_in_ms(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

int	c_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 60)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}

int	p_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 60)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}

int	x_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 100)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}

int	m_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 300)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}
