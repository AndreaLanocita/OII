#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

struct pt {
    ll x, y;
    pt(ll x, ll y): x(x), y(y) {};
};
// cout
ostream& operator <<(ostream& out, pt A) {
    out << "{" << A.x << ", " << A.y << "}";
    return out;
}

pt operator +(pt A, pt B) { return {A.x+B.x, A.y+B.y};}
pt operator -(pt A, pt B) { return {A.x-B.x, A.y-B.y};}
ll operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x;}

int main() {
    
    return 0;
}