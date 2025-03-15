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
//dau vao: phan so a
//dau ra: xuat ra man hinh phan so a duoi dang b/c hoac duoi dang 1 so nguyen
    if (a.tuso == 0)
        cout << 0;
    else if (a.mauso == -1)
        cout << -a.tuso;
    else if (a.mauso == 1)
        cout << a.tuso;
    else if (a.mauso < 0)
        cout << -a.tuso << "/" << -a.mauso;
    else
        cout << a.tuso << "/" << a.mauso;
}
PHANSO tong(PHANSO a, PHANSO b){
//dau vao: phan so a va b
//dau ra: phan so c la tong cua phan so a va b
//tinh tong nhu toan hoc
    PHANSO c;
    c.tuso = a.tuso*b.mauso + b.tuso*a.mauso;
    c.mauso = a.mauso*b.mauso;
    if (c.tuso == 0) return c;
    int n = ucln(abs(c.tuso),abs(c.mauso));
    c.tuso /= n;
    c.mauso /= n;
    return c;
}
PHANSO hieu(PHANSO a, PHANSO b){
//dau vao: phan so a va b
//dau ra: phan so c la hieu cua phan so a va b
//tinh hieu nhu toan hoc
    PHANSO c;
    c.tuso = a.tuso*b.mauso - b.tuso*a.mauso;
    c.mauso = a.mauso*b.mauso;
    if (c.tuso == 0) return c;
    int n = ucln(abs(c.tuso),abs(c.mauso));
    c.tuso /= n;
    c.mauso /= n;
    return c;
}
PHANSO tich(PHANSO a, PHANSO b){
//dau vao: phan so a va b
//dau ra: phan so c la tich cua phan so a va b
//tinh tich nhu toan hoc
    PHANSO c;
    c.tuso = a.tuso * b.tuso;
    c.mauso = a.mauso * b.mauso;
    if (c.tuso == 0) return c;
    int n = ucln(abs(c.tuso),abs(c.mauso));
    c.tuso /= n;
    c.mauso /= n;
    return c;
}
PHANSO thuong(PHANSO a, PHANSO b){
//dau vao: phan so a va b
//dau ra: phan so c la thuong cua phan so a va b
//tinh thuong nhu toan hoc
    PHANSO c;
    c.tuso = a.tuso * b.mauso;
    c.mauso = a.mauso * b.tuso;
    if (c.tuso == 0) return c;
    int n = ucln(abs(c.tuso),abs(c.mauso));
    c.tuso /= n;
    c.mauso /= n;
    return c;
}
int main(){
    PHANSO a,b,c;
    cout << "Nhap tu so cua phan so a: ";
    cin >> a.tuso;
    cout << "Nhap mau so cua phan so a: ";
    do {
        cin >> a.mauso;
    } while (a.mauso == 0);
    cout << "Nhap tu so cua phan so b: ";
    cin >> b.tuso;
    cout << "Nhap mau so cuar phan so b: ";
    do {
        cin >> b.mauso;
    } while (b.mauso == 0);
    c = tong(a,b);
    cout << "\n- Tong 2 phan so:\t"; xuat(c);
    c = hieu(a,b);
    cout << "\n- Hieu 2 phan so:\t"; xuat(c);
    c = tich(a,b);
    cout << "\n- Tich 2 phan so:\t"; xuat(c);
    c = thuong(a,b);
    cout << "\n- Thuong 2 phan so:\t"; xuat(c);
    cout <<endl;
    return 0;
}
