/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:35:40 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 12:06:57 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int		count_wd(char *str);
char	*create_str(char **ar, char *str);
void	free_all(char **ar);
char	**ft_split(char *str);

int	count_wd(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		count++;
		while (str[i])
		{
			if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
				break ;
			i++;
		}
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
	}
	return (count);
}

char	*create_str(char **ar, char *str)
{
	char	*end;
	int		len;
	char	*dest;
	int		i;

	end = str;
	while (*end && (! (*end == ' ' || (*end >= 9 && *end <= 13))))
		end++;
	len = end - str;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (!dest)
	{
		free_all(ar);
		return (NULL);
	}
	i = 0;
	while (str < end)
		dest[i++] = *str++;
	dest[i] = '\0';
	return (dest);
}

void	free_all(char **ar)
{
	char	**ptr;

	if (!ar)
		return ;
	ptr = ar;
	while (*ptr)
		free (*ptr++);
	free(ar);
}

char	**ft_split(char *str)
{
	int		count;
	char	**ar;
	int		i;

	count = count_wd(str);
	ar = (char **) malloc (sizeof(char *) * (count + 1));
	if (!ar)
		return (NULL);
	ar[count] = NULL;
	i = -1;
	while (++i < count)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (!*str)
			break ;
		ar[i] = create_str(ar, str);
		while (*str)
		{
			if (*str == ' ' || (*str >= 9 && *str <= 13))
				break ;
			str++;
		}
	}
	return (ar);
}
