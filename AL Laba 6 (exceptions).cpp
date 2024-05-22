#include <iostream>
using namespace std;

class Fibonacci_sequence {
    int *sequence;
    int length;
public:
    Fibonacci_sequence(int array[]) {
        length = sizeof(array);
        sequence = array;
        if (!this->test()) {
            throw Fibonacci_sequence_exception(array);
        }
    }
    bool test() {
        if (sequence[0] == 0 and sequence[1] == 1) {
            for (int i = 2; i < sizeof(sequence); i++) {
                if (not(sequence[i] == sequence[i - 1] + sequence[i - 2])) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    void print() {
        cout << "Length = " << length << endl << "Sequence: ";
        for (int i = 0; i < sizeof(sequence); i++) {
            cout << sequence[i] << " ";
        }
        cout << endl;
    }
};

class Fibonacci_sequence_exception: public invalid_argument{
    int* sequence;
    int length;
public:
    Fibonacci_sequence_exception(int array[]): invalid_argument("The array is not a Fibonacci sequence!") {
        length = sizeof(array);
        sequence = array;
    };
    void print() {
        cout << "Length = " << length << endl << "Sequence: ";
        for (int i = 0; i < sizeof(sequence); i++) {
            cout << sequence[i] << " ";
        }
        cout << endl;
    }
    /*const char* what() const noexcept override {
        return "The array is not a Fibonacci sequence!";
    }*/
};

int main() {
    int good_array[] = {0, 1, 1, 2, 3, 5, 8};
    try {
        Fibonacci_sequence good_sequence(good_array);
    }
    catch (Fibonacci_sequence_exception exception) {
        cout << "Exception: " << exception.what() << endl;
        exception.print();
    }

    int bad_array[] = {0, 1, 1, 3, 3, 5, 8};
    try {
        Fibonacci_sequence bad_sequence(bad_array);
    }
    catch (Fibonacci_sequence_exception exception) {
        cout << "Exception: " << exception.what() << endl;
        exception.print();
    }
}
