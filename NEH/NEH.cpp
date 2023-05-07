#include <iostream>
#include <fstream>

using namespace std;
int* weight(int* Table, int n, int m) {
    int* Weights = new int[n];
    for (int i = 0; i < n; i++) {
        Weights[i] = 0;
        for (int j = 0; j < m; j++) {
            Weights[i] += Table[i * m + j];
        }
    }
    return Weights;
}

int cmax(int* Table, int* Order, int n, int m) {
    int* C = new int[m*n];
    for (int i = 0; i < m*n; i++) {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {      
            if (i == 0 and j == 0) {
                C[i * m + j] = Table[(Order[i] * m + j)];
            }
            else if (i == 0) {
                C[i * m + j] = C[(i * m + j)-1] + Table[(Order[i] * m + j)];
            }
            else if (j == 0) {
                C[i * m + j] = C[((i-1) * m + j)] + Table[(Order[i] * m + j)];
            }else{
                C[i * m + j] = max(C[((i - 1) * m + j)], C[(i * m + j) - 1]) + Table[(Order[i] * m + j)];
            }
            
            //cout << i * m + j << "    " << C[i * m + j] << endl;
        }

    }
    return C[(m*n)-1];
}
int algorithm(int* Table, int* Order, int n, int m) {
    int* Weigths = weight(Table, n, m);

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
                //cout << Table[j * m + k] << " ";
            }
            //cout << endl;

        }
        cout << cmax(Table, Order, n, m) << endl;
        //int* weights = weight(Table, Order, n, m);
        //cout << algorithm(Table, Order, n, m) << endl;
        /*for (int j = 0;j < n;j++) {
            cout << weights[j] << endl;

        }*/
        delete[] Table;

    }
    f.close();
}
