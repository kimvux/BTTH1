#include <bits/stdc++.h>
using namespace std;
struct PHANSO{
    int tuso, mauso;
};
int sosanh(PHANSO a, PHANSO b){
//dau vao: 2 phan so a va b
//dau ra:   1 neu a=b
//          2 neu a>b
//          0 neu a<b

//lay tu so chia mau so roi so sanh 2 ket qua
    if ((float)a.tuso/(float)a.mauso == (float)b.tuso/(float)b.mauso) return 1;
    else if ((float)a.tuso/(float)a.mauso > (float)b.tuso/(float)b.mauso) return 2;
    return 0;
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
    else if (a.tuso == 0)
        cout << 0;
    else
        cout << a.tuso << "/" << a.mauso;
}
int main(){
    PHANSO a;
    cout << "Nhap tu so cua phan so a: ";
    cin >> a.tuso;
    cout << "Nhap mau so cua phan so a: ";
    do {
        cin >> a.mauso;
    } while (a.mauso == 0);
    PHANSO b;
    cout << "Nhap tu so cua phan so b: ";
    cin >> b.tuso;
    cout << "Nhap mau so cuar phan so b: ";
    do {
        cin >> b.mauso;
    } while (b.mauso == 0);
    cout << endl;
//xuat ket qua theo cac truong hop ham sosanh tra ve
    if (sosanh(a,b) == 1){
        cout << "Phan so a bang phan so b." << endl;
        xuat(a);
    }
    else if (sosanh(a,b) == 2){
        cout << "Phan so a lon nhat." << endl;
        xuat(a);
    }
    else {
        cout << "Phan so b lon nhat." << endl;
        xuat(b);
    }
    return 0;
}
