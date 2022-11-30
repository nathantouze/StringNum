rm -rf build
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build .
cp ./Debug/StringNum ../