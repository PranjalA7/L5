#include <iostream>
using namespace std;

void mat_multi(int a[10][10], int b[10][10], int mul[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
#pragma omp parallel for
        for (int j = 0; j < c; j++)
        {
            mul[i][j] = 0;
#pragma omp parallel for
            for (int k = 0; k < c; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void display_mat(int mul[10][10],int r,int c){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mul[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int a[10][10], b[10][10], mul[10][10], r, c, i, j, k;
    cout << "enter the number of row: ";
    cin >> r;
    cout << "enter the number of column: ";
    cin >> c;
    cout << "enter the first matrix element=\n";
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "enter the second matrix element=\n";
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> b[i][j];
        }
    }
    cout << "multiply of the matrix=\n";
    mat_multi(a,b,mul,r,c);
    display_mat(mul,r,c);
    return 0;
}
