#pragma once

class Print_edition {
public:
    Print_edition();
    Print_edition(char* name, int year, char* name_of_publisher, int number_of_pages, char* annotation);
    Print_edition(Print_edition& original);
    virtual void print() { };
    virtual void fprint(char* filename) { };
    virtual int getCount() final;
    Print_edition& operator =(Print_edition& original);
    virtual ~Print_edition();
protected:
    static int count;
    char* name;
    int year;
    char* name_of_publisher;
    int number_of_pages;
    char* annotation;
};

class Book final : public Print_edition {
public:
    Book(char* name, int year, char* name_of_publisher, int number_of_pages, char* annotation) : Print_edition(name, year, name_of_publisher, number_of_pages, annotation) {};
    void print() override;
    void fprint(char* filename) override;
    ~Book() {};
};

class Magazine final : public Print_edition {
public:
    Magazine(char* name, int year, char* name_of_publisher, int number_of_pages, char* annotation) : Print_edition(name, year, name_of_publisher, number_of_pages, annotation) {};
    void print() override;
    void fprint(char* filename) override;
    ~Magazine() {};
};

class Textbook final : public Print_edition {
public:
    Textbook(char* name, int year, char* name_of_publisher, int number_of_pages, char* annotation) : Print_edition(name, year, name_of_publisher, number_of_pages, annotation) {};
    void print() override;
    void fprint(char* filename) override;
    ~Textbook() {};
};