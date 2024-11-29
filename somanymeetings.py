n, k = map(int, input().split())
arr = [0 for i in range(100002)]
for i in range(n):
    x, y = map(int, input().split())
    arr[x] +=1
    arr[y+1] -=1
for i in range(1, 100002):
    arr[i] += arr[i-1]

print(max(0, max(arr)-k))