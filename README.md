# Beginner Template Project for Pydgilib

## Table of Contents

1. [Requirements](#requirements)
2. [Installation](#installation)
3. [Tutorial](#tutorial)
4. [Folder structure](#folder-structure)
5. [Collaboration tools](#collaboration-tools)

## Requirements

Windows is required. Linux is optional, but can be used.

In Windows, the following are required:

- [Python 3.7+ 64-bit](https://www.python.org/downloads/): Can be installed in
  `C:\Python37`. _Can be a good idea to add this version of Python to Windows'
  PATH._

- [Python 3.7+ 32-bit](https://www.python.org/downloads/): Can be installed in
  `C:\Python37-32\`. _This version of Python should not be added to Windows'
  PATH._

- Python `pip` for the Python 3.7+ 64 bit: On Windows it appears as an
  selectable feature to install during Python's installation, when using the
  _Customize installation_ option. Make sure it is checked.

- `pipenv`: Can be installed by opening a command line window in Windows and
  writing `pip install pipenv`.

If using Linux, the following would be required:

- Python 3.7+ 64-bit: On Ubuntu, run `sudo apt-get install python3` in the
  terminal. On ArchLinux, run `sudo pacman -S python3`.

- Python `pip`: On Ubuntu, run `sudo apt-get install python3-pip`. On
  ArchLinux, run `sudo pacman -S python-pip`.

- `pipenv`: Either on Ubuntu or on ArchLinux, in the terminal, run
  either `sudo pip install pipenv` or just `pip install pipenv` in the terminal.

Linux does not need to install Python 3.7+ 32-bit. It is not be able to interact
with the 32-bit only `dgilib.dll` and connect to the board, in order to do
measurements. Therefore, it does not need this variant of Python.

## Installation

In the [Requirements](#requirements) section, you were instructed to install
some software packages manually. Now, the rest of the necessary requirements
can be installed using the `pipenv` tool. However, some extra commands are
needed before everything becomes easy. There will be two `pipenv`
environments, one that will use the 32-bit Python and one that will use
the 64-bit Python.

Considering `.` is the location of the cloned repo, then:

- On Windows:

  - Open the command line.
      
     - _Optionally:_ You can use
    `open_cmd_administrator.cmd` at the root of the folder in order to open
    a command line with administrator privileges.

  - Go to `./Python/Experiments`.

    - Write either `C:` or `D:` or otherwise, being the drive letter
      where your cloned repo is stored.

    - Then navigate to the folder using the `cd` command.

  - Run `pipenv install --python C:\Python36-32\python.exe` where `pipenv

## Tutorial

## Folder structure

The reason the Python scripts are put in separate folders is because some of
them will use the 32-bit Python only, to interact with `dgilib.dll` (which
comes only in 32-bit format), and the others will use 64-bit Python to overcome
a well known limitation of 2GB of RAM only being able to be used by 32-bit
applications in both Windows and Linux ([^1] [^2]).

There are `Pipfile`-s in both folders to ease the installation of the two
different Python versions of different architectures.

[^1] https://en.wikipedia.org/wiki/2_GB_limit

[^2] https://docs.microsoft.com/en-us/windows/win32/memory/memory-limits-for-windows-releases

## Collaboration tools

- [Barrier](https://github.com/debauchee/barrier)
- [SyncTrayzor](https://github.com/canton7/SyncTrayzor) for Windows /
  [Syncthing](https://syncthing.net/) for Linux

## TODO

**Project itself**

- [ ] Expose color selection for gpio pins

- [ ] Keep plot window from closing

- [ ] Expose delay setting

- [ ] LED test

- [ ] Serial test

**Library**

- [ ] Fix title of plot

**README**

- [x] Write [Requirements](#requirements)
