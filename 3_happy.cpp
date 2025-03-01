#include <iostream>
#include <string>
using namespace std;

int cnt_dig(int num)
{
    int cnt = 0;
    num=abs(num);
    while(num!=0)
    {
        num /= 10;
        cnt++;
    }
    if(cnt==0) return 1;
    return cnt;
}

bool happy_checker(int num)
{
    int N = 0, Rpart = 0, Lpart = 0;
    N=cnt_dig(num);
    if(N%2!=0)
        return false;

    for (int i = 0; i < N / 2; i++)
    {
        Rpart += num % 10;
        num /= 10;
    }

    while (num > 0)
    {
        Lpart += num % 10;
        num /= 10;
    }

    if (Rpart == Lpart)
       return true;
    else
       return false;
}

int main() {
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);

    string s;
    int num=0, dig;
    bool flag=false, int_symbols=true; 

    while(cin >> s)
    {
        for (int i = 0; i < s.size(); i++){
            if(isalpha(s[i])==true){
                num=0;
                int_symbols=false;
            }
            else{
                if(!isdigit(s[i])){
                    if(s[i]==',' || s[i]=='.' || s[i]==':' || s[i]==';' || s[i]=='!' || s[i]=='?' || s[i]=='\"' || s[i]=='[' || s[i]==']'){
                        if(happy_checker(num)) {
                            cout << num << '\n';
                            flag=true;
                            int_symbols=true;
                        }
                        num=0;
                    }
                }
                else{
                    if(int_symbols==true){
                        dig=s[i]-'0';
                        num=num*10+dig;
        
                        if(i+1==s.size()){//тобто ми вже на останньому елементі
                            if (num != 0 && happy_checker(num)) {
                                cout << num << '\n';
                                flag = true;
                            }
                        }   
                    }
                }
            }
        }
        num=0;
        int_symbols=true;
    }
    
    if(!flag) cout << "-1";
}
