#include "randomGameState.h"
#include "dominion.h"
#include <stdio.h>

void randomGameState(struct gameState *state, int playerFlag, int supplyFlag) {
    //Array of all kingdom cards
    int kingdomCards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
    
    //Set necessary variables
    int numberPlayers = 1;

    //Random hand size between 0 and MAX_HAND = 500
    //int handSize = rand() % (MAX_HAND + 1 - 0) + 0;
    int handSize = rand() % (250 + 1 - 0) + 0;
    int i, randKingdomCard;
    state->handCount[0] = 0;
    for (i = 0; i < handSize; i++) {
        randKingdomCard = rand() % (26 + 1 - 0) + 0;
        state->hand[0][i] = kingdomCards[randKingdomCard];
        state->handCount[0]++;
    }

    //Randomly distribute MAX_DECK = 500 random cards between deck and discard
    //int deckSize = rand() % (MAX_DECK + 1 - 0) + 0;
    int deckSize = rand() % (250 + 1 - 0) + 0;
    int randDeckCard = rand() % (deckSize + 1 - 0) + 0;
    //Deck
    state->deckCount[0] = 0;
    for (i = 0; i < randDeckCard; i++) {
        randKingdomCard = rand() % (26 + 1 - 0) + 0;
        state->deck[0][i] = kingdomCards[randKingdomCard];
        state->deckCount[0]++;
    }
    //Discard
    state->discardCount[0] = 0;
    for (i = randDeckCard; i < deckSize; i++) {
        randKingdomCard = rand() % (26 + 1 - 0) + 0;
        state->discard[0][i] = kingdomCards[randKingdomCard];
        state->discardCount[0]++;
    }

    //Set random players if flag set
    if (playerFlag) {
        int handSizeExtra, j, randKingdomCardExtra, deckSizeExtra, randDeckCardExtra;
        int playerNum = rand() % (3+1 - 1) + 1;
        numberPlayers = numberPlayers+playerNum;
        for (i = 0; i < playerNum; i++) {
            //Random hand size between 0 and MAX_HAND = 500
            //handSizeExtra = rand() % (MAX_HAND + 1 - 0) + 0;
            handSizeExtra = rand() % (250 + 1 - 0) + 0;
            state->handCount[i] = 0;
            for (j = 0; j < handSizeExtra; j++) {
                randKingdomCardExtra = rand() % (26 + 1 - 0) + 0;
                state->hand[i][j] = kingdomCards[randKingdomCardExtra];
                state->handCount[i]++;
            }

            //Randomly distribute MAX_DECK = 500 random cards between deck and discard
            //deckSizeExtra = rand() % (MAX_DECK + 1 - 0) + 0;
            deckSizeExtra = rand() % (250 + 1 - 0) + 0;
            randDeckCardExtra = rand() % (deckSizeExtra + 1 - 0) + 0;
            //Deck
            state->deckCount[i] = 0;
            for (j = 0; j < randDeckCardExtra; j++) {
                randKingdomCardExtra = rand() % (26 + 1 - 0) + 0;
                state->deck[i][j] = kingdomCards[randKingdomCardExtra];
                state->deckCount[i]++;
            }
            //Discard
            state->discardCount[i] = 0;
            for (j = randDeckCardExtra; j < deckSizeExtra; j++) {
                randKingdomCardExtra = rand() % (26 + 1 - 0) + 0;
                state->discard[i][j] = kingdomCards[randKingdomCardExtra];
                state->discardCount[i]++;
            }
        }
    }
    state->numPlayers = numberPlayers;

    //Initialize turn
    state->outpostPlayed = 0;
    state->phase = 0;
    state->numActions = 1;
    state->numBuys = 1;
    state->playedCardCount = 0;
    state->whoseTurn = rand() % (numberPlayers-1+1 - 0) + 0;

    //Set random supply if flag set
    int j, k, rand10, randCard;
    int cards[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int check = 0;
    int counter = 0;
    if (supplyFlag) {
        //Set supply of victory cards and treasures to random amounts 1-10
        for (j = 0; j < 7; j++) {
            rand10 = rand() % (10+1 - 1) + 1;
            state->supplyCount[j] = rand10;
        }
        //Set supply of 10 random kingdom cards to random amounts 1-10
        for (j = 0; j < 10; j++) {
            rand10 = rand() % (10+1 - 1) + 1;
            do {
                check = 0;
                randCard = rand() % (26+1 - 7) + 7;
                for (k = 0; k < 10; k++) {
                    if (cards[k] == randCard) {
                        check = 1;
                        break;
                    }
                }
            } while (check != 0);
            cards[j] = randCard;
            state->supplyCount[randCard] = rand10;
        }
    }

    return;
}
