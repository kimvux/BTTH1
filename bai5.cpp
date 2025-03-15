#include <bits/stdc++.h>
using namespace std;
struct date{
    int d,m,y;
};
bool namnhuan (int year){
//dau vao: nam nao do
//dau ra: 'true' neu nam do la nam nhuan va nguoc lai
    if (year % 400 == 0) return true;
    if (year % 4 == 0 && year % 100 != 0) return true;
    return false;
}
void nhap(date &a){
//dau vao: 1 ngay nao do duoc tham chieu
//dau ra: thong tin cua ngay do duoc nhap vao hoac thay doi theo dung dieu kien
    cout << "Nhap vao nam: ";
    cin >> a.y;
    cout << "Nhap vao thang: ";
    cin >> a.m;
//nhap lai thang neu nhap sai
    while (a.m < 1 || a.m > 12) {
        cout << "Moi ban nhap lai: ";
        cin >> a.m;
    }
    cout << "Nhap vao ngay: ";
    cin >> a.d;
//nhap ngay cac truong hop thang 2
    if (a.m == 2){
        if (namnhuan(a.y) == true){
            while (a.d < 1 || a.d > 29) {
                cout << "Moi ban nhap lai: ";
                cin >> a.d;
            }
        }
        else {
            while (a.d < 1 || a.d > 28) {
                cout << "Moi ban nhap lai: ";
                cin >> a.d;
            }
        }
    }
//nhap ngay voi cac thang con lai
    else if (a.m == 1 || a.m == 3 || a.m == 5 || a.m == 7 || a.m == 8 || a.m == 10 || a.m == 12){
        while (a.d < 1 || a.d > 31) {
            cin >> a.d;
        }
    }
    else {
        while (a.d < 1 || a.d > 30) {
            cin >> a.d;
        }
    }
}
void xuat(date a){
//dau vao: 1 ngay nao do
//dau ra: xuat thong tin cua ngay do duoi dang d/m/y
    cout << a.d << "/" << a.m << "/" << a.y;
}
date ngayketiep(date a){
//dau vao: 1 ngay nao do
//dau ra: ngay ke tiep cua ngay do
    date b = a;
    b.d++;
//kiem tra va sua ngay va thang neu sai dieu kien sau khi cong ngay them 1
    if (b.m == 2 && namnhuan(b.y) == true)
        if (b.d > 29){
            b.d = 1;
            b.m++;
        }
    if (b.m == 2 && namnhuan(b.y) == false)
        if (b.d > 28){
            b.d = 1;
            b.m++;
        }
    if (b.m == 1 || b.m == 3 || b.m == 5 || b.m == 7 || b.m == 8 || b.m == 10 || b.m == 12)
        if (b.d > 31){
            b.d = 1;
            b.m++;
        }
    if (b.m == 4 || b.m == 6 || b.m == 9 || b.m == 11)
        if (b.d > 30){
            b.d = 1;
            b.m++;
        }
//kiem tra va sua thang va nam neu sai dieu kien sau khi cong them o buoc tren
    if (b.m > 12){
        b.m = 1;
        b.y++;
    }
    return b;
}
date ngaytruocdo(date a){
//dau vao: 1 ngay nao do
//dau ra: ngay truoc do cua ngay do
    date b = a;
    b.d--;
//kiem tra va sua ngay va thang neu sai dieu kien sau khi tru ngay di 1
    if (b.d == 0 && (b.m == 5 || b.m == 7 || b.m == 10 || b.m == 12)){
        b.d = 30;
        b.m--;
    }
    if (b.d == 0 && (b.m == 4 || b.m == 6 || b.m == 8 || b.m == 9 || b.m == 11 || b.m == 1 || b.m == 2)){
        b.d = 31;
        b.m--;
    }
    if (b.d == 0 && b.m == 3 && namnhuan(b.y) == true){
        b.d = 29;
        b.m--;
    }
    if (b.d == 0 && b.m == 3 && namnhuan(b.y) == false){
        b.d = 28;
        b.m--;
    }
//kiem tra va sua thang va nam neu sai dieu kien sau khi tru o buoc tren
    if (b.m == 0){
        b.m = 12;
        b.y--;
    }
    return b;
}
int ngaythubaonhieu(date a){
//dau vao: thong tin cua 1 ngay nao do
//dau ra: ngay do la ngay thu bao nhieu trong nam
//duyet tu thang 1 den thang cua ngay dau vao, tung thang cong them ngay tuong ung cua thang do
    int sum = 0;
    for (int i=1 ; i<a.m ; ++i){
        if (i== 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            sum += 31;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            sum += 30;
        else if (i == 2 && namnhuan(a.y) == true)
            sum += 29;
        else
            sum += 28;
    }
    return sum + a.d;
}
int main(){
    date a, b;
    nhap(a);
    cout << "\n- Ngay hien tai la: ";
    xuat(a);
    cout << "\n- Ngay ke tiep la: ";
    b = ngayketiep(a);
    xuat(b);
    cout << "\n- Ngay truoc do la: ";
    b = ngaytruocdo(a);
    xuat(b);
    cout << "\n- Ngay thu " << ngaythubaonhieu(a) << " trong nam " << a.y << "." << endl;
    return 0;
}
