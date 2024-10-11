#include <stdio.h>
#include <string.h>

// Function to compute the pattern's failure function
void fail(char *pat, int failure[])
{
    int n = strlen(pat);
    failure[0] = 0; // failure[0] is always 0
    int i = 0;      // length of the previous longest prefix suffix

    for (int j = 1; j < n; j++)
    {
        // Handle mismatch after j matches
        while (i > 0 && pat[j] != pat[i])
        {
            i = failure[i - 1]; // fall back in the pattern
        }
        // If there's a match, increase the length of the match
        if (pat[j] == pat[i])
        {
            i++;
        }
        failure[j] = i; // Update the failure function
    }
}

// Function to implement the KMP algorithm for pattern matching
int pmatch(char *string, char *pat)
{
    int lens = strlen(string);
    int lenp = strlen(pat);
    int failure[lenp];  // to hold the failure function
    fail(pat, failure); // compute the failure function

    int i = 0; // index for string
    int j = 0; // index for pattern

    while (i < lens)
    {
        if (string[i] == pat[j])
        {
            i++;
            j++;
        }
        // If the whole pattern was found
        if (j == lenp)
        {
            return (i - lenp); // return the starting index of the match
        }
        else if (i < lens && string[i] != pat[j])
        {
            if (j == 0)
            {
                i++; // Move to the next character in string
            }
            else
            {
                j = failure[j - 1]; // Use the failure function
            }
        }
    }
    return -1; // Pattern not found
}

int main()
{
    char string[] = "ababcabcabababd";
    char pat[] = "ababd";
    int result = pmatch(string, pat);

    if (result != -1)
    {
        printf("Pattern found at index: %d\n", result);
    }
    else
    {
        printf("Pattern not found.\n");
    }

    return 0;
} 
