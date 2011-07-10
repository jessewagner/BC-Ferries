// Jesse's Fare Calculator
//Jesse Wagner
//cs162 fridays
//Sources:

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	//variables
	char again = 'n';

	//greeting
	cout << "Welcome to Jesse's Fare Calculator!" << endl;
	cout << fixed << showpoint << setprecision(2);

	do{
		//variables
		const float small = 2.15;
		const float large = 3.45;
		int adult = 0;
		int child = 0;
		char vehicle = 'n';
		int vehicleLength = 0;
		char vehicleHeight = 'a';
		float ticketCosts = 0.00;
		float fuelSurcharge = 0.00;
		float totalAmount = 0.00;
		float adultCalc = 0.00;
		float childCalc = 0.00;
		float vehicleCalc = 0.00;
		float vehicleLengthCalc = 0.00;
		float vehicleTotal = 0.00;
		float fuelHuman = 0.00;
		float fuelVehicle = 0.00;
		
		//input
		cout << "How many adults (age 12 and over) are in your party? ";
		cin >> adult;
		cout << "How many children (age 5 to 11) are in your party? ";
		cin >> child;
		cout << "Are you driving a vehicle on to the ferry? ";
		cin >> vehicle;
		if(vehicle == 'y'){
			cout << "What is the length of the vehicle in feet? ";
			cin >> vehicleLength;
			cout << "Is the vehicle over 7 feet high? ";
			cin >> vehicleHeight;
		}

		//formulas

		//adult calculation
		adultCalc = static_cast<float>(adult) * 13.00;

		//child calculation
		childCalc = static_cast<float>(child) * 6.50;

		//fuel surcharge calculation for humans
		fuelHuman = static_cast<float>(adult + child) * 1.25;

		//vehicle ticket cost calculator
		if(vehicle == 'y', vehicleHeight == 'n') {
			vehicleCalc = 43.00;
			fuelVehicle = 4.15;
			if(vehicleLength > 20) {
				vehicleLengthCalc = static_cast<float>((vehicleLength) - 20) * small;
			}
		}
		
		if(vehicle == 'y', vehicleHeight == 'y') {
			vehicleCalc = 69.00;
			fuelVehicle = 10.40;
			if(vehicleLength > 20) {
				vehicleLengthCalc = static_cast<float>((vehicleLength) - 20) * large;
			}
		}

		//fuel surcharge calculator for humans + vehicle
		fuelSurcharge = fuelHuman + fuelVehicle;

		//vehicle total
		vehicleTotal = vehicleCalc + vehicleLengthCalc;

		//ticket cost formula
		ticketCosts = adultCalc + childCalc + vehicleTotal;

		//total amount calculation
		totalAmount = ticketCosts + fuelSurcharge;

		//output
		
		//receipt style
		cout << endl
			 << "*****************************************************************************"									<< endl
			 << "* Adults						$13.00 x "						<< adult			<<	" = $"	<< adultCalc	<< endl
			 << "* Children						$ 6.50 x "						<< child			<<	" = $"	<< childCalc	<< endl
			 << "* Fuel Surcharge (adults and children)		        $ 1.25 x "	<< adult + child	<<	" = $"	<< fuelHuman	<< endl
			 << "* Passenger Vehicle and Trailer					   = $"		<< vehicleCalc									<< endl
			 << "* Fuel Surcharge (vehicle)					   = $"				<< fuelVehicle									<< endl
			 << "* Extra Length Charge					$ " ;
		if(vehicleHeight == 'n'){
			cout << small << " x "; 
				if(vehicleLength > 20){
					cout << ((vehicleLength) - 20) << " = $" << vehicleLengthCalc;
				}else{
					cout << "0 = $0.00";
				}
		}else{
			cout << large << " x " ;
				if(vehicleLength > 20){
					cout << ((vehicleLength) - 20) << " = $" << vehicleLengthCalc;
				}else{
					cout << "0 = $0.00";
				}
		}
		cout << endl << "* Total								   = $"			<< totalAmount									<< endl
			 << "*****************************************************************************"									<< endl;
		/*//summary (style of examples)
		cout << endl << "Your fare is $"		<< ticketCosts;
		cout << " plus a fuel surcharge of $"	<< fuelSurcharge	<< endl;
		cout << "The total amount payable is $" << totalAmount		<< endl;*/
		cout << endl << "Would you like to help another customer?";
		cin >> again;
		cout << endl;

	}while(again == 'y');
	
	//thanks
	cout << "Thank you for using Jesse's Fare Calculator!";
	
	//pause and exit
	getchar();
	getchar();
	return 0;
}