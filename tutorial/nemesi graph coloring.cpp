#include <bits/stdc++.h>

using namespace std;

static int gruppi = 0;
static FILE *fr, *fw;

void nuovo_gruppo() {
	if (gruppi != 0) fprintf(fw, "\n");
	gruppi++;
}

void aggiungi(int bambino) {
	fprintf(fw, "%d ", bambino);
}

int fin(int N, vector<int> &colors, int m) {
	for(int i=1; i<=m; i++) {
		nuovo_gruppo();
		for(int j=0; j<N; j++) if(colors[j] == i) aggiungi(j);
	}
	return 0;
}

int bfs(int N, int m, vector<int> adj[], int visitato[], vector<int> &colors) {
	// return 0 if possible, 1 if not
	int maxColours = 1, n;
	for(int nodo = 0; nodo<N; nodo++) {
		// takes into account the fact that the graph might not be interconnected
		if(visitato[nodo] == 1) continue;

		visitato[nodo] = 1;
		queue<int> q;
		q.push(nodo);

		while(!q.empty()) {
			n = q.front();
			q.pop();

			for(int vicino: adj[n]) {
				// controllo che i vicini non abbiamo lo stesso colore
				if(colors[vicino] == colors[n]) {
					// se si, aumento di 1 il colore del vicino
					colors[vicino] += 1;
					maxColours = max(maxColours, colors[vicino]);	// controllo di non aver sforato m
					if(maxColours > m) return 1;
				}

				if(visitato[vicino] == 0) {
					q.push(vicino);
					visitato[vicino] = 1;
				}
			}
		}
	}
	return 0;
}

void smista(int N, int nemico[]) {
	// m-graph coloring. Dato ceh ogni bambino ha un nemico mortale, la colorazione del grafo può richiedere 
	// solo 2 o 3 colori. Provo con BFS entrambe le possibilità.

	// faccio il grafo
	vector<int> adj[N];
	for(int i=0; i<N; i++) {
		adj[i].push_back(nemico[i]);
		adj[nemico[i]].push_back(i);
	}
	int visitato[N] = { };
	vector<int> colors(N, 1);	// tengo per ciascun nodo un vettore che indica di che colore lo ho colorato

	if(bfs(N, 2, adj, visitato, colors) == 0)	// provo con due colori
		fin(N, colors, 2);
	else {
		// resetto tutte le variabili e provo con 3 colori
		int visitatoo[N] = { };
		vector<int> colorss(N, 1);
		bfs(N, 3, adj, visitatoo, colorss);
		fin(N, colorss, 3);
	} 

    return;
}


// Declaring variables
static int N;
static int* nemico;

// Declaring functions
void smista(int N, int* nemico);

int main() {
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");

	// Reading input
	fscanf(fr, "%d", &N);
	nemico = (int*)malloc(N * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, "%d", &nemico[i0]);
	}

	// Calling functions
	smista(N, nemico);

	// Writing output
	
	fclose(fr);
	fclose(fw);
	return 0;
}
