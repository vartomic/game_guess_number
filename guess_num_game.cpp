#include <iostream>
#include <random>
#include <vector>

using namespace std;

void guess_num(){
    vector<int> vec;   
    int maximum;

    //ввод максимального значения диапазона
    cout << "Enter max value: ";
    cin >> maximum;

    //проверка на корректный ввод
    while (cin.fail()){
        cout << "You're input was not a number \n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    //формирование случайного числа
    random_device rnd;
    mt19937 engine(rnd());
    uniform_int_distribution<mt19937::result_type> uid(1, maximum);
    int val = uid(engine);

    //бесконечный цикл
    while(true){
        int num;        
        cout << "Enter number: ";
        cin >> num;

        //если попытка ввода больше максимума = ошибка
        if (num > maximum) {
            cout << "Error! Number was greater than maximum \n";
            cin.clear();
            cin.ignore(100, '\n');
        }
        //если число, оно переносится в вектор
        else if (num){
            vec.push_back(num); 

            //проверка числа на соответствие загаданному
            if (num == val){
            cout <<"You guessed right!  \n";
            break;
            }
            else if (num < val){
                cout <<"Number should be greater \n";
            }
            else if (num > val){
                cout <<"Number should be smaller \n";
            }
        }  

        while (cin.fail()){
            cout << "You're input was not a number \n";
            cin.clear();
            cin.ignore(100, '\n');
        }        
    }

    //вывод вектора
    cout <<"All tries: "; 
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //вывод размера вектора
    cout <<"Size of vector: " << vec.size() << "\n";

    //вывод вместимости вектора
    cout <<"Capacity of vector: " << vec.capacity() << "\n";
}

int main(){
    guess_num();
}