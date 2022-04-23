/*  PIP   */
#include "mlisp.h"
double root/*2*/ (double a, double b);
double half__interval/*14*/ (double a, double b,
	double fa, double fb);
double __PIP__try/*32*/ (double neg__point, double pos__point);
bool close__enough_Q/*56*/ (double x, double y);
double average/*60*/ (double x, double y);
extern double tolerance;
extern double total__iterations;
double f/*66*/ (double z);
//________________ 
double root/*2*/ (double a, double b){
	double temp = 0.;
	temp = half__interval(a,
	b,
	f(a),
	f(b))
	 ;
	display("Total number of iteranions=");
	display(total__iterations);
	newline();
	display("[");
	display(a);
	display(" , ");
	display(b);
	display("]");
	return
	temp;
}

double half__interval/*14*/ (double a, double b,
	double fa, double fb){
	double root = 0.;
	total__iterations = 0.;
	root = (((fa < 0.) && (0. < fb))
	? __PIP__try(a,
	b)
	 : 
	(((0. < fa) && (fb < 0.))
	? __PIP__try(b,
	a)
	 : 
	(b + 1.)));
	newline();
	return
	root;
}

double __PIP__try/*32*/ (double neg__point, double pos__point){
	double midpoint = 0.;
	double test__value = 0.;
	midpoint = average(neg__point,
	pos__point)
	 ;
	display("+");
	total__iterations = (total__iterations + 1.);
	return
	(close__enough_Q(neg__point,
	 pos__point)
	? midpoint: 
	(test__value = f(midpoint),
	((0. < test__value)
	? __PIP__try(neg__point,
	midpoint)
	 : 
	((test__value < 0.)
	? __PIP__try(midpoint,
	pos__point)
	 : 
	midpoint))));
}

bool close__enough_Q/*56*/ (double x, double y){
 return (abs((x - y)) < tolerance);
	 }

double average/*60*/ (double x, double y){
	return
	((x + y) * (1. / 2.));
}

double tolerance = +.001e0;
double total__iterations = 0.;
double f/*66*/ (double z){
	return
	((exp((- z)) * sin((z + pi))) +cos(z) + 120.);
}

int main(){
	display("Variant 206-17\n");
	 display(root(-6.,
	-.549e1)
	 );
	 newline();
	 display("(c) Ilya Popov 2022\n");
	 std::cin.get();
	return 0;
}

