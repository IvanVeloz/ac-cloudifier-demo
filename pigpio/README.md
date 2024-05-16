## Setting up in Raspberry Pi OS
Install the pigpio package.
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install pigpio
```

Enable the pigpio daemon so that it starts automatically.
```
sudo systemctl enable --now pigpiod
```

This daemon lets us interface with the GPIO in userspace and without root privileges. It's a socket, so remote GPIO is possible through the network (but that is not used for this project).

