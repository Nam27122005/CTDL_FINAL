#include <iostream>
#include <vector>

using namespace std;

// Hàm sắp xếp nổi bọt có cờ hiệu (dừng sớm)
void noi_bot_co_co(vector<int>& a) {
    int n = a.size();
    bool da_doi_cho;
    for (int i = 0; i < n - 1; i++) {
        da_doi_cho = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                da_doi_cho = true;
            }
        }
        if (!da_doi_cho) {
            break; // Dừng sớm nếu không có sự đổi chỗ nào trong vòng lặp
        }
    }
}

// Hàm sắp xếp nổi bọt không cờ hiệu (chạy đủ số lượt)
void noi_bot_du_luot(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Hàm in vết từng bước sắp xếp
void lan_vet_noi_bot(vector<int> a) { // Truyền tham trị để không ảnh hưởng mảng gốc
    int n = a.size();
    bool da_doi_cho;
    cout << "Mang ban dau: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    
    for (int i = 0; i < n - 1; i++) {
        da_doi_cho = false;
        cout << "Luot " << i + 1 << ":" << endl;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                da_doi_cho = true;
            }
        }
        cout << "  Mang hien tai: ";
        for (int x : a) cout << x << " ";
        cout << endl;
        
        if (!da_doi_cho) {
            cout << "  Khong co su doi cho, dung thuat toan." << endl;
            break;
        }
    }
}

int main() {
    vector<int> a1 = {3, 1, 2};
    cout << "--- Vi du 1 ---" << endl;
    lan_vet_noi_bot(a1);
    return 0;
}