#include <iostream>
#include <cmath>
using namespace std;
double giaithua(int n){
//dau vao: so nguyen n
//dau ra: giai thua n!
//1 x 2 x 3 x ... x n
    double finall = 1;
    for (int i = 1; i <= n; i++) {
        finall *= i;
    }
    return finall;
}
double mySin(double x){
//dau vao: so thuc x
//dau ra: sin(x) voi do chinh xac 0.00001
    double num = x ,finall = x;
    int n = 1;
    while (fabs(num) > 0.00001){
//lap den khi nao tri tuyet doi phan tu duoc cong vao truoc do <= 0.00001 thi dung lai
        num = pow(-1, n) * pow(x, 2 * n + 1) / giaithua(2 * n + 1);
        finall += num;
        n++;
    }
    return finall;
}
int main() {
    cout << "Nhap gia tri x: ";
    double x;
    cin >> x;
    cout << "Gia tri sin(" << x << ") = " << mySin(x) << endl;
    return 0;
}
