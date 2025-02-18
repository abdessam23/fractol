Fractol

Fractol is a graphical program that generates and visualizes fractals based on mathematical equations. This project allows you to explore complex shapes and intricate designs while gaining an understanding of graphics programming, algorithms, and mathematical concepts.

Features

Mandelbrot Set: Generates and visualizes the Mandelbrot set, an iconic fractal.
Julia Set: Allows you to generate the Julia set fractal with interactive zoom and color features.
Burning Ship: A unique fractal with sharp, ship-like formations, generated with the Burning Ship algorithm (bonus feature).
Interactive Controls: Zoom in/out and move around the fractals with mouse events.
Coloring Schemes: Multiple coloring options to enhance the visuals and explore different patterns.
Requirements
To run Fractol, you’ll need to have the following installed:

Operating System: Linux (macOS or Windows with WSL recommended)
Graphics Library: MinilibX (used to interface with graphics)
Compiling Tool: Make

Installation

Clone the repository:

git clone https://github.com/abdessam23/fractol.git
Navigate to the project directory:


cd fractol

Compile the project using Make:


make

Run the program:

./fractol

Usage
Upon running the program, the initial fractal (e.g., Mandelbrot) will be displayed.
Use the mouse scroll wheel to zoom in or out on the fractal.
Click and drag to move around the fractal view.
Controls
Zoom: Mouse scroll wheel or arrow keys
Move: Click and drag
Exit: Press Esc or close the window
Bonus Feature: Burning Ship
The Burning Ship fractal is a variation of the Mandelbrot set, but with a distinctive ship-like shape that is created by mirroring the equation for complex numbers. It’s a beautiful and unique fractal that adds complexity to the program, providing another exciting visual experience.

To view the Burning Ship fractal, press the B key after starting the program.

Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit a pull request. Please make sure to follow the coding standards and keep your code clean and well-documented.


Guidelines:

Ensure your code works correctly by testing it before submitting.
Provide a brief description of any changes you make.
Follow good coding practices and documentation.

License

This project is open-source and available under the MIT License.

Acknowledgements

MinilibX: For the graphics library that makes rendering the fractals possible.
Math Concepts: For the fascinating world of fractals and complex numbers that inspired this project.
