#ifndef MODUL2_LAB4_RAII_RAII_H
#define MODUL2_LAB4_RAII_RAII_H

#include "TNotCopyable.h"

class RAII
{
private:
    TNotCopyable *Ptr;
public:
    RAII()
    {}

    RAII(TNotCopyable *ptr)
    {
        Ptr = ptr;
    }

    ~RAII()
    {
        Ptr->Close();
    }
};

#endif //MODUL2_LAB4_RAII_RAII_H
