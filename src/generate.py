import random

# Đặt hạt giống để đảm bảo luôn đưa ra cùng một bộ ngẫu nhiên ở mỗi lần gọi chương trình.
SEED = 42
random.seed(SEED)

NUM_TESTS = 10
A_MIN = 0
A_MAX = 1000000000
 
with open("test.inp", "w") as output:

    for _ in range(NUM_TESTS):
        # Kích thước của mảng.
        n = 1000000
        arr = [random.randint(A_MIN, A_MAX) for _ in range(n)]  
        
        if _ == 0:
            arr.sort()
        
        if _ == 1:
            arr.sort(reverse=True)
        
        output.write(f"{n}\n")  # Write n
        output.write(" ".join(map(str, arr)) + "\n") 