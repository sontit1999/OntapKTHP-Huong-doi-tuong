// cau1
/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class XEMAY;
class DATE
{
    int ngay;
    int thang;
    int nam;
public:
    void nhap();
    void xuat();
    friend void in(XEMAY a[],int n);
    friend class XE;
};
void DATE::nhap()
{
    cout << "Nhap ngay: " ; cin >> ngay;
    cout << "Nhap thang:" ; cin >> thang;
    cout  << "Nhap nam: " ; cin >> nam;
}
void DATE::xuat()
{
    cout << ngay << "/" << thang << "/" << nam ;
}
class XE
{
protected:
    char chusohuu[15];
    char bienso[10];
    char noidki[10];
    DATE ngaydki;
public:
    void nhap();
    void xuat();
};
void XE::nhap()
{
    cout << "Chu so huu: " ; fflush(stdin) ; gets(chusohuu);
    cout << "Bien so: "    ; fflush(stdin) ; gets(bienso);
    cout << "Noidki: "     ; fflush(stdin) ; gets(noidki);
    cout << "Ngay dki" << endl;
    ngaydki.nhap();
}
void XE::xuat()
{
    cout << setw(15) << left << chusohuu << setw(10) << left << bienso << setw(15) << left << noidki << setw(1) << left << ngaydki.ngay << "/" << left << ngaydki.thang<< "/" << setw(12) << left << ngaydki.nam;
}
class XEMAY : public XE
{
    int giatien;
    char mauson[10];
public:
    void nhap();
    void xuat();
    friend void in(XEMAY a[],int n);
};
void XEMAY::nhap()
{
    XE::nhap();
    cout << "Gia tien: " ; cin >> giatien;
    cout  << "Mau son: " ; fflush(stdin) ; gets(mauson);
}
void XEMAY::xuat()
{
    XE::xuat();
    cout << setw(14) << left << giatien << setw(10) << left << mauson << endl;
}
void in(XEMAY a[],int n)
{
    int k =0;
    cout << setw(15) << left << "chusohuu" << setw(10) << left << "bienso" << setw(15) << left << "noidki" << setw(15) << left << "Ngay dki" ;
    cout << setw(14) << left << "giatien" << setw(10) << left << "mauson" << endl;
    for(int i=0;i<n;i++)
    {
       if( a[i].ngaydki.nam == 2016 && a[i].giatien>20000000)
       {
           a[i].xuat();
           k=1;
       }
    }
    if(k == 0)
    {
        cout << "\n Khong co xe may nao dki nam 2016 va gia tien lon hon 20000000 ";
    }
}
int main()
{
    int n;
    cout << "n = " ; cin >> n;
    XEMAY a[n];
    for(int i=0;i<n;i++)
    {
        a[i].nhap();
    }

    cout << "Ds xe may dki nam 2016 va gia tien lon hon 20000000" << endl;
    in(a,n);
    return 0;
}
*/
// cau 2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class PTBAC3
{
    float a,b,c,d;
public:
    PTBAC3();
    void nhap();
    void operator--();
    friend ostream& operator<<(ostream& x, PTBAC3 y);
};
PTBAC3::PTBAC3()
{
    a = b = c = d = 0;
}
void PTBAC3::nhap()
{
    cout << "a = " ; cin >> a;
    cout << "b = " ; cin >> b;
    cout << "c = " ; cin >> c;
    cout << "d = " ; cin >> d;
}
void PTBAC3::operator--()
{
    float a[] = {this->a,this->b,this->c,this->d};
    for(int i=0;i<4;i++)
    {
        for(int j = i+1;j<4;j++)
        {
            if(a[j]>a[i])
            {
                float temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    this->a = a[0];
    this->b = a[1];
    this->c = a[2];
    this->d = a[3];

}
ostream& operator<<(ostream& x, PTBAC3 y)
{
    x << y.a << "X3" << " + " << y.b << "X2" << " + " << y.c << "X + " << y.d << " = 0";
    return x;
}
int main()
{
    PTBAC3 a;
    a.nhap();
    cout << "Pt vua nhap: ";
    cout << a;
    --a;
    cout << "\n Pt sau khi dao gia tri: " << a;
    return 0;
}
