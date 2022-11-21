#include<iostream>
#include<fstream>
#include<string>
using namespace std;



void search(ifstream&, string&, bool&, bool&);
void optionsCheck(string&,bool&, bool&);

int main(int argc, char *argv[]) {
	string line;
	string findThis;
	string options;
	bool lineOption = false;
	bool occurrencesOption = false;
	int foundPosition;
	ifstream inputfile;

	//if the user doesnt put in any arguments, asking him for a string and a search string
	if (argc == 1) {

		cout << "Give a string from which to search for: ";
		getline(cin, line);

		cout << "Give search string: ";
		getline(cin, findThis);

		/* checking if the findThis is a substring of line and if it is the position where the substring starts
		will be inserted into foundPosition. if findThis isnt a substring of line foundPosition will get the value of -1*/
		foundPosition = line.find(findThis);


		//if findThis is a substring of line, telling the user its starting position, otherwise telling that it wasnt a substring
		if (foundPosition != string::npos) {
			cout << "\"" << findThis << "\" found in \"" << line << "\" in position " << foundPosition;
		}
		else {
			cout << "\"" << findThis << "\" NOT found in \"" << line << "\"";
		}
	}

	//if the user writes only 2 arguments, telling him that there needs to be more
	else if (argc == 2) {
		cout << "Too few arguments! Give the string you are looking for and the file you want to search it from!" << endl;
	}

	//if the user writes a string and a file name
	else if (argc == 3) {
		//inserting the string the user wants to search for into findThis
		findThis = argv[1];

		//opening the file that the user gave as an argument
		inputfile.open(argv[2]);

		//searching the file for all the lines that have the string and printing the lines out
		search(inputfile, findThis, lineOption, occurrencesOption);

		//closing the file
		inputfile.close();
	}

	//if the user writes options, a string and a file name
	else if (argc == 4) {

		//inserting the options string that the user chose into "options"
		options = argv[1];

		//checking what options the user chose
		optionsCheck(options, lineOption, occurrencesOption);

		//inserting the string the user wants to search for into findThis
		findThis = argv[2];

		//opening the file that the user gave as an argument
		inputfile.open(argv[3]);

		//searching the file for all the lines that have the string and printing the lines out
		search(inputfile, findThis, lineOption, occurrencesOption);

		//closing the file
		inputfile.close();
	}

	//if there are more than 4 arguments telling the user that there are too many arguments
	else {
		cout << "Too many arguments!" << endl;
	}


	return 0;
}


void search(ifstream& inputfile, string& findThis, bool& lineOption, bool& occurrencesOption) {
	int occurrences = 0;
	int lineNum = 0;
	int foundPosition;
	string line;
	
	//if the file cant be opened, telling the user that
	if (!inputfile) {
		cout << "Couldn't open the file!" << endl;
		exit(0);
	}

	//searching for all the lines that have the string that the user said
	while (getline(inputfile, line)) {
		lineNum++;

		//checking if the line has the string
		foundPosition = line.find(findThis);

		//printing out the line if it had the string and printing the line number if the user chose that option
		if (foundPosition != string::npos) {
			occurrences++;

			if (lineOption) {
				cout << lineNum << ":" << '\t';
			}

			cout << line << endl;
		}
	}
	//printing out the number of occurrences if the user chose that option
	if (occurrencesOption == true) {
		cout << endl << "Occurrences of lines containing \"" << findThis << "\": " << occurrences << endl;
	}

	//if the string wasnt found in the file at all, telling the user that
	if (occurrences == 0 && occurrencesOption == false) {
		cout << "\"" << findThis << "\" NOT found in the file" << endl;
	}

}


void optionsCheck(string& options,bool& lineOption, bool& occurrencesOption) {

	int length = options.length();

	//checking that the user wrote -o before the options
	if ((options[0] != '-') || (options[1] != 'o') || (length == 2)) {
		cout << "Choose options with -o and after that the options you want (l= line numbering, o= occurrences)" << endl;
		exit(0);
	}

	//checking that the users "options" argument isnt too long
	if (length > 4) {
		cout << "The options argument is too long!" << endl;
		exit(0);
	}

	
	for (int i = 2; i < length ; i++) {
		//checking that the argument has only "l" and/or "o" after -o
		if (options[i] != 'l' && options[i] != 'o') {
			cout << "Invalid options! Valid options: l= line numbering, o= occurrences" << endl;
			exit(0);
		}
		//checking what options the user chose and putting the chosen ones as true
		if (options[i] == 'l') {
			lineOption = true;
		}
		if (options[i] == 'o') {
			occurrencesOption = true;
		}
	}

	//checking that the argument isnt "-ooo" or "-oll"
	if (options[2] == options[3]) {
		cout << "You can't select the same option twice!" << endl;
		exit(0);
	}

}