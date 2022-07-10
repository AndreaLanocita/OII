#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;

  char griglia[n][n];
  pair<char, int> arr[n][n];
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin>>griglia[i][j];
    }
  }
  arr[0][0].first = 't';
  arr[0][0].second = 0;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (i == 0 && j == 0) continue;
      if (griglia[i][j] == '#') arr[i][j].second = -1;
      else{
        //non andrà nessuno
        arr[i][j].second = -1;
        //dall'alto
        if (arr[i-1][j].second != -1 && i != 0){
          arr[i][j].first = 'a';
          arr[i][j].second = arr[i-1][j].second;
          //se arriva da sinistra aggiungi una torre
          if (arr[i-1][j].first == 's') arr[i][j].second++;
        }
        //da sinistra
        //se sinistra non è # ed è minore di quello dall'alto (altrimenti non potrebbe migliorare e non avrebbe senso)
        if(arr[i][j-1].second != -1 && (arr[i][j-1].second < arr[i][j].second || arr[i][j].second == -1) && j != 0){
            arr[i][j].first = 's';
            arr[i][j].second = arr[i][j-1].second;
            if (arr[i][j-1].first == 'a') arr[i][j].second++;
        }
      }
    }
  }

  cout << arr[n-1][n-1].second;

} 