
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class CONGDAN
{
protected:
    char sothecc[15];
    char hovaten[15];
    int namsinh;
    char gioitinh[10];
public:
    void nhap();
    void xuat();
};
void CONGDAN::nhap()
{
    cout << "So the can cuoc: " ; fflush(stdin) ; gets(sothecc);
    cout << "Ho va ten: "  ; fflush(stdin) ; gets(hovaten);
    cout << "Nam sinh: " ; cin >> namsinh;
    cout << "Gioi Tinh: " ; fflush(stdin) ; gets(gioitinh);
}
void CONGDAN::xuat()
{
    cout << setw(10) << left << sothecc << setw(10) << left << hovaten << setw(10) << left << namsinh << setw(10) << left << gioitinh ;
}
class CANBO : public CONGDAN
{
    float hesoluong;
    int tienphucap;
public:
    void nhap();
    void xuat();
    friend void in(CANBO ds[],int n);
};
void CANBO::nhap()
{
    CONGDAN::nhap();
    cout << "He so luong: " ; cin >> hesoluong;
    cout << "Phu cap: " ; cin >> tienphucap ;
}
void CANBO::xuat()
{
    CONGDAN::xuat();
    cout << setw(10)<< left << hesoluong << setw(10)<< left << tienphucap << setw(15)<< left << (int) nam(hesoluong*1390000+tienphucap) << endl;
}
void in(CANBO ds[],int n)
{
    int k = 0;
    cout << setw(10) << left << "sothecc" << setw(10) << left << "ho va ten" << setw(10) << left << "nam sinh" << setw(10) << left << "gioi tinh" << setw(10)<< left << "he so luong" << setw(10)<< left << "tien phu cap" << setw(10)<< left << "Thu nhap" << endl;
    for(int i=0;i<n;i++)
    {
        if(ds[i].hesoluong*1390000+ds[i].tienphucap >= 10000000 && strcmp(ds[i].gioitinh,"nam") == 0)
        {
             ds[i].xuat();
             k = 1;
        }
    }
    if(k == 0) cout << "Khong co can bo nam nao co thu nhap tu 10tr tro len " ;
}
int main()
{
    int n;

    cout << "n = " ; cin >> n;
    CANBO ds[n];
    for(int i=0;i<n;i++)
    {
        ds[i].nhap();
    }
    cout << "Ds can bo nam thu nhap tren 10 trieu " << endl;
    in(ds,n);
    return 0;
}

/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PHANSO
{
    int tuso;
    int mauso;
public:
    PHANSO();
    void nhap();
    void operator--();
    friend ostream& operator<<(ostream& x, PHANSO y);
};
PHANSO::PHANSO()
{
    tuso = 0;
    mauso = 1;
}
void PHANSO::nhap()
{
    cout << "tu so = " ; cin >> tuso;
    cout << "mau so = "; cin  >> mauso;
}
void PHANSO::operator--()
{
    if(tuso == mauso)
    {
        tuso = 1;
        mauso = 1;
    }else if(tuso > mauso){
        for(int i=mauso;i>=2;i--)
        {
            if(tuso %i== 0 && mauso%i==0)
            {
                tuso = tuso/i;
                mauso = mauso/i;
            }
        }
    }else{
        for(int i=tuso;i>=2;i--)
        {
            if(tuso %i== 0 && mauso%i==0)
            {
                tuso = tuso/i;
                mauso = mauso/i;
            }
        }
    }
}
ostream& operator<<(ostream& x, PHANSO y)
{
    x << y.tuso <<"/" << y.mauso ;
    return x;
}
int main()
{
    PHANSO a;
    a.nhap();
    cout << "Phan so vua nhap:" << a;
    --a;
    cout << "\n Phan so sau khi toi gIAN: " << a;
    return 0;
}
*/
