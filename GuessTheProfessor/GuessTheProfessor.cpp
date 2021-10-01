// Guess the right number linked to an array of professors from UAT

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    // Array of UAT professors
    const int MAX_PROFESSOR = 10;
    string professor[MAX_PROFESSOR] = { "Marquit", "Clark", "Beam", "Brokaw", "Hromas",
        "Moore", "Prater", "Peters", "Vasquez", "Belanger" };

    // Array of UAT room #s
    const int MAX_ROOM = 20;
    int roomNumber[MAX_ROOM] = { 106, 107, 108, 135, 201, 202, 203, 204, 205, 206, 207,
        208, 231, 232, 234, 235, 244, 245, 252, 253 };

    // Seed for random #
    srand(static_cast<unsigned int>(time(0)));

    // Random # from 1-10
    int ranNumber = rand() % 10;

    int tries = 0;
    int guess;

    chrono::duration<int, milli> timespan(3000);

    // Game begins
    cout << "Welcome to the UAT Campus Tour.\n\n";

    this_thread::sleep_for(timespan);

    cout << "We are currently passing by room " << roomNumber[rand() % 20] << ".\n\n";

    this_thread::sleep_for(timespan);

    cout << "Can you guess which professor is currently in this room?\n\n";

    this_thread::sleep_for(timespan);

    do
    {
        // Shows player their options
        chrono::duration<int, milli> timespan(100);

        printf("1 => Marquit\n");
        this_thread::sleep_for(timespan);

        printf("2 => Clark\n");
        this_thread::sleep_for(timespan);

        printf("3 => Beam\n");
        this_thread::sleep_for(timespan);

        printf("4 => Brokaw\n");
        this_thread::sleep_for(timespan);

        printf("5 => Hromas\n");
        this_thread::sleep_for(timespan);

        printf("6 => Moore\n");
        this_thread::sleep_for(timespan);

        printf("7 => Prater\n");
        this_thread::sleep_for(timespan);

        printf("8 => Peters\n");
        this_thread::sleep_for(timespan);

        printf("9 => Vasquez\n");
        this_thread::sleep_for(timespan);

        printf("10 => Belanger\n\n");
        this_thread::sleep_for(timespan);

        printf("Enter a guess from 1 to 10: ");
        cin >> guess;
        cout << endl;
        ++tries;

        // To keep the guess in line with the array starting its count from 0
        guess -= 1;

        // Wrong guess
        if (guess != ranNumber && guess <= 9 && guess >= 0)
        {
            cout << "Professor " << professor[guess] << " is not in this room.\n\n";

            chrono::duration<int, milli> timespan(1000);
            this_thread::sleep_for(timespan);
        }
        // Invalid guess
        else if (guess > 9 || guess < 0)
        {
            cout << "That's not a number from 1 to 10, silly.\n\n";

            chrono::duration<int, milli> timespan(2000);
            this_thread::sleep_for(timespan);
        }
        // Right guess
        else
        {
            cout << "That is correct! Professor " << professor[guess] << " is in this room. Say hi!\n\n";

            PlaySound(TEXT("Bell_Correct.wav"), NULL, SND_FILENAME);

            chrono::duration<int, milli> timespan(3000);
            this_thread::sleep_for(timespan);

            cout << "This concludes the UAT Campus Tour.\n\n";

            this_thread::sleep_for(timespan);

            cout << "You guessed " << tries;
            if (tries == 1)
            {
                cout << " time.\n\n";
            }
            else
            {
                cout << " times.\n\n";
            }
            this_thread::sleep_for(timespan);
        }
        // To prevent infinitely repeating above on entering something other than a number
        if (cin.fail())
        {
            cout << "Stop trying to break my program.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');

            chrono::duration<int, milli> timespan(2000);
            this_thread::sleep_for(timespan);
        }
    } while (guess != ranNumber);

    return 0;
}