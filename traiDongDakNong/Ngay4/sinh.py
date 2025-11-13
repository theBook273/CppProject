import random
import os
import sys

for test in range(1, 101):
    
    with open("tan.inp", "w") as f:
        
        n = random.randint(1, 100)
        S = random.randint(1, 100)
        
        f.write(f"{n} {S}\n")

        for _ in range(n):
            val1 = random.randint(1, 1000)
            val2 = random.randint(1, 1000)
            f.write(f"{val1} {val2}\n")
            
        f.write("\n")
    
    print(f"--- Đang chạy Test {test} ---")

    os.system("tan.exe")
    os.system("trautan.exe")

    return_code = os.system("fc tan.out trautan.out")

    if return_code == 1:
        print(f"\n!!! LỖI TẠI TEST {test} !!!")
        print("Phát hiện kết quả khác nhau. Dừng chương trình.")
        sys.exit(0)
    else:
        print(f"Test {test}: OK\n")

print("+++ TUYỆT VỜI! Tất cả 100 test đều đúng! +++")
