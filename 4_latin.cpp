#include <iostream>
#include <string>
using namespace std;

int countUniqueChars(string& s) {
    bool seen[26] = {false}; 
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) { 
        if (isalpha(s[i])) { 
            char lowerC = tolower(s[i]); 
            int index = lowerC - 'a'; 

            if (!seen[index]) { 
                seen[index] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

void change_symb_for_space(string& s) {
    bool inSequence = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',' || s[i] == '.' || s[i] == ':' || s[i] == ';' || s[i] == '!' || s[i] == '?' || s[i] == '"' || s[i] == '[' || s[i] == ']' || s[i] == ' ') {
            if (s[i-1]!=' '){//!!!!!
                s[i] = ' '; 
            } 
            else{
                s.erase(i, 1);
            }
        } 
    }
}


int main() {
    freopen("maxsymbol.in", "r", stdin);
    freopen("maxsymbol.out", "w", stdout);

    string strt, res, symbols;
    int num=0, dig, etalon=0, cnt1, cnt2;

    cin >> strt;
    while(cin >> symbols){
        strt=strt+' '+symbols;
    }
    symbols.clear();
    change_symb_for_space(strt);

    if (strt.empty()) {
        cout << "NULL";
        return 0;//<-----------закінчення програми якщо strt empty------------
    }

    strt=strt+' ';

    for(int i=0; i<strt.size(); i++){
        if(strt[i]==' '){
            if(countUniqueChars(symbols)>etalon){
                res=symbols;
                etalon=countUniqueChars(symbols);
            }
            else{
                if((countUniqueChars(symbols)==etalon) and (etalon!=0)){
                    res=res+' '+symbols;
                }
            }
            symbols.clear();
        }
        else{
            symbols=symbols+strt[i];
        }
        
    }

    if (res.empty()) cout << "-1";
    else cout << res;
}
