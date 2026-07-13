from random import randint
from subprocess import run, TimeoutExpired, CalledProcessError


def gen(lim):
    with open("test", "w") as f:
        n = randint(1, lim)
        f.write(f"{n}\n")
        s = [str(randint(1, lim)) for _ in range(n)]
        f.write(" ".join(s))
    return


def exc(prog, time):
    try:
        run([f"./{prog}"], timeout=time, check=1)
    except TimeoutExpired:
        print(f"[TLE] - {prog}")
        exit()
    except CalledProcessError:
        print(f"[RE] - {prog}")
        exit()
    return


LIM = 4000
LIMTEST = 50

run(["g++", "main.cpp", "-o", "main"])
run(["g++", "trau.cpp", "-o", "trau"])

for test in range(LIMTEST):
    gen(LIM)

    print(f"Test {test + 1}: ", end="")

    exc("main", 1)
    exc("trau", 1)

    with open("testChuan", "r") as f:
        chuan = f.read()

    with open("testTrau", "r") as f:
        trau = f.read()

    if chuan != trau:
        print("[WA]")
        exit()
    else:
        print("[AC]")
