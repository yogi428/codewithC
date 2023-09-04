#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100
#define NUM_PLAYERS 10
#define NUM_SNAKES 5
#define NUM_LADDERS 5

int snakes[NUM_SNAKES][2] = {
    {16, 6},
    {47, 26},
    {49, 11},
    {56, 53},
    {62, 19}
};

int ladders[NUM_LADDERS][2] = {
    {4, 14},
    {9, 31},
    {20, 38},
    {28, 84},
    {40, 59}
};

int rollDice() {
    return rand() % 6 + 1;
}

int movePlayer(int currentPlayerPosition, int diceValue) {
    int newPosition = currentPlayerPosition + diceValue;
    if (newPosition > BOARD_SIZE) {
        newPosition = BOARD_SIZE - (newPosition - BOARD_SIZE);
    }

    for (int i = 0; i < NUM_SNAKES; i++) {
        if (newPosition == snakes[i][0]) {
            printf("Oops! Snake bites. Going down from %d to %d\n", newPosition, snakes[i][1]);
            newPosition = snakes[i][1];
            break;
        }
    }

    for (int i = 0; i < NUM_LADDERS; i++) {
        if (newPosition == ladders[i][0]) {
            printf("Yay! Climbing up the ladder from %d to %d\n", newPosition, ladders[i][1]);
            newPosition = ladders[i][1];
            break;
        }
    }

    return newPosition;
}

void displayBoard(int playerPositions[]) {
    printf("\n");
    int position = 100; // Start at position 100

    for (int row = 1; row <= 10; row++) {
        for (int col = 1; col <= 10; col++) {
            // Check if any player is present at this position
            int playerPresent = 0;
            for (int i = 0; i < NUM_PLAYERS; i++) {
                if (playerPositions[i] == position) {
                    printf("P%d ", i + 1);
                    playerPresent = 1;
                }
            }

            if (!playerPresent) {
                printf("%02d ", position);
            }
            position--;
        }
        printf("\n");
    }
}



int main() {
    srand(time(NULL));

    int playerPositions[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        playerPositions[i] = 1;
    }

    printf("Welcome to the Snake and Ladder Game!\n");

    int currentPlayerIndex = 0;
    while (1) {
        printf("\nCurrent Positions:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %d: %d\n", i + 1, playerPositions[i]);
        }

        displayBoard(playerPositions);

        printf("\nPlayer %d's Turn:\n", currentPlayerIndex + 1);
        printf("Press Enter to roll the dice...");
        getchar();
        int diceValue = rollDice();
        printf("Player %d rolled a %d\n", currentPlayerIndex + 1, diceValue);

        int currentPlayerPosition = playerPositions[currentPlayerIndex];
        int newPosition = movePlayer(currentPlayerPosition, diceValue);
        playerPositions[currentPlayerIndex] = newPosition;

        if (newPosition == BOARD_SIZE) {
            printf("Player %d wins!\n", currentPlayerIndex + 1);
            break;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % NUM_PLAYERS;
    }

    return 0;
}
