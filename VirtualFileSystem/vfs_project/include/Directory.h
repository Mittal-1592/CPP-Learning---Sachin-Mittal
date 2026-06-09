#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include "FileSystemComponent.h"
class Directory : public FileSystemComponent {
    private:
        std::vector<std::shared_ptr<FileSystemComponent>> children;
    public:
        Directory(const std::string& name);
        FileSystemComponentType getComponentType() const override;
        size_t getSize() const override;
        void addChild(std::shared_ptr<FileSystemComponent> component);
        void removeChild(const std::string& childName);
        const std::vector<std::shared_ptr<FileSystemComponent>>& getChildren() const;
        bool hasChild(const std::string& childName) const;
};

#endif
