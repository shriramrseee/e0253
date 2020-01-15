CC=gcc

all: fork precious

fork: fork_bench.c
	$(CC) -o fork_bench fork_bench.c

precious: precious_bench.c
	$(CC) -o precious_bench precious_bench.c

clean:
	rm -f fork_bench precious_bench