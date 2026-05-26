# fastmath

Fast numeric operations implemented as a C extension, with a pure-Python fallback.

## Usage

```python
import fastmath

fastmath.sum_list([1.0, 2.0, 3.0])      # 6.0
fastmath.dot([1.0, 2.0], [3.0, 4.0])    # 11.0
fastmath.backend()                       # 'c' or 'python'
```
