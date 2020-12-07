// lab 9.2 A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <string>
#define TESTING


using namespace std;

#pragma pack(push, 1)

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "Computer Science ",
                             "Radio Electronics", "Computer Science",
                             "Computer Engineering", "Software" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_info;
    int third_grade;

};

#pragma pack(pop)

void Create(Students* S, const int N);
double student_avarage_evaluation(Students* S, const int i);
void Print(Students* S, const int N);
double Percentage(Students* S, const int N);
void p_sort(Students* S, const int N);
int* i_sort(Students* S, const int N);
void i_print(Students* S, int* I, const int N);
bool b_search(Students* S, const int N, const string surname, const double avarage_evaluation, const int third_grade);

#ifdef TESTING
int main()
{
    int N;
    cout << "Enter the number of students: "; cin >> N;

    Students* S = new Students[N];

    string f_surname;
    double f_avarage_evaluation;
    int f_third_grade;

    int MenuItem;

    while (true)
    {
        cout << endl << endl << endl;
        cout << "Choose an action:" << endl;
        cout << "1 - Enter information about students" << endl;
        cout << "2 - Display information about students" << endl;
        cout << "3 - Physically organize information" << endl;
        cout << "4 - Index information" << endl;
        cout << "5 - Student Search"; cout << endl;
        cout << "0 - Shut down the program" << endl;
        cout << "Enter:"; cin >> MenuItem; cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(S, N);
            break;
        case 2:
            Print(S, N);
            break;
        case 3:
            p_sort(S, N);
            Print(S, N);
            break;
        case 4:
            i_print(S, i_sort(S, N), N);
            break;
        case 5:
            cout << "Enter search criteria: " << endl;
            cout << "surname" << endl;
            cin.get();
            cin.sync();
            getline(cin, f_surname); cout << endl;

            do
            {
                cout << "GPA" << endl;
                cin >> f_avarage_evaluation; cout << endl;
            } while (f_avarage_evaluation < 1 || f_avarage_evaluation > 5);

            do
            {
                cout << "Grade from the third subject:" << endl;
                cin >> f_third_grade; cout << endl;
            } while (f_third_grade < 1 || f_third_grade > 5);

            if (b_search(S, N, f_surname, f_avarage_evaluation, f_third_grade))
            {
                cout << "Student is" << endl;
            }
            else {
                cout << "not found" << endl;
            }
        }

        if (MenuItem == 0) break;
    }

    return 0;
}
#endif

void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Student #: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Surname: "; 
        getline(cin, S[i].surname); cout << endl;

        do
        {
            cout << "Course: "; cin >> S[i].course; cout << endl;
        } while (S[i].course < 1 || S[i].course > 6);

        do
        {
            cout << "Specialty (0 - Informatics, 1 - Radio Electronics, 2 - Computer Science,";
            cout << "\ n3 - Computer Engineering, 4 - Software) ";
            cin >> speciality;
            S[i].speciality = (Speciality)speciality;
        } while (S[i].speciality < 0 || S[i].speciality > 4);

        do
        {
            cout << "physics grade: "; cin >> S[i].grade_physics; cout << endl;
        } while (S[i].grade_physics < 1 || S[i].grade_physics > 5);

        do
        {
            cout << "maths grade: "; cin >> S[i].grade_math; cout << endl;
        } while (S[i].grade_math < 1 || S[i].grade_math > 5);

        do
        {
            cout << "programming grade: "; cin >> S[i].grade_info; cout << endl;
        } while (S[i].grade_info < 1 || S[i].grade_info > 5);

        cout << endl;
    }
}

void Print(Students* S, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "| # | Last name    | Course    | Specialty      | Physics     |Mathematics   |   Programming |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(4);
        cout << "|" << setw(6) << S[i].course << setw(6);
        cout << "|" << setw(6) << speciality_str[S[i].speciality] << setw(6);
        cout << "|" << setw(6) << S[i].grade_physics << setw(6);
        cout << "|" << setw(6) << S[i].grade_math << setw(6);
        cout << "|" << setw(6) << S[i].grade_info << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}

double student_avarage_evaluation(Students* S, int i)
{
    return (S[i].grade_math * 1. + S[i].grade_physics * 1. + S[i].grade_info * 1.) / 3.;
}

void p_sort(Students* S, int N)
{
    Students temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if ((student_avarage_evaluation(S, j) > student_avarage_evaluation(S, j + 1))
                || (student_avarage_evaluation(S, j) == student_avarage_evaluation(S, j + 1))
                && (S[j].third_grade > S[j + 1].third_grade)
                || (student_avarage_evaluation(S, j) == student_avarage_evaluation(S, j + 1))
                && (S[j].third_grade == S[j + 1].third_grade)
                && (S[j].surname < S[j].surname))
            {
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }

        }
    }
}

int* i_sort(Students* S, const int N)
{
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    int j, value;
    for (int i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            (student_avarage_evaluation(S, j) > student_avarage_evaluation(S, j + 1))
            || (student_avarage_evaluation(S, j) == student_avarage_evaluation(S, j + 1))
            && (S[j].third_grade > S[j + 1].third_grade)
            || (student_avarage_evaluation(S, j) == student_avarage_evaluation(S, j + 1))
            && (S[j].third_grade == S[j + 1].third_grade)
            && (S[j].surname < S[j].surname);
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}

void i_print(Students* S, int* I, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "| # | Last name    | Course    | Specialty      | Physics     |Mathematics   |   Programming |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[I[i]].surname << setw(4);
        cout << "|" << setw(6) << S[I[i]].course << setw(6);
        cout << "|" << setw(6) << speciality_str[S[I[i]].speciality] << setw(6);
        cout << "|" << setw(6) << S[I[i]].grade_physics << setw(6);
        cout << "|" << setw(6) << S[I[i]].grade_math << setw(6);
        cout << "|" << setw(6) << S[I[i]].grade_info << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}

bool b_search(Students* S, const int N, const string surname, const double avarage_evaluation, const int third_grade)
{
    int L = 0, R = N - 1, m;
    do
    {
        m = (L + R) / 2;
        if ((S[m].surname == surname
            &&
            (student_avarage_evaluation(S, m) == avarage_evaluation)
            &&
            (S[m].third_grade == third_grade)))
        {
            return 1;
        }

        if ((S[m].third_grade < third_grade)
            ||
            (S[m].third_grade == third_grade
                &&
                student_avarage_evaluation(S, m) < avarage_evaluation)
            ||
            (S[m].third_grade == third_grade
                &&
                student_avarage_evaluation(S, m) == avarage_evaluation
                &&
                S[m].surname < surname))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
