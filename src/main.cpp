#include "raylib.h"

#include "resource_dir.h"
#include "Program.hpp"

int main ()
{
	SearchAndSetResourceDir("resources");
    InitAudioDevice();
	SetTargetFPS(60);

	raylib::Window window(1000, 1000, "Galaga", FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	Program Galaga;
	ImageManager::Load();
	SoundManager::Load();

	if (!IsWindowReady()) {
    TraceLog(LOG_ERROR, "Window failed to initialize!");
    return 1;
}

	while (!WindowShouldClose()) {
    Galaga.KeyInputs();
    Galaga.Update();
    BeginDrawing();
    ClearBackground(BLACK);
    Galaga.Draw();
    EndDrawing();
}

	ImageManager::Unload();
	SoundManager::Unload();
	CloseAudioDevice();
	window.Close();
	return 0;
}
