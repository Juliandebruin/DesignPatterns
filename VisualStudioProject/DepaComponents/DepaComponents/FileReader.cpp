#include "FileReader.h"

FileReader::FileReader(std::string fileName):
    _file(std::ifstream(fileName)),
    _file_name(fileName),
    _file_content("")
{
}

FileReader::~FileReader()
{
}

void FileReader::read_file()
{
    std::string line;
    std::string fileContent = "";

    if (_file.is_open())
    {
        while (getline(_file, line))
        {
            fileContent += line + '\n';
        }
    }

    _file_content = fileContent;
}

std::string FileReader::get_file_content()
{
    if (_file_content == "")
    {
        read_file();
    }

    return _file_content;
}

void FileReader::close_file()
{
    _file.close();
}
