#include <raylib.h>

int main()
{
    //window dimesions
    const int windowWidth{512};
    const int windowHeight{380};
    // window initialization
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    // acceleration due to gravity (pixels/frame)/frame)
    const int gravity{1};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    // is the rectangle in the air
    bool isInAir{};
    // jump velocity
    const int jumpVel{-22};

    // player y position and velocity
    int posY{windowHeight - height};
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose()) 
    {
        //start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // ground check
        if (posY >= windowHeight - height)
        {
            // rectangle on ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle in air
            // apply gravity
            velocity += gravity;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        posY += velocity;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);

        // end drawing
        EndDrawing();
    }
    //correct way to close the window
    CloseWindow();
}