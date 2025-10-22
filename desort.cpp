#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=0;
for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]){
        flag=1;//already desorted
    }
}
int min_diff=a[1]-a[0];
if(flag==0){
for(int i=0;i<n-1;i++){
    if(a[i+1]-a[i]<min_diff){
min_diff=a[i+1]-a[i];}
}
}
if(flag==1){
    cout<<"0\n";
}else{
    cout<<(min_diff/2)+1<<endl;
}
}
    return 0;
}
