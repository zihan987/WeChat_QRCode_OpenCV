# Ubuntu 18.0.4

### 安装opencv

1.下载opencv已经opencv-contrib：

```bash
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```

2.安装相关依赖：

```bash
sudo apt-get install cmake build-essential libgtk2.0-dev libavcodec-dev libavformat-dev libjpeg-dev libswscale-dev libtiff5-dev:i386 libtiff5-dev
```

3.编译

```bash
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
WeChat_QRCode time:75.886ms
Number_1: http://weixin.qq.com/r/5zvUzBnEZUQarV2v9271
```

![res.jpg](https://github.com/zihan987/WeChat_QRCode_OpenCV/blob/main/images/res.jpg?raw=true)

