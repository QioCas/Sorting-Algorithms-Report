#include <bits/stdc++.h>

const int N = 1e6 + 6;

int n, a[N];

// Hàm trộn hai nửa đã sắp xếp của mảng
void merge(int l, int m, int r) {
    // Mảng tạm để trộn hai phần mảng
    int temp[r - l + 1]; 
    int i = l, j = m + 1, k = 0;

    // So sánh và trộn hai phần mảng
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    // Sao chép phần còn lại nếu có
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    // Sao chép các phần tử đã trộn vào mảng chính
    for (int t = 0; t < k; ++t) a[l + t] = temp[t];
}

// Hàm đệ quy thực hiện Merge Sort
void MergeSort(int l, int r) {
    // Nếu mảng chỉ còn một phần tử thì kết thúc.
    if(l == r) return;
    
    // Tìm vị trí chính giữa của mảng
    int m = (l + r) / 2;
    
    MergeSort(l, m);     
    MergeSort(m + 1, r);
    
    // Trộn hai nửa đã sắp xếp
    merge(l, m, r);
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
        MergeSort(1, n);

        // Kết thúc ghi thời gian.
        auto end = std::chrono::high_resolution_clock::now();
        
        // In ra thời gian của bộ dữ liệu thư i:
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "Time taken: " << std::fixed << (double) duration.count() << " ms" << std::endl;
    }
}
