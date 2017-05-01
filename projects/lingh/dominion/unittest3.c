#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <stdio.h>
#include <stdlib.h>

void testGetCost() {
    printf("\n----------TESTING FUNCTION: getCost()----------\n");
    
    //TEST RUNS
    //TEST 1: Cost of a curse
    printf("TEST 1 - Call on curse card: ");
    assertTrue(getCost(curse), 0);
    
    //TEST 2: Cost of a estate
    printf("TEST 2 - Call on estate card: ");
    assertTrue(getCost(estate), 2);
    
    //TEST 3: Cost of a duchy
    printf("TEST 3 - Call on duchy card: ");
    assertTrue(getCost(duchy), 5);
    
    //TEST 4: Cost of a province
    printf("TEST 4 - Call on province card: ");
    assertTrue(getCost(province), 8);
    
    //TEST 5: Cost of a copper
    printf("TEST 5 - Call on copper card: ");
    assertTrue(getCost(copper), 0);
    
    //TEST 6: Cost of a silver
    printf("TEST 6 - Call on silver card: ");
    assertTrue(getCost(silver), 3);
    
    //TEST 7: Cost of a gold
    printf("TEST 7 - Call on gold card: ");
    assertTrue(getCost(gold), 6);
    
    //TEST 8: Cost of a adventurer
    printf("TEST 8 - Call on adventurer card: ");
    assertTrue(getCost(adventurer), 6);
    
    //TEST 9: Cost of a council_room
    printf("TEST 9 - Call on council_room card: ");
    assertTrue(getCost(council_room), 5);
    
    //TEST 10: Cost of a feast
    printf("TEST 10 - Call on feast card: ");
    assertTrue(getCost(feast), 4);
    
    //TEST 11: Cost of a gardens
    printf("TEST 11 - Call on gardens card: ");
    assertTrue(getCost(gardens), 4);
    
    //TEST 12: Cost of a mine
    printf("TEST 12 - Call on mine card: ");
    assertTrue(getCost(mine), 5);
    
    //TEST 13: Cost of a remodel
    printf("TEST 13 - Call on remodel card: ");
    assertTrue(getCost(remodel), 4);
    
    //TEST 14: Cost of a smithy
    printf("TEST 14 - Call on smithy card: ");
    assertTrue(getCost(smithy), 4);
    
    //TEST 15: Cost of a village
    printf("TEST 15 - Call on village card: ");
    assertTrue(getCost(village), 3);
    
    //TEST 16: Cost of a baron
    printf("TEST 16 - Call on baron card: ");
    assertTrue(getCost(baron), 4);
    
    //TEST 17: Cost of a great_hall
    printf("TEST 17 - Call on great_hall card: ");
    assertTrue(getCost(great_hall), 3);
    
    //TEST 18: Cost of a minion
    printf("TEST 18 - Call on minion card: ");
    assertTrue(getCost(minion), 5);
    
    //TEST 19: Cost of a steward
    printf("TEST 19 - Call on steward card: ");
    assertTrue(getCost(steward), 3);
    
    //TEST 20: Cost of a tribute
    printf("TEST 20 - Call on tribute card: ");
    assertTrue(getCost(tribute), 5);
    
    //TEST 21: Cost of a ambassador
    printf("TEST 21 - Call on ambassador card: ");
    assertTrue(getCost(ambassador), 3);
    
    //TEST 22: Cost of a cutpurse
    printf("TEST 22 - Call on cutpurse card: ");
    assertTrue(getCost(cutpurse), 4);
    
    //TEST 23: Cost of a embargo
    printf("TEST 23 - Call on embargo card: ");
    assertTrue(getCost(embargo), 2);
    
    //TEST 24: Cost of a outpost
    printf("TEST 24 - Call on outpost card: ");
    assertTrue(getCost(outpost), 5);
    
    //TEST 25: Cost of a salvager
    printf("TEST 25 - Call on salvager card: ");
    assertTrue(getCost(salvager), 4);
    
    //TEST 26: Cost of a sea_hag
    printf("TEST 26 - Call on sea_hag card: ");
    assertTrue(getCost(sea_hag), 4);
    
    //TEST 27: Cost of a treasure_map
    printf("TEST 27 - Call on treasure_map card: ");
    assertTrue(getCost(treasure_map), 4);
    
    //TEST 28: Invalid card
    printf("TEST 28 - Call on invalid card: ");
    assertTrue(getCost(9999), -1);


    printf("\n");
    return;
}

int main(int argc, char *argv[]) {
    testGetCost();
    return 0;
}

