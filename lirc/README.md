## Setting up LIRC in Raspberry Pi OS

To set up LIRC and be able to run the code in this demo, follow these steps.

Install the `lirc` package.
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install lirc
```

Configure the device tree overlay, by editing `/boot/config.txt` and adding this line:
```
# Uncomment this to enable infrared communication.
dtoverlay=gpio-ir,gpio_pin=17
dtoverlay=gpio-ir-tx,gpio_pin=18
```
The order in which these two devices are added to the config file will affect the numbering for the device files (that is `/dev/lirc0`, `/dev/lirc1`, etc.).

Now we need to edit the LIRC daemon optiones file to use the default driver, and point it to the correct `lirc` device:
```
sudo nano /etc/lirc/lirc_options.conf
```
Change the `driver` and `device` lines to the following:
```
driver          = default
device          = /dev/lirc0
```

Add yourself to the `video` group and reboot to apply all changes.
```
sudo usermod -aG video $USER
sudo reboot
```

At this point, you can record your own remote with `irrecord` using the instructions provided on the [LIRC documentation](https://www.lirc.org/html/irrecord.html). If you are using my exact air conditioner model, skip this.
```
irrecord --device=/dev/lirc1 --disable-namespace
```

It is preferable to use standard namespaces but it's probable that your AC remote control does not conform to the standard namespace. In that case, use `--disable-namespace`. Note that the driver creates two devices, `/dev/lirc0` and `/dev/lirc1`. One is the transmitter, the other is the receiver. You will need to determine which device is the correct one for recording (the one that doesn't error out).

The recordings for the remote used in the project are provided on the `GE-AHP05LZQ2.lircd.conf` file. Copy this configuration file to the LIRC configuration directory and restart LIRC so it can grab the new config file:
```
sudo cp GE-AHP05LZQ2.lircd.conf /etc/lirc/lircd.conf.d/
sudo systemctl restart lircd
```

Now try sending remote commands with `irsend`, for example, to press the power button:
```
list   ""    ""  # list all configured remote names
irsend list "GE-AHP05LZQ2" "" # list all the commands for the GE remote we are using
irsend -d /dev/lirc0 send_once GE-AHP05LZQ2 KEY_POWER
```

If sending the command fails (if you get `irsend: hardware does not support sending`), try changing lircd to point to the other `lirc` device.
