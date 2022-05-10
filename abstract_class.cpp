#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"

int Print_edition::count = 0;

Print_edition** add(Print_edition** array, int size, Print_edition* element) {
    Print_edition** tmp = new Print_edition*[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = array[i];
    }
    delete[]array;
    array = new Print_edition*[size + 1];
    for (int i = 0; i < size; i++) {
        array[i] = tmp[i];
    }
    array[size] = element;
    delete[]tmp;
    return array;
}

Print_edition** remove(Print_edition** array, int size, int index) {
    Print_edition** tmp = new Print_edition * [size - 1];
    for (int i = 0; i < size - 1; i++) {
        if (i < index) {
            tmp[i] = array[i];
        }
        else {
            tmp[i] = array[i + 1];
        }
    }
    delete array[index];
    delete[]array;
    array = new Print_edition*[size - 1];
    for (int i = 0; i < size - 1; i++) {
        array[i] = tmp[i];
    }
    delete[]tmp;
    return array;
}

Print_edition** edit(Print_edition** array, int index, Print_edition* new_element) {
    delete array[index];
    array[index] = new_element;
    return array;
}

int main() {
    Print_edition** p = new Print_edition*[0];
    bool stop = false;
    while (!stop) {
        system("cls"); //очистка консоли
        std::cout << "1. Create new Book." << std::endl;
        std::cout << "2. Create new Magazine." << std::endl;
        std::cout << "3. Create new Textbook." << std::endl;
        std::cout << "4. Print all." << std::endl;
        std::cout << "5. Print count." << std::endl;
        std::cout << "6. Remove element by index." << std::endl;
        std::cout << "7. Edit element by index." << std::endl;
        std::cout << "8. Save to file." << std::endl;
        std::cout << "0. Exit." << std::endl;
        int choice = 0;
        std::cin >> choice;
        char c = getchar();
        system("cls"); //очистка консоли
        switch (choice)
        {
        case 1:
        {
            char* name = new char[20];
            std::cout << "Enter name of book (20): ";
            std::cin >> name;
            int year = 0;
            std::cout << "Enter year of publishing: ";
            std::cin >> year;
            char* name_of_publisher = new char[20];
            std::cout << "Enter name of publisher (20): ";
            std::cin >> name_of_publisher;
            int number_of_pages = 0;
            std::cout << "Enter number of pages: ";
            std::cin >> number_of_pages;
            char* annotation = new char[20];
            std::cout << "Enter annotation (20): ";
            std::cin >> annotation;
            Book* b = new Book(name, year, name_of_publisher, number_of_pages, annotation);
            p = add(p, b->getCount() - 1, b);
            break;
        }
        case 2:
        {
            char* name = new char[20];
            std::cout << "Enter name of magazine (20): ";
            std::cin >> name;
            int year = 0;
            std::cout << "Enter year of publishing: ";
            std::cin >> year;
            char* name_of_publisher = new char[20];
            std::cout << "Enter name of publisher (20): ";
            std::cin >> name_of_publisher;
            int number_of_pages = 0;
            std::cout << "Enter number of pages: ";
            std::cin >> number_of_pages;
            char* annotation = new char[20];
            std::cout << "Enter annotation (20): ";
            std::cin >> annotation;
            Magazine* b = new Magazine(name, year, name_of_publisher, number_of_pages, annotation);
            p = add(p, b->getCount() - 1, b);
            break;
        }
        case 3:
        {
            char* name = new char[20];
            std::cout << "Enter name of textbook (20): ";
            std::cin >> name;
            int year = 0;
            std::cout << "Enter year of publishing: ";
            std::cin >> year;
            char* name_of_publisher = new char[20];
            std::cout << "Enter name of publisher (20): ";
            std::cin >> name_of_publisher;
            int number_of_pages = 0;
            std::cout << "Enter number of pages: ";
            std::cin >> number_of_pages;
            char* annotation = new char[20];
            std::cout << "Enter annotation (20): ";
            std::cin >> annotation;
            Textbook* b = new Textbook(name, year, name_of_publisher, number_of_pages, annotation);
            p = add(p, b->getCount() - 1, b);
            break;
        }
        case 4:
        {
            for (int i = 0; i < p[0]->getCount(); i++) {
                p[i]->print();
                std::cout << std::endl;
            }
            c = getchar();
            break;
        }
        case 5:
        {
            std::cout << p[0]->getCount() << std::endl;
            c = getchar();
            break;
        }
        case 6:
        {
            int index = 0;
            std::cout << "Enter index: ";
            std::cin >> index;
            c = getchar(); //считать энтер после ввода
            if (index >= 0 && index < p[0]->getCount())
            p = remove(p, p[0]->getCount(), index);
            break;
        }
        case 7:
        {
            int index = 0;
            std::cout << "Enter index: ";
            std::cin >> index;
            c = getchar(); //считать энтер после ввода
            char* name = new char[20];
            std::cout << "Enter new name of element (20): ";
            std::cin >> name;
            int year = 0;
            std::cout << "Enter new year of publishing: ";
            std::cin >> year;
            char* name_of_publisher = new char[20];
            std::cout << "Enter new name of publisher (20): ";
            std::cin >> name_of_publisher;
            int number_of_pages = 0;
            std::cout << "Enter new number of pages: ";
            std::cin >> number_of_pages;
            char* annotation = new char[20];
            std::cout << "Enter new annotation (20): ";
            std::cin >> annotation;
            std::cout << "1. New book" << std::endl;
            std::cout << "2. New magazine" << std::endl;
            std::cout << "3. New textbook" << std::endl;
            int choice2 = 0;
            std::cin >> choice2;
            c = getchar(); //считать энтер после ввода
            switch (choice2)
            {
            case 1:
            {
                Book* b = new Book(name, year, name_of_publisher, number_of_pages, annotation);
                p = edit(p, index, b);
            }
            case 2: 
            {
                Textbook* b = new Textbook(name, year, name_of_publisher, number_of_pages, annotation);
                p = edit(p, index, b);
            }
            case 3:
            {
                Magazine* b = new Magazine(name, year, name_of_publisher, number_of_pages, annotation);
                p = edit(p, index, b);
            }
            default:
                break;
            }
            break;
        }
        case 8:
        {
            char* filename = new char[20];
            std::cout << "Enter filename (20): ";
            std::cin >> filename;
            for (int i = 0; i < p[0]->getCount(); i++) {
                p[i]->fprint(filename);
            }
            c = getchar();
            break;
        }
        case 0:
        {
            stop = true;
            break;
        }
        default:
            break;
        }
    }
    for (int i = 0; i < p[0]->getCount(); i++)
    {
        delete p[i];
    }
    delete[]p;
}