#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int, int>>
#define vll vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define nl '\n'

using namespace std;

//----------------------DEBUGGER----------------------------------------------------------
#define dbg(x) cout << #x <<" "; _print(x); cout << endl;
 
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

 
template <class T> void _print(vector<vector<T>> v) {for(int j =0;j<v.size();j++){cout <<nl<<"[ "; for (T i : v[j]){_print(i); cout << " ";} cout << "]";};}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.F); cout << ","; _print(p.S); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>void _print(vector<vector<vector<T>>> v){for(int k =0;k<v.size();k++){_print(v[k]);}}
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/


string r,s;
int n;
char a[5][5];
bool fullok;

bool check()
{
    string rcur,scur;
    for(int i= 0;i<n;i++)
    {
        for(int j =0 ;j<n;j++)
        {
            if(a[i][j] != '.')
            {
                rcur +=a[i][j];
                break;
            }
        }
    }

    for(int i= 0;i<n;i++)
    {
        for(int j =0 ;j<n;j++)
        {
            if(a[j][i] != '.')
            {
                scur +=a[j][i];
                break;
            }
        }
    }

    if(scur == s && rcur == r)
    {
        return true;
    }
    else
        return false;
}


void perm(int row,vector<set<int>> &col)
{
    if(fullok == true)
        return;
    if(row >= n)
    {
        bool ok = check();
        fullok = ok;
        if(ok == true)
        {
            cout <<"Yes"<<nl;
            for(int i =0 ;i<n;i++)
            {
                for(int j =0;j<n;j++)
                    cout << a[i][j];
                cout <<nl;
            }
        }
        return;
    }
    auto temp = col;

    for(auto aindx : col[0])
    {
        for(auto b : col[1])
        {
            if(b == aindx)
                continue;
            
            for(auto c : col[2])
            {
                if(c == aindx || c == b)
                    continue;
                
                a[row][aindx] = 'A';
                a[row][b] = 'B';
                a[row][c] = 'C';

                bool ok = true;
                temp[0].erase(aindx);
                temp[1].erase(b);
                temp[2].erase(c);

                perm(row + 1,temp);

                a[row][aindx] = '.';
                a[row][b] = '.';
                a[row][c] = '.';

                temp[0].insert(aindx);
                temp[1].insert(b);
                temp[2].insert(c);

            }

        }
    }
}


void solve()
{
    cin>>n;
    cin>>r>>s;

    vector<set<int>> v(n);
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            a[i][j] = '.';
            v[i].insert(j);
        }
    }
    
    perm(0,v);
    if(fullok == false)
    {
        cout <<"No"<<nl;
    }

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}