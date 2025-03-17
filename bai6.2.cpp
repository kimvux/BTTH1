#include <bits/stdc++.h>
using namespace std;
struct hocsinh{
    string ten;
    float toan,van,anh,dtb;
    string xeploai;
};
void fixname (string &x){
//dau vao: chuoi ten cua hoc sinh
//dau ra: chuoi ten do duoc sua thanh dang: in hoa ki tu dau, cac ki tu con lai in thuong
//ham se chia nho chuoi ten thanh tung chuoi con (stringstream),
//sau do in hoa ki tu dau va in thuong cac ki tu con lai cua cac chuoi con,
//cuoi cung ghep cac chuoi con lai thanh ten hoan chinh
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
void nhap(hocsinh &x){
//dau vao: tham chieu den mot phan tu hoc sinh
//dau ra: thong tin cua phan tu do duoc nhap vao
//ham se cho phep nguoi dung nhap thong tin hoc sinh, ham se tu tinh toan diem trung binh va xep loai hoc sinh theo diem trung binh vua tinh
    cout << "Nhap ten hoc sinh: ";
    cin.ignore();
    getline(cin,x.ten);
    while (1){
        int check = 0;
        for (int i=0; i<x.ten.length() ; i++)
            if (x.ten[i] >= '0' && x.ten[i] <= '9'){
                cout << "Hay nhap lai: ";
                getline(cin,x.ten);
                check = 1;
            }
        if (check == 0) break;
    }
    fixname(x.ten);


    cout << "Nhap diem Toan: ";
    cin >> x.toan;
    while (x.toan < 0 || x.toan > 10){
        cout << "Hay nhap lai: ";
        cin >> x.toan;
    }

    cout << "Nhap diem Van: ";
    cin >> x.van;
    while (x.van < 0 || x.van > 10){
        cout << "Hay nhap lai: ";
        cin >> x.van;
    }

    cout << "Nhap diem Anh: ";
    cin >> x.anh;
    while (x.anh < 0 || x.anh > 10){
        cout << "Hay nhap lai: ";
        cin >> x.anh;
    }
    x.dtb = (2*x.toan + x.van + x.anh)/4;
    if (x.dtb >= 9) x.xeploai = "Xuat sac";
    else if (x.dtb >= 8) x.xeploai = "Gioi";
    else if (x.dtb >= 6.5) x.xeploai = "Kha";
    else if (x.dtb >= 5) x.xeploai = "Trung binh";
    else x.xeploai = "Yeu";
}
hocsinh DTBmax (vector<hocsinh> arr){
//dau vao: danh sach cac hoc sinh
//dau ra: hoc sinh co diem trung binh cao nhat
//ham se duyet qua danh sach cac hoc sinh de tim ra hoc sinh co diem trung binh cao nhat
    hocsinh a = arr[0];
    for (int i=1 ;i<arr.size(); ++i)
        if (arr[i].dtb > a.dtb) a = arr[i];
    return a;
}
void timkiem (vector<hocsinh> arr){
//dau vao: danh sach cac hoc sinh
//dau ra: xuat ra man hinh danh sach cac hoc sinh co ten hoac tu khoa trung khop
//ham se cho nguoi dung nhap vao mot ten day du hoac tu khoa, sau do duyet qua danh sach de tim hoc sinh co ten lien quan
    string name;
    cout << "Moi ban nhap ten/tu khoa can tim: ";
    cin.ignore();
    getline(cin,name);
    fixname(name);
    cout << "-------------------------------------------\n";
    cout << "Day la nhung hoc sinh co tu khoa lien quan:\n";
    int check = 0;
    for (int i=0 ; i<arr.size() ; ++i)
        if (arr[i].ten.find(name) != string::npos){
            check++;
            cout << arr[i].ten << '\t' << "DTB: " << arr[i].dtb << '\t' << "Xep loai: " << arr[i].xeploai << endl;
        }
    if (check == 0) cout << "....NOT FOUND....\n";
}
void toansort (vector<hocsinh> &arr){
//dau vao: danh sach cac hoc sinh
//dau ra: danhh sach cac hoc sinh da duoc sap xep theo diem toan tang dan
//ham se sap xep lai vi tri cac hoc sinh trong danh sach theo diem toan tang dan
    for (int i=0 ; i<arr.size()-1 ; ++i)
        for (int j=i+1 ; j<arr.size() ; ++j)
            if (arr[i].toan > arr[j].toan){
                hocsinh a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
}
void danhsachtoan (vector<hocsinh> arr){
//dau vao: danh sach cac hoc sinh
//dau ra: xuat ra danh sach cac hoc sinh co diem toan thap nhat, voi so luong hoc sinh duoc xuat ra duoc nguoi dung nhap vao
//ham se cho phep nguoi dung nhap vao so hoc sinh can xuat danh sach,
//sau do xuat ra man hinh cac hoc sinh co diem toan tang dan (di tu ban hoc sinh co diem thap nhat)
    cout << "Nhap vao so hoc sinh (co diem toan thap nhat) ban muon xuat danh sach: ";
    int n;
    cin >> n;
    while (n<1 || n>arr.size()){
        cout << "Vui long nhap lai: ";
        cin >> n;
    }
    cout << "Day la danh sach cua ban:\n";
    for (int i=0 ; i<n ; i++)
        cout << i+1 << ". " << arr[i].ten << '\t' << "Diem toan: " << arr[i].toan << endl;
}
void xuatdanhsachhocsinh (vector<hocsinh> arr){
//dau vao: danh sach cac hoc sinh
//dau ra: xuat ra man hinh danh sach toan bo hoc sinh
//ham nay xuat thong tin
    cout << "TEN HOC SINH" << '\t' << '\t' << "TOAN" << '\t' << "VAN" << '\t' << "ANH" << '\t' << "DTB" << '\t' << "XEP LOAI" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int i=0; i<arr.size() ; i++)
        cout << arr[i].ten << '\t' << '\t' << arr[i].toan << '\t' << arr[i].van << '\t' << arr[i].anh << '\t' << arr[i].dtb << '\t' << arr[i].xeploai << endl;
}
int main(){
    int n;
    cout << "Nhap so hoc sinh: ";
    cin >> n;
    cout << "--------------------------------------" << endl;
    hocsinh x;
    vector<hocsinh> arr;
    for (int i=0 ; i<n ; ++i){
        nhap(x);
        cout << "--------------------------------------" << endl;
        arr.push_back(x);
    }
    toansort(arr);
    int button;
    while (1){
        system("cls");
        cout << "----------THONG TIN HOC SINH----------" << endl;
        cout << "1. Xem danh sach hoc sinh." << endl;
        cout << "2. Hoc sinh co diem trung binh cao nhat." << endl;
        cout << "3. Tim kiem hoc sinh." << endl;
        cout << "4. Danh sach hoc sinh co diem toan thap nhat." << endl;
        cout << "0. Ket thuc." << endl;
        cout << endl << "Moi ban chon: ";
        cin >> button;
        if (button == 0) break;
        if (button == 1){
            system("cls");
            xuatdanhsachhocsinh(arr);
            system("pause");
        }
        else if (button == 2){
            system("cls");
            cout << "Hoc sinh co diem trung binh cao nhat la:\n";
            cout << "----------------------------------------\n";
            hocsinh x = DTBmax(arr);
            cout << "Ho va Ten: " << x.ten << endl << "Diem trung binh: " << x.dtb << endl;
            system("pause");
        }
        else if (button == 3){
            system("cls");
            timkiem(arr);
            system("pause");
        }
        else if (button == 4){
            system("cls");
            danhsachtoan(arr);
            system("pause");
        }
    }
    return 0;
}
