#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class HANG
{
    char tenhang[15];
    int dongia;
    int soluong;
public:
    void nhap();
    void xuat();
    friend class PHIEU;
};
void HANG::nhap()
{
    cout << "Ten hang: " ; fflush(stdin) ; gets(tenhang);
    cout << "Don gia:" ; cin >> dongia;
    cout << "So luong: " ; cin >> soluong;
}
void HANG::xuat()
{
    cout << setw(20) << left << tenhang << setw(20) << left << dongia << setw(15) << left << soluong << setw(20) << left << dongia *soluong << endl;
}
class PHIEU
{
    char maphieu[10];
    char khachhang[20];
    char ngaylap[12];
    int n;
    HANG *a;
public:
    void nhap();
    void xuat();
};
void PHIEU::nhap()
{
    cout << "Ma phieu: " ; fflush(stdin) ; gets(maphieu);
    cout << "Khach hang: " ; fflush(stdin); gets(khachhang);
    cout << "Ngay lap: " ; fflush(stdin) ; gets(ngaylap);
    cout << " n = " ; cin >> n;
    a = new HANG[n];
    for(int i=0;i<n;i++)
    {
        a[i].nhap();
    }
}
void PHIEU::xuat()
{
    int s = 0;
    for(int i=0;i<n;i++)
    {
        s+=a[i].soluong * a[i].dongia;
    }
    cout << "\t \t \t PHIEU MUA HANG " << endl;
    cout << setw(20) << left << "Ma Phieu: " << setw(20) << left << maphieu << setw(20) << left << "Khach Hang:" << setw(20) << left << khachhang << endl;
    cout << setw(20) << left << "Ngay Lap"  << setw(20) << left << ngaylap << setw(20) << left <<  "Tong thanh tien: \t" << s << " VND" << endl;
    cout << "Danh Muc Hang Hoa" <<endl;
    cout << setw(20) << left << "Ten Hang" << setw(20) << left << "Don Gia" << setw(15) << left << "So Luong" << setw(20) << left << "Thanh Tien"<< endl;
    for(int i=0;i<n;i++)
    {
        a[i].xuat();
    }
}
int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();
    return 0;
}
