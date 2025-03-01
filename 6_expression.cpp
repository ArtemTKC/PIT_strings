#include <iostream>
#include <string>
#include <iomanip>//треба для setpricision
using namespace std;


int main() {
    freopen("expression_1.in", "r", stdin);
    freopen("expression_1.out", "w", stdout);

    string symbols, str_num1, str_num2;
    int symbol_location=0;
    double num1=0, num2=0, res;

    bool rdng_num_2=false;

    
    while(getline(cin, symbols)){
        for (int i = 0; i < symbols.size(); i++) {
            if (symbols[i] == '+' || symbols[i] == '-' || symbols[i] == '/' || symbols[i] == '*') {
                symbol_location=i;
                rdng_num_2=true;
            }
            else{
                if(!rdng_num_2) str_num1=str_num1+symbols[i];
                else str_num2=str_num2+symbols[i];
            }
        }

        num1=stod(str_num1);
        num2=stod(str_num2);

        if((symbols[symbol_location]=='/') and (num2==0)){
            cout << "Error" << '\n';
        }
        else{
            if(symbols[symbol_location]=='/'){
                res=num1/num2;
                cout << setprecision(5) << res << '\n';
            }
        }
        if(symbols[symbol_location]=='+'){
            res=num1+num2;
            cout << setprecision(5) << res << '\n';
        }
        if(symbols[symbol_location]=='-'){
            res=num1-num2;
            cout << setprecision(5) << res << '\n';
        }
        if(symbols[symbol_location]=='*'){
            res=num1*num2;
            cout  << setprecision(5) << res << '\n';
        }

        str_num1.clear();
        str_num2.clear();
        rdng_num_2=false;
    }
}
