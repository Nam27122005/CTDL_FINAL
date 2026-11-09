#include <iostream>
#include <vector>

using namespace std;

// Hàm trộn hai đoạn liên tiếp đã tăng
void tron(vector<int>& a, int l, int m, int r, int& so_sanh, bool trace) {
    vector<int> tam; // Mảng tạm để trộn
    int i = l;       // Con trỏ duyệt nửa trái
    int j = m + 1;   // Con trỏ duyệt nửa phải

    // So sánh và trộn hai nửa
    while (i <= m && j <= r) {
        so_sanh++; // Đếm phép so sánh phần tử
        // Ưu tiên phần tử bên trái khi bằng nhau để giữ tính ổn định
        if (a[i] <= a[j]) { 
            tam.push_back(a[i]);
            i++;
        } else {
            tam.push_back(a[j]);
            j++;
        }
    }

    // Chép phần còn lại của nửa trái (nếu còn)
    while (i <= m) {
        tam.push_back(a[i]);
        i++;
    }

    // Chép phần còn lại của nửa phải (nếu còn)
    while (j <= r) {
        tam.push_back(a[j]);
        j++;
    }

    // Chép mảng tạm trở về mảng gốc ở đúng đoạn [l..r]
    for (int k = 0; k < tam.size(); k++) {
        a[l + k] = tam[k];
    }

    // Yêu cầu: Khi n <= 8, in thêm kết quả sau mỗi phép trộn
    if (trace) {
        cout << "   -> Sau khi tron doan [" << l << ".." << r << "]: ";
        for (int k = l; k <= r; k++) cout << a[k] << " ";
        cout << endl;
    }
}

// Hàm đệ quy chia để trị
void sap_xep_tron(vector<int>& a, int l, int r, int& so_sanh, bool trace) {
    if (l >= r) return; // Dừng khi đoạn có không quá 1 phần tử

    int m = l + (r - l) / 2;
    
    // Gọi đệ quy chia hai nửa
    sap_xep_tron(a, l, m, so_sanh, trace);
    sap_xep_tron(a, m + 1, r, so_sanh, trace);
    
    // Trộn hai nửa lại
    tron(a, l, m, r, so_sanh, trace);
}

// Hàm kiểm tra mảng tăng dần
bool kiem_tra_tang(const vector<int>& a) {
    if (a.empty()) return true;
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i - 1] > a[i]) return false;
    }
    return true;
}

// Hàm tiện ích để in mảng
void in_mang(const vector<int>& a) {
    if (a.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << (i == a.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

// Hàm chạy từng ca kiểm thử
void chay_kiem_thu(string ten_ca, vector<int> input) {
    cout << "=== " << ten_ca << " ===" << endl;
    cout << "Input: "; in_mang(input); cout << endl;
    
    int n = input.size();
    int so_sanh = 0;
    bool trace = (n > 0 && n <= 8); // Chỉ lần vết nếu n <= 8 theo yêu cầu
    
    sap_xep_tron(input, 0, n - 1, so_sanh, trace);
    
    cout << "Ket qua: "; in_mang(input); cout << endl;
    cout << "So phep so sanh: " << so_sanh << endl;
    cout << "Kiem tra tinh tang dan: " << (kiem_tra_tang(input) ? "DUNG" : "SAI") << endl;
    cout << "--------------------------------------\n";
}

int main() {
    // 2 Ví dụ trên phiếu
    chay_kiem_thu("Vi du 1 (Mang 7 so ngau nhien)", {38, 27, 43, 3, 9, 82, 10});
    chay_kiem_thu("Vi du 2 (Giu gia tri bang nhau)", {2, 1, 2});

    // 5 Ca kiểm tra bắt buộc
    chay_kiem_thu("Ca 1 (Mang rong)", {});
    chay_kiem_thu("Ca 2 (Mang 1 phan tu)", {5});
    chay_kiem_thu("Ca 3 (Mang da tang san)", {1, 2, 3, 4});
    chay_kiem_thu("Ca 4 (Mang giam dan)", {4, 3, 2, 1});
    chay_kiem_thu("Ca 5 (Mang co phan tu trung, so am)", {0, -2, 0, -2});

    return 0;
}