#include <iostream>
using namespace std;

class mnog{
private:
    double *m;
    int msize, size;
public:
    mnog(int ms){
        this -> msize = ms;
        m = new double [ms];
        size = 0;
    }

    ~mnog(){
        delete [] this -> m;
    }

    void add(){
        if (this -> size < this -> msize){
            cout << "Enter an item: ";
            cin >> m[this -> size];
            this -> size++;
            cout << "Item added" << endl;
        }
        else{
            cout << "A lot of it is crowded" << endl;
        }
    }

    void coutMn(){
        for (int i = 0; i < this-> size; i++){
            cout << m[i] << " ";
        }
        cout << endl << "Many were withdrawn" << endl;
    }

    void remove(){
        int a = 0;
        while (a > size || a < 1){
            cout << "Enter an item: ";
            cin >> a;
        }
        for (int i = a; i < size; i++){
            m[a] = m[a+1];
        }
        m[size] = NULL;
        size--;
        cout << "Item removed";
    }

    mnog operator+(const mnog &R){
        int k = size + R.size;
        int r = 0;
        mnog mnogestvo3(k);
        for (int i = 0; i < size; i++){
            mnogestvo3.m[i] = m[r];
            r++;
        }
        for (int i = size; i < k; i++){
            mnogestvo3.m[i] = R.m[i - size];
            r++;
        }
        mnogestvo3.size = r;
        return mnogestvo3;
    }

    mnog(const mnog &R){
        this->size = R.size;
        this -> msize = R.msize;
        m = new double [msize];
        for(int i = 0; i<msize; i++){
            m[i] = R.m[i];
        }
    }

    mnog& operator=(const mnog &R){
        if(this == &R){
            return *this;
        }
        if(msize != R.msize){
            delete []m;
            m = new double[R.msize];
            size = 0;
            msize = R.msize;
        }
        for(int i = 0; i < msize; i++){
            m[i] = R.m[i];
        }
        size = R.size;
        return *this;
    }

};

int main ( ){
    int size1 = 0, size2 = 0, t = 0, first = 0, second = 0, number = 0;
    bool k = true;
    cout << "Enter the size of the first set: ";
    cin >> size1;
    cout << "Enter the size of the second set: ";
    cin >> size2;
    mnog mnogestvo1(size1);
    mnog mnogestvo2(size2);
    mnog mnogestvo3(size1+size2);
    while (k) {
        cout << "Menu" << endl;
        cout << "1: add" << endl;
        cout << "2: cout" << endl;
        cout << "3: remove" << endl;
        cout << "4: +" << endl;
        cout << "5: Exit" << endl;
        cout << "Enter the number" << endl;
        cin >> number;
        system("cls");
        switch (number){
            case 1:
                t = 0;
                while (t < 1 || t > 2){
                    cout << "How many will you work with (1 or 2)?";
                    cin >> t;
                }
                if (t == 1){
                    mnogestvo1.add();
                    first++;
                }
                else{
                    mnogestvo2.add();
                    second++;
                }
                break;
            case 2:
                t = 0;
                if (first !=0 || second !=0){
                    while (t < 1 || t > 2){
                        cout << "How many will you work with (1 or 2)?";
                        cin >> t;
                    }
                    if (t == 1){
                        if (first > 0){
                            mnogestvo1.coutMn();
                        }
                        else cout << "Set 1 is empty!";
                    }
                    else{
                        if (second > 0){
                            mnogestvo2.coutMn();
                        }
                        else cout << "Set 2 is empty!";
                    }
                }
                break;
            case 3:
                t = 0;
                if (first !=0 || second !=0){
                    while (t < 1 || t > 2){
                        cout << "How many will you work with (1 or 2)?";
                        cin >> t;
                    }
                    if (t == 1){
                        if (first > 0){
                            mnogestvo1.remove();
                            first--;
                        }
                        else cout << "Set 1 is empty!";
                    }
                    else{
                        if (second > 0){
                            mnogestvo2.remove();
                            second--;
                        }
                        else cout << "Set 2 is empty!";
                    }
                }
                break;
            case 4:
                if (first !=0 && second !=0){
                    mnogestvo3 = mnogestvo1 + mnogestvo2;
                    mnogestvo3.coutMn();
                }
                else{
                    cout << "Set is empty!";
                }
                break;
            case 5:
                k = false;
                break;
        }
    }
    system ("pause");
    return 0;
}