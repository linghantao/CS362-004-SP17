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

randomtestcard2: randomtestcard2.c dominion.o rngs.o assertTrue.o randomGameState.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o assertTrue.o randomGameState.o $(CFLAGS)

testresults.out: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.c assertTrue.c randomGameState.c
	echo "Testing playSmithy() [randomtestcard1.c]*************************************************" &> randomtestcard1.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o assertTrue.o randomGameState.o $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -b -f dominion.o >> randomtestcard1.out
	echo "Testing playCouncilRoom() [randomtestcard2.c]*************************************************" &> randomtestcard2.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o assertTrue.o randomGameState.o $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -b -f dominion.o >> randomtestcard2.out
	echo "Testing playAdventurer() [randomtestadventurer.c]*************************************************" &> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o assertTrue.o randomGameState.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b -f dominion.o >> randomtestadventurer.out

cleanresults:
	rm -f *.exe *gcda *.gcov *.o *.gcno *.so
