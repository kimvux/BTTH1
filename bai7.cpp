#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <iomanip>
using namespace std;

struct times {
    int d , m , y;
    int hour, minute;
};
struct flight {
    string id, departure, arrival;
    times info;
};
bool namnhuan (int year){
//dau vao: nam cua ngay khoi hanh cua chuyen bay
//dau ra: true neu nam do la nam nhuan, va nguoc lai
//ham se kiem tra cac dieu kien cua nam nhuan
    if (year % 400 == 0) return true;
    if (year % 4 == 0 && year % 100 != 0) return true;
    return false;
}
bool checkID (string a){
//dau vao: chuoi ma cua chuyen bay
//dau ra: true neu chuoi thoa dieu kien cua ma chuyen bay, false neu khong thoa
//ham se kiem tra xem co ki tu dac biet hay khoang trang hay khong
    if (a.size()>5 || a.size()<1) return false;
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
bool checkDate_Info (times a){
//dau vao: ngay khoi hanh cua chuyen bay
//dau ra: true neu ngay do thoa cac dieu kien cua ngay trong nam, false neu khong thoa
//ham se kiem tra chi so cua ngay, thang, nam xem co dung voi dieu kien co ban hay khong
    if (a.m < 1 || a.m > 12) return false;
    if (a.d < 1 || a.d > 31) return false;
    if (namnhuan(a.y) == true)
        if (a.m == 2 && a.d > 29) return false;
    if (namnhuan(a.y) == false)
        if (a.m == 2 && a.d > 28) return false;
    if (a.m == 1 || a.m == 3 || a.m == 5 || a.m == 7 || a.m == 8 || a.m == 10 || a.m == 12)
        if (a.d > 31) return false;
    if (a.m == 4 || a.m == 6 || a.m == 9 || a.m == 11)
        if (a.d > 30) return false;
    return true;
}
bool checkTime_Info (times a){
//dau vao: gio khoi hanh cua chuyen bay
//dau ra: true neu gio do thoa cac dieu kien cua gio va phut, false neu khong thoa
//ham se kiem tra dieu kien cua gio va phut
    if (a.hour < 0 || a.hour > 23 || a.minute < 0 || a.minute > 59) return false;
    return true;
}
void fixname (string &a){
//dau vao: chuoi ten dia danh cua noi di hoac noi den
//dau ra: chuoi ten do duoc sua thanh dang: in hoa ki tu dau, cac ki tu con lai in thuong
//ham se chia nho chuoi ten thanh tung chuoi nho bang stringstream,
//sau do in hoa ki tu dau va in thuong cac ki tu con lai cua cac chuoi nho,
//sau do ghep cac chuoi nho lai thanh ten hoan chinh
    stringstream ss(a);
    string word;
    string name;
    while (ss >> word){
        name += toupper(word[0]);
        for (int i=1 ; i<word.length() ; i++)
            name += tolower(word[i]);
        name += " ";
    }
    name.pop_back();
    a = name;
}
bool checkName (string a){
//dau vao: chuoi ten cua dia danh
//dau ra: true neu chuoi ten khong chua ki tu dac biet, false neu khong thoa dieu kien
//ham se duyet qua tung ki tu, kiem tra co phai ki tu dac biet hay khong
    if (a.size() < 1 || a.size() > 20) return false;
    for (int i=0 ; i<a.size() ; ++i){
        if (a[i] == ' ') continue;
        if (tolower(a[i]) < 'a' || tolower(a[i]) > 'z') return false;
    }
    return true;
}
void nhap (flight &a){
//dau vao: tham chieu den mot phan tu chuyen bay
//dau ra: cac thong tin cua phan tu do duoc nhap vao
//ham se thuc hien viec nhap du lieu cho 1 chuyen bay 
    cout << "===========================================================\n";
//ID
    cout << "Nhap ma chuyen bay: ";
    getline(cin,a.id);
    while (checkID(a.id) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a.id);
    }
//DATE
    cout << "Nhap ngay bay (cach nhau bang khoang trang): ";
    cin >> a.info.d >> a.info.m >> a.info.y;
    while (checkDate_Info(a.info) == false){
        cout << "Moi ban nhap lai: ";
        cin >> a.info.d >> a.info.m >> a.info.y;
    }
//TIME
    cout << "Nhap gio bay (cach nhau bang khoang trang): ";
    cin >> a.info.hour >> a.info.minute;
    while (checkTime_Info(a.info) == false){
        cout << "Moi ban nhap lai: ";
        cin >> a.info.hour >> a.info.minute;
    }
//DEPARTURE
    cout << "Nhap diem khoi hanh: ";
    cin.ignore();
    getline(cin,a.departure);
    while (checkName(a.departure) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a.departure);
    }
    fixname(a.departure);
//ARRIVAL
    cout << "Nhap diem den: ";
    getline(cin,a.arrival);
    while (checkName(a.arrival) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a.arrival);
    }
    fixname(a.arrival);
}
void xuat (flight a){
//dau vao: du lieu cua mot chuyen bay
//dau ra: xuat thong tin chuyen bay ra man hinh
//ham nay xuat thong tin
    cout << setw(2) << setfill('0') << a.info.hour << ":" << setw(2) << setfill('0') << a.info.minute << '\t' << setw(2) << setfill('0') << a.info.d << "/" << setw(2) << setfill('0') << a.info.m << "/" << a.info.y << '\t' << a.id << '\t' << a.departure << '\t' << '\t' << a.arrival << endl;
}
void timkiem (vector<flight> arr, int n, int button){
//dau vao: danh sach cac chuyen bay, so chuyen bay trong danh sach do, lua chon cua nguoi dung muon thuc hien mot trong cac chuc nang tim kiem
//dau ra: thong tin cua cac chuyen bay thoa dieu kien tim kiem duoc lua chon boi nguoi dung
//ham nay se thuc 1 trong 3 chuc nang tim kiem duoc nguoi dung chon

//tim kiem bang ma chuyen bay
    if (button == 1){
        string a;
        cout << "Moi ban nhap ma chuyen bay: ";
        cin >> a;
        int check = 0;
        cout << "\n";
        cout << "TIME" << '\t' << "DATE" << '\t' << '\t' << "FLIGHT" << '\t' << "DEPARTURE" << '\t' << "ARRIVAL" << endl;
        for (int i=0 ; i<n ; ++i){
            if (arr[i].id == a) xuat(arr[i]);
            check++;
        }
        if (check == 0) cout << "....NOT FOUND....\n";
    }
//tim kiem bang ten hoac tu khoa cua noi khoi hanh chuyen bay
    if (button == 2){
        string name;
        cout << "Moi ban nhap ten/tu khoa can tim: ";
        cin.ignore();
        getline(cin,name);
        fixname(name);
        cout << "TIME" << '\t' << "DATE" << '\t' << '\t' << "FLIGHT" << '\t' << "DEPARTURE" << '\t' << "ARRIVAL" << endl;
        int check = 0;
        for (int i=0 ; i<arr.size() ; ++i)
            if (arr[i].departure.find(name) != string::npos){
                check++;
                xuat(arr[i]);
            }
        if (check == 0) cout << "....NOT FOUND....\n";
    }
//tim kiem bang ten hoac tu khoa cua diem den chuyen bay
    if (button == 3){
        string name;
        cout << "Moi ban nhap ten/tu khoa can tim: ";
        cin.ignore();
        getline(cin,name);
        fixname(name);
        cout << "TIME" << '\t' << "DATE" << '\t' << '\t' << "FLIGHT" << '\t' << "DEPARTURE" << '\t' << "ARRIVAL" << endl;
        int check = 0;
        for (int i=0 ; i<arr.size() ; ++i)
            if (arr[i].arrival.find(name) != string::npos){
                check++;
                xuat(arr[i]);
            }
        if (check == 0) cout << "....NOT FOUND....\n";
    }
}
void myswap(flight &a ,flight &b){
//dau vao: du lieu cua 2 chuyen bay
//dau ra: 2 chuyen bay trao doi du lieu cho nhau
//ham nay se hoan doi du lieu 2 phan tu
    flight ex1 = a;
    a = b;
    b = ex1;
}
void mysort (vector<flight> &arr, int n){
//dau vao: danh sach cac chuyen bay, so chuyen bay trong danh sach do
//dau ra: mang chuyen bay da duoc sap xep theo thoi gian khoi hanh tang dan
//ham se so sanh tu nam --> phut de hoan doi du lieu 2 chuyen bay neu phan tu chuyen bay truoc do co thoi gian lon hon
    for (int i=0 ; i<n-1 ; ++i)
        for (int j=i+1 ; j<n ; ++j){
            if (arr[i].info.y == arr[j].info.y){
                if (arr[i].info.m == arr[j].info.m){
                    if (arr[i].info.d == arr[j].info.d){
                        if (arr[i].info.hour == arr[j].info.hour){
                            if (arr[i].info.minute > arr[j].info.minute)
                                myswap(arr[i],arr[j]);
                        }
                        else if (arr[i].info.hour > arr[j].info.hour)
                            myswap(arr[i],arr[j]);
                    }
                    else if (arr[i].info.d > arr[j].info.d)
                        myswap(arr[i],arr[j]);
                }
                else if (arr[i].info.m > arr[j].info.m)
                    myswap(arr[i],arr[j]);
            }
            else if (arr[i].info.y > arr[j].info.y)
                myswap(arr[i],arr[j]);
        }
}
void danhsachtheongay (vector<flight> &arr, int n){
//dau vao: danh sach cac chuyen bay, so chuyen bay trong danh sach do
//dau ra: xuat danh sach cac chuyen bay khoi hanh tu mot noi cu the, trong mot ngay cu the
//ham se cho phep nguoi dung nhap vao dia danh va mot ngay, sau do duyet qua mang cac chuyen bay de tim chuyen bay co thong tin trung khop
    times a;
    string b;
    cout << "Nhap ngay ban muon tra cuu: ";
    cin >> a.d >> a.m >> a.y;
    while (checkDate_Info(a) == false){
        cout << "Moi ban nhap lai: ";
        cin >> a.d >> a.m >> a.y;
    }
    cin.ignore();
    cout << "Nhap noi khoi hanh cua chuyen bay: ";
    getline(cin,b);
    while (checkName(b) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,b);
    }
    fixname(b);
    cout << "TIME" << '\t' << "DATE" << '\t' << '\t' << "FLIGHT" << '\t' << "DEPARTURE" << '\t' << "ARRIVAL" << endl;
    for (int i=0; i<n ; ++i)
        if (arr[i].info.d == a.d && arr[i].info.m == a.m && arr[i].info.y == a.y && arr[i].departure.find(b) != string::npos)
            xuat(arr[i]);
}
void demsoluongchuyenbay (vector<flight> &arr, int n){
//dau vao: danh sach cac chuyen bay, so chuyen bay trong mang do
//dau ra: xuat ra man hinh so luong chuyen bay di tu mot noi cu the, den mot noi cu the
//ham se cho phep nguoi dung nhap va noi di va diem den, sau do duyet qua mang cac chuyen bay de tim chuyen bay co thong tin trung khop
    string d,a;
    cout << "Nhap diem khoi hanh: ";
    getline(cin,d);
    while (checkName(d) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,d);
    }
    fixname(d);
    cout << "Nhap diem den: ";
    getline(cin,a);
    while (checkName(a) == false){
        cout << "Moi ban nhap lai: ";
        getline(cin,a);
    }
    fixname(a);
    int count = 0;
    for (int i=0 ; i<n ; ++i)
        if (arr[i].departure == d && arr[i].arrival == a) count++;
    cout << "So luong chuyen bay di tu " << d << " den " << a << " la: " << count << endl;
}
int main(){
    int n;
    cout << "Nhap vao so chuyen bay: ";
    cin >> n;
    cin.ignore();
    vector<flight> arr;
    flight a;
    for (int i=0 ; i<n ; ++i){
        nhap(a);
        arr.push_back(a);
    }
    mysort(arr,n);

    int chon;
    while (1){
        system("cls");
        cout << "---------------------QUAN LY CHUYEN BAY---------------------\n";
        cout << "1. Xem thong tin tat ca cac chuyen bay.\n";
        cout << "2. Tim kiem thong tin.\n";
        cout << "3. Liet ke danh sach theo ngay va noi khoi hanh.\n";
        cout << "4. Dem so chuyen bay theo noi di va noi den.\n";
        cout << "0. Ket thuc...\n" << '\n';
        cout << "Moi ban chon: ";
        cin >> chon;
        if (chon == 1){
            system("cls");
            cout << "TIME" << '\t' << "DATE" << '\t' << '\t' << "FLIGHT" << '\t' << "DEPARTURE" << '\t' << "ARRIVAL" << endl;
            for (int i=0 ; i<n ; ++i)
                xuat(arr[i]);
            system("pause");
        }
        else if (chon == 2){
            system("cls");
            cout << "---------------------TIM KIEM THONG TIN---------------------\n";
            cout << "1. Tim theo ma chuyen bay.\n";
            cout << "2. Tim theo noi di.\n";
            cout << "3. Tim theo diem den.\n" << '\n';
            cout << "Moi ban chon: ";
            int button;
            cin >> button;
            while(button < 1 || button > 3){
                cin >> button;
            }
            timkiem(arr,n,button);
            cout << '\n';
            system("pause");
        }
        else if (chon == 3){
            system("cls");
            danhsachtheongay(arr,n);
            system("pause");
        }
        else if (chon == 4){
            system("cls");
            cin.ignore();
            demsoluongchuyenbay(arr,n);
            system("pause");
        }
        else if (chon == 0)
            break;

    }
    return 0;
}
