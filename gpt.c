#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefinisikan struktur untuk lagu 
typedef struct Song {
    char singer[100];
    char title[100];
    char album[100];
    int duration; // durasi dalam detik
    struct Song* next;
} Song;

// Mendefinisikan struktur untuk playlist
typedef struct Playlist {
    char name[100];
    Song* head;
    struct Playlist* next;
} Playlist;

// Fungsi prototipe
void printASCIIArt();
void printWelcomeMessage();
Song* create_song(const char* singer, const char* title, const char* album, int duration);
Playlist* create_playlist(const char* name);
void add_song(Playlist* playlist, const char* singer, const char* title, const char* album, int duration);
void display_playlist(Playlist* playlist);
Playlist* find_playlist(Playlist* head, const char* name);
Playlist* add_playlist(Playlist* head, const char* name);
void search_song(Playlist* playlist, const char* title);
void sort_playlist(Playlist* playlist, int by_singer);
void display_all_playlists(Playlist* head);
void free_songs(Song* head);
void free_playlists(Playlist* head);

// Fungsi utama
int main() {
    Playlist* playlists = NULL;
    int choice;

    // Membersihkan layar
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[1;1H");
#endif

    // Menampilkan tampilan awal Spotify
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
        printf("7. Exit\n");
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
                display_all_playlists(playlists);
                break;
            case 7:
                printf("Exiting...\n");
                free_playlists(playlists);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Fungsi tambahan
Song* create_song(const char* singer, const char* title, const char* album, int duration) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->singer, singer);
    strcpy(new_song->title, title);
    strcpy(new_song->album, album);
    new_song->duration = duration;
    new_song->next = NULL;
    return new_song;
}

void add_song(Playlist* playlist, const char* singer, const char* title, const char* album, int duration) {
    Song* new_song = create_song(singer, title, album, duration);
    if (!playlist->head) {
        playlist->head = new_song;
    } else {
        Song* temp = playlist->head;
        while (temp->next) temp = temp->next;
        temp->next = new_song;
    }
    printf("Song added to playlist '%s'.\n", playlist->name);
}

void display_playlist(Playlist* playlist) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty!\n", playlist->name);
        return;
    }
    printf("Songs in playlist '%s':\n", playlist->name);
    Song* temp = playlist->head;
    while (temp) {
        printf("- %s by %s (%s) [%d sec]\n", temp->title, temp->singer, temp->album, temp->duration);
        temp = temp->next;
    }
}

int starts_with(const char *str, const char *prefix) {
    size_t prefix_len = strlen(prefix);

    // Compare the first prefix_len characters of str with prefix
    return strncmp(str, prefix, prefix_len) == 0;
}

void search_song(Playlist* playlist, const char* title) {
    Song* temp = playlist->head;
    int found =0;
    while (temp) {
        // if (strcmp(temp->title, title) == 0) {
        // if (strstr(temp->title,title)!=NULL){
        if (starts_with(temp->title,title)){
            printf("Found: %s by %s (%s) [%d sec]\n", temp->title, temp->singer, temp->album, temp->duration);
            // return;
            found=1;
        }
        temp = temp->next;
    }
    if (found!=1){
        printf("Title '%s' not found in playlist '%s'.\n", title, playlist->name);
    }
}

void sort_playlist(Playlist* playlist, int by_singer) {
    if (!playlist->head) return;
    for (Song* i = playlist->head; i && i->next; i = i->next) {
        for (Song* j = playlist->head; j->next; j = j->next) {
            int comparison = by_singer 
                             ? strcmp(j->singer, j->next->singer) 
                             : strcmp(j->title, j->next->title);
            if (comparison > 0) {
                Song temp = *j;
                *j = *(j->next);
                *(j->next) = temp;
            }
        }
    }
}

void display_all_playlists(Playlist* head) {
    if (!head) {
        printf("No playlists available.\n");
        return;
    }
    printf("Available Playlists:\n");
    while (head) {
        int total_duration = 0;
        Song* temp = head->head;
        while (temp) {
            total_duration += temp->duration;
            temp = temp->next;
        }
        printf("- %s (Total Duration: %d seconds)\n", head->name, total_duration);
        head = head->next;
    }
}

Playlist* find_playlist(Playlist* head, const char* name) {
    while (head && strcmp(head->name, name) != 0)
        head = head->next;
    return head;
}

Playlist* add_playlist(Playlist* head, const char* name) {
    Playlist* new_playlist = (Playlist*)malloc(sizeof(Playlist));
    strcpy(new_playlist->name, name);
    new_playlist->head = NULL;
    new_playlist->next = NULL;
    if (!head) return new_playlist;
    Playlist* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_playlist;
    return head;
}

void free_songs(Song* head) {
    while (head) {
        Song* temp = head;
        head = head->next;
        free(temp);
    }
}

void free_playlists(Playlist* head) {
    while (head) {
        Playlist* temp = head;
        free_songs(head->head);
        head = head->next;
        free(temp);
    }
}

void printASCIIArt() {
    // Placeholder ASCII art
    printf("=== Welcome to Spotify! ===\n");
}

void printWelcomeMessage() {
    printf("Enjoy millions of songs and playlists.\n");
}