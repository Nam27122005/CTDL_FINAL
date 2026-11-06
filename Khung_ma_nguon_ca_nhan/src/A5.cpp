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
    // ... logic sap xep (khong the chay den day) ...
    return a;
}

int main() {
    cout << "=== CHAY CA KIEM THU BIEN01 (Mang rong) ===\n";
    cout << "Input: []\nExpected: []\n";
    vector<int> input = {};
    vector<int> actual = noi_bot_co_co_log(input);
    cout << "Actual: "; in_mang(actual); cout << "\n";
    return 0;
}