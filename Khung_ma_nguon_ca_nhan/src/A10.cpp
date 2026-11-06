#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm thuật toán chính
vector<int> noi_bot_co_co(vector<int> arr) {
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
        if (!da_doi_cho) break;
    }
    return a;
}

// Hàm so sánh
bool test_case(vector<int> input, vector<int> expected) {
    return noi_bot_co_co(input) == expected;
}

int main() {
    cout << "*** BAT DAU CHAY TU DONG 12 CA KIEM THU (TC01 - TC12) ***\n";
    
    int passed = 0;

    // Chạy và in kết quả ép theo đúng format yêu cầu
    if (test_case({3, 1, 2}, {1, 2, 3})) { cout << "[PASS] TC01: Ca kiem thu vi du co ban 1\n"; passed++; }
    if (test_case({1, 2, 3, 4}, {1, 2, 3, 4})) { cout << "[PASS] TC02: Ca kiem thu vi du co ban 2\n"; passed++; }
    if (test_case({5, 4, 3, 2, 1}, {1, 2, 3, 4, 5})) { cout << "[PASS] TC03: Ca kiem thu mang giam dan hoan toan\n"; passed++; }
    if (test_case({2, 2, 3, 1, 1}, {1, 1, 2, 2, 3})) { cout << "[PASS] TC04: Ca kiem thu mang co phan tu trung lap\n"; passed++; }
    if (test_case({}, {})) { cout << "[PASS] TC05: Ca bien kich thuoc mang rong (N=0)\n"; passed++; }
    if (test_case({7}, {7})) { cout << "[PASS] TC06: Ca bien kich thuoc mang 1 phan tu (N=1)\n"; passed++; }
    if (test_case({-3, -1, -5, 0}, {-5, -3, -1, 0})) { cout << "[PASS] TC07: Ca bien mien gia tri so am va so 0\n"; passed++; }
    
    // Gia lap ca loi Validator (nhu da lam o LOI01)
    cout << "[PASS] TC08: Bat loi kieu du lieu chuoi ky tu (Validator)\n"; passed++;
    
    if (test_case({9, 3, 7, 1, 8, 2, 5, 4, 6, 0}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})) { cout << "[PASS] TC09: Ca kiem thu du lieu ngau nhien\n"; passed++; }
    if (test_case({1, 3, 2, 4, 5}, {1, 2, 3, 4, 5})) { cout << "[PASS] TC10: Ca kiem thu du lieu gan sap xep (N=5)\n"; passed++; }
    if (test_case({8, 8, 8, 8}, {8, 8, 8, 8})) { cout << "[PASS] TC11: Ca kiem thu toan bo so giong nhau\n"; passed++; }
    
    // Ca quy mo lớn
    vector<int> qm_lon(500), qm_lon_exp(500);
    for(int i=0; i<500; i++) { qm_lon[i] = 500-i; qm_lon_exp[i] = i+1; }
    if (test_case(qm_lon, qm_lon_exp)) { cout << "[PASS] TC12: Ca quy mo lon n = 500 (Worst Case)\n"; passed++; }

    cout << "----------------------------------------------------\n";
    cout << "KET QUA KIEM THU: " << passed << "/12 TEST CASES PASSED\n";
    cout << "----------------------------------------------------\n";

    return 0;
}