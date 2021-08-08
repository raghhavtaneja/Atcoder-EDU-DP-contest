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

int dp[102][100005];

int fun(int n,int w,int val[],int wt[]){
   if(n==0 || w==0) return 0;
   if(dp[n][w]!=-1) return dp[n][w];
   if(wt[n-1]<=w){
      dp[n][w]=max(val[n-1]+fun(n-1,w-wt[n-1],val,wt),fun(n-1,w,val,wt));
   }
   else dp[n][w]=fun(n-1,w,val,wt);
   return dp[n][w];
}
void solve(){
   memset(dp,-1,sizeof(dp));
   int N,W;
   cin>>N>>W;
   int val[N],wt[N];
   for(int i=0;i<N;i++){
      cin>>wt[i]>>val[i];
   }
   cout<<fun(N,W,val,wt);
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
