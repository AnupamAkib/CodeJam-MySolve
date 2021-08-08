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
#define printcase(c, n) cout << "Case #" << c << ": " << n <<endl
#define printcaseii(c, n, m) cout << "Case " << c << ": " << n << " " << m <<endl
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
lli input(){lli x; cin >> x; return x;}
void display(int ar[], int first, int last){for(int i=first; i<last; i++){cout << ar[i] << " ";}cout<<endl;}
void display(vector<string> ar, int first, int last){for(int i=first; i<last; i++){cout << ar[i] << " ";}cout<<endl;}


void solve(int tc){
    //partially solved
    int n = input();
    string s, max_left="";
    vector<string> v;
    while(n--){
        cin >> s;
        v.pb(s);
        if(s.size() > max_left.size()) max_left = s;
    }
    //display(v, 0, v.size());

    bool flag = true;
    for(int i=0; i<v.size(); i++){
        int k=v[i].size()-1;
        int q=max_left.size()-1;
        while(1){
            if(v[i][k] == '*' || max_left[q] == '*') break;
            if(v[i][k] != max_left[q]){
                flag=false;
                break;
            }
            k--; q--;
        }
        if(!flag) break;
    }

    if(flag){
        max_left[0]='X';
        printcase(tc, max_left);
    }
    else{
        printcase(tc, '*');
    }

}


int main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc = input();
    for(int i=1; i<=tc; i++){
        solve(i);
    }

    return 0;
}





