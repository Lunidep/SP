//coin22.cpp
#include "mlisp.h"

extern double VARIANT;
extern double COINS;
double largest(double coins__set);
double count__change(double amount);
bool pier_Q(bool x_Q, bool y_Q);
double cc(double amount, double coins__set);
double denomination__list(double  coins__set);

// ������� - ����� � ����� ������
double VARIANT=17.;
//���������� ��������� ���������� �����
double COINS=4.;

double largest(double coins__set){
   return
	( coins__set == 1. ? 2.
	: coins__set == 2. ? 5.
 	: coins__set == 3. ? 15.
	: coins__set == 4. ? 25.
	: 0.
	);
}

double count__change(double amount){
	display( "______\n amount: ");
	display( amount);
        newline();
	display( "COINS: ");
	display( COINS);
        newline();
    return
	( amount <= 0. ||
	  COINS < 1. ||
	  largest (COINS) == 0. ?
	    display("Improper parameter value!\ncount-change= "), -1.
             : ( display( "List of coin denominations: "),
                denomination__list( COINS),
	        display( "count-change= "),
      		cc(amount, COINS) )
	);
}

bool Shaeffer_Q(bool x_Q, bool y_Q){
  return !(x_Q && y_Q);
}

double cc(double amount, double coins__set){
  return
	( amount == 0. ? 1.
	: Shaeffer_Q(amount >= 1., coins__set > 0.) ? 0.
	  : cc(amount, coins__set - 1.) +
	    cc(amount - largest(coins__set),
	       coins__set)
	);
}

double denomination__list(double  coins__set){
	return ( coins__set== 0 ? newline() , 0.
                : (display(largest(coins__set)),
                   display(" "),
                   denomination__list(coins__set - 1.)
                  )
               );
}

int main(){
 display ("Variant ");
 display (VARIANT);
 newline();
 display (count__change(100.) ); newline();
 COINS=13.;
 display (count__change(100.) ); newline();
 display ("(c) Ilya Popov 2022\n");

 std::cin.get();
 return 0;
}

