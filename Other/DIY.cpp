//Process any file bit-by-bit. Add lines of code at the end for what to do with 1s and 0s...
//Run it: "apt install g++ geany". Open this in Geany. Hit F9 once. F5 to run.

#include <fstream>
#include <iostream>
using namespace std;
int main()
{	int raw_byte;
	char file_byte;
	ifstream in_stream;
	
	//Gets path, fixes it, tries it.
	cout << "\nDrop/enter file:\n";
	char path[100000] = {'\0'}; cin.getline(path, 100000); if(path[0] == '\0') {cin.getline(path, 100000);}
	if(path[0] == '\'') {for(int bm = 0, a = 0; a < 100000; a++) {if(path[a] != '\'') {path[bm] = path[a]; if(path[bm] == '\\') {path[bm] = '\'';} bm++;}}}
	for(int a = 99999; a >= 0; a--) {if(path[a] != '\0') {if(path[a] == ' ') {path[a] = '\0';} break;}}
	in_stream.open(path); if(in_stream.fail() == true) {cout << "\nNo path " << path << "\n"; return 0;} in_stream.close();
	
	//Stream begins.
	in_stream.open(path);
	in_stream.get(file_byte);
	for(; in_stream.eof() == false;)
	{	//..........Converts file byte to (0 to 255.)
		raw_byte = file_byte;
		if(raw_byte < 0) {raw_byte += 256;}
		
		//..........Converts file byte to binary of 00000000 to 11111111.
		bool binary[8] = {0};
		int place_value = 128;
		for(int a = 0; a < 8; a++)
		{	if(raw_byte >= place_value)
			{	binary[a] = 1;
				raw_byte -= place_value;
			}
			place_value /= 2;
		}
		
		//..........Processing 8 bits at a time.
		for(int bit = 0; bit < 8; bit++)
		{	if(binary[bit] == 0)
			{	/*####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*######
				##'                                         '##
				#                      if                     #
				#                 file bit = 0                #
				##,                                         ,##
				####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*/
			}
			else
			{	/*####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*######
				##'                                         '##
				#                      if                     #
				#                 file bit = 1                #
				##,                                         ,##
				####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*/
			}
		}
		
		in_stream.get(file_byte);
	}
	in_stream.close();
}
