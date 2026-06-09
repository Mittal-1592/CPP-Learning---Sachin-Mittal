#include "Directory.h"
#include <algorithm>

Directory::Directory(const std::string& name) 
    : FileSystemComponent(name) {}

FileSystemComponentType Directory::getComponentType() const { 
    return FileSystemComponentType::Directory; 
}

size_t Directory::getSize() const {
    size_t totalSize = 0;
    for (const auto& child : children) { 
        totalSize += child->getSize(); 
    }
    return totalSize;
}

void Directory::addChild(std::shared_ptr<FileSystemComponent> component) {
    component->setParent(std::dynamic_pointer_cast<Directory>(shared_from_this()));
    children.push_back(component);
    updateModificationTime();
}

void Directory::removeChild(const std::string& childName) {
    auto it = std::remove_if(children.begin(), children.end(), 
        [&childName](const std::shared_ptr<FileSystemComponent>& child) { 
            return child->getName() == childName; 
        });
        
    if (it != children.end()) { 
        children.erase(it, children.end()); 
        updateModificationTime(); 
    }
}

const std::vector<std::shared_ptr<FileSystemComponent>>& Directory::getChildren() const { 
    return children; 
}

bool Directory::hasChild(const std::string& childName) const {
    for (const auto& child : children) { 
        if (child->getName() == childName) {
            return true; 
        }
    }
    return false;
}