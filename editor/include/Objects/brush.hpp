#pragma once
#include <SFML/Graphics.hpp>
#include <Objects/layer.hpp>


/* Brush types:
    Right mouse button -> "Eraser"       delete layer content
    0                  -> "Normal"           translate camera
    2                  -> "Pen"           simple square brush
    3                  -> "Pencil"  simple circle shape brush
*/

class Brush
{
    
    private:
        
        // Brush configuration
        int state = 0;
        int brushSize = 1;
        sf::Color brushColor;
        
        // Current layer content
        Layer* layer;
        
    
    public:
        
        // Brush default constructor
        Brush() {};
        
        
        // Set brush color
        void setBrushColor(sf::Color color);
        
        
        // Set layer content
        void setLayer(Layer* layer);
        
        // Edit layer content
        void editLayer(bool isFocused, sf::RenderWindow* renderer);
        
        // Return whether the current brush selected moves the camera
        bool isMovable();
    
};

