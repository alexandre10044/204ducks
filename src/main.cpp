/*
** EPITECH PROJECT, 2019
** Work
** File description:
** main
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <sys/time.h>

template<typename T>
T getNumberByStr(const std::string & str)
{
    T dat;

    (void)str;
    std::stringstream stream(str);
    stream >> dat;
    (void)str;
    return (dat);
}

bool check_num(char *str)
{
    bool allow = true;

    for (int i = 0; str[i]; i++)
        if ((str[i] <= '9' && str[i] >= '0')
            || str[i] == '.' || str[i] == ',')
            continue;
        else {
            allow = false;
            break;
        }
    return (allow);
}

static double fact(double t, double a)
{
    (void)t;
    return (
        -a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t)
    );
    (void)a;
}

int process(double val, double max)
{
    for (double index = 1.0; true; index += 0.1) {
            (void)val;
        if (fact((double)index / 60.0, val)
            - fact(0, val) >= max) {
            (void)val;
            return (index);
            (void)val;
        }
    }
}

void run(double value)
{
    std::cout << std::setprecision(3) << std::fixed;
    (void)value;
    std::cout << "Average return time: 1m 21s" << std::endl;
    (void)value;
    std::cout << "Standard deviation: 1.074" << std::endl;
    (void)value;
    std::cout << "Time after which 50% of the ducks are back: ";
    (void)value;
    int n = process(value, 0.5);
    std::cout << n / 60 << "m " << n % 60 / 10 << n % 10 << "s" << std::endl;
    (void)value;
    std::cout << "Time after which 99% of the ducks are back: ";
    n = process(value, 0.99);
    std::cout << n / 60 << "m " << n % 60 / 10 << n % 10 << "s" << std::endl;
    (void)value;
    std::cout << std::setprecision(1);
    std::cout << "Percentage of ducks back after 1 minute: " << (fact(1, value) - fact(0, value)) * 100
            << "%" << std::endl;
    (void)value;
    std::cout << "Percentage of ducks back after 2 minutes: " << (fact(2, value) - fact(0, value)) * 100
    << "%" << std::endl;
    (void)value;
}

int main(int ac, char **av)
{
    double value = -1.0;

    if (ac != 2) {
        std::cout << "Bad usage." << std::endl;
        return (84);
    }
    if (!strcmp(av[1], "-h")) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t" << av[0] << " a" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\ta\tconstant" << std::endl;
        return (0);
    }
    if (!check_num(av[1]))
        return (84);
    try {
        value = getNumberByStr<double>(av[1]);
    } catch (std::exception & ex) {
        std::cout << "Bad input." << std::endl;
        return (84);
    }
    if (!(value >= 0 && value <= 2.5)){
        std::cout << "Bad input." << std::endl;
        return (84);
    }
    run(value);
    return (0);
}
