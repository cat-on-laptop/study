n = int(input())

prime, idx = [False] * (1004005), 2

prime[0] = prime[1] = True

while idx * idx <= 1004005:
    if not prime[idx]:
        for j in range(idx * idx, 1004005, idx):
            prime[j] = True
    idx += 1
            
def isPal(num : str, l : int, r : int) -> bool:
    if l >= r:
        return True
    if num[l] != num[r]:
        return False
    return isPal(num, l + 1, r - 1)

while True:
    if prime[n]:
        n += 1
        continue
    s = str(n)
    if isPal(s, 0, len(s) - 1):
        print(n)
        break
    n += 1
