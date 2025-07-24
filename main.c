#include "pong.h"

int	main(void)
{
	InitWindow(W_WIDTH, W_HEIGHT, "Pong");

	Rectangle	player;
	player.x = (W_WIDTH - BAR_WIDTH) / 2.0f;
	player.y =  (float)(W_HEIGHT - PAD);
	player.width = (float)BAR_WIDTH;
	player.height = (float)BAR_HEIGHT;
	Vector2 ball_position = {W_WIDTH / 2, W_HEIGHT / 2};

	SetTargetFPS(60);
	int speed = 5;
	int dx = speed;
	int dy = speed;
	while (!WindowShouldClose()) {
		bool has_collision_player = CheckCollisionCircleRec(ball_position, BALL_RADIUS, player);
		if (ball_position.x + (BALL_RADIUS / 2) >= W_WIDTH - 1 || 
			ball_position.x - (BALL_RADIUS / 2) <= 0) {
			dx *= -1;
		}
		if (ball_position.y + (BALL_RADIUS / 2) >= W_HEIGHT - 1 ||
			ball_position.y - (BALL_RADIUS / 2) <= 0 || 
			has_collision_player) {
			dy *= -1;
		}
		ball_position.x += dx;
		ball_position.y += dy;
		BeginDrawing();
		{
			ClearBackground(GetColor(0x181818));
			if (IsKeyDown(KEY_RIGHT)) {
				if (player.x + BAR_WIDTH < W_WIDTH)
					player.x += PLAYER_SPEED;
			}
			if (IsKeyDown(KEY_LEFT)) {
				if (player.x > 0)
					player.x -= PLAYER_SPEED;
			}
			DrawRectangleRec(player, GOLD);
			DrawCircleV(ball_position, BALL_RADIUS, RED);
		}
		EndDrawing();
	}
	
	CloseWindow();
	return (0);
}
