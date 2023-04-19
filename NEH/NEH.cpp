#include <iostream>
#include <fstream>

using namespace std;
int weight(int *table,int x,int n, int m) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += table[i * m + x];
    }
    return result;
}
int cmax() {

}
int algorithm(int* table, int n, int m) {

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
        int* table = new int[m * n];
        for (int j = 0;j < m * n;j++) {
            f >> table[j];
        }
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < m;k++) {
                cout << table[j * m + k] << " ";
            }
            cout << endl;
            
        }
        cout << algorithm(table, n, m) << endl;
        delete[] table;

    }
    f.close();
}
