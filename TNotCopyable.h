#ifndef MODUL2_LAB4_RAII_TNOTCOPYABLE_H
#define MODUL2_LAB4_RAII_TNOTCOPYABLE_H

#pragma warning(disable:4996)
#include <exception>
#include <cstdio>
#include <string>

struct FileAlreadyOpened
        : public std::exception
{
    FileAlreadyOpened() = default;
    FileAlreadyOpened(const char* const message)
            : std::exception(message)
    { }
};

class TNotCopyable
{
private:
    FILE * Descriptor;

public:
    TNotCopyable()
            : Descriptor(nullptr)
    { }

    TNotCopyable(const TNotCopyable&) = delete;
    TNotCopyable& operator = (const TNotCopyable&) = delete;

    void OpenToWrite(std::string const & fileName)
    {
        if (Descriptor != nullptr)
            throw FileAlreadyOpened();
        Descriptor = fopen(fileName.c_str(), "w");
    }

    void OpenToRead(std::string const & fileName)
    {
        if (Descriptor != nullptr)
            throw FileAlreadyOpened();
        Descriptor = fopen(fileName.c_str(), "r");
    }

    void Close() throw()
    {
        if (Descriptor != nullptr)
        {
            fclose(Descriptor);
            Descriptor = nullptr;
        }
    }

    FILE * Get()
    {
        return Descriptor;
    }
};


#endif //MODUL2_LAB4_RAII_TNOTCOPYABLE_H
