/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciafe2 <luciafe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:31:59 by luciafe2          #+#    #+#             */
/*   Updated: 2023/10/14 17:27:16 by luciafe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (n -- && (*u1 != '\0' || *u2 != '\0'))
	{
		if (*u1 != *u2)
		{
			return (*u1 - *u2);
		}
		u1++;
		u2++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char str1[] = "Hello,  U";
	char str2[] = "Hello,  Universeee!";
	int result = ft_strncmp(str1, str2, 10);
	printf("la diferencia es %i\n", ft_strncmp(str1, str2, 10));
}
}*/