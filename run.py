import os
import subprocess
import numpy as np

n = 17 # number of qubits
l = 30 # number of parameters

thetas = np.random.uniform(low=0, high=2*np.pi, size=(l,))

i = 0
while True:
  num = len(data)
  for bits in data:
    cmd_genqasm = "make clean; make; ./genqasm " + " -t " + " ".join(['{:.8f}'.format(x) for x in thetas]) + " > qasm_"+str(i) + " -z " + 
    ret = os.system(cmd_genqasm)
  
    cmd_runqasm = "./runqasm.sh qasm_"+str(i)
    ret = os.system(cmd_runqasm)
    i += 1



