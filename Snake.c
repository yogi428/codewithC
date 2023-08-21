#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 100
#define NUM_PLAYERS 2
#define NUM_SNAKES 5
#define NUM_LADDERS 5

// ... (Rest of the code from the Snake and Ladder game snippet)

// ... (Rest of the code from the User Signup page snippet)

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Snake and Ladder Game Setup
    int playerPositions[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        playerPositions[i] = 1; // Initialize all players at position 1
    }

    printf("Welcome to the Snake and Ladder Game!\n");

    // User Signup Page
    char username[50];
    char password[50];

    printf("Welcome to the Signup Page!\n");

    // Get username from the user and check if it's available
    while (1) {
        printf("Choose a username: ");
        scanf("%s", username);

        if (isUsernameTaken(username)) {
            printf("Username already taken. Please choose a different username.\n");
        } else {
            break;
        }
    }

    // Get password from the user
    printf("Choose a password: ");
    scanf("%s", password);

    // Save the new user to the "users.txt" file
    if (saveUser(username, password)) {
        printf("Signup successful! Your account has been created.\n");
    } else {
        printf("Error saving user details. Please try again later.\n");
        return 1;
    }

    // Create a file for the new user to store additional information (if needed)
    if (createUserFile(username)) {
        printf("User file created successfully.\n");
    } else {
        printf("Error creating user file. Please try again later.\n");
        return 1;
    }

    // Snake and Ladder Game Loop
    int currentPlayerIndex = 0;
    while (1) {
        // ... (Rest of the game loop code from the Snake and Ladder game snippet)
    }

    return 0;
}
