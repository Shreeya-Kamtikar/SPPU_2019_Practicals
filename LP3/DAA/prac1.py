import time
import sys

sys.stdout.flush()

def iterative_fibo(n):
    fib_sequence = [0,1]
    steps = 0
    while len(fib_sequence) < n:
        next_fib = fib_sequence[-1] + fib_sequence[-2]
        fib_sequence.append(next_fib)
        steps += 1
    return fib_sequence,steps

def recursive_fibo(n, fib_sequence=[0,1], steps=0):
    if len(fib_sequence) == n:
        return fib_sequence, steps
    else:
        next_fib = fib_sequence[-1] + fib_sequence[-2]
        fib_sequence.append(next_fib)
        steps += 1
    return recursive_fibo(n, fib_sequence, steps)

n = int(input("Enter number of values to be generated in the sequence: "))
while True:
    print("\n1.Iterative\n2.Recursive\n3.Exit")
    choice = int(input("Enter choice: "))
    if choice == 1:
        st = time.perf_counter()
        i_result, i_step_count = iterative_fibo(n)
        en = time.perf_counter()
        exec = en - st
        print("\nIterative")
        print(f"Fibonacci Sequence (first {n} numbers): {i_result}")
        print(f"Total Steps: {i_step_count}")
        print("Execution time: ",exec)
        sys.stdout.flush()
    
    elif choice == 2:
        st1 = time.perf_counter()
        r_result, r_step_count = recursive_fibo(n)
        en1 = time.perf_counter()
        exec1 = en1 - st1
        print("\nRecursive")
        print(f"Fibonacci Sequence (first {n} numbers): {r_result}")
        print(f"Total Steps: {r_step_count}")
        print("Execution time: ",exec1)
        sys.stdout.flush()

    elif choice == 3:
        break

    else:
        print("\nInvalid choice")