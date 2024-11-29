#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
	
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
			
		}
	}

    cout << res << endl; // print the result
    return 0;
}
