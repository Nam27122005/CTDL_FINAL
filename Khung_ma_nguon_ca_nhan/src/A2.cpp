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

    cout << "  - Trang thai khoi tao: "; in_mang(a); cout << endl;

    for (int i = 0; i < n - 1; i++) {
        bool da_doi_cho = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                da_doi_cho = true;
            }
        }
        cout << "  - Sau luot i=" << i << ": "; in_mang(a); 
        cout << " | Co hoan doi: " << (da_doi_cho ? "True" : "False") << endl;
        
        if (!da_doi_cho) {
            cout << "  -> Kich hoat dung som vi mang da sap xep.\n";
            break;
        }
    }
    return a;
}

int main() {
    cout << "=== CHAY CA KIEM THU VD02 ===" << endl;
    cout << "Input: [1, 2, 3, 4]" << endl;
    cout << "Expected: [1, 2, 3, 4]" << endl;
    
    // Su khac biet cua VD02: Mang nay da duoc sap xep tang dan tu dau
    vector<int> input = {1, 2, 3, 4};
    cout << "Tien trinh thuat toan:" << endl;
    vector<int> actual = noi_bot_co_co_log(input);
    
    cout << "Actual: "; in_mang(actual); cout << endl;
    return 0;
}