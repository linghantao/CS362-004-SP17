#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include "randomGameState.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomTestCouncilRoom(int numTests);

int main (int argc, char *argv[]) {
    srand(time(NULL));
    randomTestCouncilRoom(1000); 
    return 0;
}

void randomTestCouncilRoom(int numTests) {
    struct gameState state;
    int i, j, tempHandSize, tempDeckSize, tempDiscardSize, handCheck, handResult, deckResult, discardResult, tempDeckSize2, tempDiscardSize2, tempNumBuys;
    int test1 = 0;
    int test2 = 0;
    int test3 = 0;
    int test4 = 0;
    int test5 = 0;

    printf("\n----------RANDOM TESTING playCouncilRoom()----------\n");

    for (i = 0; i < numTests; i++) {
        randomGameState(&state, 1, 1);
        int *tempHandSize2 = malloc(sizeof(int)*state.numPlayers);
        tempHandSize = state.handCount[0];
        tempDeckSize = state.deckCount[0];
        tempDiscardSize = state.discardCount[0];
        tempDeckSize2 = state.deckCount[1];
        tempDiscardSize2 = state.discardCount[1];
        tempNumBuys = state.numBuys;
        playCouncilRoom(&state, 0);
        for (j = 0; j < state.numPlayers; j++) {
            tempHandSize2[j] = state.handCount[j+1];
        }

        //TEST 1 - Current player receives exactly 4 cards
        if (assertTrue(tempHandSize+4, state.handCount[0])) {
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
        if (tempHandSize2[0] == state.handCount[1]) {
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

        //TEST 4 - Other players should have drawn a card
        int a;
        int drawCheck = 1;
        for (a = 0; a < state.numPlayers; a++) {
            if (!assertTrue(state.handCount[a], tempHandSize2[a]+1)) {
                drawCheck = 0;
            }
        }
        if (assertTrue(drawCheck, 1)) {
            test4++;
        }

        //TEST 5 - Current player should have an additional buy
        if (assertTrue(state.numBuys, tempNumBuys+1)) {
            test5++;
        } 
    }

    printf("TEST 1 passed %d out of %d iterations.\n", test1, numTests);
    printf("TEST 2 passed %d out of %d iterations.\n", test2, numTests);
    printf("TEST 3 passed %d out of %d iterations.\n", test3, numTests);
    printf("TEST 4 passed %d out of %d iterations.\n", test4, numTests);
    printf("TEST 5 passed %d out of %d iterations.\n", test5, numTests);
    printf("\n");

    return;
}
