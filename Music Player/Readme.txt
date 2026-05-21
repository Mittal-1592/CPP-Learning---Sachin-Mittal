g++ main.cpp src/*.cpp -Iinclude -o prog -lsfml-audio -lsfml-system

ffmpeg -i song.mp3 song.wav


g++ tests/*.cpp src/*.cpp -Iinclude -lgtest -lgtest_main -lgmock -lsfml-audio -lsfml-system -o runTests