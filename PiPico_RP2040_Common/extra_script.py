Import("env")
import shutil

print("Copying hardware.h")
shutil.copyfile('include/hardware.h', '.pio/libdeps/pico/OGM-Common/include/hardware.h')
print("Copying knxprod.h")
shutil.copyfile('include/knxprod.h', '.pio/libdeps/pico/OGM-Common/include/knxprod.h')
print("Copying KnxHelper.h //just empty for now")
shutil.copyfile('include/KnxHelper.h', '.pio/libdeps/pico/OGM-Common/include/KnxHelper.h')
