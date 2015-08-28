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

    // generate search term
    int term = get_random_term(len);
    printf("Array Size: %i \n", len);
    printf("Random search term: %i \n", term);

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
    int skip_chance = 20;
    // random seed
    srand(time(NULL));

    for (int i = 0, j = 0; i < len; i++)
    {
        int random;
        //find the next non-skipped integer
        do
        {
            random = rand() % 100;
            j++;
        }
        while (random < skip_chance);

        arr[i] = j;
    }
}

/*
 * Generate the int for which to search
 */
int get_random_term(int len)
{
    int term = rand() % len;
    // no zero allowed
    if (term == 0)
    {
        term = 1;
    }
    return term;
}

/*
 * Perform search and return index or -1 for not found
 */
int search(int arr[], int len, int term)
{
    int low = 0;
    int high = len - 1;
    int range = 1 + high - low;
    int mid = low + range / 2;
    int count = 1;

    do
    {        
        // status update
        printf("\nLoop %i - Range: %i\n", count, range);
        printf("    (%i-%i) | Slot %i | (%i-%i)\n",
            low, mid - 1, mid, mid + 1, high);
        printf("        Found: %i | Want: %i \n", 
            arr[mid], term);   
        
        // press enter to continue
        char ch;
        scanf("%c",&ch);
        
        // found!
        if (term == arr[mid])
        {
            return mid;
        }
        // discard top half
        else if (term < arr[mid])
        {
            printf("            Look lower! \n");
            //(for range 2)
            if (mid == low)
            {
                return -1;   
            }
            else
            {
                high = mid - 1;
            }
        }
        // discard bottom half
        else if (term > arr[mid])
        {
            printf("            Look higher! \n");
            //(for range 2)
            if (mid == high)
            {
                return -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        range = 1 + high - low;
        mid = low + range / 2;
        count++;
    }
    while (range > 0);

    // check the final remaining value
    if (arr[low] == term)
    {
        return low;
    }
    else
    {
        return -1;
    }
}
