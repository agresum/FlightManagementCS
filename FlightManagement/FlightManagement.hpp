#include <iostream>
#include <stdlib.h>
#include <list>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

class Flight {
	/** attributes */
private:
  string originCity;
  string destinationCity;
  string flightOperator;
  int airFare;
public:
  int getAirFare() const {
    return airFare;
  }

  void setAirFare(int airFare) {
    this->airFare = airFare;
  }

  const string& getDestinationCity() const {
    return destinationCity;
  }

  void setDestinationCity(const string &destinationCity) {
    this->destinationCity = destinationCity;
  }

  const string& getFlightOperator() const {
    return flightOperator;
  }

  void setFlightOperator(const string &flightOperator) {
    this->flightOperator = flightOperator;
  }

  const string& getOriginCity() const {
    return originCity;
  }

  void setOriginCity(const string &originCity) {
    this->originCity = originCity;
  }
    /** any other functions */
public:
    Flight( string originCity, string destinationCity,
    string flightOperator, int airFare) {
    this->airFare = airFare;
    this->originCity = originCity;
    this->destinationCity = destinationCity;
    this->flightOperator = flightOperator;
  }
};

class FlightDatabase {

private:
  map<string, Flight> flightdatabase;
public:
  void printfun() {
    map<string, Flight>::iterator it;
    for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
      Flight flight = it->second;
      string flightNumber=it->first;
      std::cout<<"flightNumber="+flightNumber+" airFare="<<flight.getAirFare()<<" originCity="+flight.getOriginCity()+" destinationCity="+flight.getDestinationCity()+" operator="+flight.getFlightOperator()<<endl;
    }
  }
  bool CheckUnique(string flightNumber) {
    map<string, Flight>::iterator it;
    for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
      if(flightNumber==it->first)
		  return false;
    }
	return true;
  }
  bool AddFlight(string originCity, string destinationCity,
      string flightOperator, int airFare, string flightNumber) {
    try {
      Flight flight = Flight( originCity, destinationCity, flightOperator, airFare);
      flightdatabase.insert(pair<string, Flight>(flightNumber, flight));
      return true;
    } catch (...) {
      return false;
    }
    return true;
  }
  bool RemoveFlight(string flightNumber){
	try{
      Flight flight=flightdatabase.at(flightNumber);
      flightdatabase.erase(flightNumber);
	  return true;
	}catch(...){
	cout<<"Flight Number Not Found"<<endl;
	}
    return false;	
  }
  bool UpdateFareByFlight(string flightNumber, int airFare){
    flightdatabase.at(flightNumber).setAirFare(airFare);
    return true;
  }
  void DisplayAllFlights(){
    map<string, Flight>::iterator it;
        for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
          string flightNumber=it->first;
          cout<<"flightNumber="<<it->first<<" airFare="<<it->second.getAirFare()<<" originCity="<<it->second.getOriginCity()<<" destinationCity="<<it->second.getDestinationCity()<<" operator="<<it->second.getFlightOperator()<<endl;
        }
  }
  void FindFlightByNumber(string flightNumber){
	    try{
          Flight flight=flightdatabase.at(flightNumber);
		  cout<<"flightNumber="+flightNumber+" airFare="<<flight.getAirFare()<<" originCity="+flight.getOriginCity()+" destinationCity="+flight.getDestinationCity()+" operator="+flight.getFlightOperator()<<endl;
	    }catch(...){
		  cout<<"Flight Number Not Found"<<endl;
	    }
  }
  void FindFlightsByOriginCity(string originCity){
    map<string, Flight>::iterator it;
    int chg = 0;
            for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
              if(it->second.getOriginCity()==originCity){
              cout<<"flightNumber="+it->first+" airFare="<<it->second.getAirFare()<<" originCity="+it->second.getOriginCity()+" destinationCity="+it->second.getDestinationCity()+" operator="+it->second.getFlightOperator()<<'\n';
                chg++;
              }
            }
            if(chg==0)
            cout<<"No flights from this city"<<endl;
  }
  void FindFlightsByFlightOperator(string flightOperator){
    map<string, Flight>::iterator it;
    int chg = 0;
            for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
              if(it->second.getFlightOperator()==flightOperator){
                cout<<"flightNumber="+it->first+" airFare="<<it->second.getAirFare()<<" originCity="+it->second.getOriginCity()+" destinationCity="+it->second.getDestinationCity()+" operator="+it->second.getFlightOperator()<<'\n';
              chg++; 
              }
            }
            if(chg==0){
              cout<<"No Flight for this operator"<<endl;
            }
  }
  int FindAverageCostOfAllFlights(void){
    map<string, Flight>::iterator it;
        int avg = 0;
        int count = 0;
            for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
              avg += it->second.getAirFare();
              count++;
            }
        return (avg/count);
  }
  int FindMinFareBetweenCities(string originCity, string destinationCity){
    map<string, Flight>::iterator it;
        int avg = flightdatabase.begin()->second.getAirFare();
        int chg=0; 
            for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
              if(avg >= it->second.getAirFare() && it->second.getOriginCity()==originCity && it->second.getDestinationCity()==destinationCity){
                avg = it->second.getAirFare();
                chg++;
                }
            }
        if(chg!=0)
        return (avg);
        else
        return(-1);
  }
  int FindMaxFareByOperator(string flightOperator){
    map<string, Flight>::iterator it;
        int avg = flightdatabase.begin()->second.getAirFare();
        int chg=0;
          for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
          if(avg < it->second.getAirFare() && it->second.getFlightOperator()==flightOperator)
          {
            avg = it->second.getAirFare();
            chg++;
          }
         }
        if(chg!=0)
        return avg;
        else
        return -1;
  }
  bool UpdateFareByOperator(string flightOperator, int per){
    map<string, Flight>::iterator it;
        int chg=0;
          for (it = flightdatabase.begin(); it != flightdatabase.end(); it++) {
            if(it->second.getFlightOperator() == flightOperator){
              it->second.setAirFare(it->second.getAirFare()+(it->second.getAirFare()*per)/100);
              chg++;  
            }
    }
   if(chg!=0)
   return true;
   else{
   return false; 
   }
   
  }
};

