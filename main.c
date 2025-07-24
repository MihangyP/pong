#include "pong.h"

int	main(void)
{
	InitWindow(W_WIDTH, W_HEIGHT, "Pong");

	t_player	player = {
		.pos_x = (W_WIDTH - BAR_WIDTH) / 2,
		.pos_y = W_HEIGHT - PAD
	};

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		{
			ClearBackground(GetColor(0x181817));
			
			DrawRectangle(player.pos_x, player.pos_y, BAR_WIDTH, BAR_HEIGHT, GOLD);
		}
		EndDrawing();
	}
	
	CloseWindow();
	return (0);
}
