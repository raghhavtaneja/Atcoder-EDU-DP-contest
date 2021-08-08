#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
#define int long long int
#define toggle(x) x=!x
#define inf 1e9
#define mod 1000000007
//VECTOR
#define vi std::vector<int>
#define vc std::vector<char>
#define vl std::vector<long long>
#define pb push_back
//PAIR
#define pi pair<int,int>
#define mp make_pair
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
 
int gcd(int a,int b){
   if(b==0) return a;
   return gcd(b,a%b);
}
int lcm(int a,int b){
   return a*b/gcd(a,b);
}
 
#define mem(a,b) memset((a),(b),sizeof(a))
 

 void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
} 

int dp[100005];
int n,k;

int fun(int ind,vector<int>&arr){
   if(ind==n-1){
      return 0;
   }
   if(dp[ind]!=-1) return dp[ind];
   int cost=INT_MAX;
   for(int i=ind+1;i<min(n,ind+k+1);i++){
      cost=min(cost,abs(arr[i]-arr[ind])+fun(i,arr));
   }
   return dp[ind]=cost;
}
void solve(){
   cin>>n>>k;
   vector<int> arr(n);
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++) cin>>arr[i];
   int ans=fun(0,arr);
   cout<<ans;
}


int32_t main(){
   init_code();
  
   int t=1;
   // cin>>t;
   while(t--){
      solve();
   }

   return 0;
}
