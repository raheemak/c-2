#include <iostream>
#include <cstdlib>
#include <ctime> 

using std:: cin;
using std:: cout;
using std:: endl;
using std:: string;

main(){
	void generate (int&, int&, char&);
	void display (int[] , int[], char[] ) ;
	
	int cpuAnsw, counter = 0 ; 
	bool cont = true;

	int first[100], second[100];
	bool correct [100];
	char op [100];

	int op1, op2;
	char op; 

	while (cont){
		
		generate (op1, op2, op);	
		cpuAnsw = calculate (op1,op2,op);
		display(cpuAnsw, correct, counter);
 
		counter ++;
		if (counter == 9 )
			cont = false;
	}
	display (first, second, op);
}

int rand (int min, int max) { 
	int rNum;
 	srand( time(0) );	
	rNum = min + rand()%max;
	return rNum;
}

char randOp (){
	char operands [4]= {'/', '*', '+', '-'};
	int index = rand (0,4);
	char operand = operands[index];
	return operand;
}

int calculate (int first, int second, char operand ){
	int  answer ;
	switch (operand){	
		case '+':
			answer = first + second;
			break;
		case '-':
			answer = first + second;
			break;
		case '*':
			answer = first * second;
			break;
		case '/':
			answer = first / second;
			break;
	}
	return answer;

}

void generate (int& first, int& second, char& op){
        int rand (int, int);
        char randOp ();
 	bool cont = false;
	const int MIN = 0, MAX = 11;
//	while (!cont ) {
		 first = rand (MIN, MAX);
        	 second = rand (MIN, MAX);
        	 op = randOp(); 
	//	 if (second== 0 && op == '/')
	//		cont = true;
//	}	
}

//check is equation has already been generated:
//	if yes, was it correct ? 
//		check operand: if plus or multiplication then check if either is equal 
//				if division or subtraction, then order matters 
//	if not, then reinput that equation;
//				temp int counter to index positions in array 
//
//if not, then output new equation and update lists


void display (int first[], int second[], char op[]){
	cout << " A";
	for (int x = 0 ; x <= 9 ; x++ ) 
		cout << first[x] << " " << op [x] << " " << second [x] << endl;
}

void display (int correctAnw, int correct[], int counter){
	int calculate (int, int char); 
    	cout << first[counter] << " " << op[counter] << " " << second[counter] << ": " ;
        cin >> userAnsw;
        if (userAnsw == cpuAnsw)
        	correct[counter]=true;
        else
                correct[counter]=false;
}

