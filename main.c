#include "pong.h"

int	main(void)
{
	InitWindow(W_WIDTH, W_HEIGHT, "Pong");

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();	
		ClearBackground(RED);
		EndDrawing();
	}
	
	CloseWindow();
	return (0);
}
