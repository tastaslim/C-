#include <iostream>
using namespace std;
int product(int a, int b)
{
   if (b == 1)
      return a;
   return a + product(a, b - 1);
}

int main()
{
   int a, b;
   cin >> a >> b;
   int ans = product(a, b);
   cout << ans << endl;
   return 0;
}
