/*Мабуть не існує в світі людини, яка б хоч раз у своєму житті не зіграла у гру сапер. А Нікіта так
був одним з найзатятіших фанатів цієї гри. 
Літом цього року Нікіта приїхав у Літню школу програмування та інформаційних технологій і
потрапив у блакитну паралель, де вивчалася тема «Рядки». В рамках цієї теми всім учням було
дано завдання порахувати для кожної клітинки «мінного» поля, скільки навкруги неї
знаходиться мін. Нікіта завзято взявся за справу і скоро його програма почала виконувати
необхідні обчислення. А Ви зможете написати таку програму?*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mas[1000][1000]={0};
int res[1000][1000]={0};

void in_2dmas_minesweaper(int mas[][1000], int row, int col)
{
    string line;
    for (int i = 1; i <= row; i++)
    {
        cin >> line;
        for (int j = 1; j <= col; j++)
            if (line[j-1] =='#') mas[i][j]=-1;
    }
}

void out_2dmas(int mas[][1000], int row, int col){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << '\n';
    }
}


void calculating_cnt(int row, int col)
{
    int cnt=0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (mas[i+1][j-1]==-1) cnt++;
            if (mas[i+1][j]==-1) cnt++;
            if (mas[i+1][j+1]==-1) cnt++;
            if (mas[i][j-1]==-1) cnt++;
            
            if (mas[i][j+1]==-1) cnt++;
            if (mas[i-1][j-1]==-1) cnt++;
            if (mas[i-1][j]==-1) cnt++;
            if (mas[i-1][j+1]==-1) cnt++;
            res[i][j]=cnt;
            cnt=0;
        }
    }
}


int main()
{
    int row, col;
    cin >> row >> col;

    in_2dmas_minesweaper(mas, row, col); 
    calculating_cnt(row, col);
    out_2dmas(res, row, col);

    return 0;
}