#include <bits/stdc++.h>

using namespace std;

#define N  2000010
#define ll long long
#define fs first
#define sc second
#define ii pair<int,int>
#define pb push_back
#define iii pair<int,pair<int,int>>
#define ld long double
#define getbit(x,y) ((x>>y)&1)
#define matrix vector<vector<ll>>
#define getid(x,y) (x*2-1-y)
#define S 500001

long double A, B, C, D;

int main()
{
    cout<<"Nhap tu so va mau so cua phan so thu 1\n";
    cin>>A>>B;
    cout<<"Nhap tu so va mau so cua phan so thu 2\n";
    cin>>C>>D;
    cout<<"Tong "<<A/B + C/D<<endl;
    cout<<"Hieu "<<A/B - C/D<<endl;
    cout<<"Tich "<<(A/B) * (C/D)<<endl;
    cout<<"Thuong "<<(A/B) / (C/D)<<endl;
    return 0;
}
