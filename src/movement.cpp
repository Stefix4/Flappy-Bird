#include "movement.hpp"

#include <iostream>
#include <raylib.h>


int a = 0;

const float gravity=3.0f;

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
        };
    
    };
bird fbf;

void birdJump(){
    if(IsKeyPressed(KEY_SPACE)||a>=1 && a<=50){
            fbf.flap();
            a++;
            fbf.position +=1+a/5;
        }
        else
            if(fbf.position<GetScreenHeight()-140){
                fbf.update();
                a=0;
            }
}

void drawing(){
    Texture2D fb = LoadTexture("./resources/flappy-bird.png");// fb = flappy bird
    DrawTexture(fb, GetRenderWidth() / 4 - 104, fbf.position, WHITE);
}
