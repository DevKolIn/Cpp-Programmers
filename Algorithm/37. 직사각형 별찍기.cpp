#include <iostream>

using namespace std;

int main(void) {
    int row;
    int col;
    cin >> col >> row;
   
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}