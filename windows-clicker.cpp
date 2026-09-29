#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int delayMs;
    cout << "Введи задержку между кликами (в миллисекундах): ";
    cin >> delayMs;

    cout << "\nКликер готов!" << endl;
    cout << "Нажми 'X' (английскую) для СТАРТА / ПАУЗЫ." << endl;
    cout << "Нажми 'Esc' для ВЫХОДА.\n" << endl;

    bool isClicking = false;

    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE)) {
            cout << "Выход..." << endl;
            break;
        }

        if (GetAsyncKeyState(0x58) & 1) {
            isClicking = !isClicking;
            
            if (isClicking) cout << "КЛИКАЮ..." << endl;
            else cout << "ПАУЗА." << endl;
        }

        if (isClicking) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            
            Sleep(delayMs); 
        } else {
            Sleep(10); // 
        }
    }

    return 0;
}