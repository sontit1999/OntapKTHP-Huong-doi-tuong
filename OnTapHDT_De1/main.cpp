// CAU 1
/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class VECTOR
{
    int n;
    float *a;
public:
    VECTOR();
    VECTOR(int kt);
    ~VECTOR();
    friend istream& operator>>(istream& x, VECTOR &y);
    friend ostream& operator<<(ostream& x, VECTOR y);
    float operator--();
    float operator++();
};
VECTOR::VECTOR()
{
    n = 0;
}
VECTOR::VECTOR(int kt)
{
    n = kt;
    a = new float[n];
    for(int i=0;i<n;i++)
    {
        a[i] = 0;
    }
}
VECTOR::~VECTOR()
{
    n = 0;
    a = NULL;
}
istream& operator>>(istream& x, VECTOR &y)
{
    cout << "Nhap so chieu cua vector:" << endl;
    x >> y.n;
    y.a = new float[y.n];
    cout << "Nhap vector" << endl;
    for(int i=0;i<y.n;i++)
    {
        x >> y.a[i] ;
    }
    return x;
}
ostream& operator<<(ostream& x, VECTOR y)
{
    for(int i=0;i<y.n;i++)
    {
        x << y.a[i] << "\t" ;
    }
    return x;
}
float VECTOR::operator++()
{
    float max = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max) max = a[i];
    }
    return max;
}
float VECTOR::operator--()
{
    float min = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i] < min) min = a[i];
    }
    return min;
}
int main()
{
     VECTOR a;
     cin >> a;
     cout << "Vector vua nhap: " << a;
     cout << "\nGTLN trong vector = " << ++a << endl;
     cout << "GTNN trong vector =" << --a << endl;
     return 0;
}
*/
// CAU 2

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class XE
{
protected:
    char mauson[10];
    char bienso[10];
    char noidki[15];
    int namdki;
public:

    XE();
    XE(char* ms,char* bs,char* noidk,int namdk);
    ~XE();
    void nhap();
    void xuat();
};
XE::XE()
{
    strcpy(mauson,"a");
    strcpy(bienso,"a");
    strcpy(noidki,"a");
    namdki = 1999;
}
XE::XE(char* ms,char* bs,char* noidk,int namdk)
{
    strcpy(mauson,ms);
    strcpy(bienso,bs);
    strcpy(noidki,noidk);
    namdki = namdk;
}
XE::~XE()
{
    delete this;
}
void XE::nhap()
{
    cout << "Mau son: " ; fflush(stdin) ; gets(mauson);
    cout << "Bien so: " ; fflush(stdin) ; gets(bienso);
    cout << "Noi dki: " ;fflush(stdin)  ; gets(noidki);
    cout  << "Nam dki: "; cin >> namdki;
}
void XE::xuat()
{
    cout << setw(10) << left << mauson << setw(10) << left << bienso << setw(15) << left << noidki << setw(10) << left << namdki ;

}
class CHUSOHUU : public XE
{
     char tenchu[15];
     char chungminhthu[15];
 public:
     CHUSOHUU();
     CHUSOHUU(char* ms,char* bs,char* noidk,int namdk,char* ht, char* cmt);
     ~CHUSOHUU();
     void nhap();
     void xuat();
     friend void in(CHUSOHUU a[],int n);
};
CHUSOHUU::CHUSOHUU()
{
    strcpy(mauson,"");
    strcpy(bienso,"");
    strcpy(noidki,"");
    namdki = 0;
    strcpy(tenchu,"");
    strcpy(chungminhthu,"");
}
CHUSOHUU::CHUSOHUU(char* ms,char* bs,char* noidk,int namdk,char* ht, char* cmt) : XE(ms,bs,noidk,namdk)
{
    strcpy(tenchu,ht);
    strcpy(chungminhthu,cmt);
}
CHUSOHUU::~CHUSOHUU()
{
    delete this;
}
void CHUSOHUU::nhap()
{
    XE::nhap();
    cout << "Ten chu so huu: " ; fflush(stdin) ; gets(tenchu);
    cout << "So cmt: " ; fflush(stdin) ; gets(chungminhthu);
}
void CHUSOHUU::xuat()
{
    XE::xuat();
    cout << setw(10) << left << tenchu << setw(10) << left << chungminhthu << endl;
}
void in(CHUSOHUU a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        if(strcmp(a[i].noidki,"ha noi")==0)
        {
            a[i].xuat();
        }
    }
}
int main()
{

    CHUSOHUU *ds;
    int k;
    cout << "NHap sl chu so huu = " ;
    cin >> k;
    ds = new CHUSOHUU[k];
    for(int i=0;i<k;i++)
    {
        cout << "Chu so huu thu " << i+1 << ":" << endl;
        ds[i].nhap();
    }
    cout << "Ds chu so huu" << endl;
     for(int i=0;i<k;i++)
    {
        ds[i].xuat();
    }
    cout << "Ds chu so huu noi dki o ha noi  " << endl;
    in(ds,k);

    return 0;
}
