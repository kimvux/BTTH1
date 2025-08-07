#include <bits/stdc++.h>
using namespace std;
struct PHANSO{
    int tuso, mauso;
};
int ucln(int a, int b){
//dau vao: 2 so a va b
//dau ra: uoc chung lon nhat cua a va b
//lay so lon hon tru so nho hon den khi 2 so bang nhau thi dung
    if (a == b)return a;
    return a > b ? ucln(a-b,b) : ucln(a,b-a);
}
void xuat(PHANSO a){
//dau vao: 1 phan so nao do
//dau ra: xuat ra phan so do duoi dang b/c hoac so nguyen d
    if (a.mauso == -1)
        cout << -a.tuso;
    else if (a.mauso == 1)
        cout << a.tuso;
    else if (a.mauso < 0)
        cout << -a.tuso << "/" << -a.mauso;
    else
        cout << a.tuso << "/" << a.mauso;
}
int main(){
    PHANSO a;
    cout << "Nhap tu so: ";
    cin >> a.tuso;
    cout << "Nhap mau so: ";
    do {
        cin >> a.mauso;
    } while (a.mauso == 0);
    if (a.tuso == 0) {
        cout << 0;
        return 0;
    }
    int m = ucln(abs(a.tuso), abs(a.mauso));
    a.tuso /= m;
    a.mauso /= m;
    xuat(a);
    return 0;
}
