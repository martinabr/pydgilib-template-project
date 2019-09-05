Beginner Project Template for Pydgilib
======================================

1. Requirements & Installation
2. Folder setup


2. Folder setup
---------------
The "Experiments" folder is a folder where its contents be able to be used on Windows only. That is because in this folder goes Python scripts / Jupyter Notebooks that will use the dgilib.dll in order to interact with the board, transmit and/or obtain data, measure power and reset the board at the start and/or whenever needed (the former two needing the DGI interface offered by the dgilib.dll and the Pydgilib library).

The "Plots" folder is a folder which its contents can be used either on Windows or on Linux and/or Mac OS as well. In it goes Python scripts / Jupyter Notebooks that will not use the dgilib.dll file. However, Pydgilib can be optionally imported, as long as it does not try and do commands to the board for measurement or reset. Otherwise, in this folder you can openly write anything to interpret and plot the data obtained from the scripts / notebooks executed from the "Experiments" folder.

TODO
----
- Expose color selection for gpio pins
- Keep plot window from closing
- Expose delay setting

- LED test
- serial test
- Requirements
- Fix title of plot


