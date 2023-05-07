#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

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
void order_by_weights(int* Order, int* Weights,int n) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++) {
            if (Weights[j] < Weights[j + 1]) {
                swap(Weights[j], Weights[j + 1]);
                swap(Order[j], Order[j + 1]);
            }
        }
    }
    delete[] Weights;
}
int cmax(int* Table, vector <int> Order, int n, int m,int* C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){      
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
    
    int* C = new int[m * n];
    int* Weigths = weight(Table, n, m);
    order_by_weights(Order, Weigths, n);
    vector <int> TempOrder;
    /*for (int i = 0; i < n; i++) {
        cout << Order[i] << "  ";
    }
    cout << endl;*/
    for (int i = 0; i < n; i++) {
        int position = 0;
        int Cmax = 999999999;

        TempOrder.push_back(Order[i]);
        for (int j = i; j >= 0; j--) {
            int c = cmax(Table, TempOrder, i+1, m, C);
            if (c <= Cmax) {
                Cmax = c;
                position = j;
            }
            /*cout << "In iteration: " << i << "  " << j << " -> ";
            for (int k = 0;k <= i;k++) {
                cout << TempOrder[k] << "  ";
            }
            cout << endl;*/
            if (j != 0) {
                swap(TempOrder[j - 1], TempOrder[j]);
            }
        }
        for (int j = 0; j < position; j++) {
            swap(TempOrder[j], TempOrder[j + 1]);
        }
        /*cout << "After iteration: " << i << " -> ";
        for (int j = 0;j <= i;j++) {
            cout << TempOrder[j] << "  ";
        }
        cout << endl;*/
       
    }
    for (int i = 0; i < n; i++) {
        Order[i] = TempOrder[i];
    }

    return cmax(Table,TempOrder,n,m,C);

}
int main()
{   
    auto start = chrono::high_resolution_clock::now();
    int n, m;
    ifstream f("data.txt");
    for (int i = 0; i < 121; i++) {
        string s;
        while (s.find("data") == string::npos) {
            f >> s;
            if (s.find("data") != string::npos) {
                cout << s << "  ";
            }

        }
        f >> n;
        f >> m;
        //cout << n << " " << m << endl;
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

        /*cout << cmax(Table, Order, n, m) << endl << endl;
        int* Weights = weight(Table, n, m);
        for (int j = 0;j < n;j++) {
            cout << Weights[j] << endl;

        }
        order_by_weights(Order, Weights, n);
        for (int j = 0;j < n;j++) {
            cout << Weights[j] << endl;

        }*/
        //cout << endl << cmax(Table, Order, n, m) << endl << endl;
        cout << algorithm(Table, Order, n, m) << endl;
        /*for (int j = 0;j < n;j++) {
            cout << Order[j] << endl;

        }*/
        delete[] Table;
        delete[] Order;

    }
    f.close();
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    cout << fixed << time_taken << setprecision(9) << " seconds";
}
