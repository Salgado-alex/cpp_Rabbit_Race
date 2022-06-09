#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>


using namespace std;

class tortoise {
  public:
    int square;

    tortoise();
    bool victor();
    void win();
    void fastPlod();
    void slip();
    void slowPlod();
} turtle;

tortoise::tortoise() {
  square = 1;
}

bool tortoise::victor() {
  bool victory;

  if ( square < 70 )
    victory = false;
  else
    victory = true;

  return victory;
}

void tortoise::win() {
  cout << "TORTOISE WINS!! YAY!!!" << endl;
}

void tortoise::fastPlod() {
  square += 3;//3 to right
  if ( square > 70 )
    square = 70;
}

void tortoise::slip() {
  square -= 6; //6 to left
  if ( square < 1 )
    square = 1;
}

void tortoise::slowPlod() {
  square += 1; //1 to right
}

class hare {
    public:
    int square;

    hare();
    bool victor();
    void win();
    void bigHop();
    void bigSlip();
    void smallHop();
    void smallSlip();
} rabbit;

hare::hare() {
  square = 1;
}

bool hare::victor() {
  bool victory;

 
  if ( square < 70 )
    victory = false;
  else
    victory = true;

  return victory;
}

void hare::win() {
  cout << "Hare wins" << endl;
}

void hare::bigHop() {
  square += 9;//9 to the right
  if ( square > 70 )
    square = 70;
}

void hare::bigSlip() {
  square -= 12; //12 to the left
  if ( square < 1 )
    square = 1;
}

void hare::smallHop() {
  square += 1;// 1 to right
}

void hare::smallSlip() {
  square -= 2;//2 to left
  if ( square < 1 )
    square = 1;
}

void sleep();
void displayOutput();

int main()
{
  cout << "BANG !!!" << endl; 
  cout << "AND THEY'RE OFF !!!!!" << endl;

  while ( !( turtle.victor() || rabbit.victor() ) ) {
      
    this_thread::sleep_for ( chrono::seconds(1) );
      sleep();
  }

  if ( turtle.victor() && rabbit.victor() )
    cout << "TIE";
  else if ( turtle.victor() )
    turtle.win();
  else
    rabbit.win();

  return 0;
}

void sleep() {
  srand ( time(0) );

  int random = rand() % 12;

  if ( random < 5 )
    turtle.fastPlod();
  else if ( random < 7 )
    turtle.slip();
  else
    turtle.slowPlod();

  
  if ( ( random >= 2 ) && ( random < 4 ) )
    rabbit.bigHop();
  else if ( random < 5 )
    rabbit.bigSlip();
  else if ( random < 8 )
    rabbit.smallHop();
  else if ( random < 10 )
    rabbit.smallSlip();

  displayOutput();
}

void displayOutput() {
  cout << endl;

  if ( turtle.square < rabbit.square ) {
    for ( int i = 1; i < turtle.square; i++ )
    cout << '=';
    cout << 'T';

    for ( int i = 1; i < ( rabbit.square - turtle.square ); i++ )
    cout << '=';

    cout << 'H';

    for ( int i = 1; i < ( 70 - rabbit.square ); i++ )
    cout << '=';

    cout << endl;
  }
  else if ( rabbit.square < turtle.square ) {
    for ( int i = 1; i < rabbit.square; i++ )
    cout << '=';
    cout << 'H';

    for ( int i = 1; i < ( turtle.square - rabbit.square ); i++ )
    cout << '=';

    cout << 'T';

    for ( int i = 1; i < ( 70 - turtle.square ); i++ )
    cout << '=';

    cout << endl;
  }
  else {
    for ( int i = 1; i < rabbit.square; i++ )
    cout << '=';
    cout << 'O';

    for ( int i = 1; i < ( 70 - rabbit.square ); i++ )
    cout << '=';

    cout << endl << "OUCH !!!" << endl;
  }

    cout << "T = Tortoise" << endl; 
    cout << "H = Hare"     << endl;
    cout << "O = Ouch"     << endl;
}