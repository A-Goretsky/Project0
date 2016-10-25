#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTunez.h"

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

//FULLY WORKING. PRINT STATEMENTS TEST.
song_node * createSongNode(char newname[], char newartist[]) {
    song_node * new = (song_node *) malloc(sizeof(song_node));
    strcpy(new->name, newname);
    strcpy(new->artist, newartist);
    return new;
}

//FULLY WORKING. PRINT STATEMENTS TEST.
song_node * insert_front(song_node *library[], song_node *toAdd) {
    printf("--->>> Inserting %s at front.\n", toAdd->name);
    char artname[256];
    strcpy(artname, toAdd->artist);
    //printf("%s\n", artname);
    //97 = a
    int num = artname[0] - 97;
    //printf("%d\n", num); // is index.
    if (library[num] == 0) {
        library[num] = toAdd;
        toAdd->next = NULL;
    }
    else {
        toAdd->next = library[num];
        library[num] = toAdd;
    }
    //printf("%s\n", library[19]->name);
    //printf("%s\n", library[19]->next->name);
    return toAdd;
}

//NOT FULLY WOKRING.
/*song_node * insert_order(song_node *library[], song_node *toAdd) {
    printf("--->>> <<<--- Inserting %s in order. \n", toAdd->name);
    char artname[256];
    strcpy(artname, toAdd->artist);
    char songname[256];
    strcpy(songname, toAdd->name);
    //Determine index of library to place at.
    int num = artname[0] - 97;
    //Place at beginning if no songs present.
    if (library[num] == 0) {
        library[num] = toAdd;
        toAdd->next = NULL;
    }
    song_node *node = library[num];
    //SINGLE NODE.
    else if (node->next == NULL) {
        //SAME ARTIST.
        if (strcmp(node->artist, artname) == 0) {
            if (strcmp(node->name, songname) < 0) {
                toAdd->next = node;
                library[num] = toAdd;
            }
            else {
                node->next = toAdd;
            }
        }
        //DIFFERENT ARTIST.
        else if (strcmp(node->artist, artname) < 0) {
            toAdd->next = node;
            library[num] = toAdd;
        }
        else if (strcmp(node->artist, artname) > 0) {
            node->next = toAdd;
        }
    }
    //MULTIPLE NODES.
    else if (node->next != NULL) {
        //SAME ARTIST. First node.
        if (strcmp(node->artist, artname) == 0) {
            if strcmp(node->name, songname) < 0) {
                toAdd->next = node;
                library[num] = toAdd;
            }
            else {
                toAdd->next = node->next;
                to
            }
        }
    }
}
*/
//FULLY WORKING.
void print_library(song_node *library[]) {
    printf("\n~~~Printing Full Library~~~\n");
    int x;
    for (x = 0; x < 26; x++) {
        if (library[x] != 0) {
            //printf("Library[x] was not 0 at x = %d\n", x);
            song_node *node = library[x];
            while (node) {
                printf("Artist: %s | Song: %s\n", node->artist, node->name);
                node = node->next;
            }
        }
    }
    printf("\n");
}

//FULLY WORKING
void print_letter_entries(song_node *library[], char *x) {
    printf("\n~~Printing %s List~~\n", x);
    int num = *x - 97;
    if (library[num] == 0) {
        printf("%s List is Empty.\n", x);
    }
    else {
        song_node *node = library[num];
        while (node) {
            printf("Artist: %s | Song: %s\n", node->artist, node->name);
            node = node->next;
        }
    }
}

//FULLY WORKING
void print_artist_entries(song_node *library[], char partist[]) {
    printf("\n~~Printing songs by %s~~\n", partist);
    int num = partist[0] - 97;
    if (library[num] == 0) {
        printf("Artist does not exist.\n");
    }
    else {
        song_node *node = library[num];
        while (node) {
            if (strcmp(node->artist, partist) == 0) {
                printf("Artist: %s | Song: %s\n", node->artist, node->name);
                node = node->next;
            }
            else {
                break;
            }
        }
    }
}

//FULLY WORKING
int findsong(song_node *library[], char songname[]) {
    printf("\n~~Finding song %s~~\n", songname);
    int x;
    for (x = 0; x < 26; x++) {
        if (library[x] != 0) {
            song_node *node = library[x];
            while (node) {
                if (strcmp(node->name, songname) == 0) {
                    printf("Song %s found.\nArtist: %s | Song: %s\n", node->name, node->artist, node->name);
                    return 0;
                }
                node = node->next;
            }
        }
    }
    printf("Song %s not found.\n", songname);
    return 0;
}

//FULLY WORKING
void findartist(song_node *library[], char artname[]) {
    printf("\n~~Finding %s~~\n", artname);
    int num = artname[0] - 97;
    if (library[num] == 0) {
        printf("Artist is non-existent.\n");
    }
    else {
        song_node *node = library[num];
        while (node) {
            if (strcmp(node->artist, artname) == 0) {
                printf("First %s song: %s\n", node->artist, node->name);
                node = node->next;
                break;
            }
        }
    }
}

//FULLY WORKING
int deletesong(song_node *library[], char songname[]) {
    printf("\n~~~Deleting song %s~~~\n", songname);
    int deleted = 0;
    int y = 0;
    while (y < 26) {
        if (deleted == 1) {
            printf("Song %s deleted.\n", songname);
            return 0;
        }
        //printf("For Loop Begins\n");
        if (library[y] != 0) {
            //printf("Column is not Empty.\n");
            song_node *node = library[y];
            //printf("Node has been made\n");
            while (node) {
                //printf("Current node artist: %s\nCurrent node name: %s", node->artist, node->name);
                if (node->next == NULL && strcmp(node->name, songname) == 0) {
                    //printf("BOTH WORK\n");
                    deleted = 1;
                    library[y] = NULL;
                    break;
                }
                else if (node->next != NULL && strcmp(node->name, songname) == 0) {
                    //printf("FIRST ONE FROM LIST\n");
                    deleted = 1;
                    library[y] = node->next;
                    break;
                }
                else if (node->next != NULL && strcmp(node->next->name, songname) == 0) {
                    //printf("NEXT NODE MATCHES");
                    deleted = 1;
                    node->next = node->next->next;
                    break;
                }
                else {
                    //printf("Node set to next for loop");
                    node = node->next;
                }
            }
        }
        y++;
    }
    printf("\nSong %s not found.\n", songname);
    return 0;
}

void shuffle(song_node *library[]) {
    song_node *node;
    song_node *node1;
    int total = 0;
    int x = 0;
    while (x < 26) {
        printf("Creating Total\n");
        if (library[x] != NULL) {
            node = library[x];
        }
        while (node) {
            total++;
            node = node->next;
        }
        x++;
    }
    printf("%d", total);
    int z = 0;
    while (z < 3) {
        printf("Getting Node");
        int random = rand() % (total + 1 - 0) + 0;
        printf("Random num: %d", random);
        z++;
    }
        /*int y = 0;
        while (y < 26) {
            while (random >= 0) {
                if (library[x] != NULL) {
                    node1 = library[x];
                }
                while (node) {
                    random--;
                    node1 = node1->next;
                }
            }
            y++;
        }
        z++;
    }
    printf("Artist: %s | Song: %s", node1->artist, node1->name);*/
}

void * free_library(song_node *library[]) {
    int x = 0;
    while (x < 26) {
        if (library[x] != NULL) {
            song_node *node = library[x];
            song_node *temp = node;
            node = node->next;
            free(temp);
        }
        x++;
    }
}

int main() {
    song_node *library[26]; //calloc this
    int x = 0;
    while (x < 26) {
        library[x] = 0;
        x++;
    }
    printf("\n~~~~~~Creating All Songs~~~~~~\n\n");
    song_node *song1 = createSongNode("happiness is not a place", "the wind and the wave");
    song_node *song2 = createSongNode("sorry i'm not sorry", "tessa violet");
    song_node *song3 = createSongNode("human", "dodie clark");
    song_node *song4 = createSongNode("sick of losing soulamtes", "dodie clark");
    song_node *song5 = createSongNode("dream", "tessa violet");
    song_node *song6 = createSongNode("closer", "lemaitre");
    song_node *song7 = createSongNode("river", "oh, be clever");
    song_node *song8 = createSongNode("a non love song from nashville", "dodie clark");
    printf("\n~~~~~~Inserting All Songs~~~~~~\n\n");
    insert_front(library, song1);
    insert_front(library, song2);
    insert_front(library, song3);
    insert_front(library, song4);
    insert_front(library, song5);
    insert_front(library, song6);
    insert_front(library, song8);
    printf("\n~~~~~TESTING ALL PRINT FUNCTIONS~~~~~\n\n");
    print_library(library);
    print_letter_entries(library, "t");
    print_artist_entries(library, "tessa violet");
    printf("\n~~~~~TESTING FIND FUNCTIONS~~~~~\n\n");
    findartist(library, "dodie clark");
    findartist(library, "rusty clanton");
    findsong(library, "human");
    findsong(library, "dream");
    findsong(library, "hello all");
    printf("\n~~~~~TESTING DELETE FUNCTIONS~~~~~\n\n");
    deletesong(library, "closer");
    print_library(library);
    insert_front(library, song6);
    //print_library(library);
    deletesong(library, "sorry i'm not sorry");
    print_library(library);
    insert_front(library, song2);
    //print_library(library);
    deletesong(library, "a non love song from nashville");
    print_library(library);
    insert_front(library, song8);
    //print_library(library);
    deletesong(library, "human");
    print_library(library);
    insert_front(library, song3);
    //print_library(library);
    printf("~~~~~TESTING SHUFFLE~~~~~\n");
    //shuffle(library);
    free_library(library);
}
