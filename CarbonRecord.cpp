/// CarbonRecord - preserve data on fluorocarbon fishing line -
///                imprescriptible multi-millennium storage.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/*  Version 1.0.0.  Photoresistor of  github.com/compromise-evident/CarbonRecord
is taped to any LED screen for sensing "light flash" of text in a dark terminal.
Dent on fishing line = 1, no dent = 0. Activity & inactivity are spaced equally.
Data begins & ends with 1 dent, scratch this note on metallic plates per record.
You may need to turn down the  brightness  of your screen for the photoresistor.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to run the program  -  Software package repositories for GNU+Linux operating
systems have all the tools you can imagine. Open a terminal and use this command
as root to install Geany and g++ on your computer: apt install geany g++   Geany
is a fast & lightweight text editor and Integrated Development Environment where
you can write and run code. g++ is the GNU compiler for C++ which allows written
code to run. The compiler operates in the background and displays errors in your
code as you will see in the lower Geany box. Make a new folder somewhere on your
machine. Paste this code into Geany. For clarity in auditing, enable indentation
guides: go to View >> Show Indentation Guides. Save the document as anything.cpp
within the newly-created folder. Use these shortcuts to run the program: F9, F5.
You may paste over this code with other  .cpp files, or open a new tab & repeat.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to make an executable with g++  -  Save this program as anything.cpp, open a
terminal, and type g++ then space. Drag & drop this saved file into the terminal
and its directory will be  appended to your pending entry. Click on the terminal
and press enter.   a.out now resides in the user directory, you may rename it to
anything.  To run that executable, simply drag and drop it into a terminal, then
click on the terminal and press enter.  Reminder:  executable's effect-directory
is /home/user or where you put the executable. Opening  .cpp  files in Geany and
hitting F9 creates the same executable--movable, renameable, drag & droppable.*/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	long long time_consumption = 60000000; //DEFAULT= 60000000. Increase to make
	//                                the box flash slower,  decrease it to make
	//                                the box flash faster (exposure time knob.)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	int first = 226, second = 150, third = 136;
	cout << "\n\n";
	for(int a = 0; a < 3; a++)
	{	cout << "          ";
		for(int b = 0; b < 6; b++) {cout << char(first) << char(second) << char(third);}
		cout << "\n";
	}
	
	//Gets path to file from user.
	cout << "\nMake sure the terminal background is dark."
	     << "\nTape your photoresistor against the square."
	     << "\nDrag & drop file into terminal or enter path:\n";
	
	char  path_to_file[10000];
	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';} //Fills path_to_file[] with null.
	cin.getline(path_to_file, 10000);
	if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
	
	//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/nikolay/my documents/Authorship.cpp.tar.bz2'
	if(path_to_file[0] == '\'')
	{	for(int a = 0; a < 10000; a++)
		{	path_to_file[a] = path_to_file[a + 1];
			if(path_to_file[a] == '\'')
			{	path_to_file[a    ] = '\0';
				path_to_file[a + 1] = '\0';
				path_to_file[a + 2] = '\0';
				break;
			}
		}
	}
	
	//Checks if file exists (failure can be bad path info as well.)
	in_stream.open(path_to_file);
	if(in_stream.fail() == true) {in_stream.close(); cout << "\n\nNo such file or directory.\n";             return 0;}
	char sniffed_one_file_character;
	in_stream.get(sniffed_one_file_character);
	if(in_stream.eof() == true) {in_stream.close();  cout << "\n\nNothing to process, the file is empty.\n"; return 0;}
	in_stream.close();
	
	//Gets file size in Bytes then converts to bits.
	char temp_file_byte;
	long long total_bits = 0;
	in_stream.open(path_to_file);
	in_stream.get(temp_file_byte);
	for(; in_stream.eof() == false;)
	{	in_stream.get(temp_file_byte);
		total_bits++;
	}
	total_bits *= 8;
	in_stream.close();
	
	//Lets user begin denting.
	system("clear");
	cout << "                                                Press enter to\n"
	     << "                                                roll the boxes...";
	char wait[1];
	cin.getline(wait, 1);
	
	//Rolls blank.
	for(int a = 0; a < 10; a++)
	{	cout << "\n\n\n";
		for(int a = 0; a < time_consumption; a++) {}
	}
	
	//Applies header (1 dent.)
	for(int a = 0; a < 3; a++)
	{	cout << "          ";
		for(int b = 0; b < 6; b++) {cout << char(first) << char(second) << char(third);}
		if(a == 1) {cout << "                                   header";}
		cout << "\n";
	}
	for(int a = 0; a < time_consumption; a++) {}
	
	//Blank
	cout << "\n\n\n";
	for(int a = 0; a < time_consumption; a++) {}
	
	//Begins flashing characters in the terminal.
	long long bit_count = 1;
	int  temp_file_byte_normal;
	in_stream.open(path_to_file);
	in_stream.get(temp_file_byte);
	for(; in_stream.eof() == false;)
	{	//..........Converts file byte to (0 to 255.)
		temp_file_byte_normal = temp_file_byte;
		if(temp_file_byte_normal < 0) {temp_file_byte_normal += 256;}
		
		//..........Converts file byte to binary of 00000000 to 11111111.
		bool binary[8] = {0};
		int place_value = 128;
		for(int a = 0; a < 8; a++)
		{	if(temp_file_byte_normal >= place_value)
			{	binary[a] = 1;
				temp_file_byte_normal -= place_value;
			}
			
			place_value /= 2;
		}
		
		//..........Writes 1 byte to file based on binary[].
		for(int bit = 0; bit < 8; bit++)
		{	if(binary[bit] == 0)
			{	for(int a = 0; a < 3; a++)
				{	cout << "                                   ";
					for(int b = 0; b < 6; b++) {cout << char(first) << char(second) << char(third);}
					cout << "          " << bit_count << " of " << total_bits << "\n";
				}
				for(int a = 0; a < time_consumption; a++) {}
			}
			else
			{	for(int a = 0; a < 3; a++)
				{	cout << "          ";
					for(int b = 0; b < 6; b++) {cout << char(first) << char(second) << char(third);}
					cout << "                                   " << bit_count << " of " << total_bits << "\n";
				}
				for(int a = 0; a < time_consumption; a++) {}
			}
			
			//..........Blank
			if(bit_count < total_bits)
			{	for(int a = 0; a < 3; a++) {cout << "                                                   " << bit_count << " of " << total_bits << "\n";}
				for(int a = 0; a < time_consumption; a++) {}
			}
			else {cout << "\n\n\n";}
			
			bit_count++;
		}
		
		in_stream.get(temp_file_byte);
	}
	in_stream.close();
	
	//Applies footer (1 dent.)
	for(int a = 0; a < 3; a++)
	{	cout << "          ";
		for(int b = 0; b < 6; b++) {cout << char(first) << char(second) << char(third);}
		if(a == 1) {cout << "                                   footer";}
		cout << "\n";
	}
	for(int a = 0; a < time_consumption; a++) {}
	
	//Rolls blank.
	for(int a = 0; a < 15; a++)
	{	cout << "\n\n\n";
		for(int a = 0; a < time_consumption; a++) {}
	}
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDone!";
	return 0;
}
