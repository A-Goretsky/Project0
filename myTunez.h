typedef struct song_node;

struct song_node * createSongNode(char newname[], char newartist[]);

struct song_node * insert_front(struct song_node *library[], struct song_node *toAdd);

void print_library(struct song_node *library[]);

void print_letter_entries(struct song_node *library[], char *x);

void print_artist_entries(struct song_node *library[], char partist[]);

int findsong(struct song_node *library[], char songname[]);

void findartist(struct song_node *library[], char artname[]);

int deletesong(struct song_node *library[], char songname[]);

void shuffle(struct song_node *library[]);

void * free_library(struct song_node *library[]);
