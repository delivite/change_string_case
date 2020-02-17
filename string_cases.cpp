/*
 * to_lower.cpp
 *
 *  Created on: 11 Feb 2020
 *      Author: Troy*/

#include <iostream>

std::string to_lower(const std::string &stream) {

	std::string new_stream { };

	for (auto letter : stream) {
		if (letter >= 'A' && letter <= 'Z') {
			letter += 32;
		}
		new_stream += letter;
	}

	return new_stream;
}

std::string to_upper(const std::string &stream) {

	std::string new_stream { };

	for (auto letter : stream) {
		if (letter >= 'a' && letter <= 'z') {
			letter -= 32;
		}
		new_stream += letter;
	}

	return new_stream;
}

std::string change_case(const std::string &phrase) {
	std::string new_phrase { };

	for (char letter : phrase) {

		if (letter >= 'A' && letter <= 'Z') {
			letter += 32;
		} else if (letter >= 'a' && letter <= 'z') {
			letter -= 32;
		}
		new_phrase += letter;
	}

	return phrase;
}

void to_lower1(std::string &word) {
	char *s = &word[0];
	while (*s != 0) {
		if (*s >= 'A' && *s <= 'Z') {
			*s += 32;
		}
		s++;
	}
}

void to_camel_case(std::string &word) {
	char *s = &word[0];
	if (*s >= 'a' && *s <= 'z') { //Change the first character to upper case
		*s -= 32;
	}
	while (*s != 0) {
		++s;
		if (*s == ' ') { //Move to the next character if current character is a space
			++s;
			if (*s >= 'a' && *s <= 'z') { //Change the next character after a space to upper space
				*s -= 32;
			}
			++s;
		}
		if (*s >= 'A' && *s <= 'Z') { //Change everything else to lower case
			*s += 32;
		}
	}
}

int main() {

	std::string word { "indiAna jOnEs ..." };
	to_camel_case(word);
	std::cout << word << std::endl;

	return 0;
}

