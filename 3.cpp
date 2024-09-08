#include <iostream>
#include <vector>
using namespace std;
int getMaxToys(const vector<int>& prices, int money) {
    int n = prices.size();
    int start = 0, end = 0;
    int current_sum = 0, max_toys = 0;
    while (end < n) {
        current_sum += prices[end]; 
        while (current_sum > money) {
            current_sum -= prices[start];
            start++;
        }
        max_toys = max(max_toys, end - start + 1);
        end++;
    }
    return max_toys;
}
int main() {
    vector<int> prices = {1, 4, 5, 3, 2, 1, 6};
    int money = 6;
    int result = getMaxToys(prices, money);
    cout << "Maximum number of toys that can be purchased: " << result << endl;
    return 0;
}
