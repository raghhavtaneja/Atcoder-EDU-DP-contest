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



void solve(){
   string s,t;
   cin>>s>>t;
   int n1=s.length();
   int n2=t.length();
   int dp[n1+1][n2+1];
   for(int i=0;i<=n2;i++){
      dp[0][i]=0;
   }
   for(int i=0;i<=n1;i++){
      dp[i][0]=0;
   }
   for(int i=1;i<=n1;i++){
      for(int j=1;j<=n2;j++){
         if(s[i-1]==t[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
         }
         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
   }

   int len=dp[n1][n2];
   string ans="";
   if(len==0){
      cout<<ans;
      return;
   }
   int i=n1,j=n2;
   while(i>0 && j>0){
      if(s[i-1]==t[j-1]){
         ans+=s[i-1];
         i--;
         j--;
      }
      else if(dp[i-1][j]>dp[i][j-1]){
         i--;
      }
      else{
         j--;
      }
   }
   reverse(all(ans));
   cout<<ans<<endl;

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
