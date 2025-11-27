#include "C:\Users\Jonas\Desktop\raylib-5.5_win64_mingw-w64\raylib-5.5_win64_mingw-w64\include\raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

const int screenWidth = 800;
const int screenHeight = 400;

int score = 0;

int generatePosX()
{
    return rand() % screenWidth;
}

int generatePosY()
{
    return rand() % screenHeight;
}

int main()
{
    float gameDuration = 10.0f;
    float startTime = GetTime();
    srand(time(0));
    InitWindow(screenWidth, screenHeight, "SquareCollect");
    SetTargetFPS(60);

    float posX = 20;
    float posY = 20;

    int squarePosX = generatePosX();
    int squarePosY = generatePosY();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        float timeLeft = gameDuration - (GetTime() - startTime);
        if (timeLeft <= 0)
        {
            CloseWindow();
        }

        ClearBackground(WHITE);
        DrawText("SquareCollect", 350, 200, 20, GRAY);
        float dt = GetFrameTime();
        float speed = 400.0f;
        char key;
        if (IsKeyDown(KEY_D))
            posX += speed * dt;
        if (IsKeyDown(KEY_A))
            posX -= speed * dt;
        if (IsKeyDown(KEY_W))
            posY -= speed * dt;
        if (IsKeyDown(KEY_S))
            posY += speed * dt;

        if (posX < squarePosX + 20 && posX + 20 > squarePosX && posY < squarePosY + 20 && posY + 20 > squarePosY)
        {
            squarePosX = generatePosX();
            squarePosY = generatePosY();
            score++;
        }
        string str = to_string(score);
        string str2 = to_string(timeLeft);

        DrawRectangle(posX, posY, 20, 20, GRAY);
        DrawRectangle(squarePosX, squarePosY, 20, 20, GRAY);
        DrawText(str.data(), 775, 10, 25, BLACK);
        DrawText(str2.data(), 10, 10, 40, RED);
        EndDrawing();
    }
    CloseWindow();
}
