import numpy as np
import easynn as nn

# Create a numpy array of 10 rows and 5 columns.
# Set the element at row i and column j to be i+j.
def Q1():
    a = np.zeros([10,5])
    for i in range(10):
        for j in range(5):
            a[i][j] = i+j
    return a
# Add two numpy arrays together.
def Q2(a, b):
    return a+b

# Multiply two 2D numpy arrays using matrix multiplication.
def Q3(a, b):
    c = [0]
    c = np.dot(a,b)
    return c


# For each row of a 2D numpy array, find the column index
# with the maximum element. Return all these column indices.
def Q4(a):
    arr = np.array(a)
    max_index = np.argmax(arr,axis=1)
    return max_index

# Solve Ax = b.
def Q5(A, b):
    x = np.linalg.solve(A,b)
    return x

# Return an EasyNN expression for a+b.
def Q6():
    a = nn.Input("a")
    b = nn.Input("b")
    d = a + b
    return d

# Return an EasyNN expression for a+b*c.
def Q7():
    a = nn.Input("a")
    b = nn.Input("b")
    c = nn.Input("c")
    e = a + b*c
    return e

# Given A and b, return an EasyNN expression for Ax+b.
def Q8(A, b):
    A = nn.Const(A)
    x = nn.Input("x")
    b = nn.Const(b)
    d = A*x + b
    return d


# Given n, return an EasyNN expression for x**n.
def Q9(n):
    a =1
    x = nn.Input("x")
    for _ in range(n):
        a=x*a
    return a


# Return an EasyNN expression to compute
# the element-wise absolute value |x|.
def Q10():
    a = nn.ReLU()
    x = nn.Input("x")
    b = a(x)
    c = a(-x)
    return b+c