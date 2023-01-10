struct Series
{
	char series_name[35];
	int ID;
	float IMDB;
	struct series *next;
};

typedef struct Series series;
typedef series *seriesPtr;

series s[15];
int arr = 5;

char fname[20];
char sname[20];
char tname[20];

void showmenu();
void fileread();
void display();
void Insesort();
void Bubbsort();
void fileDis();
int Linsearch(int finum);
int binsearch(int finum, int d, int u);
void takeinput( seriesPtr *sPtr, char Name[25], int id, float value);
void showLinkedList(seriesPtr sPtr);
void takeinput(seriesPtr *sPtr, char Name[25], int id, float value);
void showLinkedList(seriesPtr sPtr);