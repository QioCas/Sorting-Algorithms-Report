#include <bits/stdc++.h>

const int N = 1e6 + 6;

int n, a[N];

int main() {
    std::ifstream input("test.inp");

    // Chạy 10 bộ dữ liệu.
    for(int test = 1; test <= 10; ++test) {

        // Đọc dữ liệu
        input >> n;
        for(int i = 1; i <= n; ++i) {
            input >> a[i];
        }

        // Bắt đầu ghi thời gian.
        auto start = std::chrono::high_resolution_clock::now();

        std::priority_queue<int> pq;

        // Đưa toàn bộ phần tử vào max heap
        for (int i = 1; i <= n; ++i) {
            pq.push(a[i]);
        }
    
        // Lấy từng phần tử lớn nhất từ heap và đưa vào mảng
        for (int i = n; i >= 1; --i) {
            a[i] = pq.top();
            pq.pop();
        }
    
        // Kết thúc ghi thời gian.
        auto end = std::chrono::high_resolution_clock::now();
        
        // In ra thời gian của bộ dữ liệu thư i:
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "Time taken: " << std::fixed << (double) duration.count() << " ms" << std::endl;
    }
}
