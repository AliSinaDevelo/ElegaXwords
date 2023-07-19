# ElegaXWords - Crossword Generator App

ElegaXWords is a command-line crossword generator app that allows you to create elegant crosswords from a given set of words. Whether you want to challenge your friends or create crosswords for fun, ElegaXWords has got you covered!

## Table of Contents
1. [Features](#features)
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Sample Data](#sample-data)
6. [Contributing](#contributing)
7. [License](#license)

## Features
- Input words: Choose from manual input or read words from a file.
- Crossword grid size: Specify the size of the crossword grid to fit your desired layout.
- Solution display: Option to display or hide the solution of the generated crossword.
- Save to file: Save the generated crossword to a file for future reference.
- Interactive CLI menu: User-friendly interface to guide you through the crossword generation process.
- Error handling: Graceful handling of invalid inputs and edge cases.

## Requirements
- C compiler (GCC or Clang recommended)
- Make (optional, for automated build)
- Terminal or command prompt

## Installation
1. Clone the repository:
    git clone https://github.com/AliSinaDevelo/ElegaXWords.git
    cd ElegaXWords

2. Compile the program (if you have Make):
    make
If you don't have Make, manually compile with GCC or Clang:
    gcc -o ElegaXWords src/main.c src/crossword.c -I include


## Usage
1. Run the program:
    ./ElegaXWords


2. Follow the on-screen instructions to generate your crossword:
- Choose manual input or input from a file.
- Specify the grid size (rows x columns) for the crossword.
- Review the generated crossword.
- Choose to display or hide the solution.
- Optionally save the crossword to a file.

## Sample Data
In the `data/` folder, you'll find some sample data files for testing the app. You can use these files to see how the crossword generator works with different word sets.

## Contributing
Contributions to ElegaXWords are welcome! If you find any issues or have ideas for improvements, feel free to open an issue or submit a pull request.

## License
ElegaXWords is open-source software licensed under the [MIT License](LICENSE).

Enjoy creating elegant crosswords with ElegaXWords!

