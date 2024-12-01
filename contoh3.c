#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a song
typedef struct Song {
    char singer[100];
    char title[100];
    struct Song* next;
} Song;

// Define the structure for a playlist
typedef struct Playlist {
    char name[100];
    Song* head;
    struct Playlist* next;
} Playlist;

// Function prototypes
void printSpotifyLogo();
void printSpotifyBanner();
void printWelcomeMessage();
Song* create_song(const char* singer, const char* title);
Playlist* create_playlist(const char* name);
void add_song(Playlist* playlist, const char* singer, const char* title);
void remove_song(Playlist* playlist, const char* title);
void display_playlist(Playlist* playlist);
Playlist* find_playlist(Playlist* head, const char* name);
Playlist* add_playlist(Playlist* head, const char* name);
void display_all_playlists(Playlist* head);

// Function to print Spotify logo
void printSpotifyLogo() {
    printf("   OOO      \n");
    printf("  O   O     \n");
    printf(" O     O    \n");
    printf(" O     O    \n");
    printf("  O   O     \n");
    printf("   OOO      \n");
}

// Function to print Spotify banner
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

// Function to print welcome message
void printWelcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to Spotify - Feel the Music!   \n");
    printf("=========================================\n");
    printf("Explore millions of songs, playlists, and more.\n\n");
}

// Function to create a new song node
Song* create_song(const char* singer, const char* title) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->singer, singer);
    strcpy(new_song->title, title);
    new_song->next = NULL;
    return new_song;
}

// Function to create a new playlist
Playlist* create_playlist(const char* name) {
    Playlist* new_playlist = (Playlist*)malloc(sizeof(Playlist));
    strcpy(new_playlist->name, name);
    new_playlist->head = NULL;
    new_playlist->next = NULL;
    return new_playlist;
}

// Function to add a song to a playlist
void add_song(Playlist* playlist, const char* singer, const char* title) {
    Song* new_song = create_song(singer, title);
    if (!playlist->head) {
        playlist->head = new_song;
    } else {
        Song* temp = playlist->head;
        while (temp->next) temp = temp->next;
        temp->next = new_song;
    }
    printf("Song added to playlist '%s'.\n", playlist->name);
}

// Function to remove a song from a playlist
void remove_song(Playlist* playlist, const char* title) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty!\n", playlist->name);
        return;
    }
    if (strcmp(playlist->head->title, title) == 0) {
        Song* temp = playlist->head;
        playlist->head = playlist->head->next;
        free(temp);
        printf("Song removed from playlist '%s'.\n", playlist->name);
        return;
    }
    Song* temp = playlist->head;
    while (temp->next && strcmp(temp->next->title, title) != 0)
        temp = temp->next;
    if (temp->next) {
        Song* to_delete = temp->next;
        temp->next = temp->next->next;
        free(to_delete);
        printf("Song removed from playlist '%s'.\n", playlist->name);
    } else {
        printf("Song not found in playlist '%s'.\n", playlist->name);
    }
}

// Function to display all songs in a playlist
void display_playlist(Playlist* playlist) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty!\n", playlist->name);
        return;
    }
    printf("Songs in playlist '%s':\n", playlist->name);
    Song* temp = playlist->head;
    while (temp) {
        printf("%s - %s\n", temp->singer, temp->title); // Ubah format output di sini
        temp = temp->next;
    }
}

// Function to find a playlist by name
Playlist* find_playlist(Playlist* head, const char* name) {
    while (head && strcmp(head->name, name) != 0)
        head = head->next;
    return head;
}

// Function to add a new playlist
Playlist* add_playlist(Playlist* head, const char* name) {
    Playlist* new_playlist = create_playlist(name);
    if (!head) return new_playlist;
    Playlist* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_playlist;
    return head;
}

// Function to display all playlists
void display_all_playlists(Playlist* head) {
    if (!head) {
        printf("No playlists available.\n");
        return;
    }
    printf("Available Playlists:\n");
    while (head) {
        printf("- %s\n", head->name);
        head = head->next;
    }
}

// Main function
int main() {
    Playlist* playlists = NULL;
    int choice;
    char playlist_name[100], singer[100], title[100];

    // Clear the screen (for Unix/Linux/MacOS)
    printf("\033[2J\033[1;1H");

    // Print the Spotify intro
    printSpotifyLogo();
    printSpotifyBanner();
    printWelcomeMessage();

    do {
        printf("\nMenu:\n");
        printf("1. Add Playlist\n");
        printf("2. Add Song to Playlist\n");
        printf("3. Remove Song from Playlist\n");
        printf("4. Display Songs in Playlist\n");
        printf("5. Display All Playlists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter playlist name: ");
                scanf(" %[^\n]s", playlist_name);
                playlists = add_playlist(playlists, playlist_name);
                printf("Playlist '%s' created.\n", playlist_name);
                break;
            case 2:
                printf("Enter playlist name: ");
                scanf(" %[^\n]s", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Singer: ");
                    scanf(" %[^\n]s", singer);
                    printf("Enter Title: ");
                    scanf(" %[^\n]s", title);1
                    add_song(playlist, singer, title);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            case 3:
                printf("Enter playlist name: ");
                scanf(" %[^\n]s", playlist_name);
                playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Title of the song to remove: ");
                    scanf(" %[^\n]s", title);
                    remove_song(playlist, title);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            case 4:
                printf("Enter playlist name: ");
                scanf(" %[^\n]s", playlist_name);
                playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    display_playlist(playlist);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            case 5:
                display_all_playlists(playlists);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
