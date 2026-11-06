#include <iostream>
#include <vector>

using namespace std;

void in_mang(const vector<int>& a) {
    cout << "[";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i < a.size() - 1 ? ", " : "");
    }
    cout << "]";
}

vector<int> noi_bot_co_co_log(vector<int> arr) {
    vector<int> a = arr;
    int n = a.size();
    if (n <= 1) return a;

    for (int i = 0; i < n - 1; i++) {
        bool da_doi_cho = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                da_doi_cho = true;
            }
        }
        cout << "  - Sau luot i=" << i << ": "; in_mang(a); cout << "\n";
        if (!da_doi_cho) {
            cout << "  -> Kich hoat dung som.\n";
            break;
        }
    }
    return a;
}

int main() {
    cout << "=== CHAY CA KIEM THU BIEN03 (Mang so am va so 0) ===\n";
    cout << "Input: [-3, -1, -5, 0]\n";
    cout << "Expected: [-5, -3, -1, 0]\n";
    
    vector<int> input = {-3, -1, -5, 0};
    cout << "Tien trinh thuat toan:\n";
    vector<int> actual = noi_bot_co_co_log(input);
    
    cout << "Actual: "; in_mang(actual); cout << "\n";
    return 0;
}