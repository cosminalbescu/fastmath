import time
import fastmath
from fastmath import _pyfallback

data = [float(i) for i in range(1_000_000)]

def timed(label, fn, *args):
    start = time.perf_counter()
    result = fn(*args)
    elapsed = time.perf_counter() - start
    print(f"{label:20s} {elapsed*1000:8.2f} ms   result={result:.1f}")
    return elapsed

print(f"Active backend: {fastmath.backend()}\n")

c_time  = timed("C extension",      fastmath.sum_list,   data)
py_time = timed("Pure Python",      _pyfallback.sum_list, data)

print(f"\nC is {py_time / c_time:.1f}x faster")
