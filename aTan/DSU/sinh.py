import random
import os
import sys

os.system("g++ main.cpp -o main")
os.system("g++ trau.cpp -o trau")

for test in range(1, 10001):
    with open("test.inp", "w") as f:

        n = random.randint(1, 100)
        m = random.randint(1, 100)
        q = random.randint(1, 100)

        f.write(f"{n} {m} {q}\n")

        # weights
        for i in range(n):
            val = random.randint(1, 100000)
            f.write(f"{val}" + (" " if i != n-1 else "\n"))

        edges = []
        for i in range(m):
            u = random.randint(1, n)
            v = random.randint(1, n)
            edges.append((u, v))
            f.write(f"{u} {v}\n")

        alive_edges = list(range(1, m+1))
        for i in range(q):
            if not alive_edges:
                typ = 'C'
            else:
                typ = random.choice(['C', 'D'])
            if typ == 'C':
                x = random.randint(1, n)
                y = random.randint(1, 1000)
                f.write(f"{typ} {x} {y}\n")
            else:  # typ == 'D'
                j = random.choice(alive_edges)
                alive_edges.remove(j)
                f.write(f"{typ} {j}\n")

    print(f"-- Running {test} --")

    os.system("./main")
    os.system("./trau")

    check = os.system("diff testChuan.out testTrau.out")

    if check != 0:
        print(f"\nTEST {test}: WA!!!")
        sys.exit(0)
    else:
        print(f"TEST {test}: AC\n")

print("ALL AC - NICE!!!")
