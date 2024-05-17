
# Setting up in Raspberry Pi OS
Install OpenCV:
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libopencv-dev gstreamer1.0-opencv cmake
```

## Miscellaneous
On Raspberry Pi OS, to stream the video camera outside OpenCV (useful for testing):
```
sudo apt-get install vlc-bin 
libcamera-vid -t 2 --inline -o - | cvlc stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8000/}' :demux=h264
```
