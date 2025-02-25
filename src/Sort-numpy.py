import numpy as np
import time

with open("test.inp", 'r') as input:
    
    # Chạy 10 bộ dữ liệu.
    for test in range(1, 11):
        n = int(input.readline())
        a = np.array(list(map(int, input.readline().split())))

        # Bắt đầu ghi thời gian.
        start_time = time.time()
        
        a.sort()

        # Kết thúc ghi thời gian.
        end_time = time.time()

        duration = (end_time - start_time) * 1000
        
        print(f"Time taken: {duration:.6f} ms")
