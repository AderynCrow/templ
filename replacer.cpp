#include<iostream>
#include "main.hpp"
using namespace std;

void filename_full(string* line);
void filename_short(string* line);
void string_replace( string* src, string const& target, string const& repl);

string replace_string(string line){
	filename_full(&line);
	filename_short(&line);
	return line;
}

void filename_full(string* line){
	string variable_name = "$FILENAME";
	string_replace(line, variable_name, get_filename());
}
void filename_short(string* line){
	string variable_name = "$FILE";
	string short_name = get_filename();
	short_name.resize(short_name.find('.'));
	string_replace(line, variable_name, short_name);
}

void string_replace( string* src, string const& target, string const& repl){
    // handle error situations/trivial cases

    if (target.length() == 0) {
        // searching for a match to the empty string will result in 
        //  an infinite loop
        //  it might make sense to throw an exception for this case
        return;
    }

    if (src->length() == 0) {
        return;  // nothing to match against
    }

    size_t idx = 0;

    for (;;) {
        idx = src->find( target, idx);
        if (idx == string::npos)  break;

        src->replace( idx, target.length(), repl);
        idx += repl.length();
    }

}
