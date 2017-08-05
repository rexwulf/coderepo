#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
  
int main() {
    for (int i = 0; i < 1e6; i++) {
        int a;
        cin >> a;
        cout << a << "\n";
    }	
    return 0;
}