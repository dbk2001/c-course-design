#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"AIchess.h"

using namespace std;

void operate ::centrOprt(int i)
{
    if(i==1)//                                                     需要加参数
    {
        computer=1;
        person=2;
    }
    else
    {
        computer=2;
        person=1;
    }
    int n=1;
    while(1){
        if(n==person)
        {
            //                                                    add person operation
        }
        else
        {
            comptrOprt();
        }
        if(1==endJudge())
        {
            if(n==person)
            {
                cout<<"person win!";
                system("pause");
                break;
            }
            else
            {
                cout<<"computer win!";
                system("pause");
                break;
            }           
        }
        else
        {
            n=(n==1)?2:1;
        }
    }
}

void operate ::comptrOprt()
{
    cout << "Turn the computer" << endl; 
    point best1, best2;
    do{
        srand(time(NULL));
        best1.col = best2.col = rand()%15;
        best1.row = best2.row = rand()%15;
    } 
    while(Array[best1.col][best1.row] != 0);
    int a1 = calScore(best1, computer), b1 = calScore(best1, person);
    for(int i = 0; i < 15; i ++)
    {
        for(int j = 0; j < 15; j ++)
        {
            if(Array[i][j] != 0)
            {
                continue;
            }
            point cur = {i, j};
            int m1 = calScore(cur, computer);
            int m2 = calScore(cur, person);
            if(m1 > a1)
            {
                best1 = cur;
                a1 = m1;
                b1 = m2; 
            }
            else if(m1 == a1)
            {
                if(m2 > b1)
                { 
                    best1 = cur;
                    b1 = m2;
                }
            }
        }
    }
    int a2 = calScore(best2, person), b2 = calScore(best2, computer);
    for(int i = 0; i < 15; i ++)
    {
        for(int j = 0; j < 15; j ++)
        {
            if(Array[i][j] != 0)
            {
                continue;
            }
            point cur = {i, j};
            int m1 = calScore(cur, person);
            int m2 = calScore(cur, computer);
            if(m1 > a2)
            {
                best2 = cur;
                a2 = m1;
                b2 = m2;
            }
            else if(m1 == a2)
            {
                if(m2 > b2)
                {
                    best2 = cur;
                    b2 = m2;
                }
            }
        }
    }    
    if(a1 >= a2)
    {
        luozi = best1;
    }
    else
    {
        luozi = best2;
    }
    Array[luozi.col][luozi.row] = computer;
    //                                                     画图函数
}

bool operate ::endJudge()
{
    int i = 1;
    for(;i <= 4;i ++)
    {
        drctn d;
        int count = 0;
        switch(i){
            case 1:
                d = d1;
                break;
            case 2:
                d = d2;
                break;
            case 3:
                d = d3;
                break;
            case 4:
                d = d4;
                break;
        }
        for(int j = -4; j <= 4; j ++)
        {
            point p1 = newPoint(luozi, d, j);
            if(inBoardJudge(p1) && (Array[p1.col][p1.row] == Array[luozi.col][luozi.row]))
            {
                count ++;
            }
            else
            {
                count = 0;
            }
            if(5==count)
            {
                return true;
            }
        }
    }
    return false;
}

bool operate ::inBoardJudge(point p)
{
    if(p.col >= 0 && p.col < SIZE && p.row >= 0 && p.row < SIZE)//在其他文件中预定义生成，后作修改
    {
        return true;
    }
    else
    {
        return false;
    }
}


int operate ::calScore(point p, int side)
{
    int lian5 = 0;
    int alive4 = 0; 
    int die4 = 0;
    int ddie4 = 0; 
    int alive3 = 0; 
    int dalive3 = 0;
    int die3 = 0;
    int alive2 = 0;
    int dalive2 = 0;
    int die2 = 0;
    int nothing = 0;
    int opp = 1;
    int i = 1;
    if(side == 1)
    {
        opp = 2;
    }
    else
    {
        opp = 1;
    }
    for(;i <= 4;i ++)
    {
        drctn d;
        switch(i){
            case 1:
                d = d1;
                break;
            case 2:
                d = d2;
                break;
            case 3:
                d = d3;
                break;
            case 4:
                d = d4;
                break;
       }
       int l=1;//递增记录线上棋子的个数
       point le, ri, p1;
       int left[5], right[5];
       p1 = newPoint(p, d, -1);
       while(inBoardJudge(p1) && Array[p1.col][p1.row] == side)//查找负方向的棋子个数，遇到非同色棋子或出界跳出循环
       {
            le = p1;
            p1 = newPoint(p1, d, -1);//指向下一个负位置
            l ++;
       }
       p1 = newPoint(p, d, 1);
       while(inBoardJudge(p1) && Array[p1.col][p1.row] == side)//查找正方向的棋子个数，遇到非同色棋子或出界跳出循环
       {
            ri = p1;
            p1 = newPoint(p1, d, 1);//指向下一个正位置
            l ++;
       }
       for(int j = 1; j <= 4; j ++)//记录棋型
       {
            p1 = newPoint(le, d, -j);//记录负方向
            if(inBoardJudge(p1))
            {
                left[j] = Array[p1.col][p1.row];
            }
            else//如果出界则用对手的棋子取代
            {
                left[j] = opp;
            }
            p1 = newPoint(ri, d, j);//记录正方向
            if(inBoardJudge(p1))
            {
                right[j] = Array[p1.col][p1.row];
            }
            else
            {
                right[j] = opp;
            }
       }
       if(l == 5){                  
           lian5 ++;//连5则胜
       }
       else if(l == 4){
              if(left[1] == 0 && right[1] == 0){//alive4 
                      alive4 ++;
           }
           else if(left[1] == 0 || right[1] == 0){//die4
                   die4 ++;
           }
           else{
                   nothing ++;
           }
       }
       else if(l == 3)
       {
            if((left[1] == 0 && left[2] == side) || (right[1] == 0 && right[2] == side))
            {//ddie4
                      ddie4 ++;
            }
           else if(left[1] == 0 && right[1] == 0 && (left[2] == 0 || right[2] == 0))
           {//alive3
                   alive3 ++;                             
           }
           else if((left[1] == 0 && left[2] == 0) || (right[1] == 0 && right[2] == 0))
           {//die3
                   die3 ++;
           }
           else if(left[1] == 0 && right[1] == 0)
           {//die3
                   die3 ++; 
           } 
           else
           {//nothing
                   nothing ++;
           }
        }
       else if(l == 2)
       {
            if((left[1] == 0 && left[2] == side && left[3] == side) && 
                (right[1] == 0 && right[2] == side && right[3] == side))
            {//die4
                ddie4 ++;
            }
           else if(left[1] == 0 && right[1] == 0 && 
                ((left[2] == side && left[3] == 0) || (right[2] == side && right[3] == 0)))
            {//dalive3
                dalive3 ++;
            }
           else if((left[1] == 0 && left[3] == 0 && left[2] == side) || 
                (right[1] == 0 && right[3] == 0 && right[2] == side))
            {//die3
                die3 ++;
            }
           else if((left[1] == 0 && right[1] == 0) && 
                (left[2] == side || right[2] == side))
            {//die3
                die3 ++;
            }
           else if((left[1] == 0 && left[2] == 0 && left[3] == side) || 
                (right[1] == 0 && right[2] == 0 && right[3] == side))
            {//die3
                die3 ++;
            }
           else if((left[1] == 0 && right[1] == 0 && right[2] == 0 && right[3] == 0) || 
                (left[1] == 0 && left[2] == 0 && right[1] == 0 && right[2] == 0) || 
                (left[1] == 0 && left[2] == 0 && left[3] == 0 && right[1] == 0))
            {//alive2
                alive2 ++;
            }
           else if((left[1] == 0 && left[2] == 0 && left[3] == 0) || 
                (right[1] == 0 && right[2] == 0 && right[3] == 0))
            {//die2
                die2 ++;
           }
           else
           {//nothing
                nothing ++;
           }
        }
       else if(l == 1)
       {
            if((left[1] == 0 && left[2] == side && left[3] == side && left[4] == side) || 
                (right[1] == 0 && right[2] == side && right[3] == side && right[4] == side))
            {//ddie4
                ddie4 ++;
           }
           else if((left[1] == 0 && right[1] == 0) && ((left[2] == side && left[3] == side && left[4] == 0) || 
                (right[2] == side && right[3] == side && right[4] == 0)))
            {//dalive3
                dalive3 ++;
           }
           else if((left[1] == 0 && right[1] == 0) && 
                ((left[2] == side && left[3] == side) || (right[2] == side && right[3] == side)))
            {//die3
                die3 ++;
           }
           else if((left[1] == 0 && left[4] == 0 && left[2] == side && left[3] == side) || 
                (right[1] == 0 && right[4] == 0 && right[2] == side && right[3] == side))
            {//die3
                die3 ++;
            }
           else if((left[1] == 0 && left[2] == 0 && left[3] == side && left[4] == side) || 
                (right[1] == 0 && right[2] == 0 && right[3] == side && right[4] == side))
            {//die3
                die3 ++;
           } 
           else if((left[1] == 0 && left[3] == 0 && left[2] == side && left[4] == side) || 
                (right[1] == 0 && right[3] == 0 && right[2] == side && right[4] == side))
            {//die3
                die3 ++;
           }
           else if((left[1] == 0 && right[1] == 0 && right[3] == 0 && right[2] == side) &&
            (left[2] == 0 || right[4] == 0))
            {//dalive2
                dalive2 ++;
           }
           else if((right[1] == 0 && left[1] == 0 && left[3] == 0 && left[2] == side) && 
                (right[2] == 0 || left[4] == 0))
            {//dalive2
                dalive2 ++;
            }
           else if((left[1] == 0 && right[1] == 0 && right[2] == 0 && right[4] == 0 && right[3] == side) || 
                (right[1] == 0 && left[1] == 0 && left[2] == 0 && left[4] == 0 && left[3] == side))
            {//dalive2
                dalive2 ++;
            }
           else if((left[1] == 0 && left[3] == 0 && left[4] == 0 && left[2] == side) || 
                (right[1] == 0 && right[3] == 0 && right[4] == 0 && right[2] == side))
            {//die2
                die2 ++;
            }
           else if((left[1] == 0 && right[1] == 0 && right[2] == 0 && left[2] == side) || 
                (right[1] == 0 && left[1] == 0 && left[2] == 0 && right[2] == side))
            {//die2
                die2 ++;
            }
           else if((left[1] == 0 && left[2] == 0 && left[4] == 0 && left[3] == side) || 
                (right[1] == 0 && right[2] == 0 && right[4] == 0 && right[3] == side))
            {//die2
                die2 ++;
            }
           else if((left[1] == 0 && left[2] == 0 && right[1] == 0 && left[3] == side) || 
                (right[1] == 0 && right[2] == 0 && left[1] == 0 && right[3] == side))
            {//die2
                die2 ++;
           }
           else if((left[1] == 0 && left[2] == 0 && left[3] == 0 && left[4] == side) || 
                (right[1] == 0 && right[2] == 0 && right[3] == 0 && right[4] == side))
            {//die2
                die2 ++;
           }
           else
           {//nothing
                   nothing ++;
           }
       }
    }
    if (lian5 >= 1)
    {
        return 14;//赢5
    }
    else if (alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
    {
        return 13;//活4 双死4 死4活3
    }
    else if (alive3 >= 2)
    {
        return 12;//双活3
    }
    else if (die3 >= 1 && alive3 >= 1)
    {
        return 11;//死3高级活3
    }
    else if (die4 >= 1)
    {
        return 10;//高级死4
    }
    else if (ddie4 >= 1)
    {
        return 9;//低级死4
    }
    else if (alive3 >= 1)
    {
        return 8;//单活3
    }    
    else if (dalive3 >= 1)
    {
        return 7;//跳活3
    }
    else if (alive2 >= 2)
    {
        return 6;//双活2
    }
    else if (alive2 >= 1)
    {
        return 5;//活2
    }
    else if (dalive2 >= 1)
    {
        return 4;//低级活2
    }
    else if (die3 >= 1)
    {
        return 3;//死3
    }
    else if (die2 >= 1)
    {
        return 2;//死2
    }
    else 
    {
        return 1;//没有威胁
    }
}


point operate ::newPoint(point p, drctn d, int lenth)
{
    point p1 = {p.col + d.dy * lenth, p.row + d.dx * lenth};
    return p1;
}
