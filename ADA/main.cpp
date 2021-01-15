#include <bits/stdc++.h>
/*#define printVec(v) for(auto x:v){cout<<x<<" ";}cout<<"\n";
#define printMat(m) for(auto x:m){printVec(x);}
#define printMap(m) for(auto x:m) {cout<<x.first<<"  "<<x.second<<"\n";}cout<<"\n";
#define printSet(s) for(auto x:s) {cout<<x<<" ";}cout<<"\n";*/
#define vec(v) v.begin(),v.end()
#define INF INT_MAX
using namespace std;
typedef long long ll;
int h[8]={2,1,-1,-2,-1,1,-2,2};
int v[8]={1,2,2,-1,-2,-2,1,-1};
bool Tenta(int n, int x, int y, vector<vector<int> > &ss,int i=1){
    int m=0;
    if(ss[x][y])return false;
    ss[x][y]=i;
    if(i==n*n)return true;
    while(m<8){
        int xn=x+h[m];
        int yn=y+v[m];
        if(xn<n && xn>=0 && yn<n && yn>=0){
          Tenta(n,xn,yn,ss,i+1);
        }
        m++;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector< vector<int> >nb(n,vector<int>(n,0));
    int x,y;
    cin>>x>>y;
    cout<<Tenta(n,x-1,y-1,nb,1)<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<nb[i][j]<<" ";
        }
        cout<<endl;
    }

}
