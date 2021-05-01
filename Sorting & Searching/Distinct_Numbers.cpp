//Date of submission: 22-06-2020
 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
const double E= 1e-9;
 
//------------------------------------------------------------------------------
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*ifstream cin("input.txt");
    ofstream cout("output.txt");*/
    int n;
    cin>>n;
    set<int> s;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size();
    return 0;
}
 
//------------------------------------------------------------------------------
