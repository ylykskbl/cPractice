#ifndef PJTBALL_H
#define PJTBALL_H

#include "../include/raylib.h"

typedef struct PjtBall  //被控制的球体类型
{
    float posX;     //出生x坐标
    float posY;     //出生y坐标
    float speedBase;    //基础速度，用于表示速度快慢
    float speedX;   //x速度
    float speedY;   //y速度
    float speedUp;  //上速度，用于和下速度合并成y速度
    float speedDown;//下速度，用于和上速度合并成y速度
    float speedLeft;//左速度，用于和右速度合并成x速度
    float speedRight;//右速度，用于和左速度合并成x速度
    Color color;

}PjtBall;   



#endif