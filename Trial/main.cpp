#include "raylib.h"
#include "game.h"
#include "colors.h"


double lastUpdateTime = 0;

bool EventTriggered(double interval) // this user defined function is used to bring down the blocks on its own
{
    double currentTime = GetTime(); //GetTime() function in raylib which gives how much time has passed since program started in sec
    if(currentTime - lastUpdateTime>=interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;

}

int main(void){

    InitWindow(500,620,"raylib Tetris");
    SetTargetFPS(60);
   
    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);//Loading the custom font monogram 

    Game game = Game();
    
    while(WindowShouldClose()==false)
    {
        game.HandleInput();
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);

        //These draw functions are handling the text and light blue rectangles
        DrawTextEx(font,"Score",{365,15},38,2,WHITE); //Drawing Font (Arguments : (Font to use, Text to draw, Position to draw the text,font size,spacing between the letters, color))
        DrawTextEx(font,"Next",{370,175},38,2,WHITE); 
        DrawTextEx(font,"Next",{370,175},38,2,WHITE);
        if(game.gameOver)
        {

            DrawTextEx(font,"Game Over",{320,450},38,2,WHITE); 
        } 
        DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue); // Arguments : (Rectangle with position and size, Roundness, Segments, Color)
        DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
        
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}