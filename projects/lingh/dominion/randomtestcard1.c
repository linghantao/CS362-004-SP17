#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include "randomGameState.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomTestSmithy(int numTests);

int main (int argc, char *argv[]) {
    srand(time(NULL));
    randomTestSmithy(1000); 
    return 0;
}

void randomTestSmithy(int numTests) {
    struct gameState state;
    int i, tempHandSize, tempDeckSize, tempDiscardSize, handCheck, handResult, deckResult, discardResult, tempHandSize2, tempDeckSize2, tempDiscardSize2;
    int test1 = 0;
    int test2 = 0;
    int test3 = 0;
    int test4 = 0;

    printf("\n----------RANDOM TESTING playSmithy()----------\n");

    for (i = 0; i < numTests; i++) {
        randomGameState(&state, 1, 1);
        tempHandSize = state.handCount[0];
        tempDeckSize = state.deckCount[0];
        tempDiscardSize = state.discardCount[0];
        tempHandSize2 = state.handCount[1];
        tempDeckSize2 = state.deckCount[1];
        tempDiscardSize2 = state.discardCount[1];
        playSmithy(&state, 0);

        //TEST 1 - Current player receives exactly 3 cards
        if (assertTrue(tempHandSize+3, state.handCount[0])) {
            test1++;
        }

        //TEST 2 - The received cards come from the player's own cards
        handCheck = state.handCount[0]-tempHandSize;
        if (assertTrue(state.deckCount[0]+state.discardCount[0], tempDeckSize+tempDiscardSize-handCheck)) {
            test2++;
        }
        
        //TEST 3 - No state change occurs for other player
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
            test3++;
        }
    }

    printf("TEST 1 passed %d out of %d iterations.\n", test1, numTests);
    printf("TEST 2 passed %d out of %d iterations.\n", test2, numTests);
    printf("TEST 3 passed %d out of %d iterations.\n", test3, numTests);
    //printf("TEST 4 passed %d out of %d iterations.\n", test4, numTests);
    printf("\n");

    return;
}
