#include<iostream>
#include<vector>
using namespace std;
int main(){
//dau vao: mang A va B
//dau ra: so lan xuat hien cua mang A trong mang B, vi tri xuat hien cua mang A trong mang B
    vector<int> a,b,pos;
    int n1,n2;
    cout << "Nhap vao so luong phan tu hai mang: ";
    cin >> n1 >> n2;
    int x;
//nhap mang A va B
    cout << "Nhap mang A: ";
    for (int i=0 ; i<n1 ; i++){
        cin >> x;
        a.push_back(x);
    }
    cout << "Nhap mang B: ";
    for (int i=0 ; i<n2 ; i++){
        cin >> x;
        b.push_back(x);
    }
//o tung vi tri cua mang B, duyet qua n1(do dai mang A) phan tu ke tiep,
//neu phat hien co phan tu khac biet thi chuyen qua vi tri tiep theo cua mang B de tiep tuc duyet,
//neu khong phat hien su khac biet thi dua vi tri dau tien cua 1 phan mang B vua duyet vao mang pos
    for (int i=0 ; i<=n2-n1 ; i++){
        bool check = true;
        for (int j=0 ; j<n1 ; j++){
            if (a[j] != b[i+j]){
                check = false;
                break;
            }
        }
        if (check == true){
            pos.push_back(i);
        }
    }
    if (pos.empty()){
        cout << "Khong tim thay mang A trong mang B.\n";
        return 0;
    }
    cout << "Mang A xuat hien " << pos.size() << " lan tai cac chi so bat dau la: " << endl;
    for(int x : pos)
        cout << x << " ";
    return 0;
}
