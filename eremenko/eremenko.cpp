
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int c866(char s, char * in) { //Function for transcoding from 1251 to 866 system.
	int cod = (int)(unsigned char)s;//Format the unsigned char in int.
	int cod2 = *((int*)in + cod);//Plus codes to get the desired code.
	return cod2;
}

int c1251(char s, char *in) {//Function for transcoding from 866 to 1251 system.

	 int cod = (int)(unsigned char)s;
	 int cod2 = *((int*)in + cod);
	 return cod2;
}


int main(int argc, char* argv[])
{
	if (!(argc == 2))
	{
		cout << "You must specify a task file name in the command line options. \nThe configuration file format is as follows: \n [code866-> 1251 | code1251-> 866] [Input file name] [Output file name]\n";
		return 1;
	}
	if (strcmp("/?", argv[1]) == 0)//help command
	{
		cout << "You must specify a task file name in the command line options. \nThe configuration file format is as follows: \n [code866-> 1251 | code1251-> 866] [Input file name] [Output file name]\n";
		return -1;
	}


	ifstream conf(argv[1]), in;
	ofstream out;
	string file_in, file_out, operation;
	while (!(conf.eof()))//Until the job file ends.
	{
		conf >> operation;//write the operation. For example : "code1251->866" or "code866->1251"
		conf >> file_in;//read input and output files.
		conf >> file_out;

		in.open(file_in); out.open(file_out);//open files


		if (!(in)) { cout << "error\n"; return -1; }
		if (!(out)) { cout << "error\n"; return -1; }

		//Variables that store character codes in 1251 and 866 systems.
		int TAB866_1251[246] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 32, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 168, 184, 170, 186, 175, 191 };
		int TAB1251_866[256] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 240, 32, 242, 32, 32, 32, 32, 244, 32, 32, 32, 32, 32, 32, 32, 32, 241, 32, 243, 32, 32, 32, 32, 245, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239 };

		if (operation == "code1251->866")
		{
			string line, s, tmp;
			while (!in.eof()) {
				s = "";
				getline(in, line);
				istringstream iss(line);
				while (iss >> tmp) {//read the words from the file and write it to the string.
					s += tmp + ' ';
				}
				int *pointer = TAB1251_866;//making pointer

				for (int i = 0; i < s.size(); i++)//Until the end of the line.
				{
					out << (unsigned char)c866(s[i], (char*)(pointer));// pass a string character-by-character into a function.
				}
				cout << " ";
				out << " ";
			}
			cout << endl;
			out << endl;
			in.close(); out.close();//close files

		}
		else
		{
			if (operation == "code866->1251")
			{
				string line, s, tmp;
				while (!in.eof()) {
					s = "";
					getline(in, line);
					istringstream iss(line);
					while (iss >> tmp) {
						s += tmp + ' ';
					}
					int *pointer = TAB866_1251;
					for (int i = 0; i < s.size(); i++)
					{
						out << (unsigned char)c866(s[i], (char*)(pointer));
					}
					cout << " ";
					out << " ";
				}
				cout << endl;
				out << endl;
				in.close(); out.close();

			}
			else
			{
				cout << "ERROR!\n";
				return -1;
			}

		}
	}
	
} 

