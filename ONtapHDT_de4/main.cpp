// cau 1
/*
#include <iostream>
#include <bits/stdc++.h>


.224444444444400000000000000
using namespace std;
class HANG
{
    char tenhang[15];
    float dongia;
    int soluong;
public:
    void nhap();
    void xuat();
    friend class PHIEU;
};
void HANG::nhap()
{
    cout << "Ten hang:" ; fflush(stdin) ; gets(tenhang);
    cout << "Don gia: " ; cin >> dongia;
    cout << "So Luong : "; cin >> soluong;
}
void HANG::xuat()
{
    cout << setw(20)  << left << tenhang << setw(20)  << left << dongia << setw(20)  << left << soluong << setw(20)  << left << dongia * soluong << endl;
}
class PHIEU
{
    char maphieu[15];
    char khachhang[15];
    char ngaylap[15];
    int n;
    HANG *a;
public:
    void nhap();
    void xuat();
};
void PHIEU::nhap()
{
    cout << "Ma phieu: " ;fflush(stdin) ; gets(maphieu);
    cout << "Khach hang: " ; fflush(stdin) ;gets(khachhang);
    cout << "Ngay lap: "   ; fflush(stdin) ; gets(ngaylap);
    cout << " n = " ; cin >> n;
    a = new HANG[n];
    for(int i=0;i<n;i++)
    {
        a[i].nhap();
    }
}
void PHIEU::xuat()
{
    float s = 0;
    float maxthanhtien = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i].dongia * a[i].soluong > maxthanhtien)
        {
            maxthanhtien = a[i].dongia * a[i].soluong;
        }
        s+=a[i].dongia * a[i].soluong;
    }
    cout << "\t\t\t PHIEU MUA HANG" << endl;
    cout << setw(20) << left << "Ma Phieu: " << setw(20) << left << maphieu << setw(20) << left << "Khach hang: " << setw(20) << left << khachhang << endl;
    cout << setw(20) << left << "Ngay Lap: " << setw(20) << left << ngaylap << setw(20) << left << "Tong Thanh tien: " << setw(20) << left << s << endl;
    cout << "Danh muc hang hoa" <<endl;
    cout << setw(20)  << left << "Ten hang" << setw(20)  << left << "Don gia"<< setw(20)  << left << "soluong" << setw(20)  << left << "Thanh Tien" << endl;
    for(int i=0;i<n;i++)
    {
        if(a[i].dongia * a[i].soluong == maxthanhtien)
        {
           a[i].xuat();
        }

    }
}
int main()
{
     PHIEU a;
     a.nhap();
     a.xuat();
    return 0;
}
*/
// cau 2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Array
{
    int n;
    double *a;
public:
    Array();
    void xuat();
    void operator--();
    friend istream& operator>>(istream& x, Array &y);

};
Array::Array()
{
    n = 0;
    a = NULL;
}
void Array::xuat()
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << "\t" ;
    }
}
void Array::operator--()
{
    for(int i=1;i<n;i++)
    {
        for(int j = n-1;j>=i;j--)
        {
            if(a[j] > a[j-1])
            {
                double temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}

istream& operator>>(istream& x, Array &y)
{
    cout << " n = " ; cin >> y.n;
    y.a = new double[y.n];
    for(int i=0;i<y.n;i++)
    {
        cout << "Phan tu thu " << i + 1 << " = " ;
        x >> y.a[i];
    }
    return x;
}

int main()
{
    Array a;

    cin >> a;
    cout << "Mang vua nhap: " ;
    a.xuat();
    --a;
    cout << "\n Mang sau khi sap xep giam dan:" ;
    a.xuat();
    return 0;
}
