#include <raylib.h>

int main()
{
    //window dimesions
    const int windowWidth{512};
    const int windowHeight{380};
    // window initialization
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    // acceleration due to gravity (pixels/s)/s)
    const int gravity{1'000};

    // scarfy
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;
    // is scarfy in the air
    bool isInAir{};
    // jump velocity (pixels/s)
    const int jumpVel{-600};
    // scarfy y position and velocity
    int velocity{0};

    // nebula 
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

    //animation frame
    int frame{};
    // amount of time before we update the animation frame
    const float updateTime{1.0/12.0};
    float runningTime{};

    SetTargetFPS(60);
    while (!WindowShouldClose()) 
    {
        //delta time (time since last frame)
        //delta time is time between frames and is used to keep movements consistent as frame rate affect the movements in the game
        const float dT{GetFrameTime()};

        //start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            // rectangle on ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle in air
            // apply gravity
            velocity += gravity * dT;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        scarfyPos.y += velocity * dT;
        
        // update running time
        runningTime += dT;
        if (runningTime >= updateTime)
        {
            runningTime = 0.0;
            // update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
        }


        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        // end drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    //correct way to close the window
    CloseWindow();
}