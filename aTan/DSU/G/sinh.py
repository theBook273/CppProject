from subprocess import run, TimeoutExpired, CalledProcessError
from random import randint


def gen(lim):
    with open("test.inp", "w") as f:
        n = randint(1, lim)
        m = randint(1, lim)

        f.write(f"{n} {m}\n")
        for i in range(n):
            for j in range(m):
                f.write(f"{randint(1,lim)} ")
            f.write("\n")

        k = randint(1, lim)
        f.write(f"{k}\n")
        for i in range(k):
            f.write(f"{randint(1,lim)} ")


def exc(prog, time):
    try:
        run([f"./{prog}"], timeout=time, check=1)
        return 0
    except TimeoutExpired:
        print("[TLE]")
        return 1
    except CalledProcessError:
        print("[RE]")
        return 1


run(["g++", "main.cpp", "-o", "main"])
run(["g++", "trau.cpp", "-o", "trau"])

limTest = 10
lim = 500

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

    if chuan != trau and not check:
        print("[WA]")
    elif not check:
        print("[AC]")

print("ALL AC")
