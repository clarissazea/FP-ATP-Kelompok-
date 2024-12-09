#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printWelcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to Spotify - Feel the Music!   \n");
    printf("=========================================\n");
    printf("Explore millions of songs, playlists, and more.\n\n");
}

// Struktur untuk lagu
typedef struct Song {
    char singer[100];
    char title[100];
    char album[100];
    int duration;
    struct Song* next;
} Song;

// Struktur untuk playlist
typedef struct Playlist {
    char name[100];
    Song* head;
    struct Playlist* next;
} Playlist;

// Prototipe fungsi
void add_song(Playlist* playlist, const char* singer, const char* title, const char* album, int duration);
void display_playlist(Playlist* playlist);
void search_song(Playlist* playlist, const char* title);
void sort_playlist(Playlist* playlist, int by_singer);
void remove_song(Playlist* playlist, const char* title);
void load_songs_from_file(Playlist* playlist, const char* filename);
Playlist* find_playlist(Playlist* head, const char* name);
Playlist* add_playlist(Playlist* head, const char* name);
void free_playlists(Playlist* head);
void printWelcomeMessage();

int main() {
    Playlist* playlists = NULL;
    int choice;

#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[1;1H");
#endif

    printASCIIArt();
    printWelcomeMessage();

    do {
        printf("\nMenu:\n");
        printf("1. Add Playlist\n");
        printf("2. Add Song to Playlist\n");
        printf("3. Display Songs in Playlist\n");
        printf("4. Search Song in Playlist\n");
        printf("5. Sort Playlist\n");
        printf("6. Display All Playlists\n");
        printf("7. Remove Song from Playlist\n");
        printf("8. Load Songs from File\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char playlist_name[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                playlists = add_playlist(playlists, playlist_name);
                printf("Playlist '%s' created.\n", playlist_name);
                break;
            }
            case 2: {
                char playlist_name[100], singer[100], title[100], album[100];
                int duration;
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Singer: ");
                    scanf(" %99[^\n]", singer);
                    printf("Enter Title: ");
                    scanf(" %99[^\n]", title);
                    printf("Enter Album: ");
                    scanf(" %99[^\n]", album);
                    printf("Enter Duration (in seconds): ");
                    scanf("%d", &duration);
                    add_song(playlist, singer, title, album, duration);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            }
            case 3: {
                char playlist_name[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    display_playlist(playlist);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            }
            case 4: {
                char playlist_name[100], title[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Title to Search: ");
                    scanf(" %99[^\n]", title);
                    search_song(playlist, title);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            }
            case 5: {
                char playlist_name[100];
                int sort_choice;
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Sort by:\n");
                    printf("1. Title\n");
                    printf("2. Singer\n");
                    printf("Enter your choice: ");
                    scanf("%d", &sort_choice);
                    sort_playlist(playlist, sort_choice == 2);
                    printf("Playlist '%s' sorted.\n", playlist_name);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            }
            case 6:
                display_playlist(playlists);
                break;
            case 7: {
                char playlist_name[100], title[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Title of Song to Remove: ");
                    scanf(" %99[^\n]", title);
                    remove_song(playlist, title);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            }
            case 8: {
                char playlist_name[100], filename[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter filename: ");
                    scanf(" %99[^\n]", filename);
                    load_songs_from_file(playlist, filename);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            }
            case 9:
                printf("Exiting...\n");
                free_playlists(playlists);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);

    return 0;
}

// Tambahkan implementasi fungsi tambahan lainnya...
