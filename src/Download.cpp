#include "Download.h"
#include <windows.h>
#include <urlmon.h>
#include <iostream>
#pragma comment(lib, "urlmon.lib")

namespace Downloader {
    bool downloadFile(const std::wstring& url, const std::wstring& savePath) {
        HRESULT hr = URLDownloadToFileW(NULL, url.c_str(), savePath.c_str(), 0, NULL);
        if (SUCCEEDED(hr)) {
            return true;
        } else {
            std::cout << "Error downloading file: 0x" << std::hex << hr << "\n";
            return false;
        }
    }
}
