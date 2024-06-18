#include <iostream>
#include <cstdlib>

using namespace std;

int sqrt(int x) {
	int left = 1, right = x, result = 0;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (middle * middle == x) {
			return middle;
		} else if (middle * middle > x) {
			right = middle - 1;
		} else if (middle * middle < x){
			left = middle + 1;
			result = middle;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	int result = (argc != 2)? sqrt(17) : sqrt(atoi(argv[1]));
	cout << result << endl;
	return 0;
}
