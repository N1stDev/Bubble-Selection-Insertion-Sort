#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> vec = { 1, 10, -29, 0, 14, -32, 100, -32, 0 };
	int n = vec.size();
	int tmp, key = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if ((vec[i] > vec[j]) && (vec[i] <= vec[j+1])) {
				vec.emplace(vec.begin() + j + 1, vec[i]);
				vec.erase(vec.begin() + i + 1);
				key = 1;
				break;
			}
		}
		if (key == 0) {
			vec.emplace(vec.begin(), vec[i]);
			vec.erase(vec.begin() + i + 1);
		}
		key = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}

	return 0;
}