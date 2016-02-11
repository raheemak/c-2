/*Raheema Kadwa
 * Lab1
 * Random equation generator
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using std:: cin;
using std:: cout;
using std:: endl;
using std:: string;


const string rules = "\n*********\nWelcome to the Equation Game.\n----\nRules\n----\nYou will be asked 100 mathematical equations.\nType -999 to quit.\nRound to two decimal places.\n**********\n\n";

const string levelUp = "(1)Continue at the current level.\n(2)Go to the next level.\n(3)Display summary statistics for the current level.\n(4)Quit.";

main(){
	void generateEquation(int, int&,int&, char&);
	int checkEquation(int,int,char,int[],int[],char[],bool[],int);
	bool getInput (int, int, char, bool&);
	void update (int, int, char, bool, int[], int[], char[],bool[], int&, int&);
	void display(int, int, int, char[], bool[]);

	const int MAX = 100;
	int first [MAX], second [MAX];
	char operators [MAX], tempOperator;
	bool results[MAX], cont = true, newEquation, quit = false,correct;
	int min=0,choice,tempFirst, tempSecond, counter=0, level =0, temp=0, numCorrect=0;

	//loop ends if user does not wish to continue or is MAX if reached
	cout << rules;

	while (cont){
		
		//generate equation while nonzero int returned 
		do {
			generateEquation(level,tempFirst,tempSecond,tempOperator);
			temp = checkEquation(tempFirst,tempSecond,tempOperator,first,second,operators,results,counter);
			newEquation=(temp==0);
		}while(!newEquation); 

		correct = getInput (tempFirst,tempSecond,tempOperator,quit);
		
		if (correct)
			numCorrect++;
	
		if (quit)
			break;
		
		if (numCorrect%10==0){
			cout <<endl << levelUp <<endl << "Your Choice: ";
			cin >> choice; 
			switch (choice){
				case 2:
					level++;		
					numCorrect=0;
					min = counter;
					break;
				case 3: 
					display(min, counter, level, operators, results);
					break;
				case 4: 
					cont = false;
					break;
				deafault: 
					cout <<"Enrecognized command...\n";							
			}
 		}
       		  	/*cout <<endl <<endl <<"checking... " <<endl;
       	 		for (int x =0; x< counter ; x++){
	        		cout << first[x]<<operators[x]<<second[x]<<" " << results[x]<<endl;
        		}*/

		    update (tempFirst,tempSecond,tempOperator,correct,first,second,operators,results,counter,temp);
	
           	 if  (counter==99)
                	cont = false;
           }
}

int rand (int min, int max) {
        int rNum;
        static bool doneOnce = true;
	if (doneOnce){
		srand( time(0) );
        	doneOnce =false;
	}
	rNum = min + rand()%max;
        return rNum;
}

void display (int min, int counter, int level, char operands [], bool correct[]){
	int total [4]= {0,0,0,0};
	int right [4]= {0,0,0,0};
	//+,-,*,/	
	for (int x = min; x<counter; x++){
		if (operands[x]=='+'){
			total[0]++;
			if (correct[x])
				right[0]++;
		}
		else if (operands[x]=='-'){
			total[1]++;
			if (correct[x])
				right [1]++;
		}
		else if (operands[x]=='*'){
			total[2]++;
			if (correct[x])
				right[2]++;
		}
		else{
			total[3]++;
			if (correct[x])
				right[3]++;
		}
	}
	
	cout << "\nLEVEL " << level+1 << " RESULTS"<<endl;
	cout << "+: " << right[0]<<" out of "<<total[0]<<" correct."<<endl;
 	cout << "-: " << right[1]<<" out of "<<total[1]<<" correct."<<endl;
  	cout << "*: " << right[2]<<" out of "<<total[2]<<" correct."<<endl;
  	cout << "/: " << right[3]<<" out of "<<total[3]<<" correct."<<endl;		
	cout <<endl;
}

char randOp (){
        static char operands [4]= {'/', '*', '+', '-'};
        int index = rand (0,4);
        char operand = operands[index];
       	return operand;
}

//make a random equation
void generateEquation(int level, int&op1,int&op2, char&  op){
        int rand (int, int);
        char randOp ();
        int min,max;;

	switch (level){
		case 0:
			min = 0 ;
			max = 10;
			break;
		case 1:
			max = 25;
			break;
		case 2:
			min = 10;
			break;
		case 3:
			min = -25;
			break;
	}//swtich
	op1 = rand (min,max);	
	op2 = rand (min,max);
	op = randOp();

	//division by zero 
	while (op=='/'&&op2==0)
		op2= rand(min,max);
}		

//will return 0 if equation has not been seen before
//will return 0 if equation has been seen and answered correctly
//will return index of where in the arrays incorrectly answered equation is

int checkEquation(int op1,int op2,char op, int first[] ,int second[],char operators[] , bool results [], int counter){
	int index =0;
	for (int x =0; x <counter; x++){
		if (op=='+'||op=='*'){
			if (operators[x]&&((first[x]==op1&&second[x])||first[x]==op2&&second[x]==op1)&&!results[x]){
					index = counter;
					break;
			}
		}	
		else{	
			if (first[x]==op1&&second[x]==op2&&operators[x]==op&&!results[x]){
                                        index = counter;
					break;
                        }
		} 
		index = 0 ;
	}
	return index;
}
    
double calculate (int op1, int op2, char op){
        double  answer ;
        int temp;
	
	switch (op){
                case '+':
                        answer = op1+op2;
                        break;
                case '-':
                        answer = op1-op2;
                        break;
                case '*':
                        answer = op1*op2;
                        break;
                case '/':
                        answer = op1/(double)op2;
                        break;
        }
	//cout <<"answer: " << answer <<endl;
	temp = answer*100;
	answer = temp / (double)100;

        return answer;
}

bool getInput (int first, int second, char op, bool&quit){
	double calculate (int, int , char);
	double userAns, cpuAns;
	bool correct = false;
	
	cout << first << " " << op << " " << second << ": ";	
	cin >> userAns;
	cpuAns = calculate (first, second, op);
	
	if (userAns==-999){
		quit = true;
		cout << "Quitting..."<<endl;
	}
	else if (cpuAns == userAns)
		correct = true;
	//cout << "cpu: " <<cpuAns << " user: " <<userAns <<endl;	
	//cout << "getInput(): "<<correct << endl;
	return correct;
}

void update (int op1, int op2, char op, bool correct,int first[], int second[], char operators[], bool results[],int&counter, int&temp){
	int index;
	if (temp!=0)
		index = temp;
	else
		index = counter;
	
	first[index]=op1;
	second[index]=op2;
	operators[index]=op;
	results[index]=correct;
	
	counter++;
	temp = 0 ;
	//cout << "update(): "<<endl;
}				
