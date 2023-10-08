#include "movement.hpp"
#include "mainMenu.hpp"
#include "game.hpp"

#include <iostream>
#include <fstream>
#include <raylib.h>

//  std::ifstream fin("cache.csv");
//  std::ofstream fout("cache.csv");


/////////////////////
/// bird movement ///
/////////////////////

int a = 0;
int b =0;
bool game_over;
int score=0;
int final_score=0;
long long highest_score;
long long high_score;

struct bird{
    float speed=0;
    Vector2 position ={1280 / 4.0f - 104,780/2.0f-79};
    float radius=40;
    Vector2 stabilizer ={65,80};

     void gravity_pull(){
        speed-=0.05;
        position.y-=speed;
    };
    
    void update_pos(){
        position.y-=speed;
        speed-=0.05;
    }

    void flap(){
        speed=4.75;
    };
};
bird fbf;
bird hb;
void birdJump(){
    if(IsKeyPressed(KEY_SPACE)||IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(fbf.speed<=0)
        fbf.speed=0;
        fbf.flap();
    }
    if(fbf.speed>=1){
        fbf.update_pos();
    }
    fbf.gravity_pull();
}
void update_hb(){
    hb.position.y=fbf.position.y+hb.stabilizer.y;
    hb.position.x=fbf.position.x+hb.stabilizer.x;
}

                                                    /////////////////////
                                                    /// pipe movement ///
                                                    /////////////////////

struct pipe{
    const float speed =4.5;
    
    bool pass;

    int gap=280;

    float h1=GetRandomValue(150,500);
    float h2=780-h1-gap;

    float y1=780-h1;
    float y2=1;

    float x_pos =1380.0f;

    Vector2 pos_bottom = {x_pos,y1};
    Vector2 pos_up ={x_pos,y2};
    Vector2 size_bottom ={100,h1};
    Vector2 size_up ={100,h2};
    Vector2 tex_pos_bottom={2000,2000};
    Vector2 tex_pos_up={2000,2000};

    void reset_size(){
        h1=GetRandomValue(150,500);
        h2=780-h1-gap;
        y1=780-h1;
        y2=1;
    }

    void reset(){
        x_pos=GetRenderWidth();
        pass=false;
    }
    
    void update(){
        pos_bottom.x=x_pos;
        pos_up.x=x_pos;
        
        size_bottom.y=h1;
        size_up.y=h2;
        
        pos_bottom.y=780-h1;
        pos_up.y=y2;
        
        tex_pos_bottom.y=pos_bottom.y;
        tex_pos_bottom.x=pos_bottom.x-50;

        tex_pos_up.y=size_up.y-960;
        tex_pos_up.x=pos_up.x-50;
    }

    void move(){
        x_pos-=speed;
    }

    void create(Texture2D pill1,Texture2D pill2) {     
        DrawRectangleRec(getlower_pipe(), BLACK);
        DrawRectangleRec(getupper_pipe(), BLACK);
        DrawTextureEx(pill1,tex_pos_bottom,0,5,WHITE);
        DrawTextureEx(pill2,tex_pos_up,0,5,WHITE);   
    }

    Rectangle getlower_pipe(){
        return Rectangle {pos_bottom.x,pos_bottom.y,size_bottom.x,size_bottom.y};
    }
    Rectangle getupper_pipe(){
        return Rectangle {pos_up.x,pos_up.y,size_up.x,size_up.y};
    }
    void movement(Texture2D pill1,Texture2D pill2){
        create(pill1,pill2);
        update();
        move();
        if(x_pos<=-100){
                reset();
                h1=GetRandomValue(150,500);
                h2=780-h1-gap;
                update();
        }
        update();
    }
};
pipe wall;
pipe wall2;
void pipe_movement(Texture2D pill1,Texture2D pill2){
    wall.movement(pill1,pill2);
        if(b==1||wall.x_pos<=GetScreenWidth()/2){
            wall2.movement(pill1,pill2);   
            b=1;
        }
}

void reset_game(){
    score=0;
    fbf.position ={1280 / 4.0f - 104,780/2.0f-79};
    fbf.speed=0;
    wall.reset_size();
    wall2.reset_size();
    wall.reset();
    wall2.x_pos=1380.0f+640.0f;
    menuStateSelected=3;
}

void collision(){
    if(CheckCollisionCircleRec(hb.position,hb.radius,wall.getlower_pipe()) || CheckCollisionCircleRec(hb.position,hb.radius,wall.getupper_pipe())){
        game_over=true;
        reset_game();
    }
    if(CheckCollisionCircleRec(hb.position,hb.radius,wall2.getlower_pipe()) || CheckCollisionCircleRec(hb.position,hb.radius,wall2.getupper_pipe())){
        game_over=true;
        reset_game();
    }
    if(fbf.position.y>=780||fbf.position.y<=0){
        game_over=true;
        reset_game();
    }
}

void counter(){
    DrawText(TextFormat("Score: %d", score),1,1,40,BLACK);
    DrawText(TextFormat("Highest Score: %d", highest_score),1,40,40,BLACK);
    
    if(!wall.pass&&hb.position.x>wall.pos_bottom.x){
        wall.pass=true;
        score++;
    }
    if(!wall2.pass&&hb.position.x>wall2.pos_bottom.x){
        wall2.pass=true;
        score++;
    }
    std::ifstream fin("cache.csv");
    fin >> high_score;
    if(high_score > highest_score)
        highest_score = high_score;

    final_score=score;
    
    if(highest_score < final_score){
        std::ofstream fout("cache.csv");
        highest_score = final_score;
        fout << highest_score;
    }
    
}


                                                    ////////////////
                                                    /// drawings ///
                                                    ////////////////

void drawing(Texture2D fb, Texture2D fb_flap,Texture2D bg_game){
    DrawTextureEx(bg_game,Vector2{0,0},0,1.6f,WHITE);
    DrawTextureEx(fb,fbf.position,0,0.75, WHITE);
    if(IsKeyPressed(KEY_SPACE)||IsMouseButtonPressed(MOUSE_BUTTON_LEFT)||(fbf.speed>=1.5&&fbf.speed<=4.75)){
        DrawTextureEx(fb_flap,fbf.position,0,0.75, WHITE);
    }
}
void draw_hb(){
    DrawCircleV(hb.position,hb.radius,WHITE);
    DrawRectangleRec(StartButton_hb,PINK);
    DrawRectangleRec(ExitButton_hb,PINK);
}
