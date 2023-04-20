#include <iostream>
#include <fstream>

using namespace std;
int* weight(int* Table, int* Order, int n, int m) {
    int* Weights = new int[n];
    for (int i = 0; i < n; i++) {
        Weights[i] = 0;
        for (int j = 0; j < m; j++) {
            Weights[i] += Table[i * m + j];
        }
    }
    return Weights;
}
void sort(int* Order, int* Weights, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (Weights[j] < Weights[j + 1]){
                swap(Weights[j], Weights[j + 1]);
                swap(Order[j], Order[j + 1]);
            }
        }
    }
}
int cmax(int* Table, int* Order, int n, int m) {
    int* C = new int[m];
    for (int i = 0; i <= m; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            C[i] = max(C[j], C[j - 1]) + Table[(j - 1) + Order[i] * m];
        }
    }
    return C[m];
}
int algorithm(int* Table, int* Order, int n, int m) {
    return 1;
}
int main()
{
    int n, m;
    ifstream f("data.txt");
    for (int i = 0; i < 1; i++) {
        string s;
        while (s.find("data") == string::npos) {
            f >> s;
            if (s.find("data") != string::npos) {
                cout << s << endl;
            }
         
        }
        f >> n;
        f >> m;
        cout << n << " " << m << endl;
        int* Table = new int[m * n];
        int* Order = new int[n];
        for (int j = 0;j < m * n;j++) {
            f >> Table[j];
        }
        for (int j = 0;j < n;j++) {
            Order[j] = j;
        }
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < m;k++) {
                cout << Table[j * m + k] << " ";
            }
            cout << endl;
            
        }
        cout << algorithm(Table, Order, n, m) << endl;
        weight(Table, Order, n, m);
        delete[] Table;

    }
    f.close();
}
