#include <stdio.h>
#include "../include/raylib.h"
#include "pjtball.h"

PjtBall m_ball;    //一个球
int rndi_color;    //小球颜色的随机数
Color rnd_color[7] = {RED,BLUE,BLACK,GREEN,YELLOW,GOLD,SKYBLUE};    //小球随机颜色组
Color m_color = RED;

void Init()
{
    //初始坐标
    m_ball.posX = 600;
    m_ball.posY = 400;
    m_ball.speedBase = 200;    //小球速度
    //初始化窗口
    InitWindow(1200,800,"哈哈哈");
}

void Imput_changeColor()
{
    //按键导致颜色随机值改变
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D))
    {
        rndi_color = GetRandomValue(1,10);
        //printf("%d",rndi_color);
        m_color = rnd_color[GetRandomValue(0,6)];
    };
    

}

void Dologic()
{
    float m_delta = GetFrameTime();
    
    //键盘输入调整速度值
    if (IsKeyDown(KEY_W)){
        m_ball.speedUp = 1;
    }else
    {
        m_ball.speedUp = 0;
    };

    if(IsKeyDown(KEY_S))
    {
        m_ball.speedDown = 1;
    }else
    {
        m_ball.speedDown = 0;
    };

    if(IsKeyDown(KEY_A))
    {
        m_ball.speedLeft = 1;
    }else
    {
        m_ball.speedLeft = 0;
    };

    if(IsKeyDown(KEY_D))
    {
        m_ball.speedRight = 1;
    }else
    {
        m_ball.speedRight = 0;
    };

    //赋值给小球速度
    m_ball.speedY = m_ball.speedDown - m_ball.speedUp;
    m_ball.speedX = m_ball.speedRight - m_ball.speedLeft;
    m_ball.posX += m_delta * m_ball.speedBase * m_ball.speedX;
    m_ball.posY += m_delta * m_ball.speedBase * m_ball.speedY;

    //按键输入时随机变化颜色
    Imput_changeColor();
    
}

void Performance()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(m_ball.posX,m_ball.posY,44,m_color);
    EndDrawing();
}

int main()
{
    
    //初始化
    Init();

    //主循环
    while (!WindowShouldClose())
    {
        Dologic();
        Performance();
        
    }
    
    return 0;

}