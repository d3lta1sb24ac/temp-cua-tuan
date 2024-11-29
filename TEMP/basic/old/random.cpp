#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

typedef long long ll;
ll rand(ll l, ll r) {
    return l + rand() % (r - l + 1);
}

int main() {
    std::srand(std::time(0)); // Khởi tạo seed
    ll l = 1, r = 100;
    ll random_number = rand(l, r);
    // cout<<random_number;
    return 0;
}