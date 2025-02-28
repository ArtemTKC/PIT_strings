/*Андрій колекціонує метеликів. Відомо список усіх метеликів, яких Андрій зібрав за літо. Виведіть
кількість кожного виду метеликів.*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mas_cnt[26]={0};


int main()
{
    string line;
    bool found=false;
    while(getline(cin, line))
    {
        for(int i = 0; i < line.size(); i++)
        {
            if(tolower(line[i])>='a' && tolower(line[i])<='z')
            {
                mas_cnt[tolower(line[i]) - 'a']++;
                found=true;
            }
        }
    }  

    if(!found)
    {
        cout << "-1";
        return 0;
    }
     
    for(int i = 0; i < 26; i++)
    {
        if(mas_cnt[i]!=0)
        {
            cout << char(i+'a') << ' ' << mas_cnt[i] << '\n';
        }
    }
    return 0;
}