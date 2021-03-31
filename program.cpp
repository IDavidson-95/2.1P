#include "splashkit.h"

#include <string>
using namespace std;

#define STROUHAL 0.33

double air_speed(double freq, double amp)
{
    double result;
    result = freq * amp / STROUHAL;
    return result;
}

void output_air_speed(string name, double freq, double amp)
{
    write(name + ": ");
    write_line(air_speed(freq, amp));
}

// Reads user input and stores it in result.
string read_string(string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

double read_double(string prompt)
{
    string input;
    input = read_string(prompt);
    return convert_to_double(input);
}




// Asks for user weight and converts string to integer.
int bmi_weight(string prompt)
{
    string bmi_weight_input;
    bmi_weight_input = read_string(prompt);
    return convert_to_integer(bmi_weight_input);
}


// Asks for user height and converts string to double.
double bmi_height(string prompt)
{
    string bmi_height_input;
    bmi_height_input = read_string(prompt);
    return convert_to_double(bmi_height_input);
}


int main()
{
    string name;
    int age;
    

    int weight;
    double height;
    int bmi;


    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");


    // Ask for user input but does not store as
    // a variable as we are not outputting it anywhere.
    read_double("What is the value of pi: ");


    // Asks for user input and stores answer in appropriate
    // variable.
    weight = bmi_weight("How much do you weigh in kg: ");
    height = bmi_height("How tall are you in metres: ");


    // Takes stored weight and height variables and calculates
    // BMI, storing the calculation in variable bmi.
    bmi = (weight) / (height * height);    


    write_line(name);
    write("Age ");
    write_line(age);

    output_air_speed("African Swallow", 15, 0.21);
    output_air_speed("European Swallow", 14, 0.22); 
    output_air_speed("Golden Dragon", 0.75, 50);

    write("Your BMI is: ");
    write_line(bmi);
    
}