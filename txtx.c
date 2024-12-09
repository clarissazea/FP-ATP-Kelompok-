#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Fungsi untuk mencetak ASCII Art
void printASCIIArt() {
    printf("\033[32;1m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@@@@@            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@@@                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@                    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@    @@@@@@@@@@@       @@@@@@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@   @@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@   @@@@@@@@@@@@@@@@@@   @@@@@@  @@   @@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@                  @@@    @@@@@  @@@@@@@       @@@@      @@@     @  @       @@@@  @@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@    @@@@@@@@@@@@@@       @@@@@      @@@  @@@@   @  @@@@   @  @@@@  @@  @@@  @@@ @@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@                @@@@     @@@@@@@@@@   @  @@@@@  @  @@@@@  @  @@@@  @@  @@@@ @@  @@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@     @@@@@@@@@@@        @@@@@@ @@@@@  @   @@@  @@   @@@  @@   @@@  @@  @@@@    @@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@              @@@      @@@@@@@     @@@  @    @@@@@     @@@@    @  @@  @@@@@  @@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@                    @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
    printf("\033[32;1m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
}

// Fungsi untuk mencetak pesan selamat datang
void printWelcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to Spotify - Feel the Music!   \n");
    printf("=========================================\n");
    printf("Explore millions of songs, playlists, and more.\n\n");
}

// Fungsi untuk membuat lagu baru
Song* create_song(const char* singer, const char* title, const char* album, int duration) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->singer, singer);
    strcpy(new_song->title, title);
    strcpy(new_song->album, album);
    new_song->duration = duration;
    new_song->next = NULL;
    return new_song;
}

// Fungsi untuk menambahkan lagu ke playlist
void add_song(Playlist* playlist, const char* singer, const char* title, const char* album, int duration) {
    Song* new_song = create_song(singer, title, album, duration);
    if (!playlist->head) {
        playlist->head = new_song;
    } else {
        Song* temp = playlist->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_song;
    }
}

// Fungsi untuk menampilkan semua lagu dalam playlist
void display_playlist(Playlist* playlist) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty.\n", playlist->name);
        return;
    }
    Song* temp = playlist->head;
    printf("Songs in playlist '%s':\n", playlist->name);
    while (temp) {
        printf("Singer: %s | Title: %s | Album: %s | Duration: %d seconds\n", temp->singer, temp->title, temp->album, temp->duration);
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan semua playlist
void display_all_playlists(Playlist* head) {
    if (!head) {
        printf("No playlists available.\n");
        return;
    }
    Playlist* temp = head;
    printf("Available playlists:\n");
    while (temp) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
}

// Fungsi untuk menambahkan playlist baru
Playlist* add_playlist(Playlist* head, const char* name) {
    Playlist* new_playlist = (Playlist*)malloc(sizeof(Playlist));
    strcpy(new_playlist->name, name);
    new_playlist->head = NULL;
    new_playlist->next = NULL;

    if (!head) {
        return new_playlist;
    }
    Playlist* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_playlist;
    return head;
}

// Fungsi untuk menghapus semua lagu dalam playlist
void free_songs(Song* head) {
    Song* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Fungsi untuk menghapus semua playlist
void free_playlists(Playlist* head) {
    Playlist* temp;
    while (head) {
        temp = head;
        head = head->next;
        free_songs(temp->head);
        free(temp);
    }
}

// Fungsi untuk mengunduh playlist ke dalam file teks
void download_playlist(Playlist* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    Playlist* temp_playlist = head;
    while (temp_playlist) {
        fprintf(file, "Playlist: %s\n", temp_playlist->name);
        Song* temp_song = temp_playlist->head;
        while (temp_song) {
            fprintf(file, "  Singer: %s | Title: %s | Album: %s | Duration: %d seconds\n",
                    temp_song->singer, temp_song->title, temp_song->album, temp_song->duration);
            temp_song = temp_song->next;
        }
        fprintf(file, "\n");
        temp_playlist = temp_playlist->next;
    }

    fclose(file);
    printf("Playlist saved to '%s'.\n", filename);
}

// Fungsi utama
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
        printf("4. Display All Playlists\n");
        printf("5. Download Playlist to txt\n");
        printf("6. Exit\n");
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
                char playlist_name[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = playlists;
                while (playlist && strcmp(playlist->name, playlist_name) != 0) {
                    playlist = playlist->next;
                }
                if (!playlist) {
                    printf("Playlist '%s' not found.\n", playlist_name);
                } else {
                    char singer[100], title[100], album[100];
                    int duration;
                    printf("Enter singer: ");
                    scanf(" %99[^\n]", singer);
                    printf("Enter title: ");
                    scanf(" %99[^\n]", title);
                    printf("Enter album: ");
                    scanf(" %99[^\n]", album);
                    printf("Enter duration (in seconds): ");
                    scanf("%d", &duration);
                    add_song(playlist, singer, title, album, duration);
                    printf("Song added to playlist '%s'.\n", playlist_name);
                }
                break;
            }
            case 3: {
                char playlist_name[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = playlists;
                while (playlist && strcmp(playlist->name, playlist_name) != 0) {
                    playlist = playlist->next;
                }
                if (!playlist) {
                    printf("Playlist '%s' not found.\n", playlist_name);
                } else {
                    display_playlist(playlist);
                }
                break;
            }
            case 4:
                display_all_playlists(playlists);
                break;
            case 5: {
                char filename[100];
                printf("Enter filename to save playlist (e.g., my_playlist.txt): ");
                scanf(" %99[^\n]", filename);
                download_playlist(playlists, filename);
                break;
            }
            case 6:
                printf("Exiting...\n");
                free_playlists(playlists);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
