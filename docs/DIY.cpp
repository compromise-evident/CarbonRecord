//Process any file bit-by-bit. Add lines of code at the end for what to do with 1s and 0s...
//Run it: "apt install g++ geany". Open this in Geany. Hit F9 once. F5 to run.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{	int raw_byte;
	char file_byte;
	ifstream in_stream;
	
	//Gets path, fixes it if dropped.
	cout << "\nDrop/enter file:\n"; string path; getline(cin, path); if(path[0] == '\0') {getline(cin, path);}
	if(path[0] == '\'') {path.erase(0, 1); path.pop_back(); path.pop_back();}
	in_stream.open(path); if(in_stream.fail()) {cout << "\nNo path " << path << "\n"; return 1;} in_stream.close();
	
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
