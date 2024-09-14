#include <bits/stdc++.h>
using namespace std;
//This is not the optimal solution
//we have to use dp[n+1][sum+1];
//here dp[i][j] means with i elements can we make it up sum j;
//dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];if(j>a[i]);
//i.e, if we can make sum j with i elements either by including it or not;
// if we include it then we should make it up sum j-a[i] by i-1 elements;
// here a[i]<j if > then only chance is to make the sum with i-1 elements;
int main(){
    //enter n,sum
    //n integers.
    long long int sum,n;
    cin>>n>>sum;
    vector <long long int > v;
    long long int a[n];
    long long int totalsum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        totalsum+=a[i];
    }
    int ans=0;
    vector <int > w(n,0);
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
        if(a[i]==sum||a[i]==totalsum-sum)ans=1;
    }
    for(int i=1;i<n;i++){
        v.push_back(v[0]+v[i]);
        if(v[0]+v[i]==sum||v[0]+v[i]==totalsum-sum)ans=1;
        w.push_back(i+1);
    }
    int start=n,end=v.size();
    while(start<end){
        for(int i=start;i<end;i++){
            for(int j=w[i];j<n;j++){
                v.push_back(v[i]+v[j]);
                if(v[i]+v[j]==sum||v[i]+v[j]==totalsum-sum)ans=1;
                w.push_back(j+1);
            }
        }
        start=end;end=v.size();
    }
    if(ans==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}