#include <stdio.h>
#include <cs50.h>
#include <time.h>

// prototypes
void fill_array(int arr[], int size);


int main (int argc, string argv[])
{
    if (argc != 2)
    {
        // validate input
        printf("Usage: ./binarysearch <array size> \n");
        return 1;
    }

    int size = atoi(argv[1]);
    int data[size];
    fill_array(data, size);

    for (int i = 0; i < size; i++)
    {
    printf("%i \n", data[i]);
    }


    return 0;


}

/*
 * Fill an array with ints, with a chance of skipping
 */
void fill_array(int arr[], int size)
{
    int threshold = 20;
    srand(time(NULL));

    for (int i = 0, j = 0; i < size; i++)
    {
        int random;
        do
        {
            random = rand() % 100;
            j++;
        }
        while (random < threshold);

        arr[i] = j;
    }
}
