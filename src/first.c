#include <stdio.h>
#include "../include/raylib.h"

int main()
{

    //初始化窗口
    InitWindow(1200,800,"哈哈哈");
    float x = 600;
    int y = 400;
    float speed = 100;
    
    
    
    while (!WindowShouldClose())
    {
        
        float m_delta = GetFrameTime();    
        x = x + m_delta * speed;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(x,y,44,BLUE);
        EndDrawing();
    }
    
    

    return 0;

}