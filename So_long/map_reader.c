
#include "solong.h"


void	ft_create_matrix(char *path)
{
	int			fd;
	char	*lines;
	char		**map;
	char		*temp;

	fd = open(path, O_RDONLY);

	lines = get_next_line(fd);
	temp = " ";

	while (ft_strchr(lines, '\0') && temp != NULL)
	{
		temp = get_next_line(fd);
		lines = ft_strjoin(lines, temp);
	}
	map = ft_split(lines, '\n');
}

void	check_edges(char **map)
{
	int i;
	int j;

	map[i][j];

	while (i < 1920)
	{
		while (j < 1080)
		{
			if (map[i][j] = '1')
				
		}
	}
	
	

	
}