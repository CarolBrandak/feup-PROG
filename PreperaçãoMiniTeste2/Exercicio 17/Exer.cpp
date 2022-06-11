#include <iostream>
#include <vector>
#include "Date.h"
#include "Person.h"

using namespace std;

// persons born before date
void born_before(const vector<Person> &persons, const Date &date)
{
    date.show();
    cout << ": ";
    for (Person p : persons)
    {
        if (p.get_birth_date().is_before(date))
        {
            p.show();
            cout << " ";
        }
    }
}

/* Submit the code for Date and Person classes using file attachments. */