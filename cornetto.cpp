#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int Mat[N][M];
    pair<int, int> P, B, S;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // 0 non passo, 1 passo, 2 S
            char a;
            cin >> a;
            if (a == 'P')
            {
                P = {i, j};
                Mat[i][j] = 1;
            }
            if (a == 'B')
            {
                B = {i, j};
                Mat[i][j] = 1;
            }
            if (a == '#')
                Mat[i][j] = 0;
            if (a == '.')
                Mat[i][j] = 1;
            if (a == 'S')
                Mat[i][j] = 2;
        }
    }

    // calcolo percorso a piedi
    queue<pair<int, int>> q;
    q.push(P);
    int visitato[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visitato[i][j] = 0;
        }
    }

    int distanze[N][M];
    visitato[P.first][P.second] = 1;
    distanze[P.first][P.second] = 0;

    int flagS = 0;
    while (!q.empty())
    {
        pair<int, int> n = q.front();
        q.pop();
        if (n.first == B.first && n.second == B.second)
            break;

        if (n.first + 1 < N && visitato[n.first + 1][n.second] == 0 && Mat[n.first + 1][n.second] != 0)
        {
            visitato[n.first + 1][n.second] = 1;
            if (Mat[n.first + 1][n.second] == 2 && flagS == 0)
            {
                flagS = 1;
                S = {n.first + 1, n.second};
            }
            q.push({n.first + 1, n.second});
            distanze[n.first + 1][n.second] = distanze[n.first][n.second] + 1;
        }
        if (n.first - 1 >= 0 && visitato[n.first - 1][n.second] == 0 && Mat[n.first - 1][n.second] != 0)
        {
            visitato[n.first - 1][n.second] = 1;
            if (Mat[n.first - 1][n.second] == 2 && flagS == 0)
            {
                flagS = 1;
                S = {n.first - 1, n.second};
            }
            q.push({n.first - 1, n.second});
            distanze[n.first - 1][n.second] = distanze[n.first][n.second] + 1;
        }
        if (n.second + 1 < M && visitato[n.first][n.second + 1] == 0 && Mat[n.first][n.second + 1] != 0)
        {
            visitato[n.first][n.second + 1] = 1;
            if (Mat[n.first][n.second + 1] == 2 && flagS == 0)
            {
                flagS = 1;
                S = {n.first, n.second + 1};
            }
            q.push({n.first, n.second + 1});
            distanze[n.first][n.second + 1] = distanze[n.first][n.second] + 1;
        }
        if (n.second - 1 >= 0 && visitato[n.first][n.second - 1] == 0 && Mat[n.first][n.second - 1] != 0)
        {
            visitato[n.first][n.second - 1] = 1;
            if (Mat[n.first][n.second - 1] == 2 && flagS == 0)
            {
                flagS = 1;
                S = {n.first, n.second - 1};
            }
            q.push({n.first, n.second - 1});
            distanze[n.first][n.second - 1] = distanze[n.first][n.second] + 1;
        }
    }

    if (flagS == 0 && visitato[B.first][B.second] != 0)
    {
        cout << distanze[B.first][B.second] << endl;
        return 0;
    }

    // trovo S più vicino a B
    queue<pair<int, int>> q1;
    q1.push({B.first, B.second});
    int visitato1[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            visitato1[i][j] = 0;
    }
    int distanze1[N][M];
    distanze1[B.first][B.second] = 0;
    pair<int, int> S1;
    int flagS1=0;

    while (!q1.empty())
    {
        pair<int, int> n = q1.front();
        q1.pop();
        if (Mat[n.first][n.second] == 2)
        {
            S1.first = n.first;
            S1.second = n.second;
            flagS1=1;
            break;
        }

        if (n.first + 1 < N && visitato1[n.first + 1][n.second] == 0 && Mat[n.first + 1][n.second] != 0)
        {
            visitato1[n.first + 1][n.second] = 1;
            q1.push({n.first + 1, n.second});
            distanze1[n.first + 1][n.second] = distanze1[n.first][n.second] + 1;
        }
        if (n.first - 1 >= 0 && visitato1[n.first - 1][n.second] == 0 && Mat[n.first - 1][n.second] != 0)
        {
            visitato1[n.first - 1][n.second] = 1;
            q1.push({n.first - 1, n.second});
            distanze1[n.first - 1][n.second] = distanze1[n.first][n.second] + 1;
        }
        if (n.second + 1 < M && visitato1[n.first][n.second + 1] == 0 && Mat[n.first][n.second + 1] != 0)
        {
            visitato1[n.first][n.second + 1] = 1;
            q1.push({n.first, n.second + 1});
            distanze1[n.first][n.second + 1] = distanze1[n.first][n.second] + 1;
        }
        if (n.second - 1 >= 0 && visitato1[n.first][n.second - 1] == 0 && Mat[n.first][n.second - 1] != 0)
        {
            visitato1[n.first][n.second - 1] = 1;
            q1.push({n.first, n.second - 1});
            distanze1[n.first][n.second - 1] = distanze1[n.first][n.second] + 1;
        }
    }
    int j;
    if(visitato[B.first][B.second]==0 && (flagS==0 || flagS1==0)) cout << -1;
    else if(flagS==0 || flagS1==0) cout << distanze[B.first][B.second] << endl; // se non trovo una delle S
    else if(visitato[B.first][B.second]==0) cout << distanze[S.first][S.second]+distanze1[S1.first][S1.second] << endl;
    else cout << min(distanze[B.first][B.second], distanze[S.first][S.second]+distanze1[S1.first][S1.second]) << endl;;
    return 0;
}