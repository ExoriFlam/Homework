#include "FileManager.h"

FileManager::FileManager() {}
 

bool FileManager::save_to_txt(const ListTwoTemplate<User>& src)
{
    bool succes = false;
    
    to_txt.open("User_info.txt", ios::out);

    if (to_txt.is_open())
    {
        succes = src.save_to_txt(to_txt);
        to_txt.close();
    }

    return succes;
}

bool FileManager::save_to_bin(const ListTwoTemplate<User>& src)
{
    bool succes = false;
    to_bin.open("Users.dat", ios::binary);

    if (to_bin.is_open())
    {
        to_bin << src;

        succes = true;
        to_bin.close();
    }
    return succes;
}

bool FileManager::read_from_bin_to(ListTwoTemplate<User>& user_list)
{
    bool succes = false;

    from_bin.open("Users.dat", ios::binary);

    if (from_bin.is_open())
    {
        from_bin >> user_list;

        succes = true;
        from_bin.close();
    }
    return succes;
}

FileManager::~FileManager()
{
    to_txt.close();
    to_bin.close();
    from_bin.close();
}
