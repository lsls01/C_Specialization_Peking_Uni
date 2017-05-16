Class and Object
=
Default Method
-
```
class cellphone{
    cellphone();
    ~cellphone();
    // can be copied
    cellphone(const cellphone&);
    cellphone & operator=(const cellphone&);
    // can get address
    cellphone * operator&();
    const cellphone* operator&() const;
```
template method
-
```
template<class T>
void print(const T array[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << array[i];
        return;
}
int a[10];
print(a, 10);
```
template class
-
```
template<class T>
class Carray{
    T *ptrElement;
    int size;
    public:
    Carray(int length);
    ~ Carray();
    int len();
    void setElement(T arg, int index);
    T getElement(int index);
};
Carray<int> arrayInt(50), *ptrArrayInt;
```
Standard input stream
-
```
cin >> x;
cin.getline(str, len, ch);  // ch will not be stored into standard in stream
ch = cin.get(); // get one character
cin.ignore(len, ch);    // ignore some character
```
Judge an end of input
```
int x;
while (cin >> x) {
    ......
}
return 0;
```
This block will stop when interrupted by Ctrl-z, or reach the end of a file.

Standard output stream
-
```
cout.put('A').put('a');
int n = 10;
cout << n << endl;
cout << hex << n << endl;
cout << dec << n << endl;
cout << oct << n << endl;
#include <iomanip>
double x = 1234567.89, y = 12.34567;
int n = 1234567;
int m = 12;
cout << setprecision(6) << x << endl
     << y << endl << n << endl << m;
cout << setiosflags(ios:fixed) << setprecision(6) << x << endl 
     << y << endl << n << endl << m;
```
Set field width
```
cin.width(5);
cin >> string;
cout << string << endl;
cin >> string;
cout << string << endl;
```
when input 1234567890
you will get:
1234
56789
***
File input and output
-
```
ifstream fin;
ofstream fout;
fin.open("input.txt");
fout.open("output.txt", ios:out);
fin >> ...
fout << ...
ios::out    // output to a file, clean original content
ios::app    // output to a file, remain original content, append to the end
ios::ate    // output to a file, remain original content, insert at any position.
```
```
ofstream fout("a1.out", ios::ate);
long location = fout.tellp();   // get write point position
location = 10L;
fout.seekp(location);   // move write point to 10th Byte.
fout.seekp(location, ios::beg);
fout.seekp(location, ios::cur);
fout.seekp(location, ios::end);
```
