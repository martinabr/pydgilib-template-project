from pydgilib_extra import DGILibExtra, LOGGER_PLOT, LOGGER_CSV, LOGGER_OBJECT
import os
from matplotlib import pyplot as plt

def wait_for_plot(fig):
    if platform == "linux" or platform == "linux2":
        while plt.fignum_exists(fig.number):
            plt.pause(0.000001)

dgilib_config = {
    "loggers" : [
        LOGGER_OBJECT,
        LOGGER_CSV,
        LOGGER_PLOT
    ],
    "plot_pins_colors": ["red", "yellow", "blue", "green"]
}

with DGILibExtra(**dgilib_config) as dgilib:
    dgilib.device_reset()
    data = dgilib.logger.log(10) # Afterwards, can process data in RAM

    plt.show(block=True) # Block figure from closing at the end of the script