import matplotlib.pyplot as plt
import pandas as pd

# Read data from file
data = pd.read_csv('data.csv')

# Plot F(x)
plt.plot(data['x'], data['F(x)'], label='F(x) = sin(x)', color='blue')

# Plot f(x)
plt.plot(data['x'], data['f(x)'], label="f'(x) (Numerical Derivative)", color='red')

# Add labels and legend
plt.xlabel('x')
plt.ylabel('Value')
plt.title('Plot of F(x) and its Numerical Derivative f(x)')
plt.legend()

# Show the plot
plt.show()