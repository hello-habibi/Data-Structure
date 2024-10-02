#include <iostream>
using namespace std;

int a[10][10][10];
int b[10][10];
int path[10][10];

void matrix_multiplication(m)
{
    for (int p = 2; p <= ; P++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int temp = 0;
                for (int k = i; k <= m; k++)
                {
                    temp = temp + a[1][i][k] * a[p - 1][k][j];
                }
                a[p][i][j] = temp;
            }
        }
    }
}
void show_matrix(int m)
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << a[m][i][j] << " ";
        }  
        cout << endl;
    }
}

int main()
{

    return 0;
}