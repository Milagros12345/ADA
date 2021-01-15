#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N=3;
const int INF=1000000;
int monedas[N]={1,3,5};
int memo[100001];
int cambio(int valor){
    if(valor<0) return INF;
    if(valor==0) return 0;
    if(memo[valor]!=-1)return memo[valor];
    int res=INF;
    for(int i=0;i<N;i++){
        res=min(res,cambio(valor-monedas[i]));
    }
    return memo[valor]=res+1;
}
void LCS(char *x,char *y,int xn,int yn ){

    int M[xn][yn];
    for(int i=0;i<xn;i++)
        M[i][0]=0;
    for(int j=0;j<yn;j++)
        M[0][j]=0;
    for(int i=1;i<xn;i++){
        for(int j=1;j<yn;j++){
            if(x[i]==y[j])
                M[i][j]=M[i-1][j-1]+1;
            else
                M[i][j]=max(M[i][j-1],M[i-1][j]);
        }
    }
    for(int i=0;i<xn;i++){
        for(int j=0;j<yn;j++)
            cout<<M[i][j]<<"  ";
        cout<<endl;
    }
}
int backtrack(int M[][8],char x[],char y[],int i,int j){
    if(i==0 || j==0) return 0;
    if(x[i]==y[j])
        return backtrack(M,x,y,i-1,j-1)+x[i];
    if(M[i][j-1]>M[i-1][j])
        return backtrack(M,x,y,i-1,j);
    return backtrack(M,x,y,i-1,j);
}
int main()
{
    memset(memo,-1,sizeof memo);
    int valor=7;
    for(int i=0;i<=valor;i++){
        cout<<i<<"= "<<cambio(i)<<endl;
    }
    char Y[]={' ','m','z','j','a','w','x','u'};
    char X[]={' ','x','m','j','y','a','u','z'};
    int M[8][8];
    LCS(X,Y,8,8);
    //backtrack(M,X,Y,8,8);//error

    return 0;
}
