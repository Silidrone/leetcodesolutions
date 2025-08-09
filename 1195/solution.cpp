class FizzBuzz {
private:
    int n, curr = 1;
    std::mutex m;
    std::condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        std::unique_lock<std::mutex> lock(m);
        while(curr <= n) {
            cv.wait(lock, [&]() { return curr > n || (curr % 3 == 0 && curr % 5 != 0); });
            if(curr > n) break;

            printFizz();
            curr++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        std::unique_lock<std::mutex> lock(m);
        while(curr <= n) {
            cv.wait(lock, [&]() { return curr > n || (curr % 3 != 0 && curr % 5 == 0); });
            if(curr > n) break;

            printBuzz();
            curr++;
            cv.notify_all();
        }
    }


    // printBuzz() outputs "buzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        std::unique_lock<std::mutex> lock(m);
        while(curr <= n) {
            cv.wait(lock, [&]() { return curr > n || (curr % 3 == 0 && curr % 5 == 0); });
            if(curr > n) break;

            printFizzBuzz();
            curr++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(m);
        while(curr <= n) {
            cv.wait(lock, [&]() { return curr > n || (curr % 3 != 0 && curr % 5 != 0); });
            if(curr > n) break;

            printNumber(curr);
            curr++;
            cv.notify_all();
        }
    }
};
