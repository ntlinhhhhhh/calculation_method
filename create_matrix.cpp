#include <bits/stdc++.h>

const int N = 2000;
int main() {

    std::ofstream file("data/matrix_2000.txt");
    if (!file) {
        std::cout<<"ko the tao file";
        return 0;
    }

    file<<N<<std::endl;

    srand(time(0));
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = (rand() % 200 - 100);
            file << value << " ";
        }
        int bValue = (rand() % 200 - 100);
        file << bValue << "\n";
    }

    file.close();
    return 0;
}