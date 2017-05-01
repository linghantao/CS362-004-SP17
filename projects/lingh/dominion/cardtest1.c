#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <stdio.h>
#include <stdlib.h>

void testPlaySmithy() {
    printf("\n----------TESTING FUNCTION: playSmithy()----------\n");
    
    //TEST SETUP
    //Initialize required variables
    struct gameState state;
    state.playedCardCount = 0;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int i, j, k, l, m, n, o, p;

    //Initialize hands
    //Player 1
    //Hand [0] with the first 5 kingdom cards
    state.handCount[0] = 0;
    for (i = 0; i < 5; i++) {
        state.hand[0][i] = kingdomCards[i];
        state.handCount[0]++;
    }
    //Deck [0] with all kingdom cards
    state.deckCount[0] = 0;
    for (k = 0; k < 10; k++) {
        state.deck[0][k] = kingdomCards[k];
        state.deckCount[0]++;
    }
    //Discard [0] with all kingdom cards and 10 coppers
    state.discardCount[0] = 0;
    for (l = 0; l < 10; l++) {
        state.discard[0][l] = kingdomCards[l];
        state.discardCount[0]++;
    }
    for (m = 10; m < 20; m++) {
        state.discard[0][m] = copper;
        state.discardCount[0]++;
    }

    //Player 2
    //Hand [1] with the last 5 kingdom cards
    state.handCount[1] = 0;
    for (j= 5; j < 10; j++) {
        state.hand[1][j-5] = kingdomCards[j];
        state.handCount[1]++;
    }
    //Deck [1] with all kingdom cards
    state.deckCount[1] = 0;
    for (n = 0; n < 10; n++) {
        state.deck[1][n] = kingdomCards[n];
        state.deckCount[1]++;
    }
    //Discard [0] with all kingdom cards and 10 coppers
    state.discardCount[1] = 0;
    for (o = 0; o < 10; o++) {
        state.discard[1][o] = kingdomCards[o];
        state.discardCount[1]++;
    }
    for (p = 10; p < 20; p++) {
        state.discard[1][p] = copper;
        state.discardCount[1]++;
    }

    //Initialize supply with 10 of every card
    for (i = 0; i <= treasure_map; i++) {
        state.supplyCount[i] = 10;
    }
    //state.supplyCount[adventurer] = 10;

    //Save state of player 1 and 2's hand, deck, and discard
    int tempHandSize = state.handCount[0];
    int tempDeckSize = state.deckCount[0];
    int tempDiscardSize = state.discardCount[0];
    int tempHandSize2 = state.handCount[1];
    int tempDeckSize2 = state.deckCount[1];
    int tempDiscardSize2 = state.discardCount[1];

    //TEST RUNS
    playSmithy(&state, 0);
    
    //TEST 1: Current player receives exactly 3 cards
    printf("TEST 1 - Current player receives exactly 3 cards: ");
    assertTrue(state.handCount[0], tempHandSize+2);

    //TEST 2: The three received cards should come from the player's own cards
    printf("TEST 2 - Three received cards comes from player's own cards: ");
    //printf("before: %d  |  after: %d\n", tempDeckSize+tempDiscardSize, state.deckCount[0]+state.discardCount[0]);
    assertTrue(state.deckCount[0]+state.discardCount[0], tempDeckSize+tempDiscardSize-2);

    //TEST 3: No state change occurs for other player
    printf("TEST 3 - No state change occurs for other player: ");
    int handResult = 0;
    int deckResult = 0;
    int discardResult = 0;
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
        assertTrue(1, 1);
    } else {
        assertTrue(1, 0);
    }

    //TEST 4: No state change occurs to the victory and kingdom card piles
    printf("TEST 4 - No state change occurs to the victory and kingdom card piles: ");
    int tempCheck = 1;
    for (j = 0; j <=treasure_map; j++) {
        if (state.supplyCount[j] != 10) {
            tempCheck = 0;
        }
    }
    assertTrue(tempCheck, 1);

    printf("\n");
    return;
}

int main(int argc, char *argv[]) {
    testPlaySmithy();
    return 0;
}

