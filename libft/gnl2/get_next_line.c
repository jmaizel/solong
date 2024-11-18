/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:00 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/07 17:49:27 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libftincludes/libft.h"

static char	*fill_buffer(int fd, char *static_buffer, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(static_buffer), NULL);
		buffer[bytes_read] = '\0';
		if (!static_buffer)
		{
			static_buffer = ft_strdup("");
			if (!static_buffer)
				return (NULL);
		}
		temp = static_buffer;
		static_buffer = ft_strjoin(temp, buffer);
		free(temp);
		if (!static_buffer)
			return (NULL);
		if (ft_strchr(static_buffer, '\n'))
			break ;
	}
	return (static_buffer);
}

static char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (buffer[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*save_leftover(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*leftover;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	leftover = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!leftover)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		leftover[j++] = buffer[i++];
	leftover[j] = '\0';
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(static_buffer), static_buffer = NULL, NULL);
	static_buffer = fill_buffer(fd, static_buffer, buffer);
	free(buffer);
	if (!static_buffer)
		return (NULL);
	line = extract_line(static_buffer);
	if (!line)
		return (free(static_buffer), static_buffer = NULL, NULL);
	static_buffer = save_leftover(static_buffer);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	if (close(fd) == -1)
	{
		perror("Erreur lors de la fermeture du fichier");
		return (1);
	}

	return (0);
} */