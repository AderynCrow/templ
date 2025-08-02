#include "templateGetter.hpp"
using namespace std;

string select_string(vector<string> choices);
vector<string> get_templates(string extension);

string get_template(string extension) {
	vector<string> templates = get_templates(extension);
	if(templates.size() <= 0)
		return "";
	if(templates.size() == 1)
		return templates.front();
	return select_string(templates);
}


vector<string> get_templates(string extension) {
	string homedir = getenv("HOME");
	filesystem::path template_directory;
	template_directory = filesystem::path(homedir + "/Templates/");
	vector<string> result;
	for (const auto & entry : filesystem::directory_iterator(template_directory)){
		if (entry.is_regular_file() && entry.path().extension() == extension)
			result.push_back(entry.path());
	}
	return result;
}

string select_string(vector<string> choices){
	for (int i = 0 ; i < choices.size(); i++){
		cout << "(" << i << "): " << choices.at(i) << "\n";
	}
	cout << "Please select the Template:(0) ";
	int selection = 0;
	std::string input;
	std::getline(std::cin, input);

    if (input.empty()) {
        // If the user just hits Enter, use the default value
        selection = 0;
    } else {
        // Otherwise, try to convert the input to an integer
        try {
            selection = std::stoi(input);
        } catch (const std::invalid_argument& e) {
            selection = 0;
        } catch (const std::out_of_range& e) {
            selection = 0;
        }
	}
	if (selection >= choices.size())
		selection = choices.size()-1;
	return choices.at(selection);
}
