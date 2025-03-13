#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
struct date {
    int d,m,y;
};
struct sotietkiem {
    string maso,loai,ten,cmnd;
    date ngaymo;
    double sotien;
};
bool checkMaso (string a){
//dau vao: chuoi ma so
//dau ra: 'true' neu chuoi dung dieu kien, va nguoc lai

//kiem tra ma so khong qua 5 ki tu
    if (a.size() > 5 || a.size() < 1) return false;
//kiem tra kis tu dac biet
    for (int i=0 ; i<a.size() ; ++i){
        if (a[i] == ' ')
            return false;
        if (a[i]>='0' && a[i]<='9')
            continue;
        if ( (a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') )
            continue;
        return false;
    }
    return true;
}
bool checkLoai (string a){
//dau vao: chuoi loai so tiet kiem
//dau ra: 'true' neu chuoi dung dieu kien, va nguoc lai
    if (a != "ngan han" && a != "dai han") return false;
    return true;
}
bool checkTen (string a){
//dau vao: chuoi ten khach hang
//dau ra: 'true' neu chuoi dung dieu kien, va nguoc lai

//kiem tra do dai ten khach hang
    if (a.size() > 30 || a.size() < 1) return false;
//kiem tra ki tu dac biet
    for (int i=0 ; i<a.size() ; ++i){
        if ( (a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') || a[i] == ' ')
            continue;
        return false;
    }
    return true;
}
bool checkCMND (string a){
//dau vao: chuoi CMND
//dau ra: 'true' neu chuoi dung dieu kien, va nguoc lai

//kiem tra do dai
    if (a.size() != 9 && a.size() != 12) return false;
//kiem tra cac phan tu trong chuoi so
    for (int i=0 ; i<a.size() ; ++i)
        if (a[i]<'0' || a[i]>'9') return false;
    return true;
}
bool namnhuan (int year){
//dau vao: nam cua ngay mo so
//dau ra: 'true' neu nam do la nam nhuan, va nguoc lai

//kiem tra nam nhuan
    if (year % 400 == 0) return true;
    if (year % 4 == 0 && year % 100 != 0) return true;
    return false;
}
bool checkDate (date a){
//dau vao: ngay mo so
//dau ra: 'true' neu ngay do hop le, va nguoc lai

//kiem tra truoc thang va ngay
    if (a.m < 1 || a.m > 12) return false;
    if (a.d < 1 || a.d > 31) return false;
//kiem tra thang 2
    if (namnhuan(a.y) == true)
        if (a.m == 2 && a.d > 29) return false;
    if (namnhuan(a.y) == false)
        if (a.m == 2 && a.d > 28) return false;
//kiem tra cac thang con lai
    if (a.m == 1 || a.m == 3 || a.m == 5 || a.m == 7 || a.m == 8 || a.m == 10 || a.m == 12)
        if (a.d > 31) return false;
    if (a.m == 4 || a.m == 6 || a.m == 9 || a.m == 11)
        if (a.d > 30) return false;
    return true;
}
void fixname (string &x){
//dau vao: chuoi 'ten'
//dau ra: chuoi 'ten' duoc dinh dang theo kieu chu cai dau viet in hoa, con lai in thuong

//chia chuoi 'ten' vua nhap vao thanh tung chuoi nho,
//roi bien doi ki tu dau tien cua tung chuoi nho thanh in hoa,
//cac ki tu con lai thanh in thuong
//cong cac chuoi nho lai thanh ten hoan chinh
    stringstream ss(x);
    string word;
    string name;
    while (ss >> word){
        name += toupper(word[0]);
        for (int i=1 ; i<word.length() ; i++)
            name += tolower(word[i]);
        name += " ";
    }
    name.pop_back();
    x = name;
}
void nhap(sotietkiem &a){
//dau vao: tham chieu den 1 so tiet kiem
//dau ra: cac thong tin cua so tiet kiem duoc nhap
    cin.ignore();
//maso
    cout << "Nhap ma so: ";
    getline(cin,a.maso);
    while (checkMaso(a.maso) == false){
        cout << "Vui long nhap lai: ";
        getline(cin,a.maso);
    }
//loai tiet kiem
    cout << "Nhap loai so tiet kiem: ";
    getline(cin,a.loai);
    while (checkLoai(a.loai) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a.loai);
    }
//ten
    cout << "Nhap ten khach hang: ";
    getline(cin,a.ten);
    while (checkTen(a.ten) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a.ten);
    }
    fixname(a.ten);
//CMND
    cout << "Nhap so CMND: ";
    getline(cin,a.cmnd);
    while (checkCMND(a.cmnd) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a.cmnd);
    }
//ngay mo so
//nhap cach nhau khoang trang
    cout << "Nhap ngay mo so: ";
    cin >> a.ngaymo.d >> a.ngaymo.m >> a.ngaymo.y;
    while (checkDate(a.ngaymo) == false){
        cout << "Moi ban nhap lai: ";
        cin >> a.ngaymo.d >> a.ngaymo.m >> a.ngaymo.y;
    }
//so tien gui
    cout << "Nhap so tien gui: ";
    cin >> a.sotien;
    while (a.sotien < 0){
        cout << "Moi ban nhap lai: ";
        cin >> a.sotien;
    }
}
void xuat (sotietkiem a){
//dau vao: so tiet kiem
//dau ra: xuat thong tin so tiet kiem do

//chia ra 2 truong hop de luc '\t' no khong bi lech phan dau
//con phan sau tuy theo do dai cai ten thi no co the se lech
    if (a.loai == "dai han")
        cout << a.maso << '\t' << a.loai << '\t' << '\t'<< a.cmnd << '\t' << a.ten << '\t' << a.ngaymo.d << "/" << a.ngaymo.m << "/" << a.ngaymo.y << '\t' << fixed << setprecision(0) << a.sotien << defaultfloat << endl;
    else
        cout << a.maso << '\t' << a.loai << '\t'<< a.cmnd << '\t' << a.ten << '\t' << a.ngaymo.d << "/" << a.ngaymo.m << "/" << a.ngaymo.y << '\t' << fixed << setprecision(0) << a.sotien << defaultfloat << endl;
}
void timkiem (vector<sotietkiem> arr, int n){
//dau vao: danh sach so tiet kiem, do dai danh sach
//dau ra: xuat danh sach cac so tiet kiem dung dieu kien
    cout << "1. Tim kiem theo CMND.\n";
    cout << "2. Tim theo ma so.\n" << '\n';
    cout << "Moi ban chon: ";
    int chon;
    string a;
    cin >> chon;
//tim kiem theo CMND
    if (chon == 1){
        cout << '\n' << "Vui long nhap so CMND: ";
        getline(cin,a);
        while (checkCMND(a) == false){
            cout << "Vui long nhap lai: ";
            getline(cin,a);
        }
        for (int i=0 ; i<n ; ++i)
            if (arr[i].cmnd == a) xuat(arr[i]);
    }
//tim kiem theo ma so tiet kiem
    else if (chon == 2){
        cout << '\n' << "Vui long nhap ma so: ";
        getline(cin,a);
        while (checkMaso(a) == false){
            cout << "Vui long nhap lai: ";
            getline(cin,a);
        }
        for (int i=0 ; i<n ; ++i)
            if (arr[i].maso == a) xuat(arr[i]);
    }
}
void sotietkiemswap (sotietkiem &a, sotietkiem &b){
//dau vao: 2 so tiet kiem
//dau ra: 2 so tiet kiem hoan doi thong tin cho nhau
    sotietkiem c = a;
    a = b;
    b = c;
}
void sapxepsotietkiem (vector<sotietkiem> &arr, int n){
//dau vao: danh sach so tiet kiem, do dai danh sach
//dau ra: danh sach so tiet kiem duoc sap xep theo 1 trong 2 cach ben duoi
    cout << "Vui long chon cach sap xep ben duoi:\n";
    cout << "1. Sap xep danh sach theo so tien gui giam dan.\n";
    cout << "2. Sap xep danh sach theo ngay mo so tang dan.\n";
    cout << "3. Nhap so khac de quay lai...\n";
    cout << endl << "Moi ban chon: ";
    int chon; cin >> chon;
//sap xep danh sach theo so tien gui giam dan
//Selection Sort
    if (chon == 1){
        for (int i=0 ; i<n-1 ; ++i){
            int pos = i;
            for (int j=i+1 ; j<n ; ++j){
                if (arr[pos].sotien < arr[j].sotien) pos = j;
            }
            sotietkiemswap(arr[i],arr[pos]);
        }
    }
//sap xep danh sach theo ngay tang dan
//so sanh nam -> thang -> ngay
//Bubble Sort
    else if (chon == 2){
        for (int i=0 ; i<n-1 ; ++i){
            for (int j=i+1 ; j<n ; ++j){
                if (arr[i].ngaymo.y == arr[j].ngaymo.y){
                    if (arr[i].ngaymo.m == arr[j].ngaymo.m){
                        if (arr[i].ngaymo.d > arr[j].ngaymo.d)
                            sotietkiemswap(arr[i],arr[j]);
                    }
                    else if (arr[i].ngaymo.m > arr[j].ngaymo.m)
                        sotietkiemswap(arr[i],arr[j]);
                }
                else if (arr[i].ngaymo.y > arr[j].ngaymo.y)
                    sotietkiemswap(arr[i],arr[j]);
            }
        }
    }
}
void lietkekhoangthoigian (vector<sotietkiem> arr, int n){
//dau vao: danh sach so tiet kiem, do dai danh sach
//dau ra: xuat danh sach cac so tiet kiem tao moi trong khoang thoi gian dc nhap vao trong luc chay ham
    date a,b;
    cout << "Nhap vao khoang thoi gian ban muon liet ke:\n";
    cout << "- Bat dau: ";
    cin >> a.d >> a.m >> a.y;
    while (checkDate(a) == false){
        cout << "Moi ban nhap lai: ";
        cin >> a.d >> a.m >> a.y;
    }
    cout << "- Ket thuc: ";
    cin >> b.d >> b.m >> b.y;
    while (checkDate(b) == false){
        cout << "Moi ban nhap lai: ";
        cin >> b.d >> b.m >> b.y;
    }
//doi cho ngay nhap vao neu chang may nguoi dung nhap sai
    if (a.y > b.y){
        date c = a;
        a = b;
        b = c;
    }
    else if (a.y == b.y){
        if (a.m > b.m){
            date c = a;
            a = b;
            b = c;
        }
        else if (a.m == b.m){
            if (a.d > b.d){
                date c = a;
                a = b;
                b = c;
            }
        }
    }
//doan code duoi nay no se duyet qua danh sach,
//so sanh ngay tao moi so tiet kiem voi khoang thoi gian vua nhap vao ben tren
//chia nho cac truong hop tu: nam -> thang -> ngay
    cout << "------------------------DANH SACH SO TIET KIEM------------------------\n";
    for (int i=0 ; i<n ; ++i){
        if (a.y < arr[i].ngaymo.y && arr[i].ngaymo.y < b.y)
            xuat(arr[i]);
        else if (a.y == arr[i].ngaymo.y && arr[i].ngaymo.y != b.y){
            if (a.m == arr[i].ngaymo.m){
                if (a.d <= arr[i].ngaymo.d)
                    xuat(arr[i]);
            }
            else if (a.m < arr[i].ngaymo.m)
                xuat(arr[i]);
        }
        else if (a.y != arr[i].ngaymo.y && arr[i].ngaymo.y == b.y){
            if (b.m == arr[i].ngaymo.m){
                if (b.d >= arr[i].ngaymo.d)
                    xuat(arr[i]);
            }
            else if (b.m > arr[i].ngaymo.m)
                xuat(arr[i]);
        }
        else if (a.y == arr[i].ngaymo.y && arr[i].ngaymo.y == b.y){
            if (a.m < arr[i].ngaymo.m && arr[i].ngaymo.m < b.m)
                xuat(arr[i]);
            else if (a.m == arr[i].ngaymo.m && arr[i].ngaymo.m != b.m){
                if (a.d <= arr[i].ngaymo.d)
                    xuat(arr[i]);
            }
            else if (a.m != arr[i].ngaymo.m && arr[i].ngaymo.m == b.m){
                if (b.d >= arr[i].ngaymo.d)
                    xuat(arr[i]);
            }
            else if (a.m == arr[i].ngaymo.m && arr[i].ngaymo.m == b.m){
                if (a.d <= arr[i].ngaymo.d && arr[i].ngaymo.d <= b.d)
                    xuat(arr[i]);
            }
        }
    }
    cout << '\n';
}
void updatelaisuat (double &a){
//dau vao: lai suat truoc do
//dau ra: thay doi gia tri cua lai suat
    cout << "Moi ban nhap lai suat moi: ";
    cin >> a;
    while (a < 0){
        cout << "Moi ban nhap lai: ";
        cin >> a;
    }
}
void tinhlaisuat (vector<sotietkiem> arr, int n, double laisuat){
//dau vao: danh sach so tiet kiem, do dai danh sach, lai suat
//dau ra: xuat ra lai suat ma cac chu nhan so tiet kiem nhan duoc

//lay thoi gian thuc cua he thong
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date today;
    today.m = 1 + ltm->tm_mon;
    today.y = 1900 + ltm->tm_year;
//tinh lai suat theo cong thuc va xuat ket qua
    cout << "-----------------------LAI SUAT NHAN DUOC-----------------------\n";
    for (int i=0; i<n ; ++i){
        if (arr[i].loai == "dai han"){
            int month = today.y*12 + today.m - arr[i].ngaymo.y*12 - arr[i].ngaymo.m;
            double tienlai = arr[i].sotien * pow(1 + laisuat, month/12);
            cout << "Tien lai ma " << arr[i].ten << " nhan duoc: " << fixed << setprecision(0) << tienlai << defaultfloat << endl;
        }
        else{
            int month = today.y*12 + today.m - arr[i].ngaymo.y*12 - arr[i].ngaymo.m;
            double tienlai = arr[i].sotien * laisuat * month/12;
            cout << "Tien lai ma " << arr[i].ten << " nhan duoc: " << fixed << setprecision(0) << tienlai << defaultfloat << endl;
        }
    }
    cout << '\n';
}
void ruttien (vector<sotietkiem> &arr, int n){
//dau vao: danh sach so tiet kiem, do dai danh sach
//dau ra: thay doi so tien gui cua so duoc chon
    cout << "Vui long chon phuong thuc rut tien:\n";
    cout << "1. Rut mot phan.\n";
    cout << "2. Rut toan bo.\n";
    int chon;
    cin >> chon;
    system("cls");

    cout << "-------------------------DANH SACH SO TIET KIEM--------------------------\n";
    for (int i=0 ; i<n ; ++i){
        cout << i+1 << ". ";
        xuat(arr[i]);
    }
    cout << "\nMoi ban chon: ";
    int chon1;
    cin >> chon1;
//lay ngay cua he thong
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date today;
    today.m = 1 + ltm->tm_mon;
    today.y = 1900 + ltm->tm_year;
//rut toan bo so tien
    if (chon == 2){
        arr[chon1-1].sotien = 0;
        cout << "\n---Da rut tien thanh cong---\n" << '\n';
        return;
    }
//rut 1 phan so tien
    double year = (today.y*12 + today.m - arr[chon1-1].ngaymo.y*12 - arr[chon1-1].ngaymo.m) / 12.0;
    if (year != (int)year){
        cout << "\n---------Canh bao: Ban dang rut tien truoc han---------";
    }
    cout << "\nNhap so tien can rut: ";
    double money;
    cin >> money;
//kiem tra so tien nhap vao co du de rut hay khong
    while (money > arr[chon1-1].sotien){
        cout << "So du cua ban khong du, vui long nhap lai: ";
        cin >> money;
    }
    arr[chon1-1].sotien -= money;
    cout << "\n---Da rut tien thanh cong---\n" << '\n';
}
int main(){
    double laisuat = 0; //lai suat mac dinh la 0
    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    vector<sotietkiem> arr;
    sotietkiem x;
    for (int i=0 ; i<n ; ++i){
        nhap(x);
        arr.push_back(x);
    }
//xoa man hinh thoa tac nhap
//while(1) de chuong trinh chay lien tuc den khi nguoi dung muon dung no lai
    while(1){
        system("cls");
        cout << "--------------------QUAN LY SO TIET KIEM--------------------\n";
        cout << "1. Tim kiem so tiet kiem.\n";
        cout << "2. Liet ke danh sach so tiet kiem theo khoang thoi gian.\n";
        cout << "3. Sap xep danh sach so tiet kiem.\n";
        cout << "4. Cap nhat lai suat.\n";
        cout << "5. Tinh toan lai suat tu luc mo so den hien tai.\n";
        cout << "6. Rut tien.\n";
        cout << "7. Xem danh sach so tiet kiem.\n";
        cout << "0. Ket thuc...\n";
        cout << endl << "Moi ban chon: ";
        int button;
        cin >> button;
    //chon thao tac can thuc hien
        if (button == 1){
            system("cls");
            timkiem(arr,n);
            system("pause");
        }
        else if (button == 2){
            system("cls");
            lietkekhoangthoigian(arr,n);
            system("pause");
        }
        else if (button == 3){
            system("cls");
            sapxepsotietkiem(arr,n);
            system("pause");
        }
        else if (button == 4){
            system("cls");
            updatelaisuat(laisuat);
            system("pause");
        }
        else if (button == 5){
            system("cls");
            tinhlaisuat(arr,n,laisuat);
            system("pause");
        }
        else if (button == 6){
            system("cls");
            ruttien(arr,n);
            system("pause");
        }
        else if (button == 7){
            system("cls");
            cout << "------------------------DANH SACH SO TIET KIEM------------------------\n";
            for (int i=0 ; i<n ; ++i)
                xuat(arr[i]);
            system("pause");
        }
        else if (button == 0){
            break;
        }
    }
    return 0;
}
// <(0-o)<
