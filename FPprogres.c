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
void printASCIIArt();
void printWelcomeMessage();
Song* create_song(const char* singer, const char* title);
Playlist* create_playlist(const char* name);
void add_song(Playlist* playlist, const char* singer, const char* title);
void display_playlist(Playlist* playlist);
Playlist* find_playlist(Playlist* head, const char* name);
Playlist* add_playlist(Playlist* head, const char* name);
void free_songs(Song* head);
void free_playlists(Playlist* head);

void printASCIIArt() {
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@                    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@    @@@@@@@@@@@       @@@@@@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@   @@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@   @@@@@@@@@@@@@@@@@@   @@@@@@  @@   @@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@                  @@@    @@@@@  @@@@@@@       @@@@      @@@     @  @       @@@@  @@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@    @@@@@@@@@@@@@@       @@@@@      @@@  @@@@   @  @@@@   @  @@@@  @@  @@@  @@@ @@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@                @@@@     @@@@@@@@@@   @  @@@@@  @  @@@@@  @  @@@@  @@  @@@@ @@  @@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@     @@@@@@@@@@@        @@@@@@ @@@@@  @   @@@  @@   @@@  @@   @@@  @@  @@@@    @@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@              @@@      @@@@@@@     @@@  @    @@@@@     @@@@    @  @@  @@@@@  @@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@                    @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
}

// Function to print welcome message
void printWelcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to Spotify - Feel the Music!   \n");
    printf("=========================================\n");
    printf("Explore millions of songs, playlists, and more.\n\n");
}

// Function to create a new playlist
Playlist* create_playlist(const char* name) {
    Playlist* new_playlist = (Playlist*)malloc(sizeof(Playlist));
    strcpy(new_playlist->name, name);
    new_playlist->head = NULL;
    new_playlist->next = NULL;
    return new_playlist;
}

// Function to create a new song node
Song* create_song(const char* singer, const char* title) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->singer, singer);
    strcpy(new_song->title, title);
    new_song->next = NULL;
    return new_song;
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

// Function to display songs in a playlist
void display_playlist(Playlist* playlist) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty!\n", playlist->name);
        return;
    }
    printf("Songs in playlist '%s':\n", playlist->name);
    Song* temp = playlist->head;
    int i = 1;
    while (temp) {
        printf("%d. %s - %s\n", i++, temp->title, temp->singer);
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

// Function to free all songs in a playlist
void free_songs(Song* head) {
    while (head) {
        Song* temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free all playlists
void free_playlists(Playlist* head) {
    while (head) {
        Playlist* temp = head;
        free_songs(head->head);
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    Playlist* playlists = NULL;
    int choice;
    char playlist_name[100], singer[100], title[100];

    // Clear the screen (cross-platform)
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[1;1H");
#endif

    // Print the Spotify intro
    printASCIIArt();
    printWelcomeMessage();

    do {
        printf("\nMenu:\n");
        printf("1. Add Playlist\n");
        printf("2. Add Song to Playlist\n");
        printf("3. Display Songs in Playlist\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                playlists = add_playlist(playlists, playlist_name);
                printf("Playlist '%s' created.\n", playlist_name);
                printf("\n1. Back to menu\n");
                printf("2. Exit\n");
                printf("Enter your choice:");
                if(getchar()== '1') {
                    break;
                }else if (getchar()== '2') {
                    return 0;
                }
                break;
            case 2: {
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Singer: ");
                    scanf(" %99[^\n]", singer);
                    printf("Enter Title: ");
                    scanf(" %99[^\n]", title);
                    add_song(playlist, singer, title);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name); 
                }
                printf("\n1. Back to menu\n");
                printf("2. Exit\n");
                printf("Enter your choice:");
                if(getchar()== '1') {
                    break;
                }else if (getchar()== '2') {
                    return 0;
                }
                break;
            }
            case 3: {
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    display_playlist(playlist);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                printf("\n1. Back to menu\n");
                printf("2. Exit\n");
                printf("Enter your choice:");
                if(getchar()== '1') {
                    break;
                }else if (getchar()== '2') {
                    return 0;
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                free_playlists(playlists);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
 