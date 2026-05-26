"""Pure-Python fallback implementations of fastmath operations."""


def sum_list(values):
    """Sum of a list of numbers."""
    total = 0.0
    for v in values:
        total += v
    return total


def dot(a, b):
    """Dot product of two lists."""
    if len(a) != len(b):
        raise ValueError("lists must have equal length")
    result = 0.0
    for x, y in zip(a, b):
        result += x * y
    return result
