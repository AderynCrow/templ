#include <iostream>
#include <filesystem>
#include <vector>
#include "copy.hpp"
#include "main.hpp"
using namespace std;

string file_name;
int main(int argc, char *argv[], char *envp[]){
	//parse arguments
	if (argc < 2) {
		cout << "No file :(\n";
		return 1;
	}
	file_name = argv[1];
	if (filesystem::exists(file_name)){
		cout << "File exists :(\n";
		return 1;
	}

	copy_file(file_name);
    return 0;
}

string get_filename() {
	return file_name;
}

string get_extension(string filename) {
	filesystem::path result = filename;
	return  result.extension();
}
