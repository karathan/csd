#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define keep_window_open()	cin.ignore();

using namespace std;

/*
	main class of our data
*/
class _ID {
public:
	_ID(int number, string name, double money);
	//_ID();
	int nn() const { return number; }
	string nm() const { return name; }
	double mn() const { return money; }
	void setmoney(double x) { money = money + x; }
private:
	int number;
	string name;
	double money;
};

/*
	basic constructor
*/
_ID::_ID(int num, string nam, double mon)
	: number(num), name(nam), money(mon) { };

/*
	Overloading >> operator to read class from file
*/
istream& operator>>(istream& is, _ID& ii) {
	int _id;
	string _FName, _LName;
	double _Money;
	is >> _id >> _FName >> _LName >> _Money;
	if (!is) return is;
	ii = _ID(_id, _FName + " " + _LName, _Money);
	return is;
}

/*
	Overloading << operator to print class with specified format
*/
ostream& operator<<(ostream& os, _ID& ii) {
	return os << ii.nn()
		<< ' ' << ii.nm()
		<< ' ' << ii.mn();
}

/*
	Overloading == operator to check Ids
*/
bool operator==(const _ID& ii, int _id) {
	return ii.nn() == _id;
}

/*
	Overloading == operator to compare to class members
*/
bool operator==(const _ID& ii, const _ID& oo) {
	return (ii.nn() == oo.nn()) && (ii.nm() == oo.nm()) && (ii.mn() == oo.mn());
}

int main()
{
	int i, _cID;
	double _cMoney;
	vector<_ID> client;		// Vector of classes.
	_ID blank(0,"",0.0);	// Using the constructor to make an empty class.

	string filename = "oldmast.dat";
	ifstream input(filename);	// Opening oldmast.dat file.
	if (input.fail()) {			// If oldmast.dat doesn't exist print a message and end the program with return value -1.
		cerr << "File " << filename << " doesn't exist... exiting\n";
		keep_window_open();
		return -1;
	}
	while (!input.eof()) {
		input >> blank;				// Using the overloaded operator to read the file as classes.
		client.push_back(blank);	// Pushback every class into the vector.
	}
	input.close();

	filename = "Transaction.dat";
	ifstream trans(filename);
	if (trans.fail()) {			// If Transaction.dat doesn't exist print a message and end the program with return value -1.
		cerr << "File " << filename << " doesn't exist... exiting\n";
		keep_window_open();
		return -1;
	}
	while (!trans.eof()) {
		_cID = 0;
		_cMoney = 0.0;
		trans >> _cID >> _cMoney;
		if (_cID) {
			for (i = 0; (size_t)i < client.size() - 1; i++) {
				if (client[i] == _cID) {			// Comparing the ID inside the class with an integer.
					client[i].setmoney(_cMoney);	// Changing the Money if the ID is the same.
					break;
				}
				else {
					if (i == client.size() - 2) {	// Else if there isn't print error and continue.
						cerr << "Error: Wrong ID " << _cID << "\n";
					}
				}
			}
		}
	}
	trans.close();

	filename = "newmast.dat";
	ofstream output(filename);
	for (i = 0; (size_t)i < client.size() - 1; i++)
		output << client[i] << '\n';
	output.close();
	keep_window_open();
	return 0;
}