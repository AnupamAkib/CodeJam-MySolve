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
    string s, ans;
    cin >> s;
    ans.clear();
    for(int i=1; i<=s[0]-'0'; i++){
        ans+='(';
    }
    ans+=s[0];
    for(int i=1; i<=s[0]-'0'; i++){
        ans+=')';
    }
    //print("ans = "<<ans);

    string tmp;
    int cnt=0, pos;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='0'){
            ans+=s[i];
            continue;
        }
        tmp.clear();
        cnt=0;
        for(int j=ans.size()-1; ; j--){
            if(ans[j]==')') cnt++;

            if(cnt == s[i]-'0'){
                pos = ans.size()-cnt;
                //cout << pos << endl;
                //print(s[i]);
                for(int q=1; q<=s[i]-'0'-cnt; q++){
                    //tmp+='(';
                    ans.insert(ans.begin()+pos, '(');
                    pos++;
                }
                //tmp+=s[i];
                ans.insert(ans.begin()+pos, s[i]);
                pos++;
                for(int q=1; q<=s[i]-'0'-cnt; q++){
                    //tmp+=')';
                    ans.insert(ans.begin()+pos, ')');
                    pos++;
                }

                //cout << tmp << endl;
                break;
            }
            else if(ans[j] == s[i-1]){
                pos = ans.size()-cnt;
                //print(s[i]);
                for(int q=1; q<=s[i]-'0'-cnt; q++){
                    //tmp+='(';
                    ans.insert(ans.begin()+pos, '(');
                    pos++;
                }
                //tmp+=s[i];
                ans.insert(ans.begin()+pos, s[i]);
                pos++;
                for(int q=1; q<=s[i]-'0'-cnt; q++){
                    //tmp+=')';
                    ans.insert(ans.begin()+pos, ')');
                    pos++;
                }
                break;
            }
        }
    }

    cout << "Case #" << t << ": " << ans << endl;
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



