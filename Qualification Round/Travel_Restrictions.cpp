#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
#define ll long long int

bool canTravel(ll src,ll dest,string inc,string out){
    if(out[src]=='Y' && inc[dest]=='Y') return true;
    return false;
}

void solve(){
    ll n,i,j;
    cin>>n;
    string inc,out;
    cin>>inc>>out;
    char **mat=new char*[n];
    for(i=0;i<n;i++){
        mat[i]=new char[n];
        for(j=0;j<n;j++){
            mat[i][j]='?';   
        }
    }
    for(i=0;i<n;i++){
        if(out[i]=='N'){
            for(j=0;j<n;j++){
                mat[i][j]='N';
            }
        }
        if(inc[i]=='N'){
            for(j=0;j<n;j++){
                mat[j][i]='N';
            }
        }
    }
    for(i=0;i<n;i++){
        ll index1=n+1,index2=-1;
        for(j=i+1;j<n;j++){
            if(mat[i][j]=='N'){
                index1=j+1;
                break;
            }
        }
        for(j=index1;j<n;j++){
            mat[i][j]='N';
        }
        for(j=i-1;j>=0;j--){
            if(mat[i][j]=='N'){
                index2=j-1;
            }
        }
        for(j=index2;j>=0;j--){
            mat[i][j]='N';
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(mat[i][j]=='?'){
                if(canTravel(j-1,j,inc,out)){
                    mat[i][j]='Y';
                }
                else{ 
                    mat[i][j]='N';
                    break;
                }
            }
            else break;
        }
    }
    //cout<<canTravel(1,0,inc,out)<<"\n";
    for(i=0;i<n;i++){
        for(j=i-1;j>=0;j--){
            if(mat[i][j]=='?'){
                if(canTravel(j+1,j,inc,out)){
                    mat[i][j]='Y';
                }
                else{ 
                    mat[i][j]='N';
                    break;
                }
            }
            else break;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) cout<<"Y";
            else if(mat[i][j]=='?') cout<<"N";
            else
                cout<<mat[i][j];
        }
        cout<<"\n";
    }
    return;
}

int main()
{
    fast;
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cout<<"Case #"<<T<<":\n";
        solve();
    }
    return 0;
}