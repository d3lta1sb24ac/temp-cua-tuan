#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e7 + 1;

bool isPrime[N];
ll primeDivisor[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // Sàng Eratosthenes
    for (int i = 2; i < N; i++) isPrime[i] = 1;
    for (int i = 2; i < N; i++)
        if (isPrime[i])
            for (ll j = 1LL * i * i; j < N; j += i) {
                isPrime[j] = 0;
                if (primeDivisor[j] == 0) primeDivisor[j] = i; 
            }

    for (int i = 2; i < N; i++)
        if (isPrime[i]) primeDivisor[i] = i;

    // Đọc số test và xử lý
    ll test;
    cin >> test;
    while (test--) {
        ll n;
        cin >> n;

        if (n >= N) {
            cout << "Number exceeds the limit: " << N - 1 << "\n";
            continue;
        }

        vector<ll> res;
        while (n != 1) {
            res.push_back(primeDivisor[n]);
            n /= primeDivisor[n];
        }

        for (int i = 0; i < res.size(); i++) {
            if (i > 0) cout << "*";
            cout << res[i];
        }
        cout << "\n";
    }
}
///////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void primeFactorization(ll n) {
    vector<ll> factors;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);  // Nếu n là số nguyên tố lớn hơn căn bậc hai

    // In ra kết quả
    for (size_t i = 0; i < factors.size(); ++i) {
        if (i > 0) cout << "*";
        cout << factors[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll test;
    cin >> test;
    while (test--) {
        ll n;
        cin >> n;
        primeFactorization(n);
    }

    return 0;
}
