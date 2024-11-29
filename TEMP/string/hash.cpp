#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int N = 1e5;

struct Hash {
    string s;
    ll bs;            // Cơ sở hash
    ll M;             // Modulo
    ll hs;            // Hash tổng quát của chuỗi
    ll HS[N + 1];     // Prefix hash
    ll pw[N + 1];     // Lũy thừa của `bs`

    // Hàm khởi tạo (thay cho constructor của C++11)
    void init(const string &str, ll base, ll mod) {
        s = str;
        bs = base;
        M = mod;
        hs = 0;
        pw[0] = 1;
        for (int i = 1; i <= N; i++) {
            pw[i] = (pw[i - 1] * bs) % M;
        }
    }

    // Xây dựng prefix hash
    void build1() {
        HS[0] = s[0];
        for (int i = 1; i < s.size(); i++) {
            HS[i] = (HS[i - 1] * bs + s[i]) % M;
        }
    }

    // Xây dựng hash tổng quát
    void build2() {
        hs = s[0];
        for (int i = 1; i < s.size(); i++) {
            hs = (hs * bs + s[i]) % M;
        }
    }

    // Lấy hash của đoạn con s[i..j]
    ll get(int i, int j) {
        if (i == 0) return HS[j];
        return (HS[j] - HS[i - 1] * pw[j - i + 1] % M + M) % M;
    }
};

int main() {
    string s = "example";
    Hash h;
    h.init(s, 311, 1000000007); // Khởi tạo với base = 311 và mod = 10^9 + 7
    h.build1();
    h.build2();
    cout << "Hash đoạn [0..6]: " << h.get(0, 6) << endl;
    cout << "Hash đoạn [1..3]: " << h.hs << endl;
    return 0;
}
