#include <stdio.h>
#include <cs50.h>
#include <time.h>

// prototypes
void fill_array(int arr[], int size);
int get_random_term(int length);
int search(int arr[], int size, int term);

int main (int argc, string argv[])
{
    // validate number of  arguments
    if (argc != 2)
    {
        printf("Usage: ./binarysearch <array size> \n");
        return 1;
    }

    // validate length argument
    int len = atoi(argv[1]);
    if (len <= 0)
    {
        printf("Invalid array size argument \n");
        return 2;
    }

    // populate test array
    int data[len];
    fill_array(data, len);

    for (int i = 0; i < len; i++)
    {
    printf("[%i] %i \n", i, data[i]);
    }

    // generate search term
    int term = get_random_term(len);
    printf("search term %i \n", term);

    // perform search
    int found_index = search(data, len, term);
    if (found_index < 0)
    {
        printf("Search term %i not found! \n", term);
    }
    else {
        printf("Search term %i found at index %i! \n",
        term, found_index);
    }

    return 0;
}

/*
 * Fill an array with ints, with a chance of skipping
 */
void fill_array(int arr[], int len)
{
    int threshold = 20;
    srand(time(NULL));

    for (int i = 0, j = 0; i < len; i++)
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

/*
 * Generate the int to search for in the array
 */
int get_random_term(int len)
{
    int term = rand() % len;
    if (term == 0)
    {
        //printf("zero bad term! \n");
        term++;
    }
    return term;
}

/*
 * Perform search and return index or -1 for not found
 */
int search(int arr[], int len, int term)
{
    int low = 0;
    int high = len;
    int range = high - low;
    int mid = low + range / 2;

    do
    {
        //temp
        printf("high %i low %i mid %i value %i term %i \n",
            high, low, mid, arr[mid], term);
        
        
        //if arr[mid] = term
            //return mid
        //else if arr[mid] > term
            //(for range 2)
            //if arr[mid] = low
                //return -1
            //else
                //high = mid - 1
            
        //else if arr[mid] < term
            //(for range 2)
            //if arr[mid] = high 
                //return -1
            //else
                //low = mid + 1
        
        //temp
        low++;
        high--;
        
        range = high - low;
        mid = low + range / 2;
        
        
    }      
    while (range > 1);
      
    //(range is now 1)
    if (arr[low] == term)
    {
        return low;
    }
    else
    {
        return -1;
    }
    return 1;

}


