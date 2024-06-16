#include <iostream>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	int left = 0;
	int right = 1;
	int max_profit = 0;

	while (right < prices.size()) {
		if (prices[right] > prices[left]) {
			int profit = prices[right] - prices[left];
			max_profit = max(max_profit, profit);
		} else {
			left = right;
		}
		++right;
	}

	return max_profit;
}

int main(int argc, char* argv[]) {
	vector<int> prices = {7,1,5,3,6,4};
	int max_profit = maxProfit(prices);
	cout << max_profit << endl;
	return 0;
}
