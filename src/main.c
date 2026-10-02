#include "raylib.h"
#include "resource_dir.h"
#include "tiroalblanco.h"

int main(void)
{

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tiro al Blanco"); // Configuración inicial de la ventana

	GameScreen ventana_actual = MENU;

	Rectangle boton_inicio = {SCREEN_WIDTH/2.0f - 150, 250, 300, 50};
	Rectangle boton_puntajes = {SCREEN_WIDTH/2.0f - 150, 330, 300, 50};

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{

		Vector2 pos_mouse = GetMousePosition();

		switch(ventana_actual) //Logica
		{
			case MENU:
				if(CheckCollisionPointRec(pos_mouse, boton_inicio))
				{
					if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						ventana_actual = PARTIDA;
					}
				}

				if(CheckCollisionPointRec(pos_mouse, boton_puntajes))
				{
					if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						ventana_actual = PUNTAJES;
					}
				}

			case PARTIDA:
			case PUNTAJES:
				if(IsKeyPressed(KEY_ENTER))
				{
					ventana_actual = MENU;
				}
				break;
		}


		BeginDrawing();
		ClearBackground(RAYWHITE);

		switch(ventana_actual) //Dibujo en pantalla
		{
			case MENU:
				//Titulo centrado
				DrawText("TIRO AL BLANCO", SCREEN_WIDTH/2 - MeasureText("TIRO AL BLANCO", 60) / 2, 100, 60, DARKGRAY);

				//Boton iniciar partida
				DrawRectangleLinesEx(boton_inicio, 2, DARKGRAY);
				DrawText("Iniciar Partida", boton_inicio.x + 40, boton_inicio.y + 15, 20, BLACK);

				//Boton puntajes
				DrawRectangleLinesEx(boton_puntajes, 2, DARKGRAY);
				DrawText("Tabla de puntajes", boton_puntajes.x + 25, boton_puntajes.y + 15, 20, BLACK);

				break;

			case PARTIDA:
				DrawText("PANTALLA DE JUEGO", 20, 20, 40, RED);
                //Aca va la logica del juego
                DrawText("Presiona ENTER para volver al menú", 20, 550, 20, GRAY);
				break;

			case PUNTAJES:
				DrawText("TABLA DE PUNTUACIONES", 20, 20, 40, BLUE);
                //Aca va el manejo de puntajes y archivos
                DrawText("Presiona ENTER para volver al menú", 20, 550, 20, GRAY);
				break;

		}
			
		EndDrawing();
	}


	CloseWindow();

	return 0;
}







/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/
/*
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

		// draw our texture to the screen
		DrawTexture(wabbit, 400, 200, WHITE);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
*/