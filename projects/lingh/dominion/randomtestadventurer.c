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
    int i, numTests;
    numTests = 100;
    
    for (i = 0; i < numTests; i++) {
        randomGameState(&state, 0, 1);
        printf("numPlayers: %d\nhandCount0: %d\ndeckCount0: %d\ndiscardCount0: %d\n", state.numPlayers, state.handCount[0], state.deckCount[0], state.discardCount[0]);
        playAdventurer(&state);

    }


    

    return;
}
