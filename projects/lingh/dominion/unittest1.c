#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <stdio.h>
#include <stdlib.h>

void testDiscardCard() {
    printf("\n----------TESTING FUNCTION: discardCard()----------\n");
    
    //TEST SETUP
    //Initialize required variables
    struct gameState state;
    state.playedCardCount = 0;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int i, j, k, l, m;

    //Initialize hands
    //Hand [0] with the first 5 kingdom cards
    state.handCount[0] = 0;
    for (i = 0; i < 5; i++) {
        state.hand[0][i] = kingdomCards[i];
        state.handCount[0]++;
    }
    
    //Hand [1] with the last 5 kingdom cards
    state.handCount[1] = 0;
    for (j= 5; j < 10; j++) {
        state.hand[1][j-5] = kingdomCards[j];
        state.handCount[1]++;
    }

    //Hand [2] with just one kingdom card
    state.handCount[2] = 0;
    state.hand[2][0] = kingdomCards[0];
    state.handCount[2]++;

    //Hand [3] duplicate of Hand [0]
    state.handCount[3] = 0;
    for (m = 0; m < 5; m++) {
        state.hand[3][m] = kingdomCards[m];
        state.handCount[3]++;
    }
    
    //TEST RUNS
    //TEST 1: Discard card from a hand with one card in it
    printf("TEST 1 - Call on hand with one card: ");
    discardCard(0, 2, &state, 0);
    assertTrue(state.handCount[2], 0);
    
    //TEST 2: Discard card from the front of a hand with more than one card in it
    printf("TEST 2 - Call on front of hand with more than one card: ");
    discardCard(0, 0, &state, 0);
    assertTrue(state.handCount[0], 4);

    //TEST 3: Discard card from the back of a hand with more than one card in it
    printf("TEST 3 - Call on back of hand with more than one card: ");
    discardCard(4, 1, &state, 0);
    assertTrue(state.handCount[1], 4);
    
    //TEST 4: Consecutively discard cards from a hand with one card from the front
    printf("TEST 4 - Consecutively call from first card in hand with four cards: ");
    for (k = 0; k < 4; k++) {
        discardCard(0, 1, &state, 0);
    }
    assertTrue(state.handCount[1], 0);
    
    //TEST 5: Consecutively discard cards from a hand with four cards from the back
    printf("TEST 5 - Consecutively call from last card in hand with four cards: ");
    for (l = 3; l >= 0; l--) {
        discardCard(l, 0, &state, 0);
    }
    assertTrue(state.handCount[0], 0);
    
    //TEST 6: Discard card from a hand with no cards in it
    printf("TEST 6 - Call on an empty hand: ");
    discardCard(0, 2, &state, 0);
    assertTrue(state.handCount[2], 0);
     
    //TEST 7: Trash a card from a hand
    printf("TEST 7 - Trashing a card: ");
    int temp = state.playedCardCount;
    discardCard(0, 3, &state, 1);
    assertTrue(state.playedCardCount, temp);

    printf("\n");
    return;
}

int main(int argc, char *argv[]) {
    testDiscardCard();
    return 0;
}

