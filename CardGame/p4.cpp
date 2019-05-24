//Thanh Nguyen
// p4.cpp
//Purpose: design Card game using stack and queue
//Input: none
//Output: value of cards played by players, final result of the game

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "stack.h"
#include "queue.h"
#include <stdio.h>

using namespace std;

const int MAX_VALUE = 13;
const int START_CARDS = 7;

void welcome();
// print welcome message

Stack shuffle();
//shuffle deal cards

void dealCard(Queue& p1, Queue& p2, Stack& deal);
// deal cards to players

void rule(Queue& player, Stack& disCard, Stack& deal);
// rule of the game

void checkDeal(Stack& disCard, Stack& deal);
// check if deal pack of cards is empty
// if empty, flip pack os discard to make a new pack deal card
// then continue the game

void goodbye();
//print goodbye message

int main()
{
  Queue p1,p2; // player1's cards, player2's cards
  Stack deal, disCard;
  //pack of dealcard
  //pack of disCard
  char answer = 'y';// get answer from user
  int peek; //to peek the top value of queue or stack
  
  welcome();
  
  while (answer == 'y'){
	deal = shuffle(); // shuffling deal card
	dealCard(p1,p2,deal); // deal cards to players
	while(!p1.isEmpty() && !p2.isEmpty()){
	  //player1's turn
	  checkDeal(disCard, deal); //check dealcard
	  disCard.push(deal.pop()); //place next card in dealcard to discard stack
	  peek = disCard.peek();
	  cout << endl << "Player 1, you need to beat " << peek << endl; 
	  cout << "Press enter to play";
	  getchar();
	  cout << "You play a " << p1.peek() << endl;
	  rule(p1, disCard, deal);

	  //player2's turn
	  checkDeal(disCard, deal);
	  disCard.push(deal.pop());
	  peek = disCard.peek();
	  cout << endl << "Player 2, you need to beat " << peek << endl;
	  cout << "Press enter to play";
	  getchar();
	  cout << "You play a " << p2.peek() << endl;
	  rule(p2, disCard, deal);
	}

	if (p1.isEmpty())
	  cout << endl << "Player 1 won! Congratulation!" << endl;
	if (p2.isEmpty())
	  cout << endl << "Player 2 won! Congratulation!" << endl;

	cout << endl << "Play Again?(y/n)";
	cin >> answer;
  }
  goodbye();
}

void welcome()
{
  cout << "___________Welcome to the Card Game___________" << endl << endl;
  cout << "This game needs two players. Each player is dealt 7 cards\n "
	   << "from a shuffled pack of cards . The next card in the deal\n "
	   << "stack will be placed in a discard stack.\n" 
	   << "In each turn,if the card picked randomly from player's cards\n "
	   << "is higher in number than the one on top of the discard stack\n "
	   << "the turn is over.\n"
	   << "in case those are equal in number, the player must take\n"
	   << "one card from the deal stack. If it is lower, the player must\n"
	   << "take two cards from the deal stack.\n"
	   << "The discard stack will be turn over to continue the gamse\n"
	   << "in case the deal stack runs out of cards\n" 
       << "Which player get rid of cards first will win." << endl;
  cout << "___________________Enjoy!______________________";
  cout << endl << endl << endl;
}

Stack shuffle()
{
  const int MAX_COUNT = 4; //each card has 4 copies
  Stack result;            //shuffled cards
  bool done = false;       //check if shuffle is done
  int card;                //a random card number
  int cardCounts[MAX_VALUE + 1]; //list of cards
  srand(time(0));                //initialize random

  //initialize card
  for (int i = 0; i < MAX_VALUE + 1; i++)
	cardCounts[i] = 0;

  //shuffle card
  cout << endl << "Shuffling cards...";
  while (!done){
	card = (rand() % MAX_VALUE) + 1; //generate a random number from 1 to 13
	if (cardCounts[card] < MAX_COUNT){
	  cardCounts[card]++;
	  result.push(card);
	}
	done = true;
	for (int i = 1; i < MAX_VALUE + 1; i++){
	  if (cardCounts[i] < MAX_COUNT)
		done = false;
	}
  }
  cout << "Done" << endl;
  return result;
}

void dealCard(Queue& p1, Queue& p2, Stack& deal)
{
  cout << endl << endl;
  cout << "Now dealing cards to players..." << endl;
  for(int i = 0; i <= START_CARDS; i++){
	p1.enqueue(deal.pop());
	p2.enqueue(deal.pop());
  }
}

void rule(Queue& player, Stack& disCard, Stack& deal)
{
  if (player.peek() > disCard.peek()){
	cout << "No need to take more card. Switch player..." << endl;
	disCard.push(player.dequeue());
  }
  else if (player.peek() == disCard.peek()){
	cout << "You must take 1 card." << endl; 
	disCard.push(player.dequeue());
	checkDeal(disCard, deal);
	player.enqueue(deal.pop());
  }
  else{
	cout << "You must take 2 cards." << endl;
	disCard.push(player.dequeue());
	checkDeal(disCard, deal);
	player.enqueue(deal.pop());
	checkDeal(disCard, deal);
	player.enqueue(deal.pop());
  }
}

void checkDeal(Stack& disCard, Stack& deal)
{
  if (deal.isEmpty()){
	cout << endl << "Empty deal deck... turn over discard deck..." << endl;
	int temp = disCard.pop();
	while(!disCard.isEmpty())
	  deal.push(disCard.pop());
	disCard.push(temp);
  }
}

void goodbye()
{
  cout << endl << endl;
  cout << "____Thank you for playing!___" << endl;
  cout << "________See you again!_______" << endl;
  cout << endl << endl;
}
