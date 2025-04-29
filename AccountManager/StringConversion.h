#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H

#include <string>


static std::string toStdString(System::String^ systemString) {
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(systemString)).ToPointer();
	std::string stdString(chars, systemString->Length);
    Marshal::FreeHGlobal(IntPtr((void*)chars));
	return stdString;
}



#endif // STRING_CONVERSION_H
