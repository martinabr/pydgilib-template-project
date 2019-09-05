from pydgilib_extra import DGILibExtra, LOGGER_PLOT, LOGGER_CSV

with DGILibExtra(loggers=[LOGGER_PLOT, LOGGER_CSV]) as dgilib:
    dgilib.device_reset()
    dgilib.logger.log(10)
