#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Header.h"

Print_edition::Print_edition() {
	count++;
	name = new char[0];
	year = 0;
	name_of_publisher = new char[0];
	number_of_pages = 0;
	annotation = new char[0];
};

Print_edition::Print_edition(char* name, int year, char* name_of_publisher, int number_of_pages, char* annotation) {
	this->count++;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->year = year;
	this->name_of_publisher = new char[strlen(name_of_publisher) + 1];
	strcpy(this->name_of_publisher, name_of_publisher);
	this->number_of_pages = number_of_pages;
	this->annotation = new char[strlen(annotation) + 1];
	strcpy(this->annotation, annotation);
};

Print_edition::Print_edition(Print_edition& original) {
	this->count++;
	this->name = new char[strlen(original.name)];
	strcpy(this->name, original.name);
	this->year = original.year;
	this->name_of_publisher = new char[strlen(original.name_of_publisher)];
	strcpy(this->name_of_publisher, original.name_of_publisher);
	this->number_of_pages = original.number_of_pages;
	this->annotation = new char[strlen(original.annotation)];
	strcpy(this->annotation, original.annotation);
};

int Print_edition::getCount() {
	return count;
};

Print_edition& Print_edition::operator =(Print_edition& original) {
	delete[]name;
	delete[]name_of_publisher;
	delete[]annotation;
	this->name = new char[strlen(original.name)];
	strcpy(this->name, original.name);
	this->year = original.year;
	this->name_of_publisher = new char[strlen(original.name_of_publisher)];
	strcpy(this->name_of_publisher, original.name_of_publisher);
	this->number_of_pages = original.number_of_pages;
	this->annotation = new char[strlen(original.annotation)];
	strcpy(this->annotation, original.annotation);
	return *this;
};

Print_edition::~Print_edition() {
	count--;
	delete[]name;
	delete[]name_of_publisher;
	delete[]annotation;
};

void Book::print() {
	std::cout << "Name of book: ";
	for (int i = 0; i < strlen(name); i++) {
		std::cout << name[i];
	}
	std::cout << std::endl;
	std::cout << "Year of publishing: " << year << std::endl;
	std::cout << "Name of publisher: ";
	for (int i = 0; i < strlen(name_of_publisher); i++) {
		std::cout << name_of_publisher[i];
	}
	std::cout << std::endl;
	std::cout << "Number of pages: " << number_of_pages << std::endl;
	std::cout << "Annotation: ";
	for (int i = 0; i < strlen(annotation); i++) {
		std::cout << annotation[i];
	}
	std::cout << std::endl;
};

void Book::fprint(char* filename) {
	std::ofstream fout(filename);
	fout << "Name of book: ";
	for (int i = 0; i < strlen(name); i++) {
		fout << name[i];
	}
	fout << std::endl;
	fout << "Year of publishing: " << year << std::endl;
	fout << "Name of publisher: ";
	for (int i = 0; i < strlen(name_of_publisher); i++) {
		fout << name_of_publisher[i];
	}
	fout << std::endl;
	fout << "Number of pages: " << number_of_pages << std::endl;
	fout << "Annotation: ";
	for (int i = 0; i < strlen(annotation); i++) {
		fout << annotation[i];
	}
	fout << std::endl;
	fout << "----------------" << std::endl;
	fout.close();
};

void Magazine::print() {
	std::cout << "Name of magazine: ";
	for (int i = 0; i < strlen(name); i++) {
		std::cout << name[i];
	}
	std::cout << std::endl;
	std::cout << "Year of publishing: " << year << std::endl;
	std::cout << "Name of publisher: ";
	for (int i = 0; i < strlen(name_of_publisher); i++) {
		std::cout << name_of_publisher[i];
	}
	std::cout << std::endl;
	std::cout << "Number of pages: " << number_of_pages << std::endl;
	std::cout << "Annotation: ";
	for (int i = 0; i < strlen(annotation); i++) {
		std::cout << annotation[i];
	}
	std::cout << std::endl;
};

void Magazine::fprint(char* filename) {
	std::ofstream fout(filename);
	fout << "Name of magazine: ";
	for (int i = 0; i < strlen(name); i++) {
		fout << name[i];
	}
	fout << std::endl;
	fout << "Year of publishing: " << year << std::endl;
	fout << "Name of publisher: ";
	for (int i = 0; i < strlen(name_of_publisher); i++) {
		fout << name_of_publisher[i];
	}
	fout << std::endl;
	fout << "Number of pages: " << number_of_pages << std::endl;
	fout << "Annotation: ";
	for (int i = 0; i < strlen(annotation); i++) {
		fout << annotation[i];
	}
	fout << std::endl;
	fout << "----------------" << std::endl;
	fout.close();
};

void Textbook::print() {
	std::cout << "Name of textbook: ";
	for (int i = 0; i < strlen(name); i++) {
		std::cout << name[i];
	}
	std::cout << std::endl;
	std::cout << "Year of publishing: " << year << std::endl;
	std::cout << "Name of publisher: ";
	for (int i = 0; i < strlen(name_of_publisher); i++) {
		std::cout << name_of_publisher[i];
	}
	std::cout << std::endl;
	std::cout << "Number of pages: " << number_of_pages << std::endl;
	std::cout << "Annotation: ";
	for (int i = 0; i < strlen(annotation); i++) {
		std::cout << annotation[i];
	}
	std::cout << std::endl;
};

void Textbook::fprint(char* filename) {
	std::ofstream fout(filename);
	fout << "Name of textbook: ";
	for (int i = 0; i < strlen(name); i++) {
		fout << name[i];
	}
	fout << std::endl;
	fout << "Year of publishing: " << year << std::endl;
	fout << "Name of publisher: ";
	for (int i = 0; i < strlen(name_of_publisher); i++) {
		fout << name_of_publisher[i];
	}
	fout << std::endl;
	fout << "Number of pages: " << number_of_pages << std::endl;
	fout << "Annotation: ";
	for (int i = 0; i < strlen(annotation); i++) {
		fout << annotation[i];
	}
	fout << std::endl;
	fout << "----------------" << std::endl;
	fout.close();
};