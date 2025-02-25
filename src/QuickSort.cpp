#include <bits/stdc++.h>

const int N = 1e6 + 6;

int n, a[N];

// Gọi hàm đệ quy sắp xếp các phần tử trong đoạn [l, r]
void QuickSort(int l, int r) {
    // Nếu mảng chỉ còn một phần tử hoặc rỗng thì dừng lại
    if(l >= r) return;

    // Lấy pivot là phần tử giữa
    int middle = (l + r) >> 1;
    int pivot = a[middle];

    std::swap(a[middle], a[r]);

    int ptr = l;
    for(int i = l; i <= r - 1; ++i) {
        if(a[i] < pivot) {
            // Đưa phần tử có giá trị bé hơn pivot vào phần bên trái
            std::swap(a[ptr++], a[i]);
        }
    }

    std::swap(a[ptr], a[r]);

    QuickSort(l, ptr - 1);
    QuickSort(ptr + 1, r);
}

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

        // Gọi hàm đệ quy.
        QuickSort(1, n);

        // Kết thúc ghi thời gian.
        auto end = std::chrono::high_resolution_clock::now();
        
        // In ra thời gian của bộ dữ liệu thư i:
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "Time taken: " << std::fixed << (double) duration.count() << " ms" << std::endl;
    }
}
