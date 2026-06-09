#ifndef FILE_H
#define FILE_H

#include "FileSystemComponent.h"
class File : public FileSystemComponent {
    private:
        std::string content;
    public:
        File(const std::string& name);
        FileSystemComponentType getComponentType() const override;
        size_t getSize() const override;

        std::string getContent() const override;
        void setContent(const std::string& newContent) override;
        void appendContent(const std::string& extraContent) override;
};
#endif
