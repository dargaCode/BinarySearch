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
    int high = len - 1;
    int range = 1 + high - low;
    int mid = low + range / 2;

    do
    {
    
        //temp
        for (int i = low; i <= high; i++)
        {
            printf("[%i] %i \n", i, arr[i]);
        }
    
        //temp
        printf("range %i (low %i high %i mid %i) search %i actual %i \n",
            range, low, high, mid, term, arr[mid]);
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
            printf("Look lower! \n");
            //(for range 2)
            if (mid == low)
            {
                printf("bong! \n");
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
            printf("Look higher! \n");
            //(for range 2)
            if (mid == high) 
            {
                printf("bing! \n");
                return -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        range = 1 + high - low;
        mid = low + range / 2;
    }      
    while (range > 0);
      
    // check the final remaining value
    if (arr[low] == term)
    {
        return low;
    }
    else
    {
        printf("wtf");
        return -1;
    }
}
