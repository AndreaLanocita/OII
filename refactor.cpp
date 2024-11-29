/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

using namespace std;

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

// constraints
#define MAXL 1000000

// input data
char identifier[MAXL+1];

int main() {
//  uncomment the following lines if you want to read/write from files
    // freopen("C:\\repos\\c++\\github\\OII\\input1.txt", "r", stdin);
    // freopen("output3.txt", "w", stdout);

    assert(1 == scanf("%s", identifier));
    int numerocaratteri = 0;
    while(identifier[numerocaratteri] != '\000') {
        numerocaratteri++;
    }    
    char c;
    bool stringa = false;
    bool commento1 = false; bool commento2 = false; bool stringa2 = false;
    int counter = 0;
    int a = 0; int b = 0; int d = 0;
    int n = -1; // diventa 0 quando c'è carattere che puo precedere
    while ((c = getchar()) != EOF) {
        if(stringa) {   // forse anche singolo trattino?
            if(c== '\n') {
                stringa = false;
                commento1 = false;
            }
            else if(c == '"') {
                stringa = false;
                n = 0;
            } 
            continue;
        }
        if(stringa2) {
            if(c== '\n') {
                stringa2 = false;
                commento1 = false;
            }
            else if(c == '\'') {
                stringa2 = false;
                n = 0;
            } 
            continue;
        }
        if(commento1) {
            if(c=='\n') {
                n = 0;
                commento1 = false;
            } 
            continue;
        }
        if(commento2) {
            if((a==0) && c=='*') a = 1;
            if((a==1) && c=='/') {
                n = 0;
                commento2 = false;
                a = 0;
            }
            continue;
        }
        if(a==1) a=0;
        // apertura
        if(c=='"') {
            stringa = true;
            continue;
        } 
        if(c=='\'') {
            stringa2 = true;
            continue;
        } 
        if(c=='/') {
            if(b==0) {
                b=1;
                if(d==0) d = 1;
                continue;
            } 
            if(c=='/' && b == 1) {
                b=0;
                commento1 = true;
                continue;
            }
            if(d==0) d = 1;
            continue;
        }
        if(b==1) b = 0;
        if(c=='*' && d==1) {
            d = 0;
            commento2 = true;
            continue;
        }
        if(d==1) d = 0;

        // se per qualche motivo arriva qui

        if(n==-1) {
            if(c!='_' && (c<65 || (90 < c && c<97) || c > 122)) n = 0;
        } 
        else {
            if(c==identifier[n]) n++;
            else if(n==numerocaratteri && (c!='_' && (c<65 || (90 < c && c<97) || c > 122) && (n<48 || n>57))) {
                counter++;
                n = 0;
            } 
            else if(!(c!='_' && (c<65 || (90 < c && c<97) || c > 122))) n = -1;
        }
    }
    printf("%d\n", counter); // print the result
    return 0;
}
