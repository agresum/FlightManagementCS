/*
File: FlightManagement.cpp
Author: Sumit Agre(135710)
Purpose: Flight Management Operations
*/

#include "FlightManagement.hpp"

// using namespace std;

int main() {

    FlightDatabase flightDatabase;
//    Sample for testing
   flightDatabase.AddFlight("p", "m", "op1", 5000, "11" );
   flightDatabase.AddFlight("m", "d", "op2", 555, "22" );
   flightDatabase.AddFlight("d", "u", "op3", 666, "33" );
   flightDatabase.AddFlight("b", "h", "op4", 555, "44" );
//    flightDatabase.printfun();
//    cout<<"--------------------------"<<'\n';
//    flightDatabase.UpdateFareByFlight("2", 225552);
//    flightDatabase.printfun();
//    cout<<"--------------------------"<<'\n';
//   // flightDatabase.RemoveFlight("2");
//   // flightDatabase.printfun();
//    flightDatabase.DisplayAllFlights();
//    cout<<"--------------------------"<<'\n';
//    flightDatabase.FindFlightsByOriginCity("Pune");

  /** Test plan, you may use additional functions/classes
      for the validation purpose.
  */
  /** Some Calls can be like (Note:- invoke with object appropriately )
	/** AddTrip("AI-854","Pune","Delhi",5000)*/
	/** RemoveTrip("SG-512")*/
	/** UpdateFareByTrip(“6E-702”, 5000)*/
	/** DisplayAllTrips()*/
	/**FindFlightByNumber("6E-302"), Return the instance(s) */
	/**FindFlightsByOriginCity("Pune"), Return the instance(s) */
	/** FindAverageCostOfAllTrips()*/
	/**FindMinFareBetweenCities("Pune","Bengaluru");*/
	/**FindMaxFareByOperator(“Indigo”);*/
	//*UpdateFareByOperator("AirIndia");
//  FlightDatabase flightData;
  string originCity, destinationCity, flightOperator, flightNumber;
  int airFare;
  system("clear");  
  while(1){
    int input;
    cout << "Welcome to Fligh Management System" <<endl;
    cout << "1 AddFlight" <<endl;
    cout << "2 RemoveFlight" <<endl;
    cout << "3 UpdateFareByFlight" <<endl;
    cout << "4 DisplayAllFlights" <<endl;
    cout << "5 FindFlightByNumber" <<endl;
    cout << "6 FindFlightsByOriginCity" <<endl;
    cout << "7 FindAverageCostOfAllFlights" <<endl;
    cout << "8 FindMinFareBetweenCities" <<endl;
    cout << "9 FindMaxFareByOperator" <<endl;
    cout << "10 UpdateFareByOperator" <<endl;
    cout << "11 Exit" <<endl;
    cin >> input;
    switch(input){
	  case 1:
	  {
	    cout << "Enter OrigineCity" <<endl;
	    cin >> originCity;
	    cout << "Enter DestinationCity" <<endl;
	    cin >> destinationCity;
	    cout << "Enter Fare" <<endl;
	    cin >> airFare;
	    cout << "Enter FlightOperator" <<endl;
	    cin >> flightOperator;
	    cout << "Enter FlighNumber" <<endl;
	    cin >> flightNumber;
		if(flightDatabase.CheckUnique(flightNumber)){
	      if(flightDatabase.AddFlight(originCity, destinationCity, flightOperator, airFare, flightNumber)){
            cout << "Flight added successfully" <<endl;
	      }
		  else{
		    cout << "Error, Enter Agian!" <<endl;	
		  }
		}
		else{
		  cout<<"Error, Flight Number already exist, try again"<<endl;	
		}
	    break;
	}

	case 2:
	{
      cout << "Enter the flight number:" <<endl;
      cin >> flightNumber;
      if(flightDatabase.RemoveFlight(flightNumber)){
		cout<<"Success"<<endl;  
	  }
	  break;
	}
	case 3:
	{
      cout << "Enter the flight number:" <<endl;
      cin >> flightNumber;
      cout << "Enter the new air fare:" <<endl;
      cin >> airFare;
      flightDatabase.UpdateFareByFlight(flightNumber, airFare);
	  break;
	}
	case 4:
	{
      flightDatabase.DisplayAllFlights();
      break;
	}
	case 5:
	{
	  cout << "Enter the flight number:" <<endl;
      cin >> flightNumber;
      flightDatabase.FindFlightByNumber(flightNumber);
      break;
	}

	case 6:
	{
	  cout << "Enter OrigineCity" <<endl;
	  cin >> originCity;
      flightDatabase.FindFlightsByOriginCity(originCity);
      break;
	}
	case 7:
	{
      cout << "Average cost of flight:"<<flightDatabase.FindAverageCostOfAllFlights()<<endl;
      break;
	}
	case 8:
	{
	  cout << "Enter OrigineCity" <<endl;
      cin >> originCity;
	  cout << "Enter DestinationCity" <<endl;
	  cin >> destinationCity;
	  if(flightDatabase.FindMinFareBetweenCities(originCity, destinationCity)==-1)
	  {
        cout<<"Flight Not found"<<endl;
	  }
	  else
	  {
        cout << "Minimum fare:"<<flightDatabase.FindMinFareBetweenCities(originCity, destinationCity)<<endl;
	  }
      break;
	}
	case 9:
	{
	  cout << "Enter the Operator:" <<endl;
	  cin >> flightOperator;
	  if(flightDatabase.FindMaxFareByOperator(flightOperator)==-1){
	    cout<<"Operator Not found"<<endl;
	  }
	  else
	    cout<<"Maximum Fare:"<<flightDatabase.FindMaxFareByOperator(flightOperator)<<endl;
      break;
	}
	case 10:
	{
	  int in, per;
	  cout << "Enter the Operator:" <<endl;
	  cin >> flightOperator;
	  cout << "Do you wan to \n1. IncreaseFare\n2. DecreaseFare " <<endl;
	  cin >> in;
      cout << "By how many percentage:" <<endl;
      cin >> per;
      if(0<per && per <100){
	    if(in == 1){
		  if(flightDatabase.UpdateFareByOperator(flightOperator, per))
                    cout<<"Success"<<endl;
                  else
                  cout<<"Operator not found"<<endl;  
	    }
	    else if(in == 2){
		  if(flightDatabase.UpdateFareByOperator(flightOperator, -per))
                  cout<<"Success"<<endl;
                  else
                  cout<<"Operator not found, please try again"<<endl;
	    }
	    else{
	      cout << "incorrect" <<endl;
	    }
      }
      else{
        cout << "incorrect" <<endl;
      }
	  break;
	}
	case 11:
	{
      return 0;
	}
	default:
	{
      break;
	}
  }
  }
  return 0;
}
