/*Дано текст. Провести частотний аналіз тексту щодо латинських букв, тобто знайти скільки разів
зустрічається в ньому кожна буква.*/


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
            if(toupper(line[i])>='A' && toupper(line[i])<='Z')
            {
                mas_cnt[toupper(line[i]) - 'A']++;
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
        cout << char(i+'A') << ' ' << mas_cnt[i] << '\n';
    }
    return 0;
}