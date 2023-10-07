Import("env")
import shutil

print("Copying hardware.h")
shutil.copyfile('include/hardware.h', '.pio/libdeps/pico/OGM-Common/include/hardware.h')
print("Copying knxprod.h")
shutil.copyfile('include/knxprod.h', '.pio/libdeps/pico/OGM-Common/include/knxprod.h')
print("Copying versions.h")
shutil.copyfile('include/versions.h', '.pio/libdeps/pico/OGM-Common/include/versions.h')