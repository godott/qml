import subprocess
import numpy

n = 10 # number of qubits
l = 30 # number of parameters

theta = np.linspace(0, 2*pi, l)

subprocess.call(['./genqasm'] + [str(ang) for ang in theta])


