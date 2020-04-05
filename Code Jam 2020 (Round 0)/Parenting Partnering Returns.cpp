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
    vector<pair<int, int> > task, mem;
    map<int, int> mark;
    mark.clear();
    int n = input(), a, b;
    task.clear(); mem.clear();
    for(int i=0; i<n; i++){
        cin >> a >> b;
        task.push_back(make_pair(a, b));
    }
    mem = task;

    sort(ALL(task));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(task[j].first >= task[i].second){
                task.insert(task.begin()+i+1, task[j]);
                task.erase(task.begin()+j+1);
                break;
            }

        }
    }

    int cnt=0, pos=-1, same=0;
    for(int i=0; i<task.size()-1; i++){
        if(task[i+1].first - task[i].second < 0){
            cnt++;
            if(cnt==1) pos=i;
        }
    }

    bool flag = true;

    if(cnt>1){
        cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    }
    else{
        string ans(n, 'J');
        for(int i=0; i<=pos; i++){
            for(int j=0; j<n; j++){
                if(task[i] == mem[j]){
                    ans[j] = 'C';
                }
            }
        }
        for(int i=0; i<n; i++){
            if(mem[i].first == mem[i].second){
                mark[mem[i].first]++;
            }

            if(mark[mem[i].first] > 2){
                flag=false;
                break;
            }
        }
        if(!flag){
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            return;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(mem[i] == mem[j] && ans[i]==ans[j]){
                    if(ans[i]=='C') ans[i]='J';
                    else ans[i]='C';
                }
            }
        }

        //print("ok");
        cout << "Case #" << t << ": " << ans << endl;
    }

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




