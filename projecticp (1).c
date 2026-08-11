#include<stdio.h>
#include<string.h>

#define MAX 50

void printSongs(char songs[][50], int rating[], int n)
{
    printf("\nAll songs:\n");
    for(int i=0; i<n; i++)
    printf("%d.%s-Rating: %d\n", i+1, songs[i], rating[i]);
}

void newSong(char songs[][50], char mood[][20], int rating[], int *n)
{
    printf("\nEnter song title: ");
    scanf("%s", songs[*n]);

    printf("\nEnter mood: ");
    scanf("%s", mood[*n]);

    printf("\nEnter rating(1-5): ");
    scanf("%d", &rating[*n]);

    (*n)++;
    printf("Song added successfully!\n");

}
void recommend(char songs[][50], char mood[][20], int rating[], int n)
{
    char m[20];
    int found = 0;
    printf("\nEnter mood: ");
    scanf("%s", m);
    printf("\nRecommended Songs:\n");

    for(int i=0; i<n; i++)
    {
        if(strcmp(mood[i],m) == 0)
        {
        printf("%s-Rating:%d\n", songs[i], rating[i]);
        found = 1;
    }
}
    if(found == 0)
    printf("No songs found for that mood\n");
}

void searchSong(char songs[][50], int n)
{
    char search[50];
    int found = 0;

    printf("\nEnter song title to search: ");
    scanf("%s", search);

    for(int i=0; i<n; i++)
    {
        if(strcmp(songs[i],search) == 0)
        {
            printf("Song found: %s\n",songs[i]);
            found = 1;
        }
    }
    if(found == 0)
    printf("Song not found.\n");
}

void favorite(char songs[][50], int rating[], int fav[], int n)
{
int choice;
printSongs(songs, rating, n);
printf("Enter song number: ");
scanf("%d", &choice);
if(choice >= 1 && choice <= n)
{
    if(fav[choice - 1] == 0)
    {
        fav[choice - 1] = 1;
        printf("Added to favorites!\n");
    }
    else
    {
        printf("Already in favorites!\n");
    }
}
}

void showFavorites(char songs[][50], int fav[], int n)
{
    printf("\nFavorite Songs:\n");
    for(int i=0; i<n; i++)
    {
        if(fav[i] == 1)
        printf("-%s\n", songs[i]);
    }
}

void removeFavorite(char songs[][50], int fav[], int n)
{
    int choice;
    showFavorites(songs, fav, n);
    printf("\nEnter song number to remove from favorites: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= n)
    {
        if(fav[choice - 1] == 1)
        {
            fav[choice - 1] = 0;
            printf("Removed from favorites!\n");
        }
        else
        {
            printf("That song is not in your favorites\n");
        }
    }
    else
    {
        printf("Invalid song number\n");
    }
}

void updateRating(char songs[][50], int rating[], int n)
{
    int choice, r;

    printSongs(songs,rating,n);

    printf("\nEnter song number: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= n)
    {
        printf("Enter new rating(1-5): ");
        scanf("%d", &r);

        if(r >= 1 && r <= 5)
        {
            rating[choice - 1] = r;
            printf("Rating updated!\n");
            printf("%s is now rated: %d\n", songs[choice - 1], rating[choice - 1]);
        }
        else
        {
            printf("Invalid rating! Must be between 1 and 5. Nothing changed!\n");
        }
    }
}

void displayMoods(char mood[][20], int n)
{
    char shown[MAX][20];
    int show_count = 0;
    int found;
    printf("\nAvailable Moods:\n");

    for(int i=0; i<n; i++)
    {
        found = 0;
        for(int j = 0; j<show_count; j++)
        {
            if(strcmp(mood[i], shown[j]) == 0)
            {
                found = 1;
                break;

            }
        }

        if(found ==  0)
{
    printf("-%s\n", mood[i]);
    strcpy(shown[show_count], mood[i]);
    show_count++;
  }
}
}

int main()
{
    char songs[MAX][50] = {"Happy", "Perfect", "Lovely", "Believer", "CalmDown", "ShapeOfYou"};
    char mood[MAX][20] = {"Happy", "Relaxed", "Sad", "Energetic", "fun", "funky"};

    int rating[MAX] = {5, 4, 5, 4, 3, 5};
    int fav[MAX] = {0};

    int n = 6;
    int choice;

    do
    {
        printf("\n----Mood-Based Music Recommendation System----\n");
        printf("1.Add Song\n");
        printf("2.Display All Songs\n");
        printf("3.Recommend Songs\n");
        printf("4.Add Favorite\n");
        printf("5.Display Favorite\n");
        printf("6.Remove Favorite\n");
        printf("7.Search Song\n");
        printf("8.Change Rating\n");
        printf("9.Display Moods\n");
        printf("10.Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        newSong(songs, mood, rating, &n);

        else if(choice == 2)
        printSongs(songs,rating,n);

        else if(choice == 3)
        recommend(songs,mood,rating,n);

        else if(choice == 4)
        favorite(songs,rating,fav,n);

        else if(choice == 5)
        showFavorites(songs,fav,n);

        else if(choice == 6)
        removeFavorite(songs,fav,n);

        else if(choice == 7)
        searchSong(songs,n);

        else if(choice == 8)
        updateRating(songs,rating,n);

        else if(choice == 9)
        displayMoods(mood,n);

        else if(choice == 10)
          printf("\nThank you!\n");

        else
        printf("\nInvalid choice!\n");

    }while(choice != 10);

    return 0;
}
