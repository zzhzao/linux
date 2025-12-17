#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define PAGE_SIZE 4096

// write_map filename
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << argv[0] << "filename" << std::endl;
        return 1;
    }

    // 1. 打开文件，mmap需要自己先打开文件
    int fd = open(argv[1], O_RDONLY, 0666);
    if (fd < 0)
    {
        std::cout << "open failed... file : " << argv[1] << std::endl;
        return 1;
    }
    // 2. 获取文件大小
    struct stat st;
    fstat(fd, &st);

    // 3. 文件映射
    char *shmaddr = (char *)::mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (shmaddr == MAP_FAILED)
    {
        std::cout << "Failed to mmap file :" << argv[1] << std::endl;
        return 2;
    }
    // 4.文件操作
    std::cout << "File content :" << shmaddr << std::endl;

    // 5.关闭映射
    if (::munmap(shmaddr, PAGE_SIZE) == -1)
    {
        std::cout << "Failed to munmap file :" << argv[1] << std::endl;
        return 3;
    }
    close(fd);
    return 0;
}