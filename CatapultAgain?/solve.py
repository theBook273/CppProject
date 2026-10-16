st = []
a = []


def build(id, left, righ):
    if left == righ:
        st[id] = a[righ]
        return

    mid = (left + righ) // 2
    build(id * 2, left, mid)
    build(id * 2 + 1, mid + 1, righ)
    st[id] = st[id * 2] + st[id * 2 + 1]
    return


def update(id, left, right, pos, val):
    if left > right or pos < left or pos > right:
        return

    if left == right and right == pos:
        st[id] = val
        return

    mid = (left + right) // 2
    update(id * 2, left, mid, pos, val)
    update(id * 2 + 1, mid + 1, right, pos, val)
    st[id] = st[id * 2] + st[id * 2 + 1]


def query(id, left, right, fleft, fright):
    if left > fright or right < fleft or left > right:
        return 0

    if left >= fleft and right <= fright:
        return st[id]

    mid = (left + right) // 2
    leftSum = query(id * 2, left, mid, fleft, fright)
    rightSum = query(id * 2 + 1, mid + 1, right, fleft, fright)
    return leftSum + rightSum


def main():
    global st, a
    n, q = map(int, input().split())
    a = [0] + [int(x) for x in input().split()]
    st = [0] * (4 * n + 1)

    build(1, 1, n)

    while q > 0:
        x, u, v = map(int, input().split())
        if x == 1:
            update(1, 1, n, u, v)
        else:
            print(query(1, 1, n, u, v))
        q -= 1
    return 0


if __name__ == "__main__":
    main()
