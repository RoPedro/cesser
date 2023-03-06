#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Creates the variable that represents the player's choice, then asks for the first number
    int chosenNumber;
    printf("Choose a number between 1 to 10\n");
    scanf("%d", &chosenNumber);

    // the if condition is used because we need to lcok the choices between 1 and 10
    if (chosenNumber >= 1 && chosenNumber <= 10)
    {
        int arr[10]; //Defines an array of 10 elements
        for (int i = 0; i < 10; i++) //Loop throught the array and set each one of the loop to be an element of the array
        {
            arr[i] = i + 1; // i + 1 is used because the loop starts in zero, and we don't use the zero
        }

        // Defines a random seed because we need the 'rand()' choosing a different number from the array everytime 
        srand(time(NULL)); 

        int attempts = 0; // Number of attempts pre-defined by zero because the player starts with zero attempts tried
        int randomizedNumber = arr[rand() % 10]; // Chooses pseudo-randomly a number from the array, we need to link the arr variable to the rand() function 

        // While condition checking if player run out of attempts
        while (attempts < 3)
        {

            if (chosenNumber > randomizedNumber)
            {
                attempts++; 
                if (attempts == 3) //Checking if it is the third attempt, to not show the "wrong message". It functions breaking the loop preentively, before the message
                {
                    break;
                }

                printf("Wrong, the sorted number is smaller than %d, try again loser\n", chosenNumber);
            }
            else if (chosenNumber < randomizedNumber)
            {
                attempts++;
                if (attempts == 3) // Checking if it is the third attempt, to not show the "wrong message". It functions breaking the loop preentively, before the message
                {
                    break;
                }

                printf("Wrong, the sorted number is bigger than %d, try again loser\n", chosenNumber);
            }
            else
            {
                printf("Congrats, correct number!\n");
                return 0; //Return is needed to end the program if the chosen number is correct.
            }
            if (attempts < 3) //Needed code to allow the player to try again, it is nested in the while condition, meaning that it will run after a failed try
            {
                scanf("%d", &chosenNumber);
            }
        }
        
        // Tells the player that he failed and shows what was the random number
        printf("Failed, the correct number was %d\n", randomizedNumber);
    }
    else
    {   //prints an error if the player's input is invalid, out of range, or not a number.
        printf("error, the chosen isn't not a number in the range of 1 to 10\n");
    }

    return 0;
}
