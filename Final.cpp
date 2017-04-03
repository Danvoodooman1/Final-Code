#include #include #include #include

using namespace std; int main(int argc, char *argv[]) {

int quantities[10] = {5, 5, 15, 50, 50, 50, 100, 250, 250, 300};

string partNum = "";

string price = "";

string input = "";

int x = 0;

ifstream partsList;

partsList.open("PartNumbers.txt");

if (partsList.is_open()) {
	
	cout << "Please enter the part number: ";
	
	cin >> input;
	
	while (input != "-1") {
		
		x++;
		
		if (!partsList.eof()) {
			
			getline (partsList, partNum);
							
			if (partNum == input) {
				
				getline(partsList, price);
				
				cout << price << endl;
				
				x++;
				
				x = x / 2;
				
				quantities[x]--;
				
				if (quantities[x] < 3) {
					cout << "Notice to Cashier!" << endl;
					
					cout << "Please order new stock for this item." << endl;
				}
				
				x = 0;
				
				cout << "Please enter another part number (-1 to quit): ";
				
				cin >> input;
				
				partsList.close();
				
				partsList.open("PartNumbers.txt");
				
			}
		}
		else {
					
			cout << "Sorry number is not in our system." << endl;
					
			cout << "Please enter another code (-1 to quit): ";
					
			cin >> input;
					
			partsList.close();
					
			partsList.open("PartNumbers.txt");
		}
	}
}
else {
	cout << "Sorry the part file could not be found." << endl;
	
	cout << "Please download the proper file." << endl;
	
	cout << "The proper file is PartNumbers.txt ";

}
}
