/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.

Gabrielle Vincenza T. Tongol

Additional Sources: https://www.asciiart.eu/computers
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAXPLAY 6
#define MAXCHAR 100
#define LINECNT 100

struct nameTag
{
    char first[MAXCHAR];
};

struct dateTag
{
    char month[MAXCHAR];
    int day;
    int year;
};

struct playerTag
{
    struct nameTag name;
    struct dateTag date;
    int score;
};

void displayDesign()
{
    printf("                                                           ________________________________________________\n");
    printf("                                                          /                                                 \\ \n'");
    printf("                                                        |     _________________________________________     |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    | C:\\Users\\PC> Welcome to Word Scramble_  |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |      ---HARRY POTTER EDITION---         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |        PRESS 'G' OR 'g' TO START        |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |                                         |    |\n");
    printf("                                                         |    |_________________________________________|    |\n");
    printf("                                                         |                                                   |\n");
    printf("                                                          \\_________________________________________________/\n");
    printf("                                                                \\___________________________________/\n");
    printf("                                                               ___________________________________________\n");
    printf("                                                            _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
    printf("                                                         _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_ \n");
    printf("                                                      _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_ \n");
    printf("                                                   _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_ \n");
    printf("                                                _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_ \n");
    printf("                                               :-------------------------------------------------------------------------:\n");
    printf("                                                `---._.-------------------------------------------------------------._.---'\n");
}

void displayHarry(struct playerTag p[], int num)
{
    printf("                                                                             ______ \n");
    printf("                                                                            /      \\\n");
    printf("                                                                           |        |\n");
    printf("                                                                           |:/-\\--\\.\n");
    printf("                                                                            ( )-( )/,\n");
    printf("                                                                             | ,  .\n");
    printf("                                                                           / \\- /. \\\n");
    printf("                                                                          | ||L  / \\ \\\n");
    printf("                                                                         / /  \\/    | *\n");
    printf("                                                                       / /          \\  \\\n");
    printf("                                                                       | |      []   |\\ |\n");
    printf("                                                                      /| |           ||  |\n");
    printf("                                                                      || |           ||  |\n");
    printf("                                                                      |  |           ||  |\n");
    printf("                                                                      /_ |__________|||  |\n");
    printf("                                                                     /_ \\| ---------||   |\n");
    printf("                                                                     /_ / |         ||   |\n");
    printf("                                                                     /  | ||         | |     \n");
    printf("                                                                    \\/\\/  ||         | |  |\n");
    printf("                                                                     /  | ||    T    | |  |\n");
    printf("                                                                    /   | ||    |     |\n");
    printf("                                                                   /    HAHA GAME OVER %s!\n\n", p[num].name.first);
}

void displayDivider()
{
    int j;

    for (j = 1; j <= 88; j++)
    {
        if (j == 1)
            printf("\n");

        printf("-*");
    }
}

void displayDivider2()
{
    int j;

    for (j = 1; j <= 88; j++)
    {
        if (j == 1)
            printf("\n");

        printf("--");

        if (j == 88)
            printf("\n");
    }
}

int randomNum()
{
    int num;

    while (num % 2 == 0) // continues looping until readline encounters an odd number
    {
        srand(time(NULL));
        num = rand() % LINECNT + 1;
    }

    return num;
}

void displayJumbledWord(char cWord[], int nWordCnt)
{
    char cpyWord[15];
    char temp;
    int len = strlen(cWord);
    int i = 0;
    int pos1, pos2;

    strcpy(cpyWord, cWord); // original word is copied to another variable string

    do
    {
        while (i < len)
        {
            srand(time(NULL)); // to generate random number
            pos1 = rand() % len;
            pos2 = rand() % len;

            if (pos1 != pos2)
            {
                temp = cpyWord[pos1];
                cpyWord[pos1] = cpyWord[pos2];
                cpyWord[pos2] = temp;
            }

            i++;
        }

        i = 0;
    } while (strcmp(cpyWord, cWord) == 0); // loops until the copied word and original word are the same

    printf("\t\t\t\t\t\t\t\t-*-* %d - UNSCRAMBLE THE WORD: %s -*-*\n", nWordCnt, cpyWord);
}

void revealClues(int nChoice, char cWord[])
{
    int lastDig = strlen(cWord) - 1;
    if (nChoice == 1)
    {
        printf("\t\t\t\t\t\t\t\t\tHere is your clue: %c\n", cWord[0]);
    }
    else if (nChoice == 2)
    {
        printf("\t\t\t\t\t\t\t\t\tHere is your clue: %c\n", cWord[lastDig]);
    }
}

int checkAnswer(char cWord[], char answer[])
{
    int num = strcmp(cWord, answer);
    if (num == 0)
        return 1;
    else
        return 0;
}

int computePoints(char cWord[], char answer[], int nClueCnt)
{
    int len = strlen(cWord);
    int check = checkAnswer(cWord, answer);
    int nPnts; // points to be added or deducted

    if (check == 1)
    {
        if (nClueCnt == 1 || nClueCnt == 2)
        {
            len -= nClueCnt;
            nPnts = len * 10;
        }
        else
        {
            nPnts = 200;
        }
    }

    else if (check == 0)
    {
        nPnts = 300;
    }

    return nPnts;
}

void correctAnswer(char cWord[], char answer[], int nCluecnt, int num, struct playerTag p[])
{
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t-*-*CORRECT!-*-*\n");
    printf("\t\t\t\t\t\t\t\t    You are given %d points!\n", computePoints(cWord, answer, nCluecnt));
    printf("\t\t\t\t\t\t\t\t    CURRENT POINTS: %d\n\n", p[num].score);
}

void wrongAnswer(char cWord[], char answer[], int nCluecnt, int num, struct playerTag p[])
{
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t-*-*WRONG!-*-*\n");
    printf("\t\t\t\t\t\t\t\t    You are deducted %d points!\n", computePoints(cWord, answer, nCluecnt));
    printf("\t\t\t\t\t\t\t\t    CURRENT POINTS: %d\n\n", p[num].score);
}

void displayHighScorers(struct playerTag p[]) // not sure wd this one
{
    struct playerTag temp;
    int i, j, k;

    for (j = 0; j < MAXPLAY; j++)
    {
        for (i = j + 1; i < MAXPLAY; i++)
        {
            if (p[j].score < p[i].score)
            {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    printf("\t\t\t\t\t\t\t\t-*-*-*-*-*-*SCORE BOARD-*-*-*-*-*-*\n\n");
    for (k = 0; k < MAXPLAY - 1; k++)
    {
        printf("\t\t\t\t\t\t\t\t%d - %s: %d - DATE: %s %d %d\n", k + 1, p[k].name.first, p[k].score, p[k].date.month, p[k].date.day, p[k].date.year);
    }
}

int main()
{
    FILE *fp;      // file handling the dictionary.txt, odd numbers - get the word, even numbers- get the clue
    FILE *players; // stores initialized players

    struct playerTag p[MAXPLAY];
    char cSrtCh;  // stores player choice to start or end game
    char cClueCh; // stores character when asked for clues
    char cWord[MAXCHAR];
    char cClue[MAXCHAR];
    char answer[MAXCHAR];

    int num = MAXPLAY - 1; // used inside the p struct
    int i, j = 0;          // used in while loop to get initialized players
    int len;               // length of word
    int nChoice;           // used to store options for the game
    int nReadline = 0;     // stores random value for file output
    int nCurrline = 1;     // used inside the getting of word inside main, iterates until it is equal to nReadline
    int nStop = 1;         // stops when nCurrline and nReadline is equal
    int nClueCnt;          // stores how many clues the players has
    int nWordCnt = 1;      // stores how many words are answered by the player

    do
    {
        displayDesign();
        displayDivider();
        displayDivider2();

        while (cSrtCh != 'G' && cSrtCh != 'g')
        {

            scanf(" %c", &cSrtCh);

            if (cSrtCh != 'G' && cSrtCh != 'g')
            {
                printf("\t\t\t\t\t\t\t\tWrong input! Try again: ");
            }
        }

        // ask for player name and date
        printf("\t\t\t\t\t\t\t\tHello Player! What is your name? ");
        scanf("%s", p[num].name.first);
        printf("\t\t\t\t\t\t\t\tEnter date to day (MONTH DAY YEAR): ");
        scanf("%s %d %d", p[num].date.month, &p[num].date.day, &p[num].date.year);

        p[num].score = 2000; // initialize points for the player
        printf("\t\t\t\t\t\t\t\tYour current points are %d!\n\n", p[num].score);

        do
        {

            nReadline = randomNum();

            fp = fopen("dic77954.txt", "r");

            do // get the word
            {
                fgets(cWord, 100, fp);
                if (nCurrline == nReadline)
                {
                    nStop = 0;

                    len = strlen(cWord);

                    // makes sure to remove newline and replace it with null byte to avoid errors in the checkAnswer
                    if (cWord[len - 1] == '\n')
                        cWord[len - 1] = '\0';

                    displayJumbledWord(cWord, nWordCnt);
                }

                nCurrline++;
            } while (nStop == 1);

            nReadline += 1; // adds one to make it an even number

            do // get the clue description
            {
                fgets(cClue, 100, fp);

                if (nCurrline == nReadline)
                {
                    nStop = 0;
                    printf("\t\t\t\t\t\t\tCLUE: %s\n", cClue);
                }

                nCurrline++;
            } while (nStop == 1);

            while (nChoice != 1 && nChoice != 2 && nChoice != 3 && nChoice != 4)
            {
                printf("\t\t\t\t\t\t\t\t(1): Show first letter of the word\n");
                printf("\t\t\t\t\t\t\t\t(2): Show last letter of the word\n");
                printf("\t\t\t\t\t\t\t\t(3): Type answer\n");
                printf("\t\t\t\t\t\t\t\t(4): Surrender Game\n");
                printf("\t\t\t\t\t\t\t\tCHOICE: ");
                scanf("%d", &nChoice);

                if (nChoice != 1 && nChoice != 2 && nChoice != 3 && nChoice != 4)
                    printf("\t\t\t\t\t\t\t\tWrong input! Try again\n\n");
            }

            switch (nChoice)
            {
            case 1:
            case 2:

                nClueCnt = 1; // gets value 1 when asked for clue

                revealClues(nChoice, cWord);

                printf("\t\t\t\t\t\t\t\tEnter your answer in ALL CAPS: ");
                scanf("%s", answer);

                if (checkAnswer(cWord, answer) == 1) // checks if player's answer is correct, adds player point if so
                {
                    p[num].score += computePoints(cWord, answer, nClueCnt);

                    correctAnswer(cWord, answer, nClueCnt, num, p);
                }
                else // if answer is incorrect, player will be asked fro additional clues, only max of 2 clues are allowed
                {
                    printf("\t\t\t\t\t\t\t\t\tYour answer is wrong!\n\n");

                    while (cClueCh != 'Y' && cClueCh != 'N')
                    {
                        printf("\t\t\t\t\t\t\t\tWould you like to have another clue?\n");
                        printf("\t\t\t\t\t\t\t\t(Y): YES\n\t\t\t\t\t\t\t\t(N): NO\n");
                        printf("\t\t\t\t\t\t\t\tCHOICE: ");
                        scanf(" %c", &cClueCh);

                        if (cClueCh != 'Y' && cClueCh != 'N')
                            printf("\t\t\t\t\t\t\t\tWrong input! Try again\n");
                    }
                    if (cClueCh == 'Y') // if player wants another clue
                    {
                        nClueCnt = 2; // gets value 2 when player asks for another clue

                        if (nChoice == 1) // interchanges nChoice value to get the other letter clue
                        {
                            nChoice = 2;
                        }
                        else if (nChoice == 2)
                        {
                            nChoice = 1;
                        }

                        revealClues(nChoice, cWord);
                        printf("\t\t\t\t\t\t\t\tEnter your answer in ALL CAPS: ");
                        scanf("%s", answer);

                        if (checkAnswer(cWord, answer) == 1) // checks if correct, adds points
                        {
                            p[num].score += computePoints(cWord, answer, nClueCnt);

                            correctAnswer(cWord, answer, nClueCnt, num, p);
                        }
                        else // if wrong, deducts point
                        {
                            p[num].score -= computePoints(cWord, answer, nClueCnt);

                            wrongAnswer(cWord, answer, nClueCnt, num, p);
                        }
                    }
                    else if (cClueCh == 'N') // if player does not want another clue, points will get deducted
                    {
                        p[num].score -= computePoints(cWord, answer, nClueCnt);

                        wrongAnswer(cWord, answer, nClueCnt, num, p);
                    }
                }

                cClueCh = ' '; // initialize clue choice to none
                nChoice = 0;   // initialize menu choice
                break;         // end of case 1 and 2

            case 3:
                nClueCnt = 0; // clue count is 0 because the player did not ask for clues

                printf("\t\t\t\t\t\t\t\tEnter your answer in ALL CAPS: ");
                scanf("%s", answer);

                if (checkAnswer(cWord, answer) == 1) //
                {
                    p[num].score += computePoints(cWord, answer, nClueCnt);

                    correctAnswer(cWord, answer, nClueCnt, num, p);
                }
                else
                {
                    p[num].score -= computePoints(cWord, answer, nClueCnt);

                    wrongAnswer(cWord, answer, nClueCnt, num, p);
                }

                nChoice = 0; // initialize menu choice

                break;
            case 4: // player surrenders
                break;
            }

            // variables inside the get word and clue are initialized again
            nStop = 1;
            nCurrline = 1;
            nWordCnt++;

            fclose(fp);
        } while (nChoice != 4 && nWordCnt <= 15 && p[num].score > 0); // loop will stop when player chooses 4 to surrender,
                                                                      // word count is 15 or points is 0

        if (nChoice == 4 || nWordCnt >= 15 || p[num].score < 0)
        {
            displayHarry(p, num);

            players = fopen("TOP5PLAYERS.txt", "r"); // file open for the top players

            while (i < num) // takes input from the file to initialize top 5 scorers
            {
                fscanf(players, "%s %d %s %d %d", p[i].name.first, &p[i].score, p[i].date.month, &p[i].date.day, &p[i].date.year);
                i++;
            }
            i = 0; // updated
            displayHighScorers(p);

            players = fopen("TOP5PLAYERS.txt", "w"); // stores the new order of high scorers inside the file

            while (j < num)
            {
                fprintf(players, "%s %d %s %d %d\n", p[j].name.first, p[j].score, p[j].date.month, p[j].date.day, p[j].date.year);
                j++;
            }
            j = 0; // updated

            fclose(players);

            while (cSrtCh != 'N' && cSrtCh != 'E')
            {
                printf("\n\n");
                printf("\t\t\t\t\t\t\t\tWould you like to play again?\n");
                printf("\t\t\t\t\t\t\t\t(N): New Game\n");
                printf("\t\t\t\t\t\t\t\t(E): End Game\n");
                printf("\t\t\t\t\t\t\t\tCHOICE: ");
                scanf(" %c", &cSrtCh);

                if (cSrtCh != 'N' && cSrtCh != 'E')
                    printf("\t\t\t\t\t\t\t\tWrong input! Try again\n");
            }

            // initialize variables inside the game loop again
            nWordCnt = 1;
            nReadline = 0;
            nChoice = 0;
        }

    } while (cSrtCh == 'G' || cSrtCh == 'N');

    return 0;
}

/*
USER DEFINED FUNCTIONS

int randomNum() - returns 1 odd number from 1 - 100
No parameters
Variables:
num - will hold the random value generated
@returns num
Pre - condition: the loop will not stop until it encounters an odd number

void revealClues() - prints the letter clue
@param nChoice - player's menu choice
@param cWord - a string of the original word that is randomly generated
Pre - condition: nChoice should be 1 and 2 only

void displayJumbledWord() - prints the jumbled form of the original word
@param cWord - a string of the original word that is randomly generated
@param nWordCnt - how many words are currently answered by the player inside the program
                - used only for printing
Pre - condition: cWord is only 1 word

int checkAnswer() - checks the player's answer if it is correct or not
@param cWord - a string of the original word that is randomly generated
@param answer - user input of answer
@returns 1 when the compared cWord and answwer is 0
Pre - condition: Since cWord is from the file, the \n should be removed at the end
                of the word or else even when both strings are the same it will always
                return 0.

int computePoints() - computes the points to be added or subracted in the player's existing points
@param cWord - a string of the original word that is randomly generated
@param answer - user input of answer
@param nClueCnt - how many clues are used, either 1 or 2 only
@returns nPnts - number of points depending on what condition is true
                 will later on be used to subtract or add points of the player
Pre - condition: length of word and checkAnswer function will also be used inside

void correctAnswer() - prints the statement when the player gets correct answer
@param cWord - a string of the original word that is randomly generated
@param answer - user input of answer
@param nClueCnt - how many clues are used, either 1 or 2 only
@param num - value that is inside the array of p struct
@param struct playerTag p - storage of the player's data
Pre - condition: the function ComputePoints will be used inside the function

void wrongAnswer() - prints the statement when the player gets wrong answer
@param cWord - a string of the original word that is randomly generated
@param answer - user input of answer
@param nClueCnt - how many clues are used, either 1 or 2 only
@param num - value that is inside the array of p struct
@param struct playerTag p - storage of the player's data
Pre - condition: the function ComputePoints will be used inside the function

void displayHighScorers() - displays the top 5 high scorers
@param struct playerTag p - storage of the player's data
Pre - condition: The array p holds 6 players but will only print 5

*/