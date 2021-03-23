#include <Objects/brush.hpp>
#include <iostream>


// Set brush color
void Brush::setBrushColor(sf::Color color)
{

    brushColor = color;
    
}


// Set layer content
void Brush::setLayer(Layer* _layer)
{

    layer = _layer;
    
}

// Edit layer content
void Brush::editLayer(bool isFocused, sf::RenderWindow* renderer)
{
    
    // Erase brush selected
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && isFocused && state != 0)
    {
        sf::Vector2f position = renderer->mapPixelToCoords(sf::Mouse::getPosition(*renderer));
        layer->setPixel(position.x, position.y, sf::Color(0, 0, 0, 0));
    }
    
    // Pen brush selected
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isFocused && state == 2)
    {
        sf::Vector2f position = renderer->mapPixelToCoords(sf::Mouse::getPosition(*renderer));
        layer->setPixel(position.x, position.y, brushColor);
    }
    
}

// Return whether the current brush selected moves the camera
bool Brush::isMovable()
{
    return state == 0;
}
