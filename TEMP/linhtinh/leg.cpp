//đếm số lần xuất hiện của số nguyên tố x trong n
//lưu ý trước khi dùng phải sàng nguyên tố rồi dùng hàm leg với từng số nguyên tố để phân tích

ll leg(ll n, ll x){
    ll p = x, t = 0;
    while(n >= x)
    {
        t += n / x;
        x *= p;
    }
    return t;
}