#include "pong.h"

// TODO: collisions

int	main(void)
{
	InitWindow(W_WIDTH, W_HEIGHT, "Pong");

	Rectangle	player;
	player.x = (W_WIDTH - BAR_WIDTH) / 2.0f;
	player.y =  (float)(W_HEIGHT - PAD);
	player.width = (float)BAR_WIDTH;
	player.height = (float)BAR_HEIGHT;
	Vector2 ball_position = {W_WIDTH / 2, W_HEIGHT / 2};

	t_line vertical_line_left = {
		{player.x, player.y},
		{player.x, player.y + BAR_HEIGHT},
	};

	t_line vertical_line_right = {
		{player.x + BAR_WIDTH, player.y},
		{player.x + BAR_WIDTH, player.y + BAR_HEIGHT},
	};

	t_line horizontal_line_top = {
		{player.x, player.y},
		{player.x + BAR_WIDTH, player.y},
	};

	t_line horizontal_line_bottom = {
		{player.x, player.y + BAR_HEIGHT},
		{player.x + BAR_WIDTH, player.y + BAR_HEIGHT},
	};

	SetTargetFPS(60);
	int speed = 5;
	int dx = speed;
	int dy = speed;
	while (!WindowShouldClose()) {
		if (ball_position.x + BALL_RADIUS >= W_WIDTH || 
			ball_position.x - BALL_RADIUS <= 0) {
			dx *= -1;
		}
		if (ball_position.y + BALL_RADIUS >= W_HEIGHT ||
			ball_position.y - BALL_RADIUS <= 0) {
			dy *= -1;
		}
		if (CheckCollisionCircleRec(ball_position, BALL_RADIUS, player))
		{
			if (CheckCollisionCircleLine(ball_position, BALL_RADIUS, vertical_line_left.start, vertical_line_left.end) 
			|| CheckCollisionCircleLine(ball_position, BALL_RADIUS, vertical_line_right.start, vertical_line_right.end)) {
				printf("hey\n");
				/*dx *= -1; */
			}

			if (CheckCollisionCircleLine(ball_position, BALL_RADIUS, horizontal_line_bottom.start, horizontal_line_bottom.end) 
			|| CheckCollisionCircleLine(ball_position, BALL_RADIUS, horizontal_line_top.start, horizontal_line_top.end)) {
				printf("hey\n");
				/*dy *= -1; */
			}
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
