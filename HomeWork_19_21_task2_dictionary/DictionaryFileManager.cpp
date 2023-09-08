#include "DictionaryFileManager.h"





DictionaryFileManager::DictionaryFileManager() :
    txt{ nullptr }, bin{ nullptr }, dictionary_t{ "Dictionary.txt" }, dictionary_b{ "Data.dat" } {}

void DictionaryFileManager::set_txt_fname(const char* new_name)
{
    this->dictionary_t = new_name; 
}

void DictionaryFileManager::set_bin_fname(const char* new_name)
{
    this->dictionary_b = new_name;
}

bool DictionaryFileManager::save_to_txt(EngRusTree& src)
{
    bool succes = false;
    errno_t err_txt = fopen_s(&txt, dictionary_t, "w");
    if (!err_txt)
    {
        succes = src.save_to_txt(txt);
        fclose(txt);
    }
    
    return succes; 
}

bool DictionaryFileManager::save_to_bin(EngRusTree& src)
{
    bool succes = false;
    errno_t err_bin_w = fopen_s(&bin, dictionary_b, "wb");
    if (!err_bin_w)
    {
        succes = src.save_to_bin(bin);
        fclose(bin);
    }
    return succes;
}

bool DictionaryFileManager::read_from_bin_to(EngRusTree& destination)
{
    bool succes = false;
    errno_t  err_bin_r = fopen_s(&bin, dictionary_b, "rb");
    if (!err_bin_r)
    {
        succes = destination.read_from_bin(bin);
        fclose(bin);
    }
    return succes;
}

DictionaryFileManager::~DictionaryFileManager()
{
    if(txt) fclose(txt);
    if(bin) fclose(bin);
}
