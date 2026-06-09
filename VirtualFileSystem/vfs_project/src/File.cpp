#include "File.h"

File::File(const std::string& name) 
    : FileSystemComponent(name), content("") {}

FileSystemComponentType File::getComponentType() const { 
    return FileSystemComponentType::File; 
}

size_t File::getSize() const { 
    return content.size(); 
}

std::string File::getContent() const { 
    return content; 
}

void File::setContent(const std::string& newContent) { 
    content = newContent; 
    updateModificationTime(); 
}

void File::appendContent(const std::string& extraContent) { 
    content += extraContent; 
    updateModificationTime(); 
}