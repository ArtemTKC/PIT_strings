/*Маша і Влад Нижники люблять розв’язувати задачі разом. Як усім відомо, неможливо якісно
розв’язати задачу без смаколиків під рукою. На цей раз для перекусу Маша взяла з собою пачку
солодких чисел-паліндромів. На жаль, пачка порвалась і всі паліндроми розсипалися на стіл і в
блокнот, де дівчинка якраз писала для брата пояснення до чергової задачі. Порахуйте, скільки
смаколиків висипалося в блокнот.*/

#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string s) 
{
    for(int i=0; i<=s.size()/2; i++)
        if(s[i]!=s[s.size()-i-1]) return false;
    return true;
}

bool str_is_number(string s) 
{
    for(int i=0; i<s.size(); i++)
        if(!isdigit(s[i])) return false;
    return true;
}

int main() {
    string s;
    bool flag=false;
    while(cin >> s)
    {
        if(str_is_number(s) && is_palindrome(s))
        {
            flag=true;
            cout << s << '\n';
        }
    }
    if(!flag) cout << "The notepad is clean.";
    return 0;
}