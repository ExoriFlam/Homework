#include "AccountManager.h"

bool AccountManager::add_user(const User& user)
{
    if (!find_user(user))
    {
        if (user.check_user_input_lengths())
        {
            if (user.check_email())
            {
                users.push_back(user);
                return true;
            }
        }
            
    }
    return false;
}

bool AccountManager::find_user(const User& user)
{
    for (int i = 0; i < users.get_count(); i++)
    {
        if (users[i] == user)
        {
            return true;
        }
        
    }
    return false;
}

void AccountManager::add_user_msg(MyString email,MyString msg)
{
    for (int i = 0; i < users.get_count(); i++)
    {
        if (users[i].get_email() == email)
        {
            users[i].add_message(msg);
            break;
        }

    }
    
}

bool AccountManager::find_login(const MyString& login, const MyString& pass)const
{
    for (int i = 0; i < users.get_count(); i++)
    {
        if (users[i].get_login() == login)
        {
            if (users[i].get_password() == pass)
            {
                return true;
            }
            
        }

    }
    return false;
}

bool AccountManager::find_email(const MyString& email) const
{
    for (int i = 0; i < users.get_count(); i++)
    {
        if (users[i].get_email() == email)
        {
            return true;
        }

    }
    return false;
}

bool AccountManager::set_current_user(const MyString& login)
{
    for (int i = 0; i < users.get_count(); i++)
    {
        if (users[i].get_login() == login)
        {
            current_user = users[i];
            return true;
        }

    }
    return false;
}

void AccountManager::show_all_emails() const
{
    for (int i = 0; i < users.get_count(); i++)
    {
        cout << "\n" << users[i].get_email() << "\n";
    }
}
