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

int dp[100005][5];
int n;
int fun(int mat[][3],int day,int curr){
   if(day==n) return 0;
   if(dp[day][curr]!=-1) return dp[day][curr];
   int maxx=0;
   if(curr==0){
      maxx=max(maxx,mat[day][1]+(fun(mat,day+1,1)));
      maxx=max(maxx,mat[day][2]+(fun(mat,day+1,2)));
      maxx=max(maxx,mat[day][3]+(fun(mat,day+1,3)));
   }
   else if(curr==3){
      maxx=max(maxx,mat[day][1]+(fun(mat,day+1,1)));
      maxx=max(maxx,mat[day][2]+(fun(mat,day+1,2)));
   }
   else if(curr==2){
      maxx=max(maxx,mat[day][1]+(fun(mat,day+1,1)));
      maxx=max(maxx,mat[day][3]+(fun(mat,day+1,3)));
   }
   else if(curr==1){
      maxx=max(maxx,mat[day][3]+(fun(mat,day+1,3)));
      maxx=max(maxx,mat[day][2]+(fun(mat,day+1,2)));
   }
   return dp[day][curr]=maxx;
}
void solve(){
   cin>>n;
   memset(dp,-1,sizeof(dp));
   int mat[n][3];
   for(int i=0;i<n;i++){
      for(int j=1;j<=3;j++){
         cin>>mat[i][j];
      }
   }
   cout<<fun(mat,0,0);

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
