//Process any file bit-by-bit. Add lines of code for what to do with 1s and 0s...

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	
	//Gets path to file from user.
	cout << "\nDrag & drop file into terminal or enter path:\n";
	char  path_to_file[10000];
	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';} //Fills path_to_file[] with null.
	cin.getline(path_to_file, 10000);
	if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
	
	//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/user/my documents/doc.tar.bz2'
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
	
	//Stream begins.
	char temp_file_byte;
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
			{	/*      ______________________________________________________
				       /                                                      \
				      |  ÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅ  |
				      |  ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤ IF BIT = 0 ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤  |
				      |  ¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥  |
				       \______________________________________________________/
				*/
			}
			else
			{	/*      ______________________________________________________
				       /                                                      \
				      |  ÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅ  |
				      |  ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤ IF BIT = 1 ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤  |
				      |  ¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥  |
				       \______________________________________________________/
				*/
			}
		}
		
		in_stream.get(temp_file_byte);
	}
	in_stream.close();
}
