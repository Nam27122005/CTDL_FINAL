#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Hàm validator kiểm tra chuỗi nhập có hợp lệ là các số nguyên hay không
bool kiem_tra_hop_le_chuoi(const string& input_str, vector<int>& out_arr) {
    stringstream ss(input_str);
    string token;
    out_arr.clear();
    
    while (ss >> token) {
        try {
            size_t pos;
            int val = stoi(token, &pos);
            // Nếu còn ký tự thừa sau số (ví dụ: 12abc) -> không hợp lệ
            if (pos != token.length()) {
                return false;
            }
            out_arr.push_back(val);
        } catch (...) {
            // Lỗi ép kiểu (ví dụ: "abc") -> từ chối
            return false;
        }
    }
    return true;
}

int main() {
    cout << "=== CHAY CA KIEM THU LOI01 (Input sai dinh dang) ===\n";
    string invalid_input = "1 2 abc 4";
    cout << "Input chuoi: \"" << invalid_input << "\"\n";
    cout << "Expected: Validator tu choi, tra ve false\n";
    
    vector<int> parsed_arr;
    bool is_valid = kiem_tra_hop_le_chuoi(invalid_input, parsed_arr);
    
    cout << "Actual: Validator tra ve = " << (is_valid ? "true (Chap nhan)" : "false (Tu choi)") << "\n";
    if (!is_valid) {
        cout << "  -> THONG BAO LOI: Du lieu dau vào chua ky tu khong hop le! Da chan thanh cong.\n";
    }
    return 0;
}