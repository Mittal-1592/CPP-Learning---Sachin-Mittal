#include <iostream>
#include <sstream>
#include <iomanip>
#include "FileSystem.h"

FileSystem::FileSystem() { 
    root = std::make_shared<Directory>("/"); 
    currentDirectory = root; 
}

std::string FileSystem::getCurrentPath() const {
    std::string path = "";
    auto curr = currentDirectory;
    
    while (curr && curr != root) { 
        path = "/" + curr->getName() + path; 
        curr = curr->getParent(); 
    }
    
    return path.empty() ? "/" : path;
}

bool FileSystem::createDir(const std::string& path) {
    if (path.empty() || currentDirectory->hasChild(path)) {
        return false;
    }
    
    auto newDir = std::make_shared<Directory>(path); 
    currentDirectory->addChild(newDir); 
    
    return true;
}

bool FileSystem::createFile(const std::string& path) {
    if (path.empty() || currentDirectory->hasChild(path)) {
        return false;
    }
    
    auto newFile = std::make_shared<File>(path); 
    currentDirectory->addChild(newFile); 
    
    return true;
}

bool FileSystem::removeFile(const std::string& path) {
    if (path.empty()) return false;

    std::shared_ptr<Directory> targetDir = currentDirectory;
    std::string fileName = path;

    size_t lastSlash = path.find_last_of('/');
    if (lastSlash != std::string::npos) {
        std::string dirPath = path.substr(0, lastSlash);
        fileName = path.substr(lastSlash + 1);

        auto savedDir = currentDirectory;
        if (!changeDir(dirPath == "" ? "/" : dirPath)) {
            return false; 
        }
        targetDir = currentDirectory;
        currentDirectory = savedDir; 
    }

    for (const auto& child : targetDir->getChildren()) {
        if (child->getName() == fileName && child->getComponentType() == FileSystemComponentType::File) {
            targetDir->removeChild(fileName);
            return true;
        }
    }
    return false;
}

bool FileSystem::removeDir(const std::string& path) {
    if (path.empty()) return false;

    std::shared_ptr<Directory> targetDir = currentDirectory;
    std::string dirName = path;

    size_t lastSlash = path.find_last_of('/');
    if (lastSlash != std::string::npos) {
        std::string dirPath = path.substr(0, lastSlash);
        dirName = path.substr(lastSlash + 1);

        auto savedDir = currentDirectory;
        if (!changeDir(dirPath == "" ? "/" : dirPath)) {
            return false;
        }
        targetDir = currentDirectory;
        currentDirectory = savedDir;
    }

    for (const auto& child : targetDir->getChildren()) {
        if (child->getName() == dirName && child->getComponentType() == FileSystemComponentType::Directory) {
            targetDir->removeChild(dirName);
            return true;
        }
    }
    return false;
}

bool FileSystem::changeDir(const std::string& path) {
    if (path.empty()) {
        currentDirectory = root;
        return true;
    }

    std::shared_ptr<Directory> navCursor = currentDirectory;

    size_t startIndex = 0;
    if (path[0] == '/') {
        navCursor = root;
        startIndex = 1;
    }

    std::stringstream ss(path.substr(startIndex));
    std::string segment;

    while (std::getline(ss, segment, '/')) {
        if (segment.empty() || segment == ".") {
            continue;
        }

        if (segment == "..") {
            auto parentNode = navCursor->getParent();
            if (parentNode) {
                navCursor = parentNode;
            }
            continue;
        }

        bool segmentFound = false;
        for (const auto& child : navCursor->getChildren()) {
            if (child->getName() == segment && child->getComponentType() == FileSystemComponentType::Directory) {
                navCursor = std::static_pointer_cast<Directory>(child);
                segmentFound = true;
                break;
            }
        }

        if (!segmentFound) {
            return false; 
        }
    }
    currentDirectory = navCursor;
    return true;
}

std::string FileSystem::readFile(const std::string& path) {
    for (const auto& child : currentDirectory->getChildren()) {
        if (child->getName() == path && child->getComponentType() == FileSystemComponentType::File) {
            return child->getContent();
        }
    }
    return "Error: File not found.";
}

bool FileSystem::writeFile(const std::string& path, const std::string& content) {
    for (const auto& child : currentDirectory->getChildren()) {
        if (child->getName() == path && child->getComponentType() == FileSystemComponentType::File) {
            child->setContent(content);
            return true;
        }
    }
    return false;
}

bool FileSystem::appendToFile(const std::string& path, const std::string& content) {
    for (const auto& child : currentDirectory->getChildren()) {
        if (child->getName() == path && child->getComponentType() == FileSystemComponentType::File) {
            child->appendContent(content);
            return true;
        }
    }
    return false;
}


void FileSystem::listCurrentDirectory() const {
    for (const auto& child : currentDirectory->getChildren()) {
        // 1. Fetch the raw metadata epoch value from the component
        std::time_t modTime = child->getModificationTime();
        
        // 2. Convert it into a local calendar structure
        std::tm* localTime = std::localtime(&modTime);
        
        // 3. Format it beautifully (e.g., Jun 08 11:47)
        std::stringstream ss;
        ss << std::put_time(localTime, "%b %d %H:%M");

        // 4. Print the component details identically to a long-format Linux terminal
        if (child->getComponentType() == FileSystemComponentType::Directory) {
            std::cout << "[DIR]  " << std::left << std::setw(15) << child->getName() 
                      << " \t" << ss.str() << " \t(" << child->getSize() << " bytes)\n";
        } else {
            std::cout << "[FILE] " << std::left << std::setw(15) << child->getName() 
                      << " \t" << ss.str() << " \t(" << child->getSize() << " bytes)\n";
        }
    }
}

void FileSystem::gatherAllComponents(std::shared_ptr<Directory> dir, std::vector<std::shared_ptr<FileSystemComponent>>& results) const {
    for (const auto& child : dir->getChildren()) {
        results.push_back(child);
        if (child->getComponentType() == FileSystemComponentType::Directory) {
            gatherAllComponents(std::static_pointer_cast<Directory>(child), results);
        }
    }
}

std::vector<std::shared_ptr<FileSystemComponent>> FileSystem::findByName(const std::string& name) const {
    std::vector<std::shared_ptr<FileSystemComponent>> matches; 
    std::vector<std::shared_ptr<FileSystemComponent>> allItems; 
    gatherAllComponents(root, allItems);
    
    for (const auto& item : allItems) { 
        if (item->getName() == name) {
            matches.push_back(item); 
        }
    }
    return matches;
}

std::vector<std::shared_ptr<FileSystemComponent>> FileSystem::findBySize(size_t minSize, size_t maxSize) const {
    std::vector<std::shared_ptr<FileSystemComponent>> matches; 
    std::vector<std::shared_ptr<FileSystemComponent>> allItems; 
    gatherAllComponents(root, allItems);
    
    for (const auto& item : allItems) { 
        size_t s = item->getSize(); 
        if (s >= minSize && s <= maxSize) {
            matches.push_back(item); 
        }
    }
    return matches;
}

std::vector<std::shared_ptr<FileSystemComponent>> FileSystem::findByTimestamp(std::time_t startTime, std::time_t endTime) const {
    std::vector<std::shared_ptr<FileSystemComponent>> matches; 
    std::vector<std::shared_ptr<FileSystemComponent>> allItems; 
    gatherAllComponents(root, allItems);
    
    for (const auto& item : allItems) { 
        std::time_t t = item->getModificationTime(); 
        if (t >= startTime && t <= endTime) {
            matches.push_back(item); 
        }
    }
    return matches;
}

std::vector<std::shared_ptr<FileSystemComponent>> FileSystem::findByContent(const std::string& pattern) const {
    std::vector<std::shared_ptr<FileSystemComponent>> matches; 
    std::vector<std::shared_ptr<FileSystemComponent>> allItems; 
    gatherAllComponents(root, allItems);
    
    for (const auto& item : allItems) {
        if (item->getComponentType() == FileSystemComponentType::File) { 
            auto f = std::static_pointer_cast<File>(item); 
            if (f->getContent().find(pattern) != std::string::npos) {
                matches.push_back(f); 
            }
        }
    }
    return matches;
}