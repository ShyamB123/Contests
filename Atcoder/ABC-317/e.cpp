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

    for(int i=0 ;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    vector<vector<int>> marked(n,vector<int>(m,0));
    // right
    for(int i =0;i<n;i++)
    {
        bool ok = false;

        for(int j =0;j<m;j++)
        {
            if(a[i][j] == '>')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;
                j++;
                ok = true;
            }
            while(ok == true && j < m && a[i][j] == '.')
            {
                marked[i][j] = 1;
                // a[i][j] = '#';
                j++;
            }
            if(ok == true && j < m)
                j--;
            ok = false;
        }
    }

    // left
    for(int i =0;i<n;i++)
    {
        bool ok = false;

        for(int j =m-1;j>=0;j--)
        {
            if(a[i][j] == '<')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;
                j--;

                ok = true;
            }
            while(ok == true && j >= 0 && a[i][j] == '.')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;

                j--;
            }
            if(ok == true && j >=0)
                j++;
            ok = false;
        }
    }

    // down
    for(int j =0;j<m;j++)
    {
        bool ok = false;

        for(int i =0;i<n;i++)
        {
            if(a[i][j] == 'v')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;

                i++;

                ok = true;
            }
            while(ok == true && i < n && a[i][j] == '.')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;

                i++;
            }
            if(ok == true && i < n)
                i--;
            ok = false;
        }
    }

    // up
    for(int j =0;j<m;j++)
    {
        bool ok = false;

        for(int i =n-1;i>=0;i--)
        {
            if(a[i][j] == '^')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;

                i--;
                ok = true;
            }
            while(ok == true && i >= 0 && a[i][j] == '.')
            {
                // a[i][j] = '#';
                marked[i][j] = 1;

                i--;
            }
            if(ok == true && i >= 0)
                i++;
            ok = false;
        }
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(marked[i][j] == 1)
            {
                a[i][j] = '#';
            }
        }
    }

    int xs,ys;

    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(a[i][j] == 'S')
            {
                xs = i;
                ys = j;
                break;
            }
        }
    }   
    queue<vi> q;

    q.push({xs,ys,0});

    vector<vector<bool>> visited(n,vector<bool>(m,false));
    visited[xs][ys] = true;

    // n s e w
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty())
    {
        auto el = q.front();
        q.pop();

        int x = el[0];
        int y = el[1];
        int dist = el[2];

        if(a[x][y] == 'G')
        {
            cout << dist <<nl;
            return;
        }

        for(int i =0;i<4;i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(newx < n && newx >= 0 && newy < m && newy >= 0 && visited[newx][newy] == false && a[newx][newy] != '#')
            {
                vi temp;
                visited[newx][newy] = true;
                temp = {newx,newy,dist + 1};
                q.push(temp);
            }
        }
    }

    cout << -1 <<nl;


}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}