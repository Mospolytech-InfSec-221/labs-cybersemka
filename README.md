# labs-cybersemka
labs-cybersemka created by GitHub Classroom
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main()  
{  
    cout << "Kishiev Seymur, 221-353" << endl;  
    cout << "min int = " << (int)0b10000000000000000000000000000000 << ", max int = " << (int)0b01111111111111111111111111111111 << ", size of int = " << sizeof(int) << endl;  
    cout << "min unsigned int = " << (unsigned int)0 << ", max unsigned int = " << (unsigned int)0b11111111111111111111111111111111 << ", size of unsigned int = " << sizeof(unsigned int) << endl;  
    cout << "min short = " << (short)0b1000000000000000 << ", max short = " << (short)0b0111111111111111 << ", size of short = " << sizeof(short) << endl;  
    cout << "min unsigned short = " << (unsigned short)0 << ", max unsigned short = " << (unsigned short)0b1111111111111111 << ", size of unsigned short = " << sizeof(unsigned short) << endl;  
    cout << "min long = " << (long)0b10000000000000000000000000000000 << ", max long = " << (long)0b01111111111111111111111111111111 << ", size of long = " << sizeof(long) << endl;  
    cout << "min long long = " << (long long)0b1000000000000000000000000000000000000000000000000000000000000000 << ", max long long = " << (long long)0b0111111111111111111111111111111111111111111111111111111111111111 << ", size of long long = " << sizeof(long long) << endl;  
    cout << "min double = -" << (double)0b1000000000000000000000000000000000000000000000000000000000000000 << ", max double = " << (double)0b0111111111111111111111111111111111111111111111111111111111111111 << ", size of double = " << sizeof(double) << endl;  
    cout << "min char = " << (char)0b10000000 << ", max char = " << (char)0b01111111 << ", size of char = " << sizeof(char) << endl;  
    cout << "min bool = " << (bool)0 << ", max bool = " << (bool)0b01111111 << ", size of bool = " << sizeof(bool) << endl << endl;  
  
    int n;  
    cout << "Enter the number: ";  
    cin >> n;  
  
    cout << "bin: " << bitset<sizeof(int) * 8>(n) << endl;  
    cout << "bool: " << (bool)n << endl;  
    cout << "double: " << (double)n << endl;  
    cout << "char: " << (char)n << endl;  
  
  
    cout << "coefficient (a and  b):" << endl;  
    int a, b;  
    double q;  
    cin >> a >> b;  
    cout << a << "*x=" << b << endl;  
    cout << "x=" << b << "/" << a << endl;  
    cout << "x=" << b / a << endl;  
    q = double(b) / double(a);  
    cout << "Answer: " << q << endl;  
  
    cout << "Enter the numbers:" << endl;  
    int x, y;  
    cin >> x >> y;  
    double z;  
    z = ((y - x) / 2.) + x;  
    cout << "middle = " << z << endl;  
  
  
}
