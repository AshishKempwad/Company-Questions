#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   long int arr[n];
   int k;
   cin>>k;
   long int maxx=-1;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       maxx=max(maxx,arr[i]); 
   }
   long int c[100005];
   memset(c,-1,sizeof(c));
   long int count=0;
   long int maxi=-1;
   for(int i=0;i<n;i++){
     //  maxi=-1;
       if(arr[i]>k){
           for(int j=k;j<=maxx;j+=arr[i]){
               maxi=max(maxi,c[j]);
           }
       }
       count+=i-maxi;
       c[arr[i]]=i;
   }
   cout<<count<<endl;
   return 0;
}