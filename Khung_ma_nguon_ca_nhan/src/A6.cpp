#include <iostream>
#include <vector>
using namespace std;

void in_mang(const vector<int>& a) {
    cout << "[";
    for (size_t i = 0; i < a.size(); ++i) cout << a[i] << (i < a.size() - 1 ? ", " : "");
    cout << "]";
}

vector<int> noi_bot_co_co_log(vector<int> arr) {
    vector<int> a = arr;
    int n = a.size();
    if (n <= 1) {
        cout << "  -> Mang rong hoac co 1 phan tu. Tra ve luon.\n";
        return a;
    }
    return a;
}

int main() {
    cout << "=== CHAY CA KIEM THU BIEN02 (Mang 1 phan tu) ===\n";
    cout << "Input: [7]\nExpected: [7]\n";
    vector<int> input = {7};
    vector<int> actual = noi_bot_co_co_log(input);
    cout << "Actual: "; in_mang(actual); cout << "\n";
    return 0;
}