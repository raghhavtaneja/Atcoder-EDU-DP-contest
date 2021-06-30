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

int solving(vector<int>a,int n){
   vector<int> dp(n+1);
   dp[0]=0;
   dp[1]=0;
   for(int i=2;i<=n;i++){
      int op1=abs(a[i]-a[i-1])+dp[i-1];
      int op2=i!=2?abs(a[i]-a[i-2])+dp[i-2]:INT_MAX;
      dp[i]=min(op1,op2);
   }
   return dp[n];
}

void solve(){
   int n;
   cin>>n;
   vi a(n+1);
   for(int i=1;i<=n;i++) cin>>a[i];
   cout<<solving(a,n);
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
