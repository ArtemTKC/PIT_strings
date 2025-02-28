/*Макс зовсім змучився писати приклади на обчислення Тимофію. Малий настільки швидко усе
розв’язував, що навіть програма, яка автоматизувала перевірку результатів не допомагала! ☹
Усю ніч Максим ісписував дрібним почерком листочки, а вже в обід Тимофій радісно кричав
«Давай іще!». І тоді Льова вирішив виручити друга: він написав для малого цілу купу складних
прикладів на багато дій виду ab…с, де  – символи арифметичних дій «+» або «-». Щоб
одразу зробити Максу максимальну послугу – звільнити від перевірки, Льова запропонував
учням блакитної паралелі написати програму, що розвв’язує кожен з прикладів.*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string expression, first, second;
    int answer=0, num1 = 0, num2 = 0, pos_operation_2;
    while(cin >> expression)
    {
        if(!(expression.empty()))
        {
            int pos_operation_1=expression.find_first_of("+-", 0);
            first=expression.substr(0, pos_operation_1);
            for (int i = 0; i < first.size(); i++) {
                num1 = num1 * 10 + (first[i] - '0');
            }
            answer=num1;
            expression+="+0";
            int pos_operation_2=expression.find_first_of("+", pos_operation_1 + 1);
            while(pos_operation_2 != -1)
            {
                second=expression.substr(pos_operation_1 + 1, pos_operation_2 - pos_operation_1 - 1);
                num2 = 0;
                for (int i = 0; i < second.size(); i++) {
                    num2 = num2 * 10 + (second[i] - '0');
                }
                char operation=expression[pos_operation_1];
                if(operation=='+')
                {
                    answer=answer+num2;
                }
                if(operation=='-')
                {
                    answer=answer-num2;
                }
                pos_operation_1 = pos_operation_2;
                pos_operation_2=expression.find_first_of("+-", pos_operation_1 + 1);
            }
            cout << answer << "\n";
        }
        else
        {
            cout << "NULL";
        }
    }
    
    return 0;
}