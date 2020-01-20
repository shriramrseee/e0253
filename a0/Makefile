CC=gcc
ITER=5
MEM=104857600

all: fork precious

fork: fork_bench.c
	$(CC) -o fork_bench -DITER=$(ITER) -DMEM=$(MEM) fork_bench.c

precious: precious_bench.c
	$(CC) -o precious_bench -DITER=$(ITER) -DMEM=$(MEM) precious_bench.c

clean:
	rm -f fork_bench precious_bench