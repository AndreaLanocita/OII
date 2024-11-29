#include <bits/stdc++.h>
using namespace std;

int chiedi(int K);
void rispondi(string S);

void indovina(int N){
  vector<pair<int, char>> v(N);
  int r=N-1;  // prima era N-1
  int p=(N*(N+1))/2;

  // in v teniamo il numero di sottostringhe che iniziamo con l'iesima lettera
  while(r>0){
    int t=chiedi(p);
    v[r--].first = t;
    p-=t;
  }

  // calcolo l'ultima lettera, non serve chiedere
  v[0].first = p;

  // cambio i caratteri seguendo l'alfabeto
  for(int i=0; i<N; i++) v[i].second = 97+i;

  // riordino il vettore secondo il numero di sottostringhe per lettera
  // otterrò la parola in ordine inverso
  sort(v.begin(), v.end());

  string risposta;
  for(int i=N-1; i>=0; i--) risposta.push_back(v[i].second);

  rispondi(risposta);
  return ;
}

// grader

static int chiamate = 0;
static string str;
static vector<string> sub;

int chiedi(int K) {
  chiamate++;
  return sub[K - 1].size();
}

void rispondi(string out) {
  if (out == str) {
    cout << "Risposta corretta: " << chiamate << " chiamate eseguite" << endl;
  } else {
    cout << "Risposta sbagliata" << endl;
  }
  exit(0);
}

int main() {
  // se preferisci leggere e scrivere da file
  // ti basta decommentare le seguenti due righe:

  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int N;
  cin >> N >> str;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      sub.push_back(str.substr(i, j - i));
    }
  }
  sort(sub.begin(), sub.end());

  indovina(N);

  cout << "Risposta non fornita" << endl;

  return 0;
}
