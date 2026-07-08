from subprocess import run, TimeoutExpired, CalledProcessError
from random import randint

LIM = 50000
TEST = 100
CHUAN = "chuan"
TRAU = "trau"


def gen(lim):
    n = randint(1, lim)
    a = []
    for i in range(n):
        a.append(str(randint(1, lim)))

    with open("test.inp", "w") as f:
        f.write(f"{n}\n")
        f.write(f"{" ".join(a)}")


def exc(prog, time):
    try:
        run([f"./{prog}"], timeout=time, check=1)
    except TimeoutExpired:
        print(f"[TLE] - {prog}")
        exit()
    except CalledProcessError as e:
        print(f"[RE]: {prog} | code: {e}")
        exit()


def comp():
    run(["g++", f"{CHUAN}.cpp", "-o", f"{CHUAN}"])
    run(["g++", f"{TRAU}.cpp", "-o", f"{TRAU}"])
    for test in range(TEST):
        gen(LIM)

        print(f"TEST {test + 1}: ", end="")

        exc(CHUAN, 1)
        exc(TRAU, 1)

        with open(f"{CHUAN}.out", "r") as f:
            chuan = f.read()

        with open(f"{TRAU}.out", "r") as f:
            trau = f.read()

        if chuan != trau:
            print("[WA]")
            exit()
        else:
            print("[AC]")

    print("ALL TEST PASSED")


comp()
