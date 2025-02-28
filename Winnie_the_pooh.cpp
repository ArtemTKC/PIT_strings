/*Ось і настав довгоочікуваний Ювілей Вінні-Пуха. У чарівний ліс на свято зібралось багато гостей.
У тому числі Вінні-Пух запросив до себе друзів з інших галактик. Нажаль, коли він відсилав
запрошення, він зовсім забув, що на планеті, де живуть його друзі інопланетяни, усі читають не
зліва направо, а справа наліво. Вінні-Пух розуміє, що до Ювілею вони вже не прилетять, але
ведмежа не сумує. Він хоче перевірити, чи правда, що дата його Ювілею, прочитана справа
наліво, також існує, і інопланетяни прилетять в інший день. Допоможіть Вінни-Пуху визначити,
чи чекати йому в гості інопланетних друзів.*/

#include <iostream>
#include <string>
using namespace std;

bool is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) return false;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        days_in_month[2] = 29;
    }
    return (day >= 1 && day <= days_in_month[month]);
}

int main() {
    int N;
    cin >> N;
    string date;
    getline(cin, date);
    for(int i = 1; i <= N; i++) 
    { 
        getline(cin, date);

        int i_day = (date[9] - '0') * 10 + (date[8] - '0');
        int i_month = (date[7] - '0') * 10 + (date[6] - '0');
        int i_year = (date[4] - '0') * 1000 + (date[3] - '0') * 100 + (date[1] - '0') * 10 + (date[0] - '0');

        if (is_valid_date(i_day, i_month, i_year)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}


