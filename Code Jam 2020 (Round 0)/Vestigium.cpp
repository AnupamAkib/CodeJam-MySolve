/*BISMILLAHIR RAHMANIR RAHIM*/
#include<bits/stdc++.h>
#define lli long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ALL(x) x.begin(), x.end()
#define print(x) cout<<x<<endl
#define pb(x) push_back(x)
#define cases(x, y) for(int x=1; x<=y; x++)
#define PI acos(-1.0)
#define maxiii(a, b, c) max(max(a, b), c)
#define miniii(a, b, c) min(min(a, b), c)
#define printcase(c, n) cout << "Case " << c << ": " << n <<endl;
#define printcaseii(c, n, m) cout << "Case " << c << ": " << n << " " << m <<endl;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
lli input(){lli x; cin >> x; return x;}
void display(int ar[], int first, int last){for(int i=first; i<last; i++){cout << ar[i] << " ";}cout<<endl;}
void display(vector<int> ar, int first, int last){for(int i=first; i<last; i++){cout << ar[i] << " ";}cout<<endl;}


void solve(int t){
    map<int, int> row;
    map<int, map<int, int> > col;
    map<int, bool> flag2;
    row.clear(); col.clear(); flag2.clear();

    int n = input(), trace = 0, r=0, c=0;
    int a[n+2][n+2], k;
    for(int i=0; i<n; i++){
        row.clear();
        bool flag1 = true;
        for(int j=0; j<n; j++){
            cin >> k;
            if(i==j) trace+=k;
            if(flag1) row[k]++;
            if(flag2[j]==false) col[j][k]++;

            if(row[k]>1 && flag1){
                r++;
                flag1=false;
            }
            if(col[j][k]>1 && !flag2[j]){
                c++;
                flag2[j]=true;
            }
        }

    }
    cout << "Case #" << t << ": " << trace << " " << r  << " " << c << endl;
}


int main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*===========================================================================================*/

    int tc = input();
    for(int i=1; i<=tc; i++){
        solve(i);
    }

    /*===========================================================================================*/

    return 0;
}



