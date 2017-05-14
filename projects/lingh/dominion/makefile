CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c dominion_helpers.h rngs.o
	gcc -c dominion.c -g $(CFLAGS)

assertTrue.o: assertTrue.h assertTrue.c
	gcc -c assertTrue.c -g $(CFLAGS)

randomGameState.o: randomGameState.h randomGameState.c
	gcc -c randomGameState.c -g $(FLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o assertTrue.o randomGameState.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o assertTrue.o randomGameState.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o assertTrue.o randomGameState.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o assertTrue.o randomGameState.o $(CFLAGS)

clean:
	rm -f *.exe *gcda *.gcov *.o *.gcno *.so
