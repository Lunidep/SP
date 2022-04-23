/*  PIP   */
#include "mlisp.h"
double day__of__week/*1*/ ();
double zeller/*18*/ (double d, double m,
	double y, double c);
double neg__to__pos/*29*/ (double d);
double birthday/*36*/ (double dw);
extern double dd;
extern double mm;
extern double yyyy;
//________________ 
double day__of__week/*1*/ (){
 return
 zeller(dd
	 , (010. + (!((2. < mm))
	? mm
	: 
	(mm - 12.)))
	 , remainder((1. + ((mm < 3.)
	? (yyyy - 2.)
	: 
	(yyyy - 1.)))
	 , 100.)
	 
	 , quotient((!((2. < mm))
	? (yyyy - 1.)
	: 
	yyyy)
	 , 100.)
	 )
	 ;
}

double zeller/*18*/ (double d, double m,
	double y, double c){
 return
 neg__to__pos(remainder((d +y +quotient(((26. * m) - 2.)
	 , 10.)
	  +quotient(y
	 , 4.)
	  +quotient(c
	 , 4.)
	  + (2. * (- c)))
	 , 7.)
	 );
}

double neg__to__pos/*29*/ (double d){
 return
 ((d < 0.)
	? (d + 7.)
	: 
	d);
}

double birthday/*36*/ (double dw){
 display("Ilya Popov was born on ");
	 display(((dw == 1.)
	? "Monday "
	: (dw == 2.)
	? "Tuesday "
	: (dw == 3.)
	? "Wednesday "
	: (dw == 4.)
	? "Thursday "
	: (dw == 5.)
	? "Friday "
	: (dw == 6.)
	? "Saturday "
	: ("Sunday ")));
	 display(dd);
	 display(".");
	 display(mm);
	 display(".");
	 return
 yyyy;
}

double dd = 15.;
double mm = 11.;
double yyyy = 2002.;
int main(){
	display(birthday(day__of__week()));
	 newline();
	 std::cin.get();
	return 0;
}

