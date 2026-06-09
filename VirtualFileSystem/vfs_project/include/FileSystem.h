#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <vector>
#include "Directory.h"
#include "File.h"
class FileSystem {
    private:
        std::shared_ptr<Directory> root;
        std::shared_ptr<Directory> currentDirectory;
        void gatherAllComponents(std::shared_ptr<Directory> dir, std::vector<std::shared_ptr<FileSystemComponent>>& results) const;
    public:
        FileSystem();
        std::string getCurrentPath() const;
        bool createDir(const std::string& path);
        bool createFile(const std::string& path);
        bool removeFile(const std::string& path);
        bool removeDir(const std::string& path);
        bool changeDir(const std::string& path);
        std::string readFile(const std::string& path);
        bool writeFile(const std::string& path, const std::string& content);
        bool appendToFile(const std::string& path, const std::string& content);
        void listCurrentDirectory() const;
        std::vector<std::shared_ptr<FileSystemComponent>> findByName(const std::string& name) const;
        std::vector<std::shared_ptr<FileSystemComponent>> findBySize(size_t minSize, size_t maxSize) const;
        std::vector<std::shared_ptr<FileSystemComponent>> findByTimestamp(std::time_t startTime, std::time_t endTime) const;
        std::vector<std::shared_ptr<FileSystemComponent>> findByContent(const std::string& pattern) const;
};
#endif
