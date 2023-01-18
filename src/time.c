/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:07:10 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/18 17:43:23 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	get_timer(void)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return (time_now.tv_sec + (time_now.tv_usec / 1000000));
}

int	get_fps(void)
{
	static int		frame_counter;
	static int		fps = 0;
	static int		oldtime;
	int				new_time;

	frame_counter++;
	new_time = get_timer();
	if (new_time - oldtime == 1)
	{
		fps = frame_counter;
		frame_counter = 0;
	}
	oldtime = new_time;
	return (fps);
}
