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
        return Suit + std::to_string(Value);
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

bool Compare(Card card1, Card card2)
{
    return card1.GetValue() < card2.GetValue();
};
class Player
{
public:
    int score;
    int pointsTaken;
    std::vector<Card> Hand;
    std::vector<Card> Hearts;
    std::vector<Card> Spades;
    std::vector<Card> Clubs;
    std::vector<Card> Diamonds;
    std::string Name;
    Player() :Hand(), Hearts(), Spades(),Clubs(),Diamonds()
    {
        score = 0;
        std::cout << "What is your name?";
        std::cin >> Name;
        pointsTaken = 0;
    }
};
class Deck {
public:
    Card Cards[52];
    Deck() :Cards{}
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
            std::uniform_int_distribution<> rand(0, 51);
            std::mt19937 gen(rd());
            int holder = rand(gen);
            //perform the swap
            Cards[i] = Cards[holder];
            Cards[holder] = card;
        }   
    }
    void Deal(Player player1, Player player2, Player player3, Player player4)
    {
        this->Shuffle();
        //assignes 13 cards to each hand then sorts the hands
        //It also assignes each card to its suite, so we can keep track of the players cards in each suite and sort their hand more easily
        for (int i = 0; i < 52; i++)
        {

            if (i % 4 == 0)
            {
                if (Cards[i].GetSuit() == 'S')
                {
                    player1.Spades.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'H')
                {
                    player1.Hearts.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'D')
                {
                    player1.Diamonds.push_back(Cards[i]);
                }
                else
                {
                    player1.Clubs.push_back(Cards[i]);
                }
            }
            else if (i % 4 == 1)
            {

                if (Cards[i].GetSuit() == 'S')
                {
                    player2.Spades.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'H')
                {
                    player2.Hearts.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'D')
                {
                    player2.Diamonds.push_back(Cards[i]);
                }
                else
                {
                    player2.Clubs.push_back(Cards[i]);
                }
            }
            else if (i % 4 == 2)
            {
                if (Cards[i].GetSuit() == 'S')
                {
                    player3.Spades.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'H')
                {
                    player3.Hearts.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'D')
                {
                    player3.Diamonds.push_back(Cards[i]);
                }
                else
                {
                    player3.Clubs.push_back(Cards[i]);
                }
            }
            else
            {
                if (Cards[i].GetSuit() == 'S')
                {
                    player4.Spades.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'H')
                {
                    player4.Hearts.push_back(Cards[i]);
                }
                else if (Cards[i].GetSuit() == 'D')
                {
                    player4.Diamonds.push_back(Cards[i]);
                }
                else
                {
                    player4.Clubs.push_back(Cards[i]);
                }
            }


        }

    }
};
//A class to score the stats of all the Player

class Game
{
public:
    Player Player1;
    Player Player2;
    Player Player3;
    Player Player4;
    Deck GameDeck;
    Game():Player1(), Player2(),Player3(),Player4(), GameDeck()
    {
    }
    void Round()
    {
        GameDeck.Deal(Player1, Player2, Player3, Player4);
    }
};
int main()
{
    std::cout << "Hello World!\n";
    Game game;
    game.Round();
    for (int i = 0; i < game.Player1.Spades.size(); i++)
    {
        std::cout << game.Player1.Spades[i].ToString() <<" ";
    }
    std::cin.get();
    return 0;
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
