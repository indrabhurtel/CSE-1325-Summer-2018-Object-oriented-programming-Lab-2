//Indra Bhurtel

#include<iostream>
#include<string>
#include<vector>
#include<queue>


using namespace std;

class Rider{  // rider class
    int height; // height in inches
    string name; // rider name

public:

    Rider( string str, int h): name(str), height(h){} // constructor
    Rider(int h) : height(h){}
    int get_height(){ return height;}
    string get_name(){return name;}
};

class ride{ // ride class
    int min_height;  // minimum height required to ride in inches
    string ride_name; // ride name
    queue < Rider > line;  // riders queue

public:
    ride(){}
    ride(string name, int h): min_height(h), ride_name(name){} // constructor
    void add_line(Rider r){
    if (r.get_height()>= min_height){ // check if rider has minimum height
        line.push(r);

    cout << " -Adding rider to line. "<< endl;
    }
    else{
        cout<<"-Sorry can't add rider-too short."<<endl;
    }
    }
    };

    class Amusement_park: public ride{
    int nrides;
    vector<ride> rides;
public:
    Amusement_park(int n): nrides(n){ // constructor

    cout<<"~~~Amusement Park Info~~~"<< endl;
    string name;
    int min_h;

    for (int i =1; i<=n; ++i){
    cout<<"Ride"<<i <<"-Enter minimum ride height and ride name: "<<endl;
    cin>> min_h>> name;
    rides.push_back(ride(name, min_h)); // add and initialize ride with minimum height and ride name
    }
    }
    ride & get_ride(int n){
    n--;

   if (n < nrides){
        return rides[n];
    }
    cout<<"Something went wrong"<< endl;
    }

    };

int	main()
{
				Rider	r1("Yaris",	45);	//name,	height	in	inches
				Rider	r2(49);	//height	in	inches
				Amusement_park	a1(3);	//3	is	the	number	of rides	in	the	amusement	park
				a1.get_ride(1).add_line(r1);		//add	a	rider	to	the	line	of	a	ride
				Amusement_park	a2(2);	//2	is	the	number	of	rides	in	the	amusement	park
				a2.get_ride(1).add_line(r2);	//add	a	rider	to	the	line	of	a	ride
				return	0;
}
