#include "C:\Users\grimm\Desktop\raylib-5.5_win64_mingw-w64\raylib-5.5_win64_mingw-w64\include\raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "SquareCollect");
    SetTargetFPS(60);

    float posX = 20;
    float posY = 20;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("SquareCollect", 350, 200, 20, GRAY);
        float dt = GetFrameTime();
        float speed = 100.0f;
        char key;
        if (IsKeyDown(KEY_D))
            posX += speed * dt;
        if (IsKeyDown(KEY_A))
            posX -= speed * dt;
        if (IsKeyDown(KEY_W))
            posY -= speed * dt;
        if (IsKeyDown(KEY_S))
            posY += speed * dt;
        DrawRectangle(posX, posY, 20, 20, GRAY);
        EndDrawing();
    }
    CloseWindow();
}
