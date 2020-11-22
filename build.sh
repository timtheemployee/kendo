if [ -d "build" ]
then
    echo "Build directory exists, deleting..."
    rm -rf build
else
    echo "Build directory not exists, creating new one..."
fi

mkdir build
cd build
cmake ..
make
cd desktop
./desktop
