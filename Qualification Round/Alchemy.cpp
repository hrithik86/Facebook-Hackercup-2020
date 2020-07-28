#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
#define ll long long int

void solve(){
    ll n,i=0,j=0;
    string a;
    cin>>n>>a;
    char s[n];
    while(i<n){
        while(j<3 && i<n){
            s[j]=a[i];
            j++;i++;
        }
        ll cnt1=0,cnt2=0;
        if(s[j-1]=='A') cnt1++;
        else cnt2++;
        if(s[j-2]=='A') cnt1++;
        else cnt2++;
        if(s[j-3]=='A') cnt1++;
        else cnt2++;
        if((cnt1==1 && cnt2==2) || (cnt1==2 && cnt2==1)){
            j-=2;
            if(cnt1>cnt2) s[j-1]='A';
            else s[j-1]='B';
        }
        else{
            if(i<n){
                s[j]=a[i];
                i++;j++;
            }
        }
    }
    if(j==1){
        cout<<"Y";
        return;
    }
    while(j>=3){
        ll cnt1=0,cnt2=0;
        if(s[j-1]=='A') cnt1++;
        else cnt2++;
        if(s[j-2]=='A') cnt1++;
        else cnt2++;
        if(s[j-3]=='A') cnt1++;
        else cnt2++;
        if((cnt1==1 && cnt2==2) || (cnt1==2 && cnt2==1)){
            j-=2;
            if(cnt1>cnt2) s[j-1]='A';
            else s[j-1]='B';
        }
        else break;
    }
    if(j==1){
        cout<<"Y";
    }
    else cout<<"N";
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("alchemy_input (1).txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    fast;
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cout<<"Case #"<<T<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}
