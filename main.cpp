#include <iostream>
#include <filesystem>
#include <vector>
#include "copy.hpp"
#include "main.hpp"
using namespace std;

int main(int argc, char *argv[], char *envp[]){
	if (argc < 2) {
		cout << "No file :(\n";
		return 1;
	}
	file_name = argv[1];
	if (filesystem::exists(file_name)){
		cout << "File exists :(\n";
		return 1;
	}
	file_extension = file_name.extension();
	homedir = getenv("HOME");
	template_directory = filesystem::path(homedir + "/Templates/");

	vector<string> templates = get_templates(file_extension);
	copy_file();
    return 0;
}

vector<string> get_templates(string extension) {
	vector<string> result;
	 for (const auto & entry : filesystem::directory_iterator(template_directory)){
		 if (entry.is_regular_file() && entry.path().extension() == extension)
			 result.push_back(entry.path());
	 }
	 return result;
}
