#include <iostream>
#include <math.h>

using namespace std;

long long comparisons_equation(int n) {
	long long comparisons = 0;
	for (int k = 1; k <= n; k++)
		comparisons += ceil(log2(3 * k / 4.0));
	return comparisons;
}


int main() {

	for(size_t n = 1; n < 30 ; n++)
  		cout << "# of comparisons for n: " << n << " is: " << comparisons_equation(n) << endl;
  return 0;
}
