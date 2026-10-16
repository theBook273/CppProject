from subprocess import run, TimeoutExpired, CalledProcessError
from random import randint


def gen(lim):
    with open("test.inp", "w") as f:
        n = randint(5, lim)
        q = randint(1, lim)
        f.write(f"{n} {q}\n")
        for i in range(n):
            f.write(f"{randint(1, lim)} ")
        for i in range(q):
            type = randint(1, 2)
            if type == 1:
                x = randint(1, n)
                k = randint(1, lim)
                f.write(f"{type} {x} {k}\n")
            else:
                l = randint(1, n)
                r = randint(l, n)
                d = randint(1, lim)
                f.write(f"{type} {l} {r} {d}\n")


def exc(prog, time):
    try:
        run([f"./{prog}"], timeout=time, check=1)
        return 0
    except TimeoutExpired:
        print(f"[TLE] - {prog}")
        return 1
    except CalledProcessError:
        print(f"[RE] - {prog}")
        return 1


run(["g++", "main.cpp", "-o", "main"])
run(["g++", "trau.cpp", "-o", "trau"])

limTest = 20
lim = 1000
cnt = 0

for test in range(limTest):
    print(f"TEST {test+ 1}: ", end="")

    gen(lim)
    check = 0
    check = check or exc("main", 1)
    check = check or exc("trau", 1)

    with open("testChuan", "r") as f:
        chuan = f.read()
    with open("testTrau", "r") as f:
        trau = f.read()

    if chuan != trau:
        print("[WA]")
    else:
        print("[AC]")

if cnt == limTest:
    print("All test passed!")
