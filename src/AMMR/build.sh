source_dir=$PWD


cd $source_dir/
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j6

cd $source_dir/
