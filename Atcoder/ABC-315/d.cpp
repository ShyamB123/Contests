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



void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n][m];

    set<int> x,y;
    // vector<int>
    int hor[n][26];
    int vert[m][26];

    memset(hor,0,sizeof(hor));
    memset(vert,0,sizeof(vert));


    for(int i =0;i<n;i++)
    {
        for(int j =0 ;j<m;j++)
        {
            cin>>a[i][j];
            hor[i][a[i][j] - 'a']++;
            vert[j][a[i][j] - 'a']++;
        }
    }
    for(int i =0;i<n;i++)
    {
        x.insert(i);
    }

    for(int i =0;i<m;i++)
    {
        y.insert(i);
    }

    bool ok = true;

    while(ok)
    {
        set<char> ch;
        vii xrmv;
        vii yrmv;

        ok = false;
        for(auto it : x)
        {
            int count = 0;
            int poss = 0;
            int val;
            for(int k = 0;k<26;k++)
            {
                if(hor[it][k] > 0)
                {
                    poss++;
                    val = k;
                    count += hor[it][k];
                }
            }
            if(poss == 1 && count > 1)
            {
                // hor[it][val] = 0;
                // for(int j=0;j<m;j++)
                // {
                //     if(a[it][j] != '.')
                //         vert[j][val]--;

                //     a[it][j] = '.' ;  
                // }
                xrmv.pb({it,val});
            }
        }



        for(auto it : y)
        {
            int count = 0;
            int poss = 0;
            int val;
            for(int k = 0;k<26;k++)
            {
                if(vert[it][k] > 0)
                {
                    poss++;
                    val = k;
                    count += vert[it][k];
                }
            }
            if(poss == 1 && count > 1)
            {
                // vert[it][val] = 0;
                // for(int i=0;i<n;i++)
                // {
                //     if(a[i][it] != '.')
                //         hor[i][val]--;
                //     a[i][it] = '.' ;  
                // }
                yrmv.pb({it,val});
            }
        }


        for(auto it : xrmv)
        {
            ok = true;
            x.erase(it.F);
            int val = it.S;
            hor[it.F][val] = 0;
            for(int j=0;j<m;j++)
            {
                if(a[it.F][j] != '.')
                    vert[j][val]--;

                a[it.F][j] = '.' ;  
            }
            
            // for(int j =0;j<m;j++)
            // {
            //     a[it][j] = '.';
            // }
        }
        for(auto it : yrmv)
        {
            ok = true;
            y.erase(it.F);
            int val = it.S;
            vert[it.F][val] = 0;
            for(int i=0;i<n;i++)
            {
                if(a[i][it.F] != '.')
                    hor[i][val]--;
                a[i][it.F] = '.' ;  
            }
            // for(int i =0;i<n;i++)
            // {
            //     a[i][it] = '.';
            // }
        }
    }   

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(a[i][j] != '.')
                ans++;
        }
    }

    cout << ans <<nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}