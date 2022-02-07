#include<iostream>
#include<chrono>

class Stopwatch {
public:
    void start() {
        std::cout << "Start #" << i << std::endl;
        if(i==0) {
            start1 = std::chrono::steady_clock::now();
        }
    }
    void stop() {
        std::cout << "Stop #" << i++ << std::endl;
        stop1 = std::chrono::steady_clock::now();
    }
    void print() {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
        std::cout << "Sum = " << elapsed.count() << std::endl;
    }
private:
    int i{0};
    std::chrono::steady_clock::time_point start1{std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point stop1{std::chrono::steady_clock::now()};
};

int main()
{
    Stopwatch myWatch;
    myWatch.start();
    int c{0};
    for(int i=0; i<100000000; ++i) {
        c+=1;
    }
    myWatch.stop();

    myWatch.start();
    for(int i=0; i<100000000; ++i) {
        c+=1;
    }
    myWatch.stop();
    myWatch.print();

    return 0;
}









