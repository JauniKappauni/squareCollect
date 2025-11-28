#include "C:\Users\Jonas\Desktop\raylib-5.5_win64_mingw-w64\raylib-5.5_win64_mingw-w64\include\raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

const int screenWidth = 800;
const int screenHeight = 400;

int score = 0;
int highScore = 0;

bool gameOver;

bool isCountingDown = true;
float countDownTime = 3.0f;

void DrawGameOver()
{
    ClearBackground(WHITE);
    DrawText("Time's up!", 300, 150, 50, RED);
    string scoreString = "Score: " + to_string(score);
    DrawText(scoreString.data(), 600, 150, 25, RED);
    DrawText("Press enter to restart", 325, 200, 25, RED);
}

int generatePosX()
{
    return rand() % screenWidth;
}

int generatePosY()
{
    return rand() % screenHeight;
}

void ResetGame(float &posX, float &posY, int &squarePosX, int &squarePosY, int &score, float &startTime)
{
    posX = 20;
    posY = 20;
    squarePosX = generatePosX();
    squarePosY = generatePosY();
    score = 0;
    startTime = GetTime();
}

void DrawCountDown(float &startTime)
{
    countDownTime -= GetFrameTime();
    int count = countDownTime + 1;

    ClearBackground(WHITE);
    DrawText(to_string(count).c_str(), 350, 150, 100, BLACK);

    if (countDownTime <= 0)
    {
        isCountingDown = false;
        startTime = GetTime();
    }
}

void UpdateHighScore(int score, int &highScore){
    if(score > highScore) highScore = score;
}

int main()
{
    int gameDuration = 10;
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
        if (isCountingDown)
        {
            DrawCountDown(startTime);
            EndDrawing();
            continue;
        }

        int timeLeft = gameDuration - (GetTime() - startTime);
        if (timeLeft <= 0)
        {
            gameOver = true;
            UpdateHighScore(score, highScore);
        }
        if (gameOver)
        {
            DrawGameOver();
            if (IsKeyPressed(KEY_ENTER))
            {
                isCountingDown = true;
                countDownTime = 3.0f;
                gameOver = false;
                ResetGame(posX, posY, squarePosX, squarePosY, score, startTime);
            }
            EndDrawing();
            continue;
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
        string str = "Score: " + to_string(score);
        string str2 = to_string(timeLeft);
        string str3 = "HighScore: " + to_string(highScore);
        DrawRectangle(posX, posY, 20, 20, GRAY);
        DrawRectangle(squarePosX, squarePosY, 20, 20, GRAY);
        DrawText(str.data(), 10, 10, 25, BLACK);
        DrawText(str2.data(), 10, 375, 25, RED);
        DrawText(str3.data(), 10, 35, 25, BLACK);
        EndDrawing();
    }
    CloseWindow();
}
