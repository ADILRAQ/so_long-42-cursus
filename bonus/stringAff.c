/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringAff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:29:07 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/03 13:10:36 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_string_aff(t_info *pl, t_img ig)
{
	char	*str;
	char	*str1;
	char	*str2;
	int		mid;

	mid = (pl->x_max * 64) / 2;
	str = ft_itoa(pl->mov);
	str1 = ft_itoa(pl->coins);
	str2 = ft_itoa(pl->to_coins);
	mlx_put_image_to_window(pl->mlx, pl->win, ig.p_mov, mid - 130, 0);
	mlx_string_put(pl->mlx, pl->win, mid - 80, 20, 65386, str);
	mlx_put_image_to_window(pl->mlx, pl->win, ig.t_j, mid - 45, 0);
	mlx_put_image_to_window(pl->mlx, pl->win, ig.col_m, mid + 60, 0);
	mlx_string_put(pl->mlx, pl->win, mid + 100, 15, 65386, str2);
	mlx_string_put(pl->mlx, pl->win, mid + 110, 15, 65386, " / ");
	mlx_string_put(pl->mlx, pl->win, mid + 140, 15, 65386, str1);
	free(str);
	free(str1);
	free(str2);
}
