import sys
si = sys.stdin.readline
n, m = map(int, si().split())

arr = [
    si().rstrip()
    for _ in range(n)
]

ans = 64
def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < m

field1 = [
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB'
]

field2 = [
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW'
]

for row in range(0, n - 7):
    for col in range(0, m - 7):
        cnt1 = cnt2 = 0
        for i in range(8):
            for j in range(8):
                if arr[row+i][col+j] != field1[i][j]:
                    cnt1 += 1
                if arr[row+i][col+j] != field2[i][j]:
                    cnt2 += 1
        ans = min(ans, cnt1, cnt2)

        
print(ans)
