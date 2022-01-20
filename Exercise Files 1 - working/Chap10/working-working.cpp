// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>


/*
 * 1 Deck -> 52 cards
 * 4 suits: spades, hearts, diamonds and clubs.
 * Within each suit are 13 ranks.
 * A 2 3 4 5 6 7 8 9 T J Q K
 * Ex: Ts 3h Kd 6c
 */


class Card{
	char _rank;
	char _suit;
public:
	Card(){reset();}
	Card(char rank,char suit):_rank(rank),_suit(suit){}
	Card(const Card &);

	~Card(){reset();}
	void reset(){_suit=_rank='0';}
	Card & operator = (const Card &);

	void setSuit(char suit){_suit=suit;}
	char getSuit()const{return _suit;}
	void setRank(char rank){_rank=rank;}
	char getRank()const{return _rank;}
};
Card::Card(const Card & card){
	_suit=card.getSuit();
	_rank=card.getRank();
}
Card & Card::operator=(const Card & card) {
    if(this != &card) {
    	_rank=card.getRank();
    	_suit=card.getSuit();
    }
    return *this;
}

std::vector<Card> card_vi=
{{'A','s'},{'2','s'},{'3','s'},{'4','s'},{'5','s'},{'6','s'},{'7','s'},{'8','s'},{'9','s'},{'T','s'},{'J','s'},{'Q','s'},{'K','s'},
 {'A','h'},{'2','h'},{'3','h'},{'4','h'},{'5','h'},{'6','h'},{'7','h'},{'8','h'},{'9','h'},{'T','h'},{'J','h'},{'Q','h'},{'K','h'},
 {'A','d'},{'2','d'},{'3','d'},{'4','d'},{'5','d'},{'6','d'},{'7','d'},{'8','d'},{'9','d'},{'T','d'},{'J','d'},{'Q','d'},{'K','d'},
 {'A','c'},{'2','c'},{'3','c'},{'4','c'},{'5','c'},{'6','c'},{'7','c'},{'8','c'},{'9','c'},{'T','c'},{'J','c'},{'Q','c'},{'K','c'}};



class Deck{
	int _numOfDecks;
	std::vector<Card> _cards_v;
public:
	Deck():_numOfDecks(1) {reset();}
	//Deck(int n){reset();}
	Deck(const Deck &);

	~Deck(){reset();}
	void reset();
	Deck & operator = (const Deck &);

	void setNumOfDecks(int numOfDecks){_numOfDecks=numOfDecks;}
	int getNumOfDecks()const{return _numOfDecks;}
	void setCard_v(std::vector<Card> & cards_v){_cards_v=cards_v;}
	std::vector<Card> getCard_v()const{return _cards_v;}
	void setCardIn_v(Card & card){_cards_v.push_back(card);}
};
void Deck::reset(){
	_cards_v={};
}
Deck::Deck(const Deck & deck){
	_cards_v=deck.getCard_v();
}
Deck & Deck::operator=(const Deck & deck) {
    if(this != &deck) {
    	_cards_v = deck.getCard_v();
    }
    return *this;
}


void new_mazo(Deck &,int n);// Create a new deck wich may optionally contain more than one deck of 52 cards.
int remaining(Deck &);
void shuffle_mazo(Deck &);
void shuffle_mazo(Deck &,int);
Card & deal_card(Deck &);// Deal a single card and from the deck and reduce the count of remaining cards in the deck by one
void new_mazo(Deck &);
int deck_size(Deck &);
void printCard(Card &);
void printMazo(Deck &);

void new_mazo(Deck & deck){
	for(Card card:card_vi){
		deck.setCardIn_v(card);
	}
}
void new_mazo(Deck & deck,int numOfDecks){
	deck.setNumOfDecks(numOfDecks);
	for(int i=0;i<numOfDecks;i++){
		new_mazo(deck);
	}
}


void printCard(Card & card){
	printf("%c%c,",card.getRank(),card.getSuit());
}
void printMazo(Deck & deck){
	printf("\nsizeDeck: %d\n",deck.getCard_v().size());
	int cont=0;
	for(auto card:deck.getCard_v()){
		printCard(card);
		if(cont++==12){
			puts("");
			cont=0;
		}
	}
	puts("");
}
void printMazo(std::vector<Card> & card_v){
	printf("\nsizeDeck: %d\n",card_v.size());
	int cont=0;
	for(auto card:card_v){
		printCard(card);
		if(cont++==12){
			puts("");
			cont=0;
		}
	}
	puts("");
}
void addCard(std::vector<Card> & card_v)
{
	Card card{'Z','z'};
	card_v.push_back(card);
}
void addCard(Deck & deck)
{
	Card card{'Z','z'};
	deck.setCardIn_v(card);
}


int main()
{

	int cardsToDealMazo1=2,cardsToDealMazo2=7;
	int numOfDecks=3;

	puts("Mazo 1:");
	Deck deck1;
	new_mazo(deck1);
	//printMazo(deck1);
	shuffle_mazo(deck1,3);
	//printMazo(deck1);
	for(int i=0;i<cardsToDealMazo1;i++){
		printCard(deal_card(deck1));
	}
	printMazo(deck1);
	printf("\nRemainingMazo1: %d, MazoSize1: %d\n",remaining(deck1), deck_size(deck1));


    puts("Hello, World!");
    printf("Alex");
    return 0;
}

void shuffle_mazo(Deck & deck){
	int sizeDeck=deck.getCard_v().size();
	//printMazo(deck);
	std::vector<Card> cards_vTemp(sizeDeck);
	int i=1;
	for(auto card:deck.getCard_v()){
		cards_vTemp[i]=card;
		if((i+=2)>=sizeDeck){
			i=0;
		}
	}
	//printMazo(cards_vTemp);
	deck.setCard_v(cards_vTemp);
}
void shuffle_mazo(Deck & deck, int n){
	for(int i=0;i<n;i++){
		shuffle_mazo(deck);
	}
}



Card & deal_card(Deck & deck){

	int size= deck.getCard_v().size();
    long num=size;
	//printf("size: %d\n",size);
    //printf("time value: %ld\n", (long) time(nullptr));
    //printf("RAND_MAX is %d\n", RAND_MAX);
    srand((unsigned)time(nullptr));
    rand();
    printf("time value: %ld\n", (long) time(nullptr));
    while(num>=size){
		num = rand() % 100;
		printf("\npseudo-random value: %d\n", num);
    }

	static Card card;
	card.setRank(deck.getCard_v()[num].getRank());
	card.setSuit(deck.getCard_v()[num].getSuit());

    std::vector<Card> card_v = deck.getCard_v();
    card_v.erase(card_v.begin()+num);
    deck.setCard_v(card_v);

	return card;
}

int remaining(Deck & deck){
	int valInt=0;

	return valInt;
}

int deck_size(Deck & deck){
	int valInt=0;

	return valInt;
}






