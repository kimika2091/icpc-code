#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(string &password) {
    cout << password << endl;
    string respond;
    getline(cin, respond);
    if (respond.find("DENIED") == string::npos) return -1;
    int t = 0;
    for (char ch : respond) {
        if (isdigit(ch)) {
            t = t * 10 + ch - '0';
        }
    }
    return t;
}

const char bit[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                    '0','1','2','3','4','5','6','7','8','9'};
void solve() {
    string password = "";
    int res = 0;
    for (int i = 1; i <= 20; i++) {
        password += 'A';
        res = ask(password);
        if (res == -1) return;
        if (res != 5) break;
    }
    int len = password.size(), now = 5;
    for (int i = 0; i < len; i++) {
        char correct = password[i];
        for (char j : bit) {
            if (j == correct) continue;
            password[i] = j;
            now = ask(password);
            if (now == -1) return;
            if (now > res){
                correct = j;
                res = now;
                break;
            } 
        }
        password[i] = correct;
    }
}
int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    solve();  
    return 0; 
}