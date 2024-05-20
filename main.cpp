#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <random>
#include "HilbertCurve.hpp"

// Function to generate a random color
sf::Color getRandomColor() {
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(0, 255);
    return sf::Color(dist(rng), dist(rng), dist(rng));
}

// Function to create a line with specified thickness
sf::RectangleShape createLine(sf::Vector2f start, sf::Vector2f end, float thickness, sf::Color color) {
    sf::Vector2f direction = end - start;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::RectangleShape line(sf::Vector2f(length, thickness));
    line.setFillColor(color);
    line.setPosition(start);
    line.setRotation(std::atan2(direction.y, direction.x) * 180 / 3.14159);
    return line;
}

int main() {
    int order = 4; // Order of the Hilbert curve
    int width = 512; // Width of the window
    int height = 512; // Height of the window
    int padding = 20; // Padding around the Hilbert curve
    float lineThickness = 3.0f; // Thickness of the lines

    HilbertCurve hilbertCurve(order, width, height, padding); // Create a HilbertCurve object with padding
    auto curve = hilbertCurve.getCurve(); // Get the generated Hilbert curve points

    // Create an SFML window to display the Hilbert curve
    sf::RenderWindow window(sf::VideoMode(width, height), "Hilbert Curve");

    // Generate random colors for each segment
    std::vector<sf::Color> colors;
    for (size_t i = 0; i < curve.size(); ++i) {
        colors.push_back(getRandomColor());
    }

    // Main loop to keep the window open and display the curve
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close the window if the close event is triggered
        }

        window.clear(sf::Color::White); // Clear the window with a white background

        // Draw each segment of the Hilbert curve with a specified thickness
        for (size_t i = 1; i < curve.size(); ++i) {
            sf::Vector2f start(curve[i - 1].first, curve[i - 1].second);
            sf::Vector2f end(curve[i].first, curve[i].second);
            sf::RectangleShape line = createLine(start, end, lineThickness, colors[i]);
            window.draw(line); // Draw the line segment
        }

        window.display(); // Display the window
    }

    return 0;
}
