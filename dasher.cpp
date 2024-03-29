#include <raylib.h>

int main()
{
    //window dimesions
    const int windowWidth{512};
    const int windowHeight{380};
    // window initialization
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    SetTargetFPS(60);
    while (!WindowShouldClose()) 
    {
        //start drawing
        BeginDrawing();
        ClearBackground(WHITE);


        // end drawing
        EndDrawing();
    }
    //correct way to close the window
    CloseWindow();
}