#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

void *my_malloc(size_t size)
{
    if (size > 0)
    {
        void *ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ptr == MAP_FAILED)
        {
            return nullptr;
        }
        return ptr;
    }
    return nullptr;
}

void my_free(void *start, size_t size)
{
    if (start != nullptr && size > 0)
    {
        int ret = munmap(start, size);
        if (ret != 0)
        {
            perror("munmap");
        }
    }
}

int main()
{
    void *ptr = my_malloc(1024);
    if (ptr == nullptr)
    {

        std::cerr << "malloc failed.." << std::endl;
        return 1;
    }

    // todo: 内存操作




    my_free(ptr, 1024);
    return 0;
}