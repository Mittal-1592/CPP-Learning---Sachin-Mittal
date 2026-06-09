#ifndef I_FILE_SYSTEM_COMPONENT_H
#define I_FILE_SYSTEM_COMPONENT_H
    
#include <string>
#include <ctime>
#include "FileSystemComponentType.h"
class IFileSystemComponent {
    public:
        virtual ~IFileSystemComponent() = default;
        virtual std::string getName() const = 0;
        virtual std::time_t getCreationTime() const = 0;
        virtual std::time_t getModificationTime() const = 0;
        virtual size_t getSize() const = 0;
        virtual FileSystemComponentType getComponentType() const = 0;
};

#endif
