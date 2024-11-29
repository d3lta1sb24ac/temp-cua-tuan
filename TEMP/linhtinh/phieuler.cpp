
ll eulerPhi(ll n) { 
    if (n == 0) return 0;
    ll ans = n;
    for (ll x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
