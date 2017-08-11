#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

int countVowels(int counts[],char inputStr[],int size);
void displayCounts(string text[], int counts[], int size);

int main()
{
    const int VOWEL_CNT = 5;
    const int SIZE = 300;
    string VOWELS_TEXT [VOWEL_CNT] = { "a - A", "e - E", "i - I", "o - O", "u - U" };
    char str[SIZE];             // input string
    // array of vowel counts
    cout << "This program counts the vowel occurrences in input phrase\n";
    while (true) {
       int vowelCnt[VOWEL_CNT] = {0,0,0,0,0};
       int totalCount=0;
       cout << "Enter a phrase and hit Enter (maximum length " << SIZE - 1 << "): ";
       cin.getline (str, SIZE);
       if (strlen(str)==0) break;
       cout << "Vowel\t" << setw(10) << "Count" << endl;
       totalCount = countVowels (vowelCnt, str, SIZE);
       displayCounts(VOWELS_TEXT, vowelCnt, sizeof(vowelCnt)/sizeof(*vowelCnt));
       cout << "Total of vowels is " << totalCount << endl;
    }
    return 0;
}

int countVowels( int counts[], char inputStr[], int size )
{
    int i;
    int totalCount = 0;
    for (i = 0; i < strlen(inputStr); i++)\
    {
        if (inputStr[i] == 'A' || inputStr[i] == 'a')
        {
            counts[0]++;
        }
        else if (inputStr[i] == 'E' || inputStr[i] == 'e')
        {
            counts[1]++;
        }
        else if (inputStr[i] == 'I' || inputStr[i] == 'i')
        {
            counts[2]++;
        }
        else if (inputStr[i] == 'O' || inputStr[i] == 'o')
        {
            counts[3]++;
        }
        else if(inputStr[i] == 'U' || inputStr[i] == 'u')
        {
            counts[4]++;
        }
    }
    //for (i=0; i<strlen(inputStr); i++) //this for section might be the problem with the total count
    for (i=0; i <= 4; i++)
    {
        totalCount += counts[i];
    }
    return totalCount;
}

void displayCounts(string text[], int counts[], int size) //this function might be also the reason for the total issue
{
    //int totalCount = 0;
    int i;
    for (i = 0; i < size; i++)
    {
         cout << text[i] << "\t" << setw(10) << counts[i] << endl; // once this displays it just runs off and doesnt allow for more entry
         //totalCount += counts[i];
    }
}
