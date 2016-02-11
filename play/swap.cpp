// Raheema Kadwa 
// Lab 1 

#include <iostream> 

using std::cin;
using std::cout;
using std:: endl;

main(){
	void  swap (int&, int&) , swap(int, int[], int[]);
	void display (int, int[], int[]);
	void initialize (int[][4], int, int, const int[], int, const int[], int);
	void display1(const int[], int), displayM(int[][4], int, int);

	/////
	int x = 45, y = 23;
			
	cout <<"Swap(x,y):"<<endl;
	cout << endl << "x: " << x<< " y: " << y <<endl;
	swap(x, y);
	cout << "x: " << x<< " y: " << y << endl << endl;	
	
	/////
	const int MAX = 10;
        int  array1 [MAX]= {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        int array2 [MAX]= {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};


	cout <<endl<< "Swap(int[], int[])"<<endl;
	display (MAX, array1, array2);
	swap (MAX, array1, array2);
	display (MAX, array1, array2);

	/////
        cout <<endl<<"Initalize(...)"<<endl;
	int size1=7, size2=6;
        const int array3[size1]={2,4,6,8,10,12,14};
        const int array4[size2]={1,3,5,7,9,11};
        int rows = 7, columns=4;
        int array5[rows][4];

	cout << "1: {";	
	display1(array3, size1);
	cout <<"2: {";
	display1(array4, size2);
	cout <<endl<<"Initialized... "<<endl<<endl;

	initialize(array5, rows, columns, array3, size1, array4, size2);
	displayM(array5, rows, columns);
	cout <<endl;
}

void display1(const int array[], int size){
	for (int x =0; x< size; x++ ) {
		cout << array[x]<<" " ;
	}
	cout <<"}"<<endl;
}

void swap ( int& first, int&second){
	int temp = first;
	first = second;
	second = temp;
}

void display (int max, int array1[], int array2[]){
	cout<< endl;
	for ( int x = 0 ; x < max ; x++ ) 
		cout << array1[x] << "\t" << array2[x] << endl;
	cout << endl;
}

void swap (int max, int first[], int second[]){
	void swap (int&, int&);

	for (int x= 0 ; x < max ; x+=2)
		swap (first[x], second[x]);
}

void initialize(int array[][4], int rows, int columns, const int first[], int size1, const int second[], int size2){
	//counter[0] keeps track of first array
	//counter[1] keeps track of second array

	int counter1=0, counter2=0;
	int current =0;
	bool backwards1 = false, backwards2=false;

	for (int row=0; row<rows; row++){	
		current = row%2;
		for (int column=0; column<columns; column++){
			//check to see if populating even numbered rows or odd numbered rows
			//cout <<"current: " <<row<< ", "<<column;
			//cout<<" current: "<<current;
			
			if (current==0){
				//cout << "Current: "<<current<<endl;
				//cout << " counter1: " <<counter1 <<endl;;
				
				array[row][column]= first[counter1];
				if (!backwards1&&counter1==(size1-1)){
					counter1++;
					backwards1= true;
					
				}
				else if (backwards1&&counter1==0){
					counter1--;
					backwards1=false;		
				}
				if (backwards1)
					counter1--;
				else
					counter1++;			
			}

			else{ 
				array[row][column]=second[counter2];
				//cout << " counter2: " <<counter2<<endl;
				if (!backwards2&&counter2==(size2-1)){
                                        counter2++;
                                        backwards2= true;
                                }
                                else if (backwards2&&counter2==0){ 
                                        counter2--;
                                        backwards2=false;
                                }
                                if (backwards2)
                                        counter2--;
                                else
                                        counter2++;
			} 	
		}
		//cout <<endl;
	}
}


void displayM(int array[][4], int rows, int columns){
	for (int row  =0; row<rows; row++){
		for (int column=0; column<columns; column++)
			cout<< array[row][column]<<" ";
		cout<<endl;
	}
}
