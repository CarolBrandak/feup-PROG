#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include "Page.h"
#include "Book.h"

using namespace std;

//! Builds "index" for the "words" received as parameter
void Book::build_index(const std::set<std::string> &words)
{
    bool is_page;
    bool add_index;
    for (string w : words)
    {
        add_index = false;
        for (size_t i = 0; i < book_.size(); i++)
        {
            is_page = false;
            Page currpage = book_[i];
            for (size_t numline = 0; numline < currpage.get_num_lines(); numline++)
            {
                if (currpage.get_line(numline).find(w) != string::npos)
                {
                    is_page = true;
                    break;
                }
            }

            if (is_page)
            {
                if (!add_index && !index_.count(w))
                {
                    index_.insert({w, {}});
                    add_index = true;
                }
                index_.at(w).insert(i + 1);
            }
        }
    }
}