// HOTEL MANAGEMENT SYTEM

#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;


// Array Size
const int userarrsize = 100;
const int totalArrSize = 1000;

// Array

string p_assword[userarrsize];
string n_ame[userarrsize];
string r_ole[userarrsize];
string enter_food[totalArrSize];
int enter_NoRooms[totalArrSize];
string enter_typeofRoom[totalArrSize];
int enter_person[totalArrSize];
int enter_checkInOut[totalArrSize];
string enter_feedback[totalArrSize];
float totalBudGet[totalArrSize];

// Details of Rooms
string typeOFRooms[4] = {"double bed", "triple bed", "quad bed", "quint bed"};
int noOfRooms[4] = {10, 10, 10, 10};
int priceOfRooms[4] = {4000, 6000, 8000, 10000};
string fOOD[4] = {"breakfast", "half board", "full board", "snacks"};
int priceOfFoodDeals[4] = {1500, 2000, 3000, 1000};

// Global Variables
string name;
string role;
string password;
string Food;
int NoRooms;
int Person;
int checkInOut;
string feedback;
string typeofRoom;
float totalBudget;
int field;
int roomsBill = 0;
int foodBill = 0;

// Counts
int userCount = 0;
int foodCount = 0;
int NoRoomsCount = 0;
int typeofRoomCount = 0;
int personCount = 0;
int checkInOutCount = 0;
int feedbackCount;

// ProtoTypes of Functions

void header();
void viewFood();
int OwnerMenu();
void viewUsers();
int ManagerMenu();
int loginoption();
void clearscreen();
void signUpArray();
int CustomerMenu();
void viewDetails();
void viewBookings();
void viewFeedback();
void viewTotalBill();
void OwnerInterface();
void ManagerInterface();
void CustomerInterface();
string enterTypeofRooms();
int enterPerson(int Person);
void subMenu(string submenu);
string enterFood(string Food);
bool isvalidUserName(string name);
int enterNoOfStays(int checkInOut);
bool isvalidPassword(string password);
string enterFeedback(string feedback);
bool validTypeOfRoom(string typeofRoom);
void storeFeedbackInFile(string feedback);
void subMenubeforeMainMenu(string submenu);
string signIn(string name, string password);
int foodCalculation(string Food, int checkInOut);
int roomsCalculation(string enter_typeofRoom[], int checkInOut);

// File Handling(Read and Write Data)

void storeCredentialInFile(string name, string password, string role);
void storePersonInFile(int Person);
void storeCheckInOutInFile(int checkInOut);
void storeNoOfRoomsInFile(int NoRooms);
void storeTypeofRoomsInFile();
void storeFoodDealsInFile(string Food);
string getField(string record,int field);
string getCredential(string record1,int field);
string getFeedback(string record2,int field1);
void readDataFromCredential(string name,string password,string role);
void readDataFromBookings();
void readDataFromFeedback();


main()
{
   readDataFromCredential(name,password,role);
   readDataFromBookings();
   readDataFromFeedback();
   bool flag;
   int option = 0;
   while (option != 4)
   {
      header();
      subMenubeforeMainMenu("Login");
      option = loginoption();
      if (option == 1)
      {
         system("cls");
         header();
         subMenubeforeMainMenu("SignIn");
         cout << "Enter the Name:" << endl;
         cin >> name;
         cout << "Enter Password:" << endl;
         cin >> password;
         role = signIn(name, password);

         if (role == "owner" || role == "Owner" || role == "OWNER")
         {
            clearscreen();
            OwnerInterface();
         }

         if (role == "manager" || role == "MANAGER" || role == "Manager")
         {
            clearscreen();
            ManagerInterface();
         }

         if (role == "customer" || role == "CUSTOMER" || role == "Customer")
         {
            clearscreen();
            CustomerInterface();
         }
         else
         {
            cout << "Invalid Credential!!" << endl;
         }
         clearscreen();
      }

      else if (option == 2)
      {
         system("cls");

         header();
         subMenubeforeMainMenu("SignUp");
         cout << "Enter the Name:" << endl;
         getline(cin >> ws, name);

         cout << "Enter -- Password(4-8 characters):" << endl;
         cin >> password;

         flag = isvalidPassword(password);
         if (flag == true)
         {
            cout << "Password Verified!!" << endl;
         }
         else
         {
            while(!flag)
            {
               cout << "Invalid Password......Enter again!!" << endl;
               cout << "Enter Password(4-8 characters):" << endl;
               cin >> password;
               flag = isvalidPassword(password);
            }
            
         }

         cout << "Enter Role(Owner/Manager/customer):" << endl;
         cin >> role;

         bool credential = isvalidUserName(name);
         if (credential == true)
         {
            signUpArray();
            storeCredentialInFile(name, password, role);
            cout << "SignedUp Successfully!!!" << endl;
         }
         else
         {
            cout << "UserName Already Exist!!" << endl;
         }

         clearscreen();
      }
      else if (option == 3)
      {
         viewUsers();
         clearscreen();
      }
   }
}

// Function Definition

void header()
{
   cout << "           _____                       ____                        _____             " << endl;
   cout << "         //\\  \\                  // \\   \\                     //\\   \\            " << endl;
   cout << "        //::\\__\\                //:: \\__ \\                   //::\\   \\           " << endl;
   cout << "       //::://  //               //::::|   |                  //::::\\   \\          " << endl;
   cout << "      //::://  //               //:::::|   |                 //::::::\\   \\         " << endl;
   cout << "     //::://  //               //::::::|   |                //:://\\::\\   \\        " << endl;
   cout << "    //::://__//               //::://|:|   |               //::// _\\:: \\   \\       " << endl;
   cout << "   //::::\\   \\             //:::// |:|   |              \\::\\   \\::  \\   \\      " << endl;
   cout << "  //::::::\\   \\   _____   //::://  |:|___|______     __  \\::\\   \\::  \\   \\     " << endl;
   cout << " //::://\\:\\   \\ //\\ \\ //::://   |:::::::: \\   \\  //\\  \\:\\  \\::  \\   \\    " << endl;
   cout << "//::://\\:::\\   //:\\__ \\//::://   |::::::::: \\__ \\//::\\  \\:\\  \\::  \\___\\   " << endl;
   cout << "\\:://   \\::\\ //://   //\\:://    //~~~~//::://   //\\::\\  \\:::\\ \\:://  //   " << endl;
   cout << " \\//___//\\::\\//://   // \\//____//    //::://   //  \\::\\  \\::\\  \\//__//    " << endl;
   cout << "          \\:::::://   //               //::://   //    \\::\\  \\::\\   \\        " << endl;
   cout << "           \\:::://   //               //::://   //      \\::\\  \\::\\___\\       " << endl;
   cout << "           //::://   //               //::://   //        \\::\\ //:://    //      " << endl;
   cout << "          //::://   //               //::://   //          \\:\\//::://    //        " << endl;
   cout << "         //::://   //               //::://   //            \\:::::://    //         " << endl;
   cout << "        //::://   //               //::://   //              \\:::://    //          " << endl;
   cout << "        \\:://   //                \\:://   //                \\:://    //           " << endl;
   cout << "         \\//___//                  \\//___//                  \\//____//            " << endl;
   cout << "                                                                               " << endl;
   cout << "        HOTEL                      MANAGEMENT              SYSTEM              " << endl;
   cout << endl;
   cout << endl;
}

void subMenubeforeMainMenu(string submenu)
{
   string title = submenu + "Menu";
   cout << title << endl;
   cout << "________________________________" << endl;
   cout << endl;
}

void subMenu(string submenu)
{
   string title = "Main Menu >" + submenu;
   cout << title << endl;
   cout << "________________________________" << endl;
   cout << endl;
}

void clearscreen()
{
   cout << "Press any key to Continue..." << endl;
   getch();
   system("cls");
}

int loginoption()
{
   int option = 0;

   cout << "1.  SIGN TO THE ACCOUNT " << endl;
   cout << "2.  SIGN UP FOR THE ACCOUNT" << endl;
   cout << "3.  VIEW USERS           " << endl;
   cout << "4.  EXIT THE LOGIN MENU   " << endl;

   cout << "SELECT THE OPTION OF YOUR CHOICE =";
   cin >> option;
   return option;
}

void signUpArray()
{
   n_ame[userCount] = name;
   p_assword[userCount] = password;
   r_ole[userCount] = role;
   userCount++;
}
string signIn(string name, string password)
{
   for (int x = 0; x < userCount; x++)
   {
      if (n_ame[x] == name && p_assword[x] == password)
      {
         return r_ole[x];
      }
   }
   return "Undefined";
}

bool isvalidUserName(string name)
{
   bool flag = true;

   for (int x = 0; x < userCount; x++)
   {
      if (n_ame[x] == name)
      {
         flag = false;
         break;
      }
   }

   return flag;
}

bool isvalidPassword(string password)
{
   bool flag = false;
   int passwordLength = password.length();
   if (passwordLength >= 4 && passwordLength <= 8)
   {
      return true;
   }
   return flag;
}

void viewUsers()
{
   cout << "UserName"
        << "\t"
        << "Passwords"
        << "\t"
        << "Role" << endl;
   for (int x = 0; x < userCount; x++)
   {
      cout << n_ame[x] << "\t\t" << p_assword[x] << "\t\t" << r_ole[x] << endl;
   }
}

// OWNER MENU

int OwnerMenu()
{
   int option;
   cout << "Select any Option of your Choice.  " << endl;
   cout << "1.  VIEW DETAILS OF HOTEL          " << endl;
   cout << "2.  VIEW BOOKINGS                  " << endl;
   cout << "3.  FOOD                           " << endl;
   cout << "4.  BOOKING BILLS                  " << endl;
   cout << "5.  VIEW FEEDBACK                 " << endl;
   cout << "6.  LOG OUT                        " << endl;
   cout << "Enter your Choice:                 " << endl;
   cin >> option;
   return option;
}
void OwnerInterface()
{
   int OwnerOption = 0;
   while (OwnerOption != 6)
   {
      header();
      subMenu("AdminMenu");
      OwnerOption = OwnerMenu();
      if (OwnerOption == 1)
      {
         system("cls");
         header();
         subMenu("View Details");
         viewDetails();
         clearscreen();
      }
      else if (OwnerOption == 2)
      {
         system("cls");
         header();
         subMenu("View Bookings");
         viewBookings();
         clearscreen();
      }
      else if (OwnerOption == 3)
      {
         system("cls");
         header();
         subMenu("Food");
         viewFood();
         clearscreen();
      }
      else if (OwnerOption == 4)
      {
         system("cls");
         header();
         subMenu("Booking Bills");
         viewTotalBill();
         clearscreen();
      }
      else if (OwnerOption == 5)
      {
         system("cls");
         header();
         subMenu("View Feedbacks");
         viewFeedback();
         clearscreen();
      }
   }
}

// CUSTOMER MENU

int CustomerMenu()
{
   int option;
   cout << "Select any Option of your Choice.  " << endl;
   cout << "1.  PERSONS                        " << endl;
   cout << "2.  CHECK_IN & CHECK_OUT           " << endl;
   cout << "3.  TYPE OF ROOMS                  " << endl;
   cout << "4.  FOOD                           " << endl;
   cout << "5.  VIEW BOOKINGS                  " << endl;
   cout << "6.  CHECK TOTAL BILL               " << endl;
   cout << "7.  GIVE FEEDBACK                  " << endl;
   cout << "8.  LOG OUT                        " << endl;
   cout << "ENTER OPTION:                      " << endl;
   cin >> option;
   getch();
   return option;
}
void CustomerInterface()
{
   int CustomerOption = 0;
   while (CustomerOption != 8)
   {
      header();
      subMenu("CustomerMenu");
      CustomerOption = CustomerMenu();

      if (CustomerOption == 1)
      {
         system("cls");
         header();
         subMenu("Persons");
         enterPerson(Person);
         clearscreen();
      }
      else if (CustomerOption == 2)
      {
         system("cls");
         header();
         subMenu("Check_In & Check_Out");
         checkInOut = enterNoOfStays(checkInOut);
         clearscreen();
      }
      else if (CustomerOption == 3)
      {
         system("cls");
         header();
         subMenu("Types of Rooms");
         enterTypeofRooms();
         clearscreen();
      }
      else if (CustomerOption == 4)
      {
         system("cls");
         header();
         subMenu("Foods");
         Food = enterFood(Food);
         clearscreen();
      }
      else if (CustomerOption == 5)
      {
         system("cls");
         header();
         subMenu("View Bookings");
         viewBookings();
         clearscreen();
      }
      else if (CustomerOption == 6)
      {
         system("cls");
         header();
         subMenu("Check bills of bookings");
         viewTotalBill();
         clearscreen();
      }
      else if (CustomerOption == 7)
      {
         system("cls");
         header();
         subMenu("Feedbacks");
         enterFeedback(feedback);
         clearscreen();
      }
      
   }
}

// MANAGER MENU 

int ManagerMenu()
{
   int option;
   cout << "SELECT ANY OPTION OF YOUR CHOICE.  " << endl;
   cout << "1.  VIEW DETAILS OF HOTEL          " << endl;
   cout << "2.  CUSTOMER BOOKINGS              " << endl;
   cout << "3.  BILLS OF BOOKINGS              " << endl;
   cout << "4.  LOG OUT                        " << endl;
   cout << "ENTER OPTION:                      " << endl;
   cin >> option;
   return option;
}
void ManagerInterface()
{
   int ManagerOption = 0;
   while (ManagerOption != 4)
   {
      header();
      subMenu("ManagerMenu");
      ManagerOption = ManagerMenu();
      if (ManagerOption == 1)
      {
         system("cls");
         header();
         subMenu("View Details of Hotel");
         viewDetails();
         clearscreen();
      }
      else if (ManagerOption == 2)
      {
         system("cls");
         header();
         subMenu("Customer Bookings");
         viewBookings();
         clearscreen();
      }
      else if (ManagerOption == 3)
      {
         system("cls");
         header();
         subMenu("Bills of Bookings");
         viewBookings();
         clearscreen();
      }
   }
}

// DEFINITION OF FUNCTIONS FOR FILE FILE HANDLING

void storeCredentialInFile(string name, string password, string role)
{
   fstream file;
   file.open("user.txt", ios::app);
   file << name << "," ;
   file << password << "," ;
   file << role <<  endl;
   file.close();
}

string getField(string record,int field)
{
   int commaCount=1;
   string item;
   for(int x=0; x < record.length(); x++)
    {
       if (record[x]==',')
       {
         commaCount++;
       }
       else if(commaCount==field)
       {
         item=item+record[x];
       }
       
    }
    return item;
}
void readDataFromCredential(string name,string password,string role)
{
   string record;
   fstream file;
   file.open("user.txt", ios::in);
   while (getline(file, record) )
   {
      n_ame[userCount] = getField(record,1);
      p_assword[userCount] =getField(record,2) ;
      r_ole[userCount] = getField(record,3);
      userCount++;
   }
   file.close();
}

string getCredential(string record1,int field1)
{
   int commaCount=1;
   string item;
   for(int x=0; x < record1.length(); x++)
    {
       if (record1[x]==',')
       {
         commaCount++;
       }
       else if(commaCount==field1)
       {
         item=item+record1[x];
       }
       
    }
    return item;
}


void storePersonInFile(int Person)
{
   fstream file1;
   file1.open("bookings.txt", ios::app);
   file1 << Person << ",";
   file1.close();
}

void storeCheckInOutInFile(int checkInOut)
{
   fstream file1;
   file1.open("bookings.txt", ios::app);
   file1 << checkInOut << ",";
   file1.close();
}

void storeNoOfRoomsInFile(int NoRooms)
{
   fstream file1;
   file1.open("bookings.txt", ios::app);
   file1 << NoRooms << ",";
   file1.close();
}

void storeTypeofRoomsInFile()
{
   fstream file1;
   file1.open("bookings.txt", ios::app);
   file1 << typeofRoom << ",";
   file1.close();
}

void storeFoodDealsInFile(string Food)
{
   fstream file1;
   file1.open("bookings.txt", ios::app);
   file1 << Food << endl;
   file1.close();
}

void readDataFromBookings()
{
   string record1;
   fstream file1;
   file1.open("bookings.txt", ios::in);
   while (getline(file1, record1))
   {
      enter_person[personCount] = stoi(getCredential(record1,1));
      enter_checkInOut[checkInOutCount] = stoi(getCredential(record1,2));
      enter_NoRooms[NoRoomsCount] = stoi(getCredential(record1,3));
      enter_typeofRoom[typeofRoomCount] = getCredential(record1,4);
      enter_food[foodCount] = getCredential(record1,5);
      personCount++;
      checkInOutCount++;
      NoRoomsCount++;
      typeofRoomCount++;
      foodCount++;
   }
} 

void storeFeedbackInFile(string feedback)
{
   fstream file1;
   file1.open("feedback.txt", ios::app);
   file1 << feedback  << ",";
   file1.close();
}

string getFeedback(string record2,int field1)
{
   int commaCount=1;
   string item;
   for(int x=0; x < record2.length(); x++)
    {
       if (record2[x]==',')
       {
         commaCount++;
       }
       else if(commaCount==field1)
       {
         item=item+record2[x];
       }
       
    }
    return item;
}

void readDataFromFeedback()
{
   string record2;
   fstream file1;
   file1.open("feedback.txt", ios::in);
   while (getline(file1, record2))
   {
      enter_feedback[feedbackCount] = getFeedback(record2,1);
      feedbackCount++;
   }
   file1.close();
}



// BOOKINGS OF THE CUSTOMER

int enterPerson(int Person)
{
   cout << "Enter No oF Persons:" << endl;
   cin >> Person;
   enter_person[personCount] = Person;
   personCount++;
   storePersonInFile(Person);
   return Person;
}

int enterNoRooms(int NoRooms)
{
   cout << "Enter Rooms:" << endl;
   cin >> NoRooms;
   enter_NoRooms[NoRoomsCount] = NoRooms;
   NoRoomsCount++;
   storeNoOfRoomsInFile(NoRooms);
   return NoRooms;
}

string enterFood(string Food)
{
   cout << "ENTER FOOD(breakfast/half board/full board/snacks):" << endl;
   getline(cin >> ws, Food);
   enter_food[foodCount] = Food;
   foodCount++;
   storeFoodDealsInFile(Food);
   return Food;
}

int enterNoOfStays(int checkInOut)
{
   cout << "Enter No of Days:" << endl;
   cin >> checkInOut;
   enter_checkInOut[checkInOutCount] = checkInOut;
   checkInOutCount++;
   storeCheckInOutInFile(checkInOut);
   return checkInOut;
}

bool validTypeOfRoom(string typeofRoom)
{
   bool flag = false;
   for (int x = 0; x < 4; x++)
   {
      if (typeOFRooms[x] == typeofRoom)
      {
         return true;
      }
   }
   return flag;
}

string enterTypeofRooms()
{
   NoRooms = enterNoRooms(NoRooms);
   cout << "Enter Type of Rooms (Double/Triple/Quad/Quint bed....):" << endl;
   for (int x = 0; x < NoRooms; x++)
   {
      getline(cin >> ws, typeofRoom);
      storeTypeofRoomsInFile();
      if (validTypeOfRoom(typeofRoom))
      {
         enter_typeofRoom[x] = typeofRoom;
         typeofRoomCount++;
      }
      else
      {
         cout << "Give Valid Input! .....Enter again" << endl;
         x--;
      }
   }

   return "";
}

string enterFeedback(string feedback)
{
   cout << "Give Feedback" << endl;
   getline(cin >> ws, feedback);
   enter_feedback[feedbackCount] = feedback;
   feedbackCount++;
   storeFeedbackInFile(feedback);
   return feedback;
}

// VIEW BOOKINGS

void viewFood()
{
   cout << "No."<< "\t\t" << "Food" << endl;
   for (int x = 0; x < foodCount; x++)
   {
      cout << x + 1 << "\t\t" << enter_food[x] << endl;
   }
}
void viewBookings()
{
   cout << "Persons:" << endl;
   for (int x = 0; x < personCount; x++)
   {
      cout << enter_person[x] << endl;
   }
   cout << "Number of Rooms:" << endl;
   for (int x = 0; x < NoRoomsCount; x++)
   {
      cout << enter_NoRooms[x] << endl;
   }
   cout << "Types of Rooms:" << endl;
   for (int x = 0; x < NoRooms; x++)
   {
      cout << enter_typeofRoom[x] << endl;
   }
   cout << "No of Stays:" << endl;
   for (int x = 0; x < checkInOutCount; x++)
   {
      cout << enter_checkInOut[x] << endl;
   }
}

void viewDetails()
{
   cout << "Type of Rooms"
        << "\t\t"
        << "No of Rooms Available"
        << "\t\t"
        << "Price of Rooms(per stay)"
        << "\t\t"
        << "Food Deals"
        << "\t\t"
        << "Price" << endl;
   for (int x = 0; x < 4; x++)
   {
      cout << typeOFRooms[x] << "\t\t" << noOfRooms[x] << "\t\t\t\t" << priceOfRooms[x] << "\t\t\t\t\t" << fOOD[x] << "\t\t" << priceOfFoodDeals[x] << endl;
   }
}

void viewFeedback()
{

   for (int x = 0; x < feedbackCount; x++)
   {
      cout << "Customer" << x + 1 << endl;
      cout << enter_feedback[x] << endl;
   }
}

int roomsCalculation(string enter_typeofRoom[], int checkInOut)
{
   for (int x = 0; x < 4; x++)
   {
      if (typeOFRooms[x] == enter_typeofRoom[x])
      {
         roomsBill = roomsBill + (priceOfRooms[x] * checkInOut);
      }
   }

   return roomsBill;
}
int foodCalculation(string Food, int checkInOut)
{
   for (int x = 0; x < 4; x++)
   {
      if (fOOD[x] == Food)
      {
         foodBill = foodBill + (priceOfFoodDeals[x] * checkInOut);
      }
   }
   return foodBill;
}
void viewTotalBill()
{
   int foodBILL = foodCalculation(Food, checkInOut);
   cout << "Food bill:" << foodBILL << endl;
   int roomsBILL = roomsCalculation(enter_typeofRoom, checkInOut);
   cout << "Rooms bill:" << roomsBILL << endl;
   cout << "TOTAL BUDGET WILL BE:" << foodBILL + roomsBILL << endl;

}
