
//extPersonType.
   
#ifndef H_extPersonType
#define H_extPersonType

#include <string>
#include "addressType.h"
#include "dateType.h"
#include "personType.h"

class extPersonType: public personType
{ 
public:

  //print the entire information
  void printInfo() const;

  //set information to given values
  void setInfo(string fName, string lName,
	       int month, int day, int year,
	       string street, string c, string s, 
	       string z, string phone, string pStatus);

  //return true is last name is lName
  bool isLastName(string lName) const;

  //store address into the reference parameters
  void getAddress(string& sAddress, string& c, 
		  string& s, string& z);

  //return status
  string getStatus() const;

  //return phone number
  string getPhoneNumber() const;

  //return true if status is equal to the given value
  bool isStatus(string status);

  //return true if birthday is equal to given values
  bool isDOB(int month, int day, int year);

  //store birthdays into the reference parameters
  void getDOB(int& month, int& day, int& year);

  //return true if month is equal to the given value
  bool isMonth(int month) const;

  //constructor
  extPersonType(string fName = "", string lName = "", 
		int month = 1, int day = 1, int year = 1900,
		string street = "", string c = "", string s = "",
		string z = "", string phone = "", string pStatus = "");

private:
  addressType address;
  dateType dob;
  string phoneNumber;
  string personStatus;
};

#endif
