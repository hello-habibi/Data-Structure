#include <iostream>
using namespace std;
int count =0;
void solve(int n, char from, char to, char aux) {
    if (n == 0) {
        return;
    }
    solve(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;count++;
    solve(n - 1, aux, to, from);
}

int main() {
    int n = 1; 
    solve(n, 'A', 'B', 'C');
    cout<<count<<endl;
    return 0;
}
