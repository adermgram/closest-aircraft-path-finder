# Closest Aircraft Pair Finder

This C++ program finds the closest pair of aircrafts from a given list of aircrafts with their x, y coordinates. It utilizes a divide-and-conquer algorithm to efficiently determine the pair of aircrafts with the shortest distance between them.

## Table of Contents

- [Features](#features)
- [Algorithm](#algorithm)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Features

- Input the number of aircrafts along with their names and (x, y) coordinates.
- Uses an efficient divide-and-conquer algorithm to find the closest pair of aircrafts.
- Outputs the closest distance and the details of the two closest aircrafts.

## Algorithm

The program implements a divide-and-conquer approach to solve the closest pair problem:

1. **Divide**: The list of aircrafts is divided into two halves based on their x-coordinates.
2. **Conquer**: Recursively find the closest pair in both halves.
3. **Combine**: Check for any closer pairs across the dividing line by considering aircrafts near the midpoint within a strip.

This approach reduces the time complexity to **O(n log n)**, which is more efficient than the brute-force O(n²) approach.

## Getting Started

### Prerequisites

- C++ compiler (e.g., `g++`)
- Basic knowledge of C++ and standard libraries like `<vector>`, `<algorithm>`, `<cmath>`

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/adermgram/closest-aircraft-path-finder.git
   cd closest-aircraft-path-finder
   ```
2. Compile the code:
   ```bash
   g++ main.cpp -o closest_aircraft_pair
   ```
## Usage
1. Run the program:
   ```bash
   ./closest_aircraft_pair
   ```
2. Follow the prompts to input the number of aircrafts, their names, and their coordinates.
3. The program will output the closest pair of aircrafts and the distance between them.

## Example
```bash
Enter the number of aircrafts: 3
Enter the x and y coordinates along with names of the aircrafts:
Enter name for aircraft 1: Alpha
Enter x and y for aircraft 1: 1.0 2.0
Enter name for aircraft 2: Bravo
Enter x and y for aircraft 2: 2.0 3.0
Enter name for aircraft 3: Charlie
Enter x and y for aircraft 3: 3.0 1.0

The closest pair distance is 1.41421
The closest aircrafts are (1.0, 2.0) named Alpha and (2.0, 3.0) named Bravo
```
## Contribution
If you'd like to contribute to this project, feel free to fork the repository and submit a pull request. Any contributions or improvements are welcome!

1. Fork the project.
2. Create a new branch (git checkout -b feature/your-feature).
3. Make your changes and commit (git commit -am 'Add some feature').
4. Push to the branch (git push origin feature/your-feature).
5. Open a pull request.
