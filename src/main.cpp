#include <SFML/Window.hpp>
#include "Calculate.h"

#include <iostream>
#include <string>

int main()
{
    Calculate calc;
    std::string expression = "";
    std::string input;
    bool haveResult = false;

    while (!haveResult)
    {
        std::cout << "Amend string with (or press leave blank to compute):" << std::endl;
        std::getline(std::cin, input);

        expression += input;
        std::cout << expression << std::endl;

        if (input.empty())
        {
            haveResult = true;
            std::cout << "Empty input. Exiting loop." << std::endl;
        }
    }

    float result = calc.process(expression); // call the method
    std::cout << result << std::endl;

    return 0;
}

/*
int main()
{
    sf::Window window(sf::VideoMode({300, 600}), "My window");
    Calculate calculator;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();

            render();
            processInput();
        }
    }
}


void render()
{

}

void processInput()
{

}

*/