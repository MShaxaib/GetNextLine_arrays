
#include "get_next_line.h"

//!    █████████     ███████    ███████████   ██████████
//!   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███░░░░░█
//!  ███     ░░░  ███     ░░███ ░███    ░███  ░███  █ ░
//! ░███         ░███      ░███ ░██████████   ░██████
//! ░███         ░███      ░███ ░███░░░░░███  ░███░░█
//! ░░███     ███░░███     ███  ░███    ░███  ░███ ░   █
//!  ░░█████████  ░░░███████░   █████   █████ ██████████
//!   ░░░░░░░░░     ░░░░░░░    ░░░░░   ░░░░░ ░░░░░░░░░░




char	*read_line(int fd, char *buf, char *str)
{
	int		readlines;
	char	*temp;

	readlines = 1;
	while (readlines != 0)
	{
		readlines = read(fd, buf, BUFFER_SIZE);
		if (readlines == -1)
		{
			if(str)
			{
			free(str);
			str = NULL;
			}
			return(0);
		}
		else if (readlines == 0)
			break ;
		buf[readlines] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (str);
}

char	*extract(char *line)
{
	size_t	count;
	char	*str;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	str = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!*str)
	{
		free(str);
		str = NULL;
	}
	line[count + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, str);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	str = extract(line);
	return (line);
}return (line);
}

// !  █████  █████ ███████████ █████ ████
// ! ░░███  ░░███ ░█░░░███░░░█░░███ ░░███
// !  ░███   ░███ ░   ░███  ░  ░███  ░███   █████
// !  ░███   ░███     ░███     ░███  ░███  ███░░
// !  ░███   ░███     ░███     ░███  ░███ ░░█████
// !  ░███   ░███     ░███     ░███  ░███  ░░░░███
// !  ░░████████      █████    █████ █████ ██████
// !   ░░░░░░░░      ░░░░░    ░░░░░ ░░░░░ ░░░░░░

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}



char	*ft_strdup(const char *src)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = ft_strlen(src);
	str = (char *)malloc(sizeof(*src) * (j + 1));
	while(i < j)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return(str);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}



char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if(str == 0)
		return(NULL);
	i = 0;
	j = 0;
	while(s[i])
	{
		if(i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return(str);
}

//!  ██████   ██████            ███
//! ░░██████ ██████            ░░░
//!  ░███░█████░███   ██████   ████  ████████
//!  ░███░░███ ░███  ░░░░░███ ░░███ ░░███░░███
//!  ░███ ░░░  ░███   ███████  ░███  ░███ ░███
//!  ░███      ░███  ███░░███  ░███  ░███ ░███
//!  █████     █████░░████████ █████ ████ █████
//! ░░░░░     ░░░░░  ░░░░░░░░ ░░░░░ ░░░░ ░░░░░



int main() {
    int fd;          
    char *line;

    
    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
    }
    return 0;
}

