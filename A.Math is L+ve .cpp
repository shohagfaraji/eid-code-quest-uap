#include<bits/stdc++.h>
using namespace std;

void Solve(){
    string s;
    cin >> s;
    int a = s[0] - '0';
    int b = s[2] - '0';
    int c = s[4] - '0';
    bool f = false;
    if(s[1] == '+') {
        f = (a + b == c);
    } else {
        f = (a - b == c);
    }
    cout << (f ? "YES" : "NO");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ts;
    cin >> ts;
    while(ts--){
        Solve();
        cout << '\n';
    }

    return 0;
}
