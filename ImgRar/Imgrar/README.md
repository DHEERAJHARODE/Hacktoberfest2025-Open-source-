# ImgRar v1.0

![baseconversion py](https://github.com/Otherwa/Imgrar/assets/67428572/348e23c9-486e-4a58-96fe-f290f1697068)
![convert py](https://github.com/Otherwa/Imgrar/assets/67428572/1ef03222-8e7c-4c17-a3fe-4d32176d7534)


ImgRar is a tool for converting small to medium-sized codes to images and vice-versa. This tool provides a simple command-line interface to perform these conversions.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [Options](#options)
- [Installation](#installation)
- [License](#license)

## Features

- Convert code to PNG image.
- Convert PNG image to code.
- Specify input and output directories.
- Set the frame size for image conversion.

## Requirements

- Python 3.x
- Dependencies listed in `requirements.txt`

## Usage

To use ImgRar, follow these steps:

1. Clone the repository:

   ```
   git clone https://github.com/yourusername/ImgRar.git
   ```

2. Navigate to the project directory:

   ```
   cd ImgRar
   ```

3. Install the required dependencies:

   ```
   pip install -r requirements.txt
   ```

4. Run the ImgRar tool:
   ```
   python img_rar.py [options]
   ```

## Options

- `-output`, `--Output`: Set the output directory.
- `-input`, `--Input`: Set the input directory.
- `-code2png`, `--Code2Png`: Convert from code to PNG image.
- `-png2code`, `--Png2Code`: Convert from PNG image to code.
- `-fsize`, `--fsize`: Set the frame size.

Example usages:

- To convert code to PNG image:

  ```
  python img_rar.py -input [./input_dir] -output [./output_dir] -code2png [1|true] -fsize [256|num]
  ```

- To convert PNG image to code:
  ```
  python img_rar.py -input input_dir -output output_dir -png2code
  ```

## Installation

You can install this tool by cloning the GitHub repository and installing the required dependencies as mentioned in the [Usage](#usage) section.

## License

This project is licensed under the XYZ License - see the [LICENSE.md](LICENSE.md) file for details.

Feel free to fork and contribute to this project. If you encounter any issues or have suggestions, please open an issue on GitHub.
