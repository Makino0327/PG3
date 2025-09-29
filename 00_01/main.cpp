#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);            
    const char* str = u8"あいうえお";     
    printf("%s\n", str);                  
    return 0;
}
