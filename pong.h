#ifndef PONG_H
# define PONG_H

# include <stdio.h>
# include "raylib.h"

# define W_WIDTH 800
# define W_HEIGHT 600
# define BAR_WIDTH 70
# define BAR_HEIGHT 70
# define PAD 100
# define PLAYER_SPEED 5
# define BALL_RADIUS 8

typedef struct
{
	int pos_x;
	int	pos_y;
}	t_player;

typedef struct
{
	Vector2	start;
	Vector2	end;
}	t_line;

#endif // PONG_H
