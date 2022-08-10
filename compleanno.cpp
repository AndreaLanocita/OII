#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define INF INT_MAX

void aggiungi();
void copia();
void incolla();

// ha senso moltiplicare le emoji solo per questi numeri
// quindi io prendo qualsiasi sequenza di emoji e posso moltiplicarla per questi
vector<int> mul{2, 3, 4, 5, 7, 11, 13, 17, 19, 23};

pair<long long int, long long int> ric(long long n, unordered_map<long long int, pair<long long int, long long int>> &ans) {
    // caso base
    if(n<6) {
		ans[n] = {n, n-1};
		return ans[n];
	} 

    // ho già il risultato
    if(ans.count(n) == 1) return ans[n];

    // calcolo
    for(int j=0; j<mul.size() && mul[j]<=n; j++) {		// dato che ogni volta tengo conto del caso in cui aggiungo 1 a quello prima, devo controllare solo i copia-incolla
        ric(n/mul[j], ans);
		// resti
        if(ans.count(n) == 0 || ans[n/mul[j]].first + n%mul[j] + 1 + mul[j] < ans[n].first) {
            ans[n] = make_pair(ans[n/mul[j]].first + n%mul[j] + 1 + mul[j], n/mul[j]);
        }
    }
	return ans[n];
}

void auguri(long long int N) {
	stack<pair<int, long long int>> ordine;  // op, n op
	// numero di click e precedente
	unordered_map<long long int, pair<long long int, long long int>> ans;
	for(int i=1; i<=6; i++) ans[i] = {i, i-1};
	ric(N, ans);

	long long int i = N, counter = 0;
	while(i!=0) {
		if(i - ans[i].second == 1) {
			counter++;
			i--;
			continue;
		} 

		if(counter != 0) ordine.push(make_pair(0, counter));
		counter = 0;

		// aggiungo i resti
		if(i%ans[i].second!=0)ordine.push(make_pair(0, i%ans[i].second));

		// aggiungo l'incolla
		ordine.push(make_pair(1, i/ans[i].second-1));	// incolla
		i = ans[i].second;
	}
	if(counter!=0) ordine.push(make_pair(0, counter));

	// print
	while(!ordine.empty()) {
		if(ordine.top().first == 0) {
			for(long long int i=ordine.top().second; i!=0; i--) aggiungi();
		} 
		else if(ordine.top().first == 1) {
			copia();
			for(long long int i=ordine.top().second; i!=0; i--) incolla();
		} 
		ordine.pop();
	}
}


static int click = 0;
static long long int emoji = 0;
static long long int clipboard = 0;

void auguri(long long int N);

void aggiungi() {
    click += 1;
    emoji += 1;
}

void copia() {
    click += 2;
    clipboard = emoji;
}

void incolla() {
    if (clipboard == 0) {
        fprintf(stderr, "Attenzione: non ha senso chiamare 'incolla' senza aver prima chiamato 'copia'.\n");
    }

    click += 1;
    emoji += clipboard;
}

int main() {
    long long int N;
    scanf("%lld", &N);

    auguri(N);

    if (emoji != N) {
        fprintf(stderr, "Attenzione: il messaggio costruito ha %lld emoji invece che %lld.\n", emoji, N);
    }

    printf("%d\n", click);
}