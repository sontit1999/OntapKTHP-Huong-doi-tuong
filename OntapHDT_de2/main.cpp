// cau 1
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class SOPHUC
{
    int a;
    int b;
public:
    SOPHUC();
    SOPHUC(int x, int y);
    SOPHUC operator+(SOPHUC y);
    friend istream& operator>>(istream& x,SOPHUC &y);
    friend ostream& operator<<(ostream& x, SOPHUC y);
    friend SOPHUC tong(SOPHUC a[],int n);
};
SOPHUC::SOPHUC()
{
    a = 0;
    b = 0;
}
SOPHUC::SOPHUC(int x, int y)
{
    a = x;
    b = y;
}
SOPHUC SOPHUC::operator+(SOPHUC y)
{
    SOPHUC temp;
    temp.a = a + y.a;
    temp.b = b + +y.b;
    return temp;
}
istream& operator>>(istream& x,SOPHUC &y)
{
    cout << "Phan thuc = " ;
    x >> y.a;
    cout << "Phan ao = " ;
    x >> y.b;
    return x;
}
ostream& operator<<(ostream& x, SOPHUC y)
{
    x << y.a << " + " << y.b << "*i" ;
    return x;
}
SOPHUC tong(SOPHUC a[],int n)
{
    SOPHUC s;
    for(int i=0;i<n;i++)
    {
        s.a += a[i].a;
        s.b += a[i].b;
    }
    return s;
}
int main()
{
    int n;
    cout << "n = " ; cin >> n;
    SOPHUC a[n];
    SOPHUC s;
    for(int i=0;i<n;i++)
    {
        cout << "Nhap so phuc thu " << i+1 << endl;
        cin >> a[i];
    }
    cout << "DS so phuc la: ";
    for(int i=0;i<n;i++)
    {
       cout << a[i] << "\t ," ;

    }
    cout << "Tong cac so phuc vua nhap = " << tong(a,n) ;
    return 0;
}

*/

// cau 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class NGAY
{
protected:

    int ngay;
    int thang;
    int nam;
public:
    NGAY();
    NGAY(int d, int m, int y);
    void nhap();
    void xuat();
};
NGAY::NGAY()
{
    ngay = 1;
    thang = 1;
    nam  = 1970;
}
NGAY::NGAY(int d, int m, int y)
{
    ngay = d;
    thang = m;
    nam = y;
}
void NGAY::nhap()
{
    cout << "Nhap ngay: " ; cin >> ngay;
    cout << "Nhap thang: " ; cin >> thang;
    cout << "Nam: "  ; cin >> nam;
}
void NGAY::xuat()
{
    cout << ngay << "/" << thang << "/" << nam ;
}
class NGUOI : public NGAY
{
    char chungminhthu[15];
    char hoten[15];
    char noisinh[15];
public:
    NGUOI();
    NGUOI(int d, int m, int y,char* cmt, char* ht, char* ns);
    void nhap();
    void xuat();
    void operator=(NGUOI y);
    friend void sapxep(NGUOI a[], int n);
};
NGUOI::NGUOI() : NGAY()
{
    strcpy(chungminhthu,"");
    strcpy(hoten,"");
    strcpy(noisinh,"");
}
NGUOI::NGUOI(int d, int m, int y,char* cmt, char* ht, char* ns) : NGAY(d,m,y)
{
    strcpy(chungminhthu,cmt);
    strcpy(hoten,ht);
    strcpy(noisinh,ns);
}
void NGUOI::nhap()
{
    NGAY::nhap();
    cout << "Chung minh thu: " ; fflush(stdin) ; gets(chungminhthu);
    cout << "Ho ten: " ; fflush(stdin) ; gets(hoten);
    cout << "Noi sinh: " ; fflush(stdin) ; gets(noisinh);
}
void NGUOI::xuat()
{
    cout << setw(20) << left << chungminhthu << setw(15) << left << hoten << setw(15) << left << noisinh ;
    cout << setw(12) << right ;
    NGAY::xuat();
    cout << endl;
}
void NGUOI::operator=(NGUOI y)
{
    ngay = y.ngay;
    thang = y.thang;
    nam = y.nam;
    strcpy(chungminhthu,y.chungminhthu);
    strcpy(hoten,y.hoten);
    strcpy(noisinh,y.noisinh);
}
void sapxep(NGUOI a[], int n)
{
    for(int i =1;i<n;i++)
    {
        for(int j = n -1 ; j>=i ; j--)
        {
            if((2019-a[j].nam)>(2019-a[j-1].nam))
               {
                   NGUOI temp;
                   temp = a[j];
                   a[j] = a[j-1];
                   a[j-1] = temp;
               }
        }
    }
}
int main()
{
    int k;
    cout << " k = " ; cin >> k;
    NGUOI a[k];
    for(int i=0;i<k;i++)
    {
        cout << "Nhap nguoi thu " << i+1 << endl;
        a[i].nhap();
    }
    cout << "DS trc khi sap xep " << endl;
    cout << setw(20) << left << "chungminhthu" << setw(15) << left << "hoten" << setw(15) << left << "noisinh" ;
    cout << setw(12) << right << "Ngay sinh" << endl ;

    for(int i=0;i<k;i++)
    {
        a[i].xuat();
    }
    sapxep(a,k);
    cout << "DS sau khi sap xep " << endl;
    cout << setw(20) << left << "chungminhthu" << setw(15) << left << "hoten" << setw(15) << left << "noisinh" ;
    cout << setw(12) << right << "Ngay sinh" << endl ;

    for(int i=0;i<k;i++)
    {
        a[i].xuat();
    }
    return 0;
}
