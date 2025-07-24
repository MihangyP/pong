#include "pong.h"

int	main(void)
{
	InitWindow(W_WIDTH, W_HEIGHT, "Pong");

	Vector2	player_position = {(W_WIDTH - BAR_WIDTH) / 2, W_HEIGHT - PAD};
	Vector2 ball_position = {W_WIDTH / 2, W_HEIGHT / 2};

	SetTargetFPS(60);
	int speed = 3;
	int dx = speed;
	int dy = speed;
	while (!WindowShouldClose()) {
		
		if (ball_position.x + (BALL_RADIUS / 2) >= W_WIDTH - 1 || 
			ball_position.x - (BALL_RADIUS / 2) <= 0)  {
			dx *= -1;
		}
		if (ball_position.y + (BALL_RADIUS / 2) >= W_HEIGHT - 1 ||
			ball_position.y - (BALL_RADIUS / 2) <= 0) {
			dy *= -1;
		}
		ball_position.x += dx;
		ball_position.y += dy;
		BeginDrawing();
		{
			ClearBackground(GetColor(0x181818));
			if (IsKeyDown(KEY_RIGHT)) {
				if (player_position.x + BAR_WIDTH < W_WIDTH)
					player_position.x += PLAYER_SPEED;
			}
			if (IsKeyDown(KEY_LEFT)) {
				if (player_position.x > 0)
					player_position.x -= PLAYER_SPEED;
			}
			DrawRectangle(player_position.x, player_position.y, BAR_WIDTH, BAR_HEIGHT, GOLD);
			DrawCircleV(ball_position, BALL_RADIUS, RED);
		}
		EndDrawing();
	}
	
	CloseWindow();
	return (0);
}
