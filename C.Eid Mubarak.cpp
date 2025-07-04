#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll pw(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    cout << pw(m, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ts = 1;
    cin >> ts;
    while (ts--) {
        Solve();
        cout << '\n';
    }

    return 0;
}