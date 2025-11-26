#include "C:\Users\grimm\Desktop\raylib-5.5_win64_mingw-w64\raylib-5.5_win64_mingw-w64\include\raylib.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "SquareCollect");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("SquareCollect", 350, 200, 20, GRAY);
        EndDrawing();
    }
    CloseWindow();
}