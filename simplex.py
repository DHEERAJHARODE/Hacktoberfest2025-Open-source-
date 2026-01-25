import numpy as np

def simplex(c, A, b):
    """
    Simplex algorithm to solve the standard form linear programming problem:
    Maximize:     c^T * x
    Subject to:   A * x <= b, x >= 0
    
    Parameters:
    c (numpy array): Coefficients for the objective function
    A (numpy array): Coefficient matrix for the constraints
    b (numpy array): Right-hand side vector for the constraints
    
    Returns:
    x (numpy array): Solution vector
    optimal_value (float): Optimal value of the objective function
    """
    m, n = A.shape

    # Add slack variables to convert inequalities to equations
    A = np.hstack([A, np.eye(m)])
    c = np.hstack([c, np.zeros(m)])
    
    # Initialize basic and non-basic variables
    basic_vars = list(range(n, n + m))
    non_basic_vars = list(range(n))
    
    # Initial solution is the identity matrix for the slack variables
    x = np.zeros(n + m)
    x[basic_vars] = b
    
    while True:
        # Compute the objective function value
        z = c[non_basic_vars] @ x[non_basic_vars]
        
        # Compute the reduced costs
        reduced_costs = c - c[basic_vars] @ np.linalg.inv(A[:, basic_vars]) @ A
        
        # Check for optimality
        if np.all(reduced_costs >= 0):
            return x[:n], z
        
        # Choose entering variable (most negative reduced cost)
        entering = np.argmin(reduced_costs)
        
        # Compute the direction vector
        d = np.zeros(n + m)
        d[entering] = 1
        d[basic_vars] = -np.linalg.inv(A[:, basic_vars]) @ A[:, entering]
        
        # Compute step size
        step_sizes = x[basic_vars] / -d[basic_vars]
        step_sizes[step_sizes <= 0] = np.inf
        leaving = basic_vars[np.argmin(step_sizes)]
        
        # Update basic and non-basic variables
        basic_vars.remove(leaving)
        non_basic_vars.append(leaving)
        non_basic_vars.remove(entering)
        basic_vars.append(entering)
        
        # Update solution
        x += np.min(step_sizes) * d

# Example usage:
c = np.array([-3, -2])
A = np.array([[1, 2], [2, 1], [0, 1]])
b = np.array([4, 3, 2])

solution, optimal_value = simplex(c, A, b)
print("Optimal solution:", solution)
print("Optimal value:", optimal_value)
