/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:42:32 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/12 22:59:55 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
	{
		return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int main ()
{
	char res= '2';
	char  fn;
	fn = is_alpha(res);
	printf("%d\n", fn);
}
*/
