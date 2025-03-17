#include <bits/stdc++.h>

using namespace std;

const double TOL = 1e-9; // Ngưỡng sai số
const int MAX_ITER = 10000; // Số lần lặp tối đa

vector<double> jacobiMethod(const vector<vector<double>>& A, const vector<double>& b, vector<double> X_old) {
    int n = A.size();
    vector<double> X(n, 0.0);

    for (int k = 0; k < MAX_ITER; ++k) {
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * X_old[j];
                }
            }
            X[i] = (b[i] - sigma) / A[i][i];
        }

        // Kiểm tra hội tụ
        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += abs(X[i] - X_old[i]);
        }
        if (error < TOL) {
            cout << "Phương pháp hội tụ sau " << k + 1 << " lần lặp.\n";
            return X;
        }

        X_old = X; // Cập nhật nghiệm cũ
    }

    cout << "Chua hoi tu!\n";
    return X;
}

int main() {
    ifstream file("data/matrix_100.txt");
    
    if (!file) {
        cout << "File khong ton!\n";
        return 0;
    }

    int n;
    file >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x0(n, 1.0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> A[i][j];
        }
        file >> b[i]; // Đọc vector b
    }
    file.close();

    vector<double> solution = jacobiMethod(A, b, x0);


    if (!solution.empty()) {
        std::cout << "Nghiem cua phuong trinh la:\n";
        for (size_t i = 0; i < solution.size(); i++) {
            std::cout << "x[" << i + 1 << "] = " << std::fixed << std::setprecision(6) << solution[i] << std::endl;
        }
    }

    return 0;
}
