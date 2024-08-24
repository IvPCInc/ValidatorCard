#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string card_Number;
    setlocale(LC_ALL, "Russian");
    while (true) {

        cout << "Пожалуйста, введите номер кредитной карты для проверки: ";
        cin >> card_Number;

        if (card_Number == "Выход")
            break;

        else if (!isNumberString(card_Number)) {
            cout << "Неверный ввод! ";
            continue;
        }

        int len = card_Number.length();
        int doubleEvenSum = 0;

        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((card_Number[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }


        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (card_Number[i] - 48);
        }

        cout << (doubleEvenSum % 10 == 0 ? "ДЕЙСТВИТЕЛЬНЫЙ !" : "НЕДЕЙСТВИТЕЛЬНЫЙ !") << endl;

        continue;
    }

    return 0;
}