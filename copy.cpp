#include "main.hpp"
#include "copy.hpp"
#include "templateGetter.hpp"
#include "replacer.hpp"
#include <iostream>
#include <fstream>
using namespace std;
string get_extension(string filename);

void copy_file(string filename) {
	ifstream in_file;
	ofstream out_file;
	filesystem::path template_path = get_template(get_extension(filename));
	in_file.open(template_path);
	out_file.open(filename);
	string line;
	while (getline(in_file,line)){
		out_file << replace_string(line) << endl;
	}
	out_file.close();
}

