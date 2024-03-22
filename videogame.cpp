// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<long long, long long>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
	
	ll T;
	cin >> T;
	
    ll N;
    cin >> N;
	
	vector<ll> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	
	ll M;
	cin >> M;
	
	vector<ll> X(M), Y(M);
	for (int i = 0; i < M; i++) {
		cin >> X[i] >> Y[i];
	}

    vp tu(N), amico(M);
	for (int i = 0; i < N; i++) tu[i] = {A[i], B[i]};
	for (int i = 0; i < M; i++) amico[i] = {X[i], Y[i]};
	sort(tu.begin(), tu.end());
	sort(amico.begin(), amico.end());

	ll pt=0, pa=0, res=0, flag=0;	// pt = tuo puntatore; pa = puntatore amico
	while(1) {
		// casi da non considerare --> devo mandare avanti uno dei due puntatori
		flag=0;
		// tu inizi troppo tardi
		while(pa<M && tu[pt].first > amico[pa].second) pa++;
		if(pa>=M) break;

		// il tuo amico inizia troppo tardi
		while(pt<N && amico[pa].first > min(tu[pt].second, tu[pt].first+T)) {
			pt++;
			flag=1;
		} 
		if(pt>=N) break;
		if(flag==1) continue;	// potrei aver mandato avanti entrambi i puntatori, ricomincio

		// casi da considerare --> update res e mando avanti puntatore di chi finisce prima di giocare
		// inizi prima tu
		if(tu[pt].first <= amico[pa].first) {
			// finisci prima tu
			if(tu[pt].second <= amico[pa].second) {
				res+=(tu[pt].second+1-amico[pa].first);
				pt++;
			}
			// finisce prima l'amico
			else {
				res+=(amico[pa].second+1-amico[pa].first);

				// se finisce prima l'amico, potrei perdere interesse e andarmente prima che ritorni
				tu[pt].first = amico[pa].second+1;

				pa++;
			}
		}
		// inizia prima il tuo amico
		else if(amico[pa].first < tu[pt].first) {
			// finisci prima tu
			if(tu[pt].second <= amico[pa].second) {
				res+=(tu[pt].second+1-tu[pt].first);
				pt++;
			}
			// finisce prima l'amico
			else {
				res+=(amico[pa].second+1-tu[pt].first);

				// se finisce prima l'amico, potrei perdere interesse e andarmente prima che ritorni
				tu[pt].first = amico[pa].second+1;

				pa++;
			}
		}
	}

    cout << res << endl; // print the result
    return 0;
}
