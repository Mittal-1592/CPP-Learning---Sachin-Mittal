#ifndef FILE_SYSTEM_COMPONENT_H
#define FILE_SYSTEM_COMPONENT_H

#include <memory>
#include "IFileSystemComponent.h"
class Directory;
class FileSystemComponent : public IFileSystemComponent, public std::enable_shared_from_this<FileSystemComponent> {
    protected:
        std::string name;
        size_t size;
        std::time_t creationTime;
        std::time_t modificationTime;
        std::weak_ptr<Directory> parent;
    public:
        FileSystemComponent(const std::string& name);
        virtual ~FileSystemComponent() = default;

        std::string getName() const override;
        std::time_t getCreationTime() const override;
        std::time_t getModificationTime() const override;
        size_t getSize() const override;
        void setParent(std::shared_ptr<Directory> parentDir);
        std::shared_ptr<Directory> getParent() const;
        void updateModificationTime();

        virtual std::string getContent() const { 
            return "Error: Path configuration resolves to a directory, not a file."; 
        }
        
        virtual void setContent(const std::string& newContent) {}
        virtual void appendContent(const std::string& extraContent) {}
};
#endif
