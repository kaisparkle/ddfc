import threading
import multiprocessing
import serial_read
import matplotlib.pyplot as plot
import matplotlib.animation as animation
import time

# instantiate serial reader
reader = serial_read.SerialReader("COM5")

# BMP plot
fig = plot.figure()
bmp_axis = fig.add_subplot(211)
bmp_x_values = []
bmp_y_values = []

# packet rate plot
packet_axis = fig.add_subplot(212)
packet_x_values = []
packet_y_values = []

start = time.time()


def animate(i, bmp_x_list, bmp_y_list, packet_x_list, packet_y_list):
    # convert millisecond timestamp to seconds for plot
    bmp_x_list.append(time.time())
    bmp_y_list.append(reader.get_bmp_altitude())
    bmp_axis.clear()
    bmp_axis.plot(bmp_x_list, bmp_y_list)
    bmp_axis.set_title("Altitude from Pad over Time")
    bmp_axis.set_xlabel("Time (s)")
    bmp_axis.set_ylabel("Altitude from Pad (m)")

    if reader.get_packet_count() > 0:
        packet_x_list.append(time.time())
        packet_y_list.append(reader.get_packet_count() / (time.time() - start))
        packet_axis.clear()
        packet_axis.plot(packet_x_list, packet_y_list)
        packet_axis.set_title("Packet Rate over Time")
        packet_axis.set_xlabel("Time (s)")
        packet_axis.set_ylabel("Packet Rate (Hz)")


if __name__ == "__main__":
    serial_read_thread = threading.Thread(target=reader.run, daemon=True)
    serial_read_thread.start()

    anim = animation.FuncAnimation(fig=fig, func=animate, fargs=(bmp_x_values, bmp_y_values, packet_x_values,
                                                                 packet_y_values), interval=100, repeat=True)
    plot.show()
