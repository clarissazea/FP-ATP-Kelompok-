#include <stdio.h>

void printSpotifyLogo() {
    printf("   OOO      \n");
    printf("  O   O     \n");
    printf(" O     O    \n");
    printf(" O     O    \n");
    printf("  O   O     \n");
    printf("   OOO      \n");
}

void printASCIIArt() {
    printf(" .d8888b.  8888888b.   .d88888b. 88888888888 8888888 8888888888 Y88b   d88P \n");
    printf("d88P  Y88b 888   Y88b d88P\" \"Y88b    888       888   888         Y88b d88P  \n");
    printf("Y88b.      888    888 888     888    888       888   888          Y88o88P   \n");
    printf(" \"Y888b.   888   d88P 888     888    888       888   8888888       Y888P    \n");
    printf("    \"Y88b. 8888888P\"  888     888    888       888   888            888     \n");
    printf("      \"888 888        888     888    888       888   888            888     \n");
    printf("Y88b  d88P 888        Y88b. .d88P    888       888   888            888     \n");
    printf(" \"Y8888P\"  888         \"Y88888P\"     888     8888888 888            888     \n");
}

int main() {
    printASCIIArt();
    return 0;
}

void printWelcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to Spotify - Feel the Music!   \n");
    printf("=========================================\n");
    printf("Explore millions of songs, podcasts, and more.\n");
    printf("\n");
}

void printMenu() {
    printf("Choose an option to get started:\n");
    printf("[1] Browse Music\n");
    printf("[2] Playlists\n");
    printf("[3] Podcasts\n");
    printf("[4] Settings\n");
    printf("[5] Exit\n");
    printf("\n");
}

int main() {
    // Clear screen (may vary by OS; here for Unix/Linux/MacOS)
    printf("\033[2J\033[1;1H"); // Clear terminal screen

    // Print the Spotify ASCII logo and interface
    printSpotifyLogo();
    printSpotifyBanner();
    printWelcomeMessage();
    printMenu();

    // Prompt user input
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Respond to user choice
    switch (choice) {
        case 1:
            printf("\nOpening the Music Library...\n");
            break;
        case 2:
            printf("\nLoading your Playlists...\n");
            break;
        case 3:
            printf("\nAccessing Podcasts...\n");
            break;
        case 4:
            printf("\nOpening Settings...\n");
            break;
        case 5:
            printf("\nThank you for using Spotify! See you next time!\n");
            break;
        default:
            printf("\nInvalid choice. Please restart the app.\n");
            break;
    }

    return 0;
}

