#pragma once
#include <fstream>
#include <string>

/**
 * @brief Class to read files in string format
 */
class FileReader
{
public:
	/**
	 * @brief Construct a new File Reader object
	 * 
	 * @param fileName fileName of file to open
	 */
	FileReader(std::string fileName);
	/**
	 * @brief Destroy the File Reader object
	 */
	virtual ~FileReader();

	/**
	 * @brief Reads file if open and saves it
	 */
	void read_file();
	/**
	 * @brief Gets saved file content in string format,
	 *  only reads file if it has not been read before
	 * 
	 * @return std::string Returns file content
	 */
	std::string get_file_content();
	/**
	 * @brief Close file
	 */
	void close_file();

private:
	std::ifstream _file; /*< File object */
	std::string _file_name; /*< File name */
	std::string _file_content; /*< File content */
};

