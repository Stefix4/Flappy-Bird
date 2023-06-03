#include "raylib.h"

const float gravity=3.0f;

int main(void)
{
    int a=0;
    const int screenWidth = 900;
    const int screenHeight = 500;
    bool isFullscreen = false;
    Rectangle screen = {0,0,900,500};
    
    struct bird{
        float position=GetScreenHeight()/2.0f-79;

        void update(){
            position+=gravity;
        };

        void flap(){
            position -=3*gravity;

        };
        void test(){
            position -=gravity;
        }
    
    };




    //set up the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetTargetFPS(144); 

    Image logo = LoadImage("../resources/flappy-bird-logo.png");
    Texture2D fb = LoadTexture("../resources/flappy-bird-photo-removebg-preview.png");// fb = flappy bird 
    Texture2D background = LoadTexture("../resources/background.png");
    Texture2D pill1 = LoadTexture("../resources/pillar-1.png");
    SetWindowIcon(logo);
    SetWindowMinSize(screenWidth,screenHeight);
    HideCursor();
    bird fbf;



    //game loop
    while (!WindowShouldClose())    
    {   if(IsKeyPressed(KEY_SPACE)||a>=1&&a<=50){
            fbf.flap();
            a++;
            fbf.position +=1+a/5;
        }
        else
            if(fbf.position<GetScreenHeight()-140){
                fbf.update();
                a=0;
            } 

        if (IsKeyPressed(KEY_F11)){
            isFullscreen = !isFullscreen;
        
        if(isFullscreen)
            ToggleFullscreen();
        else{
            SetWindowSize(screenWidth, screenHeight);
            ToggleFullscreen();
        }
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(background,0,0,WHITE);
            DrawTexture(fb,screenWidth/4-104,fbf.position,WHITE);
            //DrawTexture(pill1,screenWidth/2,screenHeight/2,WHITE);

        EndDrawing();

    }

    CloseWindow();        

    return 0;
}