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

void printASCIIArt() {
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@                    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@    @@@@@@@@@@@       @@@@@@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@   @@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@   @@@@@@@@@@@@@@@@@@   @@@@@@  @@   @@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@                  @@@    @@@@@  @@@@@@@       @@@@      @@@     @  @       @@@@  @@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@    @@@@@@@@@@@@@@       @@@@@      @@@  @@@@   @  @@@@   @  @@@@  @@  @@@  @@@ @@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@                @@@@     @@@@@@@@@@   @  @@@@@  @  @@@@@  @  @@@@  @@  @@@@ @@  @@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@     @@@@@@@@@@@        @@@@@@ @@@@@  @   @@@  @@   @@@  @@   @@@  @@  @@@@    @@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@              @@@      @@@@@@@     @@@  @    @@@@@     @@@@    @  @@  @@@@@  @@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@                    @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
    printf("\033[32;1m @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \033[0m\n");
}

void printWelcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to Spotify - Feel the Music!   \n");
    printf("=========================================\n");
    printf("Explore millions of songs, playlists, and more.\n\n");
}

// Prototipe fungsi
void add_song(Playlist* playlist, const char* singer, const char* title, const char* album, int duration);
void display_playlist(Playlist* playlist);
void search_song(Playlist* playlist, const char* title);
void sort_playlist(Playlist* playlist, int by_singer);
void remove_song(Playlist* playlist, const char* title);
Playlist* find_playlist(Playlist* head, const char* name);
Playlist* add_playlist(Playlist* head, const char* name);
void free_playlists(Playlist* head);
void printWelcomeMessage();


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
    // Periksa apakah lagu dengan judul dan penyanyi yang sama sudah ada
    Song* temp = playlist->head;
    while (temp) {
        if (strcmp(temp->title, title) == 0 && strcmp(temp->singer, singer) == 0) {
            printf("Song '%s' by '%s' already exists in the playlist '%s'.\n", title, singer, playlist->name);
            return; // Tidak menambahkan lagu baru
        }
        temp = temp->next;
    }

    // Jika tidak ada lagu yang sama, tambahkan lagu baru
    Song* new_song = create_song(singer, title, album, duration);
    if (!playlist->head) {
        playlist->head = new_song;
    } else {
        Song* last = playlist->head;
        while (last->next) last = last->next;
        last->next = new_song;
    }
    printf("Song '%s' by '%s' added to playlist '%s'.\n", title, singer, playlist->name);
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

void remove_song(Playlist* playlist, const char* title) {
    if (!playlist->head) {
        printf("Playlist '%s' is empty!\n", playlist->name);
        return;
    }

    Song* temp = playlist->head;
    Song* prev = NULL;

    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                playlist->head = temp->next;
            }
            free(temp);
            printf("Song '%s' removed from playlist '%s'.\n", title, playlist->name);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Song '%s' not found in playlist '%s'.\n", title, playlist->name);
}


Playlist* find_playlist(Playlist* head, const char* name) {
    while (head && strcmp(head->name, name) != 0)
        head = head->next;
    return head;
}

Playlist* add_playlist(Playlist* head, const char* name) {
    // Cek apakah nama playlist sudah ada
    Playlist* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Playlist with name '%s' already exists.\n", name);
            return head; // Tidak menambahkan playlist baru
        }
        temp = temp->next;
    }

    // Jika nama belum ada, tambahkan playlist baru
    Playlist* new_playlist = (Playlist*)malloc(sizeof(Playlist));
    if (!new_playlist) {
        printf("Memory allocation failed.\n");
        return head;
    }
    strcpy(new_playlist->name, name);
    new_playlist->head = NULL;
    new_playlist->next = head; // Tambahkan di awal linked list
    printf("Playlist '%s' created.\n", name);
    return new_playlist;
}

// Function to import a playlist from a CSV file
Playlist* importPlaylistFromFile(Playlist* head,const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Extract the playlist name from the filename
    char name[100];
    sscanf(filename, "%99[^.].txt", name); // Extract the part before ".txt"
    
    // Check if playlist already exists
    Playlist* existingPlaylist = find_playlist(head, name);
    if (existingPlaylist) {
        printf("Playlist '%s' already exists. Import aborted.\n", name);
        fclose(file);
        return NULL;
    }

    // Create a new playlist
    
    // Playlist* newPlaylist = createPlaylist(name);
    head=add_playlist(head,name);
    head = find_playlist(head, name);

    char line[500];
    fgets(line, sizeof(line), file); // Skip header line

    while (fgets(line, sizeof(line), file)) {
        char singer[100], title[100], album[100];
        int duration;

        // Parse CSV line
        if (sscanf(line, "%99[^,],%99[^,],%99[^,],%d",
                   singer, title, album, &duration) == 4) {
           add_song(head, singer, title, album, duration);
            // add_song(playlist, song);
        }
    }

    fclose(file);

    // Add the new playlist to the list of playlists
    // addPlaylist(head, newPlaylist);
    printf("Playlist '%s' imported from %s.\n", name, filename);
    return head;
}

void savePlaylistToFile(Playlist* head, const char* playlistName) {
    Playlist* playlist = find_playlist(head, playlistName);
    if (!playlist) {
        printf("Playlist '%s' not found.\n", playlistName);
        return;
    }

    if (!playlist->head) {
        printf("Playlist '%s' is empty.\n", playlistName);
        return;
    }

    char filename[200];
    snprintf(filename, sizeof(filename), "%s.txt", playlist->name);

    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "Singer,Title,Album,Duration\n"); // Write CSV header
    Song* current = playlist->head;
    while (current) {
        fprintf(file, "%s,%s,%s,%d\n",
                current->singer,
                current->title,
                current->album,
                current->duration);
        current = current->next;
    }

    fclose(file);
    printf("Playlist '%s' saved to %s\n", playlist->name, filename);
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

int main() {
    int choice;
    Playlist *playlists = NULL; // Dummy pointer for demonstration
    char input[10];            // Buffer to read user input

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
    printf("8. Import playlist and songs from file txt\n");
    printf("9. Save playlist to file txt\n");
    printf("10. Exit\n");
     // Pilihan baru untuk mendownload playlist ke file
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (scanf("%d", &choice) != 1) {
        // Input bukan angka, tampilkan pesan error
        printf("Invalid choice! Please enter a number.\n");

        // Bersihkan buffer input
        while (getchar() != '\n');

        // Lanjutkan loop tanpa menjalankan switch
        continue;
    }

        switch (choice) {
            case 1: {
                char playlist_name[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                playlists = add_playlist(playlists, playlist_name);
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
            case 6: {
            if (playlists == NULL) {
            printf("No playlists exist.\n");
            } else {
            display_all_playlists(playlists);
            }
            break;
            }
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
            case 8:{
                char filename[100], title[100];
                printf("Enter  playlist txt filename: ");
                scanf(" %99[^\n]", filename);
                // if(!importPlaylistFromFile(playlists,filename)){
                //     printf("error\n");
                // }else{}
                playlists= importPlaylistFromFile(playlists,filename);
                break;


            }case 9:{
                char playlist_name[100], title[100];
                printf("Enter playlist name: ");
                scanf(" %99[^\n]", playlist_name);
                Playlist* save = find_playlist(playlists, playlist_name);
                if(save !=NULL){
                    savePlaylistToFile(save,playlist_name);
                }else{
                    printf("error");
                }
                break;
            }

            }case 10:{
                printf("Exiting program. Goodbye!\n");
                free_playlists(playlists);
                break;
            }
            default:
                printf("Invalid choice! Try again.\n");
            }
    } while (choice != 10);

    return 0;
}