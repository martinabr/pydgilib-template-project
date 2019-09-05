# Beginner Project Template for Pydgilib

## Table of Contents

1. [Requirements](#requirements)
1. [Installation](#installation)
1. [Tutorial](#tutorial)

## Requirements

Windows is required. Linux is optional, but can be used.

In Windows, the following are required:

- [Python 3.7+ 64bit](https://www.python.org/downloads/): Can be installed in `C:\Python37`. *Can be a good idea to add this version of Python to Windows' PATH.*

- [Python 3.7+ 32bit](https://www.python.org/downloads/): Can be installed in `C:\Python37-32\`. *This version of Python should not be added to Windows' PATH.*

- Python `pip` for the Python 3.7+ 64 bit: On Windows it appears as an selectable feature to install during Python's installation, when using the _Customize installation_ option. Make sure it is checked.

- `pipenv`: Can be installed by opening a command line window in Windows and writing `pip install pipenv`.

If using Linux, the following would be required:

- Python 3.7+ 64bit: On Ubuntu, run `sudo apt-get install python3` in the terminal. On ArchLinux, run `sudo pacman -S python3`.

- Python `pip`: On Ubuntu, run `sudo apt-get install python3-pip`. On ArchLinux, run `sudo pacman -S python-pip`.

- `pipenv`: Either on Ubuntu or on ArchLinux, in the terminal, run either `sudo pip install pipenv` or just `pip install pipenv` in the terminal.

Linux does not need to install Python 3.7+ 32bit, since it will not be able to interact with the 32-bit only `dgilib.dll` and connect to the board, in order to do measurements. Therefore, it does not need this variant of Python.

## Installation

In the [Requirements](#requirements) section, you were instructed to install some software packages manually. Now, the rest of the necessary requirements can be installed using the `pipenv` tool.

## Tutorial
