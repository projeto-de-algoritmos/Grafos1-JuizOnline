#include <iostream>

using namespace std;

int main()
{

    int r = 0;
    int c = 0;
    int grafo[61][201];
    int copia[61][201];
    int aux[61][201];
    int valor = 0;
    cin >> r >> c;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grafo[i][j];
            copia[i][j] = grafo[i][j];
        }
    }
    copia[0][0] = grafo[0][0];
    copia[0][1] = grafo[0][1];
    copia[0][2] = grafo[0][2];
    int j = 0;
    for (int i = 1; i < c; i++)
    {
        if (grafo[i][0] == copia[i - 1][0])
        {
            if (grafo[i][2] < copia[i - 1][2])
            {
                aux[j][2] = grafo[i][2];
            }
        }
        else
            j++;
    }

    for (int j = 0; j < r; j++)
    {
        valor += aux[j][2];
        // cout << copia[i][2] << endl;
    }
    cout << valor << endl;
    return 0;
}