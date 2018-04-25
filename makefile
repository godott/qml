genqasm: qaoa.o pauli.o pauli_lib.o graph.o complex.o
	gcc -o genqasm qaoa.o pauli.o pauli_lib.o graph.o complex.o

<<<<<<< HEAD
foo.o: qaoa.c graph.h pauli_lib.h
=======
qaoa.o: qaoa.c graph.h pauli_lib.h
>>>>>>> e1b2198cab16f144a58839a524d404378b97458a
	gcc -c qaoa.c

pauli.o: pauli.c pauli.h complex.h
	gcc -c pauli.c

pauli_lib.o: pauli_lib.c pauli_lib.h pauli.h
	gcc -c pauli_lib.c

complex.o: complex.c complex.h
	gcc -c complex.c

graph.o: graph.c graph.h
	gcc -c graph.c

clean:
<<<<<<< HEAD
	rm qaoa.o pauli.o pauli_lib.o graph.o complex.o
=======
	$(RM) genqasm *.o
>>>>>>> e1b2198cab16f144a58839a524d404378b97458a
