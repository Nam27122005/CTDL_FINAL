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
    if (n <= 1) return a;
    for (int i = 0; i < n - 1; i++) {
        bool da_doi_cho = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) { swap(a[j], a[j+1]); da_doi_cho = true; }
        }
        cout << "  - Sau luot i=" << i << ": "; in_mang(a); cout << "\n";
        if (!da_doi_cho) { cout << "  -> Kich hoat dung som.\n"; break; }
    }
    return a;
}

int main() {
    cout << "=== CHAY CA KIEM THU TK01 (Mang giam dan) ===\n";
    cout << "Input: [5, 4, 3, 2, 1]\nExpected: [1, 2, 3, 4, 5]\n";
    vector<int> input = {5, 4, 3, 2, 1};
    vector<int> actual = noi_bot_co_co_log(input);
    cout << "Actual: "; in_mang(actual); cout << "\n";
    return 0;
}