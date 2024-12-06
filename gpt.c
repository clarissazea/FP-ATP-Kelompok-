#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefisinikan struktur untuk lagu 
typedef struct Song {
    char singer[100];
    char title[100];
    int duration; // Durasi lagu dalam detik
    struct Song* next;
} Song;

// Mendefinisikan struktur untuk playlist
typedef struct Playlist {
    char name[100];
    Song* head;
    struct Playlist* next;
} Playlist;

// Mendefinisikan fungsi untuk dipanggil
void printASCIIArt();
void printWelcomeMessage();
Song* create_song(const char* singer, const char* title, int duration);
Playlist* create_playlist(const char* name);
void add_song(Playlist* playlist, const char* singer, const char* title, int duration);
void display_playlist(Playlist* playlist);
Playlist* find_playlist(Playlist* head, const char* name);
Playlist* add_playlist(Playlist* head, const char* name);
void free_songs(Song* head);
void free_playlists(Playlist* head);

// Fungsi tambahan
void search_song_by_title(Playlist* playlist, const char* title);
void sort_songs_by_singer(Playlist* playlist);

// Implementasi fungsi baru
Song* create_song(const char* singer, const char* title, int duration) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->singer, singer);
    strcpy(new_song->title, title);
    new_song->duration = duration;
    new_song->next = NULL;
    return new_song;
}

void add_song(Playlist* playlist, const char* singer, const char* title, int duration) {
    Song* new_song = create_song(singer, title, duration);
    if (!playlist->head) {
        playlist->head = new_song;
    } else {
        Song* temp = playlist->head;
        while (temp->next) temp = temp->next;
        temp->next = new_song;
    }
    printf("Song added to playlist '%s'.\n", playlist->name);
}

void search_song_by_title(Playlist* playlist, const char* title) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty!\n", playlist->name);
        return;
    }
    Song* temp = playlist->head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Found: %s - %s (%d seconds)\n", temp->title, temp->singer, temp->duration);
            return;
        }
        temp = temp->next;
    }
    printf("Song '%s' not found in playlist '%s'.\n", title, playlist->name);
}

void sort_songs_by_singer(Playlist* playlist) {
    if (!playlist->head || !playlist->head->next) return;

    Song* i;
    Song* j;
    for (i = playlist->head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->singer, j->singer) > 0) {
                // Tukar data
                char temp_singer[100], temp_title[100];
                int temp_duration;

                strcpy(temp_singer, i->singer);
                strcpy(temp_title, i->title);
                temp_duration = i->duration;

                strcpy(i->singer, j->singer);
                strcpy(i->title, j->title);
                i->duration = j->duration;

                strcpy(j->singer, temp_singer);
                strcpy(j->title, temp_title);
                j->duration = temp_duration;
            }
        }
    }
    printf("Playlist '%s' sorted by singer.\n", playlist->name);
}

// Perubahan pada fungsi main
int main() {
    Playlist* playlists = NULL;
    int choice;
    char playlist_name[100], singer[100], title[100];
    int duration;

    do {
        printf("\nMenu:\n");
        printf("1. Add Playlist\n");
        printf("2. Add Song to Playlist\n");
        printf("3. Remove Song from Playlist\n");
        printf("4. Display Songs in Playlist\n");
        printf("5. Display All Playlists\n");
        printf("6. Search Song by Title\n");
        printf("7. Sort Songs by Singer\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                playlists = add_playlist(playlists, playlist_name);
                printf("Playlist '%s' created.\n", playlist_name);
                break;
            case 2:
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Singer: ");
                    scanf(" %99[^\n]", singer);
                    printf("Enter Title: ");
                    scanf(" %99[^\n]", title);
                    printf("Enter Duration (in seconds): ");
                    scanf("%d", &duration);
                    add_song(playlist, singer, title, duration);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            case 6:
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    printf("Enter Title to Search: ");
                    scanf(" %99[^\n]", title);
                    search_song_by_title(playlist, title);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            case 7:
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                playlist = find_playlist(playlists, playlist_name);
                if (playlist) {
                    sort_songs_by_singer(playlist);
                } else {
                    printf("Playlist '%s' not found.\n", playlist_name);
                }
                break;
            // Kasus lain tetap sama
            case 8:
                printf("Exiting...\n");
                free_playlists(playlists);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
