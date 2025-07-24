#ifndef PONG_H
# define PONG_H

# include <stdio.h>
# include "raylib.h"

# define W_WIDTH 800
# define W_HEIGHT 600
# define BAR_WIDTH 70
# define BAR_HEIGHT 10
# define PAD 50
# define PLAYER_SPEED 5
# define BALL_RADIUS 8

typedef struct
{
	int pos_x;
	int	pos_y;
}	t_player;

#endif // PONG_H
