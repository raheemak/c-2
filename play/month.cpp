#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

class Date {
	private:
		int month, day, year;
	
	public:
		void initialize(){
			month=day=year=-1;
		}

		void display(){
			cout << month << "/" << day << "/" << year << endl;
		}
		
		void input();	
};

void Date::input (){ 
	char slash;
	cout << "Enter date: ";
	cin >>  month >> slash >> day >> slash >> year;
}

main(){
	//void initialize (int&, int&, int&);
	//void display (int, int, int);
	//void input (int&, int&, int&);
	
	//int month, day, year;

	/*initialize (month,day,year);
	display(month,day,year);
	input(month,day,year);
	display(month,day,year);
	*/
	
	Date d;
	d.initialize();
	d.display();
	d.input();
}



/*NOTES: 
 *
 * Class : combination of variables that describe what the class is composed of 
 * and functions that will operate on those variables.
 *	-object
 *	-handle
 *	-data members (variables)
 *	-methods
 *
 * //how to define class
 * 	class Identifier {
 * 	
 * 	};
 * 
 * 	- semi colon is needed at end of class defintion
 *There are two domains with classes: 
	-public: anything declared can be accessed directly so long as you 
		have an instance of that object
	-private

Methods are functions that only be invoked once object has been declared
Methods and member should be distinguished.

You can write methods outside of the class if you use :: 
	-must be connected by class through use of double color
	-scope resolution operator
	-connects function through class

Purpose of creating class is to create logical representation of what we want torepresent.

Different from structures because you can only invoke functions through handle.

Class : 
	-behaviours
	-characteristics
can you pass an object similar to how you pass a structure? 
put all classes in the same file? 
*/

