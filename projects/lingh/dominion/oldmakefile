CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c dominion_helpers.h rngs.o
	gcc -c dominion.c -g $(CFLAGS)

assertTrue.o: assertTrue.h assertTrue.c
	gcc -c assertTrue.c -g $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o assertTrue.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o assertTrue.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o assertTrue.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o assertTrue.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittestresults.out: unittest1.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c assertTrue.c
	echo "Result for running unit tests:" > unittestresults.out
	echo "unittest1.c**************************************************" >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "unittest2.c**************************************************" >> unittestresults.out
	echo "***.c file was lost but the results of the created executable are provided below***" >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "unittest3.c**************************************************" >> unittestresults.out
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "unittest4.c**************************************************" >> unittestresults.out
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "cardtest1.c**************************************************" >> unittestresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "cardtest2.c**************************************************" >> unittestresults.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "cardtest3.c**************************************************" >> unittestresults.out
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "cardtest4.c**************************************************" >> unittestresults.out
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "gcov summary**************************************************" >> unittestresults.out
	gcov -b -f dominion.o >> unittestresults.out

cleanresults:
	rm unittestresults.out
