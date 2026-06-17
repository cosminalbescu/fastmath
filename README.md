# fastmath

Fast numeric operations implemented as a C extension, with a pure-Python fallback.

## Project structure

| File / folder | Purpose |
|---|---|
| `README.md` | Short project description and usage example. |
| `pyproject.toml` | Build configuration, package metadata, setuptools backend, `src` layout, and native extension declaration. |
| `src/fastmath/__init__.py` | Public package entry point. Tries to import the C extension first, then falls back to the pure-Python implementation. |
| `src/fastmath/_core.c` | C extension implementing `sum_list` and `dot`. This file is compiled into a native `.so` module. |
| `src/fastmath/_pyfallback.py` | Pure-Python implementation of the same functions, used as a fallback and reference implementation. |
| `benchmark.py` | Compares C extension performance against the pure-Python fallback. |
| `.github/workflows/build.yml` | Builds wheels and sdist, tests the wheels, uploads artifacts, and publishes to TestPyPI on release. |

## Usage

```python
import fastmath

fastmath.sum_list([1.0, 2.0, 3.0])      # 6.0
fastmath.dot([1.0, 2.0], [3.0, 4.0])    # 11.0
fastmath.backend()                       # 'c' or 'python'
```
