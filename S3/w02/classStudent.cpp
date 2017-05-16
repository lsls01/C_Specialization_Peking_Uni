#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Student
{
    private:
        int one, two, three, four, age;
        char id[20], name[50];

    public:
        void setValue()
        {
            char str[100];
            cin.getline(str, 100);
            int len = strlen(str);
            int i = 0;
            
            for(; str[i] != ','; i++)
                name[i] = str[i];
            name[i] = '\0';

            age = 0;
            for(i++; str[i] != ','; i++)
                age = age * 10 + str[i] - '0';
            
            int j = 0;
            for(i++; str[i] != ','; i++, j++)
                id[j] = str[i];
            id[j] = '\0';

            one = 0;
            two = 0;
            three = 0;
            four = 0;
            
            for(i++; str[i] != ','; i++)
                one = one * 10 + str[i] - '0';

            for(i++; str[i] != ','; i++)
                two = two * 10 + str[i] - '0';

            for(i++; str[i] != ','; i++)
                three = three * 10 + str[i] - '0';

            for(i++; str[i] != '\0'; i++)
                four = four * 10 + str[i] - '0';

            printf("%s,%d,%s,%d", name, age, id, (one + two + three + four) / 4);

        };
};

int main()
{
    int first, second, third, forth, age, avg;
    char id[20], name[50];
    Student student;
    student.setValue();
    return 0;
}
