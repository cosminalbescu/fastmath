"""fastmath — fast numeric operations with a C extension and a Python fallback."""

__version__ = "0.1.0"

try:
    from ._core import sum_list, dot          # C extension (fast)
    _BACKEND = "c"
except ImportError:                           # pragma: no cover
    from ._pyfallback import sum_list, dot     # pure-Python fallback
    _BACKEND = "python"


def backend():
    """Return which implementation is active: 'c' or 'python'."""
    return _BACKEND


__all__ = ["sum_list", "dot", "backend"]
