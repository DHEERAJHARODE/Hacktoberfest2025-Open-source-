"""Simple Calculator

Features:
- Safe expression evaluation using Python's AST (no exec/eval of arbitrary code)
- Supports +, -, *, /, %, ** and unary +/-, parentheses, integers and floats
- Command-line: --expr "1+2*3" for one-shot evaluation
- Interactive REPL when no --expr provided
- --test runs a small internal test suite

Usage examples:
    python simple_calculator.py --expr "(2+3)*4"
    python simple_calculator.py
    python simple_calculator.py --test
"""
from __future__ import annotations

import ast
import argparse
import math
import sys
from typing import Any


class EvalError(Exception):
    pass


ALLOWED_BINARY_OPS = {
    ast.Add: lambda a, b: a + b,
    ast.Sub: lambda a, b: a - b,
    ast.Mult: lambda a, b: a * b,
    ast.Div: lambda a, b: a / b,
    ast.Mod: lambda a, b: a % b,
    ast.Pow: lambda a, b: a ** b,
    ast.FloorDiv: lambda a, b: a // b,
}

ALLOWED_UNARY_OPS = {
    ast.UAdd: lambda a: +a,
    ast.USub: lambda a: -a,
}


def safe_eval(node: ast.AST) -> float:
    """Recursively evaluate an AST expression node allowing only safe arithmetic.

    Raises EvalError on disallowed nodes.
    """
    if isinstance(node, ast.Expression):
        return safe_eval(node.body)

    if isinstance(node, ast.Constant):
        if isinstance(node.value, (int, float)):
            return float(node.value)
        raise EvalError(f"Unsupported constant type: {type(node.value).__name__}")

    if isinstance(node, ast.Num):  # for Python <3.8 compatibility
        return float(node.n)

    if isinstance(node, ast.BinOp):
        left = safe_eval(node.left)
        right = safe_eval(node.right)
        op_type = type(node.op)
        func = ALLOWED_BINARY_OPS.get(op_type)
        if func is None:
            raise EvalError(f"Operator {op_type.__name__} not allowed")
        try:
            return func(left, right)
        except Exception as e:
            raise EvalError(f"Error evaluating binary op: {e}") from e

    if isinstance(node, ast.UnaryOp):
        operand = safe_eval(node.operand)
        op_type = type(node.op)
        func = ALLOWED_UNARY_OPS.get(op_type)
        if func is None:
            raise EvalError(f"Unary operator {op_type.__name__} not allowed")
        return func(operand)

    if isinstance(node, ast.Call):
        # optionally allow a small whitelist of math functions like sqrt, sin, cos
        if isinstance(node.func, ast.Name) and node.func.id in ("sqrt", "sin", "cos", "tan", "log"):
            func_name = node.func.id
            args = [safe_eval(arg) for arg in node.args]
            try:
                f = getattr(math, func_name)
            except AttributeError:
                raise EvalError(f"Function {func_name} not available")
            return float(f(*args))
        raise EvalError("Function calls are not allowed except a few math.* helpers: sqrt,sin,cos,tan,log")

    if isinstance(node, ast.Expr):
        return safe_eval(node.value)

    if isinstance(node, ast.Paren):  # rare / not present in AST, kept for safety
        return safe_eval(node.value)

    raise EvalError(f"Unsupported AST node: {node.__class__.__name__}")


def evaluate_expression(expr: str) -> float:
    """Parse and safely evaluate a single arithmetic expression string."""
    try:
        parsed = ast.parse(expr, mode="eval")
    except SyntaxError as e:
        raise EvalError(f"Syntax error: {e.msg}") from e
    return safe_eval(parsed)


def repl() -> None:
    print("Simple Calculator REPL — type 'quit' or 'exit' to leave. Use --help for more options.")
    while True:
        try:
            s = input("calc> ").strip()
        except (EOFError, KeyboardInterrupt):
            print()
            break
        if not s:
            continue
        if s.lower() in ("quit", "exit"):
            break
        if s.lower() in ("help", "h"):
            print("Enter arithmetic expressions using + - * / % ** and parentheses. Example: (2+3)*4")
            continue
        try:
            result = evaluate_expression(s)
        except EvalError as e:
            print(f"Error: {e}")
        except Exception as e:
            print(f"Unexpected error: {e}")
        else:
            # print integer without decimal when possible
            if abs(result - int(result)) < 1e-12:
                print(int(result))
            else:
                print(result)


def run_tests() -> bool:
    tests = {
        "1+2*3": 7,
        "(1+2)*3": 9,
        "2**3**1": 8,  # 2**(3**1) -> 2**3
        "4/2": 2,
        "5%2": 1,
        "-3 + 7": 4,
        "sqrt(16)": 4,
        "sin(0)": 0,
    }
    ok = True
    for expr, expected in tests.items():
        try:
            got = evaluate_expression(expr)
        except EvalError as e:
            print(f"FAIL: {expr} -> raised EvalError: {e}")
            ok = False
            continue
        # compare numeric with tolerance
        if abs(got - expected) > 1e-9:
            print(f"FAIL: {expr} = {got} (expected {expected})")
            ok = False
        else:
            print(f"OK:   {expr} = {got}")
    return ok


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Simple safe calculator")
    parser.add_argument("--expr", "-e", help="evaluate expression and exit", type=str)
    parser.add_argument("--test", help="run internal tests", action="store_true")
    args = parser.parse_args(argv)

    if args.test:
        success = run_tests()
        print("All tests passed." if success else "Some tests failed.")
        return 0 if success else 2

    if args.expr:
        try:
            result = evaluate_expression(args.expr)
        except EvalError as e:
            print(f"Error: {e}")
            return 1
        # neat printing
        if abs(result - int(result)) < 1e-12:
            print(int(result))
        else:
            print(result)
        return 0

    repl()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
