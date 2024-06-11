#include <stdio.h>
#include "../include/raylib.h"
#include "pjtball.h"

void Init(PjtBall *p_ball)
{

    //初始坐标
    p_ball->posX = 600;
    p_ball->posY = 400;
    p_ball->speedBase = 200;    //小球速度
    //初始化窗口
    InitWindow(1200,800,"哈哈哈");
}

void Imput_changeColor(PjtBall *p_ball)
{
    Color rnd_color[7] = {RED,BLUE,BLACK,GREEN,YELLOW,GOLD,SKYBLUE};    //小球随机颜色组
    int rndi_color;    //小球颜色的随机数
    Color *p_color = rnd_color;     //笔记：数组就是指针，所以与 &rnd_color[0] 的结果是一样的
    //按键导致颜色随机值改变
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D))
    {
        rndi_color = GetRandomValue(0,6);
        p_ball->color = *(p_color + rndi_color);
        printf("%u %u %u %u\n",p_ball->color.r,p_ball->color.g,p_ball->color.b,p_ball->color.a);
    };
    

}

void Dologic(PjtBall *p_ball)
{
    float m_delta = GetFrameTime();
    
    //键盘输入调整速度值
    if (IsKeyDown(KEY_W)){
        p_ball->speedUp = 1;
    }else
    {
        p_ball->speedUp = 0;
    };

    if(IsKeyDown(KEY_S))
    {
        p_ball->speedDown = 1;
    }else
    {
        p_ball->speedDown = 0;
    };

    if(IsKeyDown(KEY_A))
    {
        p_ball->speedLeft = 1;
    }else
    {
        p_ball->speedLeft = 0;
    };

    if(IsKeyDown(KEY_D))
    {
        p_ball->speedRight = 1;
    }else
    {
        p_ball->speedRight = 0;
    };

    //赋值给小球速度
    p_ball->speedY = p_ball->speedDown - p_ball->speedUp;
    p_ball->speedX = p_ball->speedRight - p_ball->speedLeft;
    p_ball->posX += m_delta * p_ball->speedBase * p_ball->speedX;
    p_ball->posY += m_delta * p_ball->speedBase * p_ball->speedY;


    //按键输入时随机变化颜色
    Imput_changeColor(p_ball);
    
}

void Performance(PjtBall *p_ball)
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(p_ball->posX,p_ball->posY,44,p_ball->color);
    EndDrawing();
}

int main()
{
    //声明一个小球
    PjtBall m_ball;
    //设置默认颜色
    m_ball.color = RED;
    
    
    //初始化
    Init(&m_ball);

    //主循环
    while (!WindowShouldClose())
    {
        Dologic(&m_ball);
        Performance(&m_ball);
        
    }
    
    return 0;

}