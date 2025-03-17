#include <bits/stdc++.h>

const int N = 10000;

double randomDouble(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

int main() {
    std::ofstream file("data/matrix_10000.txt");
    if (!file) {
        std::cout << "Không thể tạo file!";
        return 0;
    }

    file << N << std::endl;
    srand(time(0));

    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<double> b(N);
    
    // Tạo ma trận A với đường chéo trội
    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                A[i][j] = randomDouble(-5, 5);
                sum += std::abs(A[i][j]);
            }
        }
        A[i][i] = sum + randomDouble(5, 10); // Đảm bảo đường chéo trội
    }

    // Sinh vế phải b ngẫu nhiên
    for (int i = 0; i < N; i++) {
        b[i] = randomDouble(-100, 100);
    }

    // Ghi vào file
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << A[i][j] << " ";
        }
        file << b[i] << "\n";
    }

    file.close();
    return 0;
}
