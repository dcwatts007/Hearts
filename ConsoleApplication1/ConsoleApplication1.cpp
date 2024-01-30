// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
#include <random>
class Card {
public: 
    int Value;
    char Suit;
    Card()
    {
        Value = 0;
        Suit = ' ';
    }
    Card(int val,char str)
{
        Value = val;
        Suit = str;
}
    std::string ToString()
    {
        if (Value == 14)
        {
            return Suit + "A";
        }
        if (Value == 13)
        {
            return Suit + "K";
        }
        if (Value == 12)
        {
            return Suit + "Q";
        }
        if (Value == 11)
        {
            return Suit + "J";
        }
        return Suit + "" + Value;
    }
    int GetValue()
    {
        return Value;
    }
    char GetSuit()
    {
        return Suit;
    }

};
class Deck {
public:
    Card Cards[52];
    Deck()
    {
        //creates an array of all 52 cards in a standard deck
        for (int i = 0; i < 4; i++)
        {
            for (int j = 2; j < 15; j++)
            {
                if (i == 0)
                {
                    Card card(j,'S');
                    Cards[i * 13 + j - 2] = card;
                }
                else if(i==1)
                {
                    Card card(j, 'H');
                    Cards[i * 13 + j - 2] = card;
                }
                else if (i == 2)
                {
                    Card card(j, 'C');
                    Cards[i * 13 + j - 2] = card;
                }
                else
                {
                    Card card(j, 'D');
                    Cards[i * 13 + j - 2] = card;
                }
            }
        }
    }
    void Shuffle()
    {
        //sets up a random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        // swaps each card with a random other card (cards may be swapped multiple times)
        for (int i = 0; i < 52; i++)
        {
            //create a placeholder to swap the cards
            Card card = Cards[i];
            //create a random index
            std::uniform_int_distribution<> rand(0, 52);
            std::mt19937 gen(rd());
            int holder = rand(gen);
            //perform the swap
            Cards[i] = Cards[holder];
            Cards[holder] = card;
        }   
    }
    void Deal(std::list<Card> hand1, std::list<Card> hand2, std::list<Card> hand3, std::list<Card> hand4)
    {
        //assignes 13 cards to each hand then sorts the hands
        for (int i = 0; i < 52; i++)
        {
            this->Shuffle();
            if (i % 4 == 0)
            {
                hand1.push_back(Cards[i]);
            }
            else if (i % 4 == 1)
            {
                hand2.push_back(Cards[i]);
            }
            else if (i % 4 == 2)
            {
                hand3.push_back(Cards[i]);
            }
            else
            {
                hand4.push_back(Cards[i]);
            }
        }
    }
};
//A class to score the stats of all the Player
class Player
{
public:
    int score;
    int pointsTaken;
    std::list<Card> Hand;
    Player()
    {
        score = 0;
        pointsTaken;
    }
};
class Game
{
public:
    Player Player1;
    Player Player2;
    Player Player3;
    Player Player4;
    Deck GameDeck;
    Game()
    {
    }
    void Round()
    {
        GameDeck.Deal(Player1.Hand, Player2.Hand, Player3.Hand, Player4.Hand);
        
    }
};
int main()
{
    std::cout << "Hello World!\n";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
