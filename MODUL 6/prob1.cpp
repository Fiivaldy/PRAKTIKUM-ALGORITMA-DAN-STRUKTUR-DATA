#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> vertex(N);
    map<char, int> indexVertex;

    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
        indexVertex[vertex[i]] = i;
    }

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        char U, V;
        int W;

        cin >> U >> V >> W;

        int baris = indexVertex[U];
        int kolom = indexVertex[V];

        matrix[baris][kolom] = W;
    }

    cout << "Adjacency Matrix:" << endl;

    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << vertex[i];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << vertex[i];

        for (int j = 0; j < N; j++) {
            cout << " " << matrix[i][j];
        }

        cout << endl;
    }

    return 0;
}