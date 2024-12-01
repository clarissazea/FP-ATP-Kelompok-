#include <stdio.h>

void printSpotifyLogo() {
    printf("   OOO      \n");
    printf("  O   O     \n");
    printf(" O     O    \n");
    printf(" O     O    \n");
    printf("  O   O     \n");
    printf("   OOO      \n");
}

void printSpotifyBanner() {
    printf("   _____             _   _  __         \n");
    printf("  / ____|           | | (_)/ _|        \n");
    printf(" | (___   ___   ___ | |_ _| |_ _   _   \n");
    printf("  \\___ \\ / _ \\ / _ \\| __| |  _| | | |  \n");
    printf("  ____) | (_) | (_) | |_| | | | |_| |  \n");
    printf(" |_____/ \\___/ \\___/ \\__|_|_|  \\__, |  \n");
    printf("                               __/ |  \n");
    printf("                              |___/   \n");
    printf("\n");
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

