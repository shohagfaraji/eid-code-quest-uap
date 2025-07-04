#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1) {
            int mx = a[i - 1] ^ a[i];
            mx = max(mx, a[i - 1] | a[i]);
            mx = max(mx, a[i - 1] & a[i]);
            ans += mx;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ts;
    cin >> ts;
    while (ts--) {
        Solve();
        cout << '\n';
    }

    return 0;
}