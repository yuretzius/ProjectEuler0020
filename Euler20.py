from time import perf_counter
import sys

sys.setrecursionlimit(10**6)

F = {0: 1, 1: 1}

def factorial(n: int) -> int:
    if n in F: return F[n]
    
    val = n*factorial(n-1)
    
    F[n] = val
    return val

def main() -> int:
    
    start = perf_counter()
    
    N = 100
    sfN = str(factorial(N))
    
    ans = 0
    for si in sfN:
        ans += int(si)
        
    end = perf_counter()

    print(ans)
    print(end - start,'sec')
    
    return 0
    
if __name__=="__main__":
    main()