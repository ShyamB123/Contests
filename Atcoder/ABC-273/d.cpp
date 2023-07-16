#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*
5 5 2 4
3
1 5
2 2
1 4
4
L 2
U 3
U 2
R 4

*/



void solve()
{
    int h,w;
    cin>>h>>w;


    int sx,sy;
    cin>>sx>>sy;
    sx--;
    sy--;

    int n;
    cin>>n;

    map<int,vector<int>> hor;
    map<int,vector<int>> vert;

    for(int i =0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        hor[x].pb(y);
        vert[y].pb(x);
    }

    for(auto &it : hor)
    {
        sort(all(it.second));
        it.second.pb(INT_MAX);
    }
    for(auto &it : vert)
    {
        sort(all(it.second));
        it.second.pb(INT_MAX);
    }

    // dbg(hor);
    // dbg(vert);

    vector<pair<char,int>> v;

    int q;
    cin>>q;

    int curx = sx;
    int cury = sy;


    for(int i=0;i<q;i++)
    {
        char dir;
        int dist;
        cin>>dir>>dist;


        if(dir == 'L')
        {
            if(hor.find(curx) != hor.end())
            {
                int indx = lower_bound(all(hor[curx]),cury) - hor[curx].begin() - 1;
                if(indx == -1)
                {
                    // no walls
                    cury = max(0,cury - dist);
                }
                else
                {
                    int wall = hor[curx][indx];
                    cury = max(wall + 1,cury - dist);
                }
                // dbg(cury);
            }
            else
            {
                cury = max(0,cury - dist);
            }
        }
        else if(dir == 'R')
        {
            if(hor.find(curx) != hor.end())
            {
                int indx = lower_bound(all(hor[curx]),cury) - hor[curx].begin();
                if(hor[curx][indx] == INT_MAX)
                {
                    // no walls
                    cury = min(w-1,cury + dist);
                }
                else
                {
                    int wall = hor[curx][indx];
                    cury = min(wall - 1,cury + dist);
                }
                // dbg(cury);
            }
            else
            {
                cury = min(w-1,cury + dist);
            }
        }
        else if(dir == 'U')
        {
            if(vert.find(cury) != vert.end())
            {
                int indx = lower_bound(all(vert[cury]),curx) - vert[cury].begin() - 1;
                if(indx == -1)
                {
                    // no walls
                    curx = max(0,curx - dist);
                }
                else
                {
                    int wall = vert[cury][indx];
                    curx = max(wall + 1,curx - dist);
                }
                // dbg(cury);
            }
            else
            {
                curx = max(0,curx - dist);
            }
        }
        else if(dir == 'D')
        {
            if(vert.find(cury) != vert.end())
            {
                int indx = lower_bound(all(vert[cury]),curx) - vert[cury].begin();
                if(vert[cury][indx] == INT_MAX)
                {
                    // no walls
                    curx = min(h-1,curx + dist);
                }
                else
                {
                    int wall = vert[cury][indx];
                    curx = min(wall - 1,curx + dist);
                }
                // dbg(cury);
            }
            else
            {
                curx = min(h-1,curx + dist);
            }
        }
        cout << curx + 1<<" "<<cury + 1<<nl;
    }

    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}