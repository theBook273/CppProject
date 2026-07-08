from subprocess import run, TimeoutExpired, CalledProcessError
from random import randint

LIM = 100000
TEST = 100
CHUAN = "chuan"
TRAU = "trau"


def gen(lim):
    n = randint(1, lim)
    k = randint(1, lim)
    a = [str(randint(1, lim)) for _ in range(n)]
    with open("test.inp", "w") as f:
        f.write(f"{n} {k}\n")
        f.write(" ".join(a))


def exc(prog, time):
    try:
        run([f"./{prog}"], timeout=time, check=1)
    except TimeoutExpired:
        print(f"[TLE] - {prog}")
        exit()
    except CalledProcessError as e:
        print("f[RE] - {prog}. ERROR CODE:")
        print(e)
        exit()


run(["g++", f"{CHUAN}.cpp", "-o", f"{CHUAN}"])
run(["g++", f"{TRAU}.cpp", "-o", f"{TRAU}"])

for test in range(TEST):
    print(f"TEST {test + 1}: ", end="")
    gen(LIM)

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
