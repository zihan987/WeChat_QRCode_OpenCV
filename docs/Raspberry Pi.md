# Raspberry Pi

| 型号 | 4B   |
| ---- | ---- |
| OS   | Lite |
| 内存 | 2G   |

![pi.jpeg](https://github.com/zihan987/WeChat_QRCode_OpenCV/blob/main/images/pi.jpeg?raw=true)

### 安装opencv

1.下载opencv已经opencv-contrib：

```bash
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```

下载慢可以使用sftp的put命令从本地上传到树莓派。

2.安装相关依赖：

```bash
sudo apt-get install  devscripts debhelper cmake libgtkmm-3.0-dev libarchive-dev libcurl4-openssl-dev intltool

sudo apt-get install build-essential cmake pkg-config libjpeg-dev libtiff5-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk2.0-dev libgtk-3-dev libatlas-base-dev libblas-dev libeigen{2,3}-dev liblapack-dev gfortran
```

3.编译

```bash
cd opencv-master
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D INSTALL_C_EXAMPLES=ON \
-D OPENCV_ENABLE_NONFREE=ON \
-D OPENCV_EXTRA_MODULES_PATH= 你的路径/opencv_contrib/modules \
-D BUILD_EXAMPLES=ON ..

make -j4
sudo make install
```

### 运行demo

1.下载本项目：

```bash
git clone https://github.com/zihan987/WeChat_QRCode_OpenCV.git
```

2.编译：

算法模型文件在[models文件夹](https://github.com/zihan987/WeChat_QRCode_OpenCV/tree/main/models)中，需要在demo中替换路径。

```bash
cd WeChat_QRCode_OpenCV
mkdir build && cd build
cmake ..
build
```

3.测试

命令如下：

```
./demo [input_path] [output_path]
```

举例(需要自己选择路径)：

```bash
./demo ../images/achai.jpeg ../images/res/res.jpg
```

结果如下：

```bash
WeChat_QRCode time:183.902ms
Number_1: http://weixin.qq.com/r/5zvUzBnEZUQarV2v9271
```

![res.jpg](https://github.com/zihan987/WeChat_QRCode_OpenCV/blob/main/images/res.jpg?raw=true)

