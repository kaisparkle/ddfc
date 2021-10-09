import threading
import multiprocessing
import serial_read
import matplotlib.pyplot as plot
import matplotlib.animation as animation

# instantiate serial reader
reader = serial_read.SerialReader("/dev/ttyACM0")

# BMP plot
bmp_fig = plot.figure()
axis = bmp_fig.add_subplot(1, 1, 1)
x_values = []
y_values = []


def bmp_animate(i, x_list, y_list):
    # convert millisecond timestamp to seconds for plot
    x_list.append(reader.get_bmp_timestamp() / 1000)
    y_list.append(reader.get_bmp_pressure())

    x_list = x_list[-500:]
    y_list = y_list[-500:]

    axis.clear()
    axis.plot(x_list, y_list)

    plot.xticks(rotation=45, ha="right")
    plot.subplots_adjust(bottom=0.30)
    plot.title("BMP180 Pressure over Time Since Execution")
    plot.ylabel("Pressure (Pa)")


if __name__ == "__main__":
    serial_read_thread = threading.Thread(target=reader.run, daemon=True)
    serial_read_thread.start()

    anim = animation.FuncAnimation(fig=bmp_fig, func=bmp_animate, fargs=(x_values, y_values), interval=100, repeat=True)
    plot.show()
