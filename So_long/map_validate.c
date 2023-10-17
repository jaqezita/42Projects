
#include "so_long.h"

void	map_ok(t_game **game)
{
	validate_square_map(&game);
	validate_map(&game, 0, 0);
	ft_validate_characteres(&game, 0, 0);
	count_characters(&game, 0, 0);
}