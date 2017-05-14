#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include "randomGameState.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomTestAdventurer();

int main (int argc, char *argv[]) {
    srand(time(NULL));
    randomTestAdventurer(); 
    return 0;
}

void randomTestAdventurer() {
    struct gameState state;
    int i, j, numTests, tempHandSize, tempDeckSize, tempDiscardSize, treasureCheck, handResult, deckResult, discardResult, tempHandSize2, tempDeckSize2, tempDiscardSize2;
    int test1 = 0;
    int test2 = 0;
    int test3 = 0;
    int test4 = 0;
    numTests = 1000;

    printf("\n----------RANDOM TESTING playAdventurer()----------\n");

    for (i = 0; i < numTests; i++) {
        randomGameState(&state, 1, 1);
        tempHandSize = state.handCount[0];
        tempDeckSize = state.deckCount[0];
        tempDiscardSize = state.discardCount[0];
        tempHandSize2 = state.handCount[1];
        tempDeckSize2 = state.deckCount[1];
        tempDiscardSize2 = state.discardCount[1];
        //printf("numPlayers: %d\nhandCount0: %d\ndeckCount0: %d\ndiscardCount0: %d\n", state.numPlayers, state.handCount[0], state.deckCount[0], state.discardCount[0]);
        playAdventurer(&state);

        //TEST 1 - Current player receives exactly 2 treasure cards
        if (assertTrue(tempHandSize+2, state.handCount[0])) {
            test1++;
        }

        //TEST 2 - The two receivd cards are treasure cards
        for (j = 0; j < 2; j++) {
            if (state.hand[0][state.handCount[0]-j] == copper || state.hand[0][state.handCount[0]-j] == silver || state.hand[0][state.handCount[0]-j] == gold) {
                treasureCheck = 1;
            } else {
                treasureCheck = 0;
            }
        }
        if (assertTrue(treasureCheck, 1)) {
            test2++;
        }

        //TEST 3 - The deck and/or discard are properly handled
        if (assertTrue(state.deckCount[0]+state.discardCount[0], tempDeckSize+tempDiscardSize-2)) {
            test3++;
        }

        //TEST 4 - No state change occurs for other player
        handResult = 0;
        deckResult = 0;
        discardResult = 0;
        if (tempHandSize2 == state.handCount[1]) {
            handResult = 1;
        }
        if (tempDeckSize2 == state.deckCount[1]) {
            deckResult = 1;
        }
        if (tempDiscardSize2 == state.discardCount[1]) {
            discardResult = 1;
        }
        if (handResult && deckResult && discardResult) {
            test4++;
        }
    }

    printf("TEST 1 passed %d out of %d iterations.\n", test1, numTests);
    printf("TEST 2 passed %d out of %d iterations.\n", test2, numTests);
    printf("TEST 3 passed %d out of %d iterations.\n", test3, numTests);
    printf("TEST 4 passed %d out of %d iterations.\n", test4, numTests);
    printf("\n");

    return;
}
