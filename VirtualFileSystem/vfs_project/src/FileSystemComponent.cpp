#include "FileSystemComponent.h"
#include "Directory.h"

FileSystemComponent::FileSystemComponent(const std::string& name)
    : name(name), 
      size(0), 
      creationTime(std::time(nullptr)), 
      modificationTime(std::time(nullptr)) {}

std::string FileSystemComponent::getName() const { 
    return name; 
}

std::time_t FileSystemComponent::getCreationTime() const { 
    return creationTime; 
}

std::time_t FileSystemComponent::getModificationTime() const { 
    return modificationTime; 
}

size_t FileSystemComponent::getSize() const { 
    return size; 
}

void FileSystemComponent::setParent(std::shared_ptr<Directory> parentDir) { 
    parent = parentDir; 
}

std::shared_ptr<Directory> FileSystemComponent::getParent() const { 
    return parent.lock(); 
}

void FileSystemComponent::updateModificationTime() { 
    modificationTime = std::time(nullptr); 
}