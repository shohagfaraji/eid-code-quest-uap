#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n, k, x = 0;
    cin >> n >> k;
    vector<string> s(n);
    for (auto& i : s)
        cin >> i;

    // Right to left all
    priority_queue<int> RL;
    int ii, A, B;
    for (int i = 1; i < n; i++) {
        ii = i, A = B = 0;
        for (int j = 0; j < i && i < n; j++) {
            A += s[i][j] == '@';
            B += s[j][i] == '@';
            i++;
        }
        i = ii;
        RL.push(A);
        RL.push(B);
    }
    A = 0;
    for (int i = 0; i < n; i++) {
        A += s[i][i] == '@';
    }
    RL.push(A);

    // Left to right all
    int i, j, nn = n - 1;
    priority_queue<int> LR;
    for (i = 0; i < n; i++) {
        ii = i, A = B = 0;
        for (j = 0; j <= i; j++) {
            A += (s[ii][j] == '@');
            if (ii + j < nn) {
                B += (s[nn - j][nn - ii] == '@');
            }
            ii--;
        }
        LR.push(A);
        if (ii + j < nn)
            LR.push(B);
    }

    // Bottom to up
    priority_queue<int> BU;
    for (int i = 0; i < n; i++) {
        A = 0;
        for (int j = nn; j >= 0; j--) {
            A += (s[j][i] == '@');
        }
        BU.push(A);
    }

    //Taking maximum
    int ans = 0, c = k;
    while (!RL.empty() && c--) {
        ans += RL.top();
        RL.pop();
    }
    c = k;
    int mxK = 0;
    while (!LR.empty() && c--) {
        mxK += LR.top();
        LR.pop();
    }
    ans = max(ans, mxK);
    c = k, mxK = 0;
    while (!BU.empty() && c--) {
        mxK += BU.top();
        BU.pop();
    }
    ans = max(ans, mxK);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ts = 1;
    while (ts--) {
        Solve();
        cout << '\n';
    }

    return 0;
}