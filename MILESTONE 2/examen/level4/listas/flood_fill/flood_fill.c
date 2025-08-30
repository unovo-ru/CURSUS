/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:35:34 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/22 20:06:53 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ft_list.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x 
			|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, fo_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

char **make(char **zone, t_point size)
{
	char **new_zone;

	new_zone = malloc(sizeof(char *) * size.y);
	int i = 0;
	while (i < size.y)
	{
		new[i] = malloc(size.x + 1);

    		int j = 0;
		while (j < size.x)
		{
			new[i][j] = zone[i][j];
        		j++;
		}
		new[i][size.x] = '\0';
		i++;
	}
	return (new_zone);
}
