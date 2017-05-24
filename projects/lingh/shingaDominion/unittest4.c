#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <stdio.h>
#include <stdlib.h>

void testGainCard() {
    printf("\n----------TESTING FUNCTION: gainCard()----------\n");
    
    //TEST SETUP
    //Initialize required variables
    struct gameState state;
    int kingdomCard[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int i, j;
    int player = 0;

    //Initialize empty hand, empty deck, and empty discard
    state.handCount[0] = 0;
    state.deckCount[0] = 0;
    state.discardCount[0] = 0;

    //Initialize supply
    //Set up supply with 10 curses, 8 of each victory card, 46 coppers, 40 silvers, 30 golds, 10 adventurers, 10 council_rooms, 10 feasts, 8 gardens, 10 mines, 10 remodels, 10 smithys, 10 villages, 10 barons, and 8 great_halls (simulate game start with 2 players)
    state.supplyCount[curse] = 10;
    state.supplyCount[estate] = 8;
    state.supplyCount[duchy] = 8;
    state.supplyCount[province] = 8;
    state.supplyCount[copper] = 46;
    state.supplyCount[silver] = 40;
    state.supplyCount[gold] = 30;
    for (i = adventurer; i <= treasure_map; i++) {
        for (j = 0; j < 10; j++) {
            if (kingdomCard[j] == i) {
                if (kingdomCard[j] == great_hall || kingdomCard[j] == gardens) {
                    state.supplyCount[i] = 8;
                } else {
                    state.supplyCount[i] = 10;
                }
                break;
            } else {
                state.supplyCount[i] = -1;
            }
        }
    }
   
    //TEST RUNS
    //TEST 1: Try to gain a card to the hand that is not in the kingdom card set
    printf("TEST 1 - Trying to add a card not in the kingdom card set to the hand: ");
    assertTrue(gainCard(embargo, &state, 2, player), -1);

    //TEST 2: Try to gain a card to the deck that is not in the kingdom card set
    printf("TEST 2 - Trying to add a card not in the kingdom card set to the deck: ");
    assertTrue(gainCard(embargo, &state, 1, player), -1);
    
    //TEST 3: Try to gain a card to the discard that is not in the kingdom card set
    printf("TEST 3 - Trying to add a card not in the kingdom card set to the discard: ");
    assertTrue(gainCard(embargo, &state, 0, player), -1);
    
    //TEST 4a & 4b: Gain an adventurer card to the hand
    printf("TEST 4a - Gain an adventurer card to the hand: ");
    int test4countHand = state.supplyCount[adventurer];
    gainCard(adventurer, &state, 2, player);
    assertTrue(state.hand[player][state.handCount[player]-1], adventurer);
    printf("TEST 4b - Lose an adventurer card from the supply pile: ");
    assertTrue(state.supplyCount[adventurer], test4countHand - 1);

    //TEST 5a & 5b: Gain a council_room card to the deck
    printf("TEST 5a - Gain a council_room card to the deck: ");
    int test4countDeck = state.supplyCount[council_room];
    gainCard(council_room, &state, 1, player);
    assertTrue(state.deck[player][state.deckCount[player]-1], council_room);
    printf("TEST 5b - Lose a council_room card from the supply pile: ");
    assertTrue(state.supplyCount[council_room], test4countDeck - 1);
    
    //TEST 6a & 6b: Gain a feast card to the discard
    printf("TEST 6a - Gain a feast card to the deck: ");
    int test4countDiscard = state.supplyCount[feast];
    gainCard(feast, &state, 0, player);
    assertTrue(state.discard[player][state.discardCount[player]-1], feast);
    printf("TEST 6b - Lose a feast card from the supply pile: ");
    assertTrue(state.supplyCount[feast], test4countDiscard - 1);

    printf("\n");
    return;
}

int main(int argc, char *argv[]) {
    testGainCard();
    return 0;
}

