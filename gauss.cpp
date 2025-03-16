#include <bits/stdc++.h>
#include <vector>

const double eps = 1e-9;

int gaussianElimination (std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x) {
    
    int N = A.size();

    for (int i = 0; i < N; i++) {
        int max_row = i;
        for (int j = i + 1; j < N; j++) {
            if (fabs(A[j][i]) > fabs(A[max_row][i])) {
                max_row = j;
            }
        }

        std::swap(A[i], A[max_row]);
        std::swap(b[i], b[max_row]);

        if (fabs(A[i][i]) < eps) {
            bool all_zero = true;

            for (int k = i; k < N; k++) {
                if (fabs(A[i][k]) > eps) {
                    all_zero = false;
                    break;
                }
            }

            if (all_zero) {
                if (fabs(b[i]) > eps) return -1; // he vo nghiem
                return 0; // he vo so nghiem
            }
        }
        
        for (int j = i + 1; j < N; j++) {
            double m = A[j][i] / A[i][i];
            for (int k = i; k < N; k++) {
                A[j][k] -= m * A[i][k];
            }
            b[j] -= m * b[i];
        }
    }

   
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++) { 
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
    return 1; // he co nghiem duy nhat
}


int main() {
    std::ifstream file("data/matrix_2000.txt");

    if (!file) {
        std::cout<< "file không tồn tại";
        return 0;
    }

    int N;
    file>>N;

    std::vector<std::vector<double>> A(N, std::vector<double> (N));
    std::vector<double> b(N);
    std::vector<double> x(N);

    for(int i =0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            file >> A[i][j];
        }
        file >> b[i];
    }

    file.close();

    int result = gaussianElimination(A, b, x);

    if (result == -1) {
        std::cout << "hpt vo nghiem" << std::endl;
    } else if (result == 0) {
        std::cout << "hpt vo so nghiem" << std::endl;
    } else {
        std::cout << "Nghiem cua pt:" << std::endl;
        for (int i = 0; i < N; i++) {
            std::cout << "x[" << i + 1 << "] = " << std::fixed << std::setprecision(6) << x[i] << std::endl;
        }
    }
    return 0;
}