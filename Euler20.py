from time import perf_counter
import sys

sys.setrecursionlimit(10**6)

F = {0: 1, 1: 1}

def factorial(n: int) -> int:
    if n in F: return F[n]
    
    val = n*factorial(n-1)
    
    F[n] = val
    return val
    
def sum_fact_digits(n: int) -> int:
    sfn = str(factorial(n))
    val = 0
    for si in sfn:
        val += int(si)
    return val

def main() -> int:
    
    assert sum_fact_digits(10) == 27
    
    start = perf_counter()
    
    N = 100  
    ans = sum_fact_digits(N)
 
    end = perf_counter()

    print(ans)
    print(end - start,'sec')
    
    return 0
    
if __name__=="__main__":
    main()