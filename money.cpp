//Indra Bhurtel

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


class currency_converter{ // currency_converter class

       int currency;

   public:

   currency_converter(int valuee) // constructor
   {
       currency = valuee;
   }

   double PoundToDollar()
   {
       return 1.32 * currency;
   }

   double PesoToDollar()
   {
       return 0.050*currency;
   }

   double YenToDollar()
   {
       return 0.009 * currency;
   }

   double RupeesToDollar()
   {
       return 0.015 * currency;
   }

   double DinarToDollar()
   {
       return 0.00084 * currency;
   }

};


class currency_exchange{  // currency_exchange class

       double Converted_Money;

   public:

       currency_exchange(int valuee, string money) // constructor
       {
           currency_converter converter(valuee);

           Converted_Money = 0.0;

           if(money == "yen" || money == "Yen")
               Converted_Money = converter.YenToDollar();

           else if(money == "rupees" || money == "Rupees")
               Converted_Money = converter.RupeesToDollar();

           else if(money == "peso" || money == "Peso")
               Converted_Money = converter.PesoToDollar();

           else if(money == "pound" || money == "Pound")
               Converted_Money = converter.PoundToDollar();

           else if(money == "dinar" || money == "Dinar")
               Converted_Money = converter.DinarToDollar();

       }

   double MoneyEqualToDollar()
   {
       return Converted_Money;
   }
};


int main()
{
   int value;
   string currency;
   double Dollar;
   double Total_Dollar = 0.0;
   string Office_One, Temp, Office_Two, Name_One, Name_Two;
   string Location = "";

   cout << "Enter name of exchange office and manager: ";
   cin >> Office_One >> Temp >> Name_One;

   cout << "Enter name of exchange office and manager: ";
   cin >> Office_Two >> Temp >> Name_Two;

   cout << endl<< endl;
   cout << fixed << setprecision(2);

   do
   {
       cout << "***********" << endl<< endl;
       cout << "Hello traveler! Where are you in the airport? ";
       cin >> Location;
       cout << endl << endl<< endl;
       if(Location != "exit")
       {
       if(Location == "North" || Location == "north" || Location == "East" || Location == "east")
       {
           cout << "Welcome to " << Office_One << " " << Temp<< " ";
           cout << "Please contact manager " << Name_One << " if you have any complaints." << endl<< endl;
       }

       else
       {
           cout << "Welcome to " << Office_Two << " " << Temp<< " ";
           cout << "Please contact manager " << Name_Two << " if you have any complaints." << endl<< endl;
       }

       cout << "What currency are you converting to dollars and how much? ";
       cin >> value >> currency;

       currency_exchange exchange(value, currency);
       Dollar = exchange.MoneyEqualToDollar();
       Total_Dollar += Dollar;
       if(Dollar != 0)
           cout << "Here you go: $" << Dollar << endl << endl;
       else
           cout << "We do not convert " << currency << " currency here. Sorry." << endl << endl;
       }
   }
   while(Location != "exit");
   cout << "$$$Total dollars given out: $" << Total_Dollar << endl << endl; // print total dollars dispensed by both exchanges
   cout << "Exiting..." << endl << endl;
}
