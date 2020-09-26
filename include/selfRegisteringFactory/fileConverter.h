#ifndef FILE_CONVERTER_H
#define FILE_CONVERTER_H

class FileConverter {
private:
protected:
public:
	FileConverter() = default;
	FileConverter(const FileConverter&) = default;
	~FileConverter() = default;

	virtual void Import(const char*) = 0;
	virtual void Export(const char*) = 0;
};

#endif
