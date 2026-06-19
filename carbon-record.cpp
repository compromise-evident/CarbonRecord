//YOUR CONTROLS:                                                                Run it: "apt install g++ geany". Open the .cpp in Geany. Hit F9 once. F5 to run.
char time_consumption[] = {"sleep 0.19"}; //Smaller = faster boxes.



/*Version 1.0.3
preserve data on fluorocarbon fishing line -
imprescriptible multi-millennium storage.

Dent on fishing line = 1, no dent = 0. Activity & inactivity are spaced equally.
Data begins & ends with 1 dent, scratch this note on  metal plates per record.*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{	ifstream in_stream;
	
	std::cout << "\033[2J\033[3J\033[1;1H"; //Clears screen, erasing history.
	cout << "\n"
	     << "        ███████████              ███████████\n"
	     << "        ██       ██              ██       ██\n"
	     << "        ██       ██              ██       ██\n"
	     << "        ██       ██              ██       ██\n"
	     << "        ██████████1              ██████████0\n\n"
	
	     << "                         ██\n\n"
	
	     << "     \\o-,.._                            _..,-o/\n"
	     << "      Set terminal to 80x24, \"White on black\".\n"
	     << "         Tape one photoresistor to left eye\n"
	     << "            thoroughly. Adjust brightness.\n"
	     << "                  Drop/enter file:  ";
	
	//Gets path, fixes it if dropped.
	string path; getline(cin, path); if(path[0] == '\0') {getline(cin, path);}
	if(path[0] == '\'') {path.erase(0, 1); path.pop_back(); path.pop_back();}
	in_stream.open(path); if(in_stream.fail()) {cout << "\nNo path " << path << "\n"; return 1;} in_stream.close();
	
	//Checks if file is empty.
	in_stream.open(path);
	char sniffed_one_file_character;
	in_stream.get(sniffed_one_file_character);
	if(in_stream.eof() == true) {in_stream.close();  cout << "\n\nNothing to process, the file is empty.\n"; return 0;}
	in_stream.close();
	
	//Gets file size in Bytes then converts to bits.
	char temp_file_byte;
	long long total_bits = 0;
	in_stream.open(path);
	in_stream.get(temp_file_byte);
	for(; in_stream.eof() == false;)
	{	in_stream.get(temp_file_byte);
		total_bits++;
	}
	total_bits *= 8;
	in_stream.close();
	
	//Rolls blank.
	std::cout << "\033[2J\033[3J\033[1;1H"; //Clears screen, erasing history.
	for(int a = 0; a < 10; a++)
	{	cout << "\n\n\n";
		system(time_consumption);
	}
	
	//Applies header (1 dent.)
	cout << "          ███████\n"
	     << "          ███████                                   header\n"
	     << "          ███████\n";
	system(time_consumption);
	
	//Blank
	cout << "\n\n\n";
	system(time_consumption);
	
	//Begins flashing characters in the terminal.
	long long bit_count = 1;
	int  temp_file_byte_normal;
	in_stream.open(path);
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
			{	/*####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*######
				##'                                         '##
				#                   if file                   #
				#                   bit = 0                   #
				##,                                         ,##
				####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*/
				cout << "                                   ███████          " << bit_count << " of " << total_bits << "\n"
				     << "                                   ███████          " << bit_count << " of " << total_bits << "\n"
				     << "                                   ███████          " << bit_count << " of " << total_bits << "\n";
				system(time_consumption);
			}
			else
			{	/*####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*######
				##'                                         '##
				#                   if file                   #
				#                   bit = 1                   #
				##,                                         ,##
				####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*/
				cout << "          ███████                                   " << bit_count << " of " << total_bits << "\n"
				     << "          ███████                                   " << bit_count << " of " << total_bits << "\n"
				     << "          ███████                                   " << bit_count << " of " << total_bits << "\n";
				system(time_consumption);
			}
			
			//..........Blank
			if(bit_count < total_bits)
			{	for(int a = 0; a < 3; a++) {cout << "                                                    " << bit_count << " of " << total_bits << "\n";}
				system(time_consumption);
			}
			else {cout << "\n\n\n"; system(time_consumption);}
			
			bit_count++;
		}
		
		in_stream.get(temp_file_byte);
	}
	in_stream.close();
	
	//Applies footer (1 dent.)
	cout << "          ███████\n"
	     << "          ███████                                   footer\n"
	     << "          ███████\n";
	system(time_consumption);
	
	//Rolls blank.
	for(int a = 0; a < 15; a++)
	{	cout << "\n\n\n";
		system(time_consumption);
	}
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDone!";
}
