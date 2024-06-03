#include <stdio.h>
#include "../include/raylib.h"
#include "pjtball.h"

PjtBall pjtBall;    //来个球

void m_init()
{
    //初始坐标
    pjtBall.posX = 600;
    pjtBall.posY = 400;
    pjtBall.speedBase = 200;    //小球速度
    //初始化窗口
    InitWindow(1200,800,"哈哈哈");
}

void m_dologic()
{
    float m_delta = GetFrameTime();
    
    //键盘输入调整速度值
    if (IsKeyDown(KEY_W)){
        pjtBall.speedUp = 1;
    }else
    {
        pjtBall.speedUp = 0;
    };

    if(IsKeyDown(KEY_S))
    {
        pjtBall.speedDown = 1;
    }else
    {
        pjtBall.speedDown = 0;
    };

    if(IsKeyDown(KEY_A))
    {
        pjtBall.speedLeft = 1;
    }else
    {
        pjtBall.speedLeft = 0;
    };

    if(IsKeyDown(KEY_D))
    {
        pjtBall.speedRight = 1;
    }else
    {
        pjtBall.speedRight = 0;
    };

    //赋值给小球速度
    pjtBall.speedY = pjtBall.speedDown - pjtBall.speedUp;
    pjtBall.speedX = pjtBall.speedRight - pjtBall.speedLeft;
    pjtBall.posX += m_delta * pjtBall.speedBase * pjtBall.speedX;
    pjtBall.posY += m_delta * pjtBall.speedBase * pjtBall.speedY;
    
}

void m_performance()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(pjtBall.posX,pjtBall.posY,44,RED);
    EndDrawing();
}

int main()
{
    
    //初始化
    m_init();

    //主循环
    while (!WindowShouldClose())
    {
        m_dologic();
        m_performance();
        
    }
    
    return 0;

}