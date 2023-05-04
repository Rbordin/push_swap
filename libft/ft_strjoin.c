/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:06:07 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/02 12:55:35 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		((char *)s3)[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		((char *)s3)[i] = s2[j];
		i++;
		j++;
	}
	((char *)s3)[i] = '\0';
	return (s3);
}
