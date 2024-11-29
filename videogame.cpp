<<<<<<< HEAD
=======
// NOTE: it is recommended to use this even if you don't understand the following code.

>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
=======
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

>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
	
<<<<<<< HEAD
	long long  T;
	cin >> T;
	
    long long  N;
    cin >> N;
	
	vector<long long > A(N), B(N);
	vector<pair<long long , long long >> iniziotu;
	vector<pair<long long , long long >> inizioamico;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		iniziotu.push_back({A[i], B[i]});
	}
	
	long long  M;
	cin >> M;
	
	vector<long long > X(M), Y(M);
	for (int i = 0; i < M; i++) {
		cin >> X[i] >> Y[i];
		inizioamico.push_back({X[i], Y[i]});
	}
	sort(inizioamico.begin(), inizioamico.end());
	sort(iniziotu.begin(), iniziotu.end());

    // insert your code here
	long long res = 0;
	long long pt = 0, pa = 0;
	while(pa < inizioamico.size() && pt < iniziotu.size()) {
		int flag = 0;

		// l'amico finisce prima che io inizi
		while(pa < inizioamico.size() && pt < iniziotu.size() && inizioamico[pa].second < iniziotu[pt].first) pa++;
		if(pa >= inizioamico.size() || pt >= iniziotu.size()) break;

		// tu finisci prima che l'amico inizi
		while(pt < iniziotu.size() && min(iniziotu[pt].first+T, iniziotu[pt].second) < inizioamico[pa].first) {	
			pt++;
			flag = 1;
		} 
		if(pt >= iniziotu.size()) break;
		if(flag==1) continue;


		if(inizioamico[pa].first > iniziotu[pt].first) {	// amico inizia dopo di te e 
			if(iniziotu[pt].second > inizioamico[pa].second) {	// finisco dopo amico
				res += (inizioamico[pa].second - inizioamico[pa].first+1);
				pa++;
			} else {
				res += (iniziotu[pt].second - inizioamico[pa].first+1);
				pt++;
			}
		}

		// inizi dopo tu (o uguale)
		else {
			if(iniziotu[pt].second > inizioamico[pa].second) {
				res += (inizioamico[pa].second - iniziotu[pt].first+1);
				pa++;
			} else {
				res += (iniziotu[pt].second - iniziotu[pt].first+1);
				pt++;
			}
			
=======
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
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
		}
	}

    cout << res << endl; // print the result
    return 0;
}
